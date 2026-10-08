/*******************************
Bachelor of Software Engineering
Media Design School
Auckland
New Zealand
(c) 2026 Media Design School at Strayer
File Name : [cLevel.cpp]
Description : [Implimentation for class cLevel, loads the level from file and creates objects as nessesary. also draws and checks for collisions on said blocks]
Author : [Alastor Spear]
Mail : alastor.spear@mds.ac.nz
*******************************/

#include "cLevel.h"

//#include "cPlayer.h" // is throwing a hissy fit if if put this in the ,h file >:(


cLevel::cLevel(std::string _levelFilePath)
	: m_LevelFilePath(_levelFilePath)
{
	m_ptrBlockTexture = new sf::Texture();
	m_ptrBlockTexture->loadFromFile(m_WallTextureFilePath);

	// flower texture stuff
	m_ptrFlowerTexture = new sf::Texture();
	m_ptrFlowerTexture->loadFromFile(m_FlowerTextureFilePath);
	m_FlowerTextureRect.position.x = m_CurrentFlower;
	m_FlowerTextureRect.position.y = 0;
	m_FlowerTextureRect.size.x = 16;
	m_FlowerTextureRect.size.y = 32;
}


cLevel::~cLevel()
{
	UnloadLevel();

	delete m_ptrBlockTexture;
	m_ptrBlockTexture = nullptr;

	delete m_ptrFlowerTexture;
	m_ptrFlowerTexture = nullptr;
}


/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ LOAD/UNLOAD LEVEL ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

void cLevel::LoadLevel()
{
	// open level file and read from it
	std::fstream loadFileStream;
	loadFileStream.open(m_LevelFilePath, std::ios::in);

	std::string loadFileString;
	int lineCount = 0;

	// retrive all characters from file and put them in levelArray
	if (loadFileStream.is_open())
	{
		while (std::getline(loadFileStream, loadFileString))
		{
			for (int i = 0; i < loadFileString.size(); i++)
			{
				levelArray[i][lineCount] = loadFileString[i];
			}
			lineCount++;
		}
		loadFileStream.close(); // close stream bc we are no longer using it
	}
	
	for (int y = 0; y < m_LevelHight; y++)
	{
		for (int x = 0; x < m_LevelWidth; x++)
		{
			// check for blocks in the level
			if (levelArray[x][y] == 'X') // X -> default block
			{
				sf::RectangleShape* newBox = new sf::RectangleShape({ m_TileSize, m_TileSize });
				newBox->setPosition(sf::Vector2f(x * m_TileSize, y * m_TileSize));
				newBox->setTexture(m_ptrBlockTexture);

				// we may need extra logic for setting up colliders

				LevelDefaultBlocks.push_back(newBox);
			}

			// check for obsticals
			if (levelArray[x][y] == 'V') // V -> obstical
			{
				sf::RectangleShape* newBox = new sf::RectangleShape({ m_TileSize, m_TileSize });
				newBox->setPosition(sf::Vector2f(x * m_TileSize, y * m_TileSize));
				//newBox->setTexture(&); // obstical texture
				newBox->setFillColor(sf::Color::Red);

				LevelObsticalBlocks.push_back(newBox);
			}

			// check for Checkpoints
			if (levelArray[x][y] == 'C') // C -> check point
			{
				sf::RectangleShape* newBox = new sf::RectangleShape({ m_TileSize, m_TileSize });
				newBox->setPosition(sf::Vector2f(x * m_TileSize, y * m_TileSize));
				//newBox->setTexture(&); // checkpoint texture
				newBox->setFillColor(sf::Color::Green);

				LevelCheckPointBlocks.push_back(newBox);

				// first found checkpoint is the player starting position
				m_PlayerPosition = sf::Vector2f(x * m_TileSize, y * m_TileSize);
			}

			// check for flowers
			if (levelArray[x][y] == 'F' && m_NumOfFlowers < 6) // F -> Flower // also prevents more than 6 flowers being in a level at once
			{
				sf::RectangleShape* newBox = new sf::RectangleShape({ m_TileSize / 2, m_TileSize }); // flowers have half the width of a normal block
				newBox->setPosition(sf::Vector2f(x * m_TileSize, y * m_TileSize));
				newBox->setTexture(m_ptrFlowerTexture);
				newBox->setTextureRect(m_FlowerTextureRect); // Flower texture

				// move allong FlowerTextureRect by 16
				m_CurrentFlower += 16;
				m_FlowerTextureRect.position.x = m_CurrentFlower;

				m_NumOfFlowers++;

				FlowerFound.push_back(false);

				LevelFLowerBlocks.push_back(newBox);
			}


			// check for Platforms
			if (levelArray[x][y] == 'L') // L -> Platform 
			{
				sf::RectangleShape* newBox = new sf::RectangleShape({ m_TileSize, m_TileSize });
				newBox->setPosition(sf::Vector2f(x * m_TileSize, y * m_TileSize));
				//newBox->setTexture(&); // platform texture
				newBox->setFillColor(sf::Color::Magenta);

				LevelPlatformBlocks.push_back(newBox);
			}

			// check for Sunlight
			if (levelArray[x][y] == 'S') // S -> Sunlight 
			{
				sf::RectangleShape* newBox = new sf::RectangleShape({ m_TileSize, m_TileSize });
				newBox->setPosition(sf::Vector2f(x * m_TileSize, y * m_TileSize));
				//newBox->setTexture(&); // Sunlight texture
				newBox->setFillColor(sf::Color::Yellow);

				LevelSunlightBlocks.push_back(newBox);
			}
			/*
			player will be arranged in file like this:

			XXXPXXX
			XXXNXXX
			= SisterNiki

			or

			XXXPXXX
			XXXAXXX
			= SisterAl

			this corresponds with wich character should be active
			if it is just 'P', then default to SisterNiki
			*/


			// check for the player
			if (levelArray[x][y] == 'P') // P -> Player position
			{
				m_PlayerPosition = sf::Vector2f(x * m_TileSize, y * m_TileSize);

				if (levelArray[x][y + 1] == 'A')
				{
					m_StartingCharacter = SisterAl;
				}
				else
				{
					m_StartingCharacter = SisterNiki;
				}

			}
		}
	}
}


void cLevel::UnloadLevel()
{
	// for the given level. delete everything inside it
	
	// delete wall tiles
	for (int i = 0; i < LevelDefaultBlocks.size(); i++)
	{
		delete LevelDefaultBlocks[i];
		LevelDefaultBlocks[i] = nullptr;
	}

	// delete Obstial Tiles
	for (int i = 0; i < LevelObsticalBlocks.size(); i++)
	{
		delete LevelObsticalBlocks[i];
		LevelObsticalBlocks[i] = nullptr;
	}

	// delete checkpoints
	for (int i = 0; i < LevelCheckPointBlocks.size(); i++)
	{
		delete LevelCheckPointBlocks[i];
		LevelCheckPointBlocks[i] = nullptr;
	}

	// delete flowers
	for (int i = 0; i < LevelFLowerBlocks.size(); i++)
	{
		delete LevelFLowerBlocks[i];
		LevelFLowerBlocks[i] = nullptr;

	}

	// delete Platform tiles
	for (int i = 0; i < LevelPlatformBlocks.size(); i++)
	{
		delete LevelPlatformBlocks[i];
		LevelPlatformBlocks[i] = nullptr;
	}

	// delete Sunlight
	for (int i = 0; i < LevelSunlightBlocks.size(); i++)
	{
		delete LevelSunlightBlocks[i];
		LevelSunlightBlocks[i] = nullptr;
	}
}


/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ DRAW BLOCKS ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

void cLevel::DrawAllBlocks(sf::RenderWindow& _window)
{
	DrawWallBlocks(_window);
	DrawObsticalBlocks(_window);
	DrawCheckPointBlocks(_window);
	DrawFlowerBlocks(_window);
	DrawPlatformBlocks(_window);
	DrawSunlightBlocks(_window);
}


void cLevel::DrawWallBlocks(sf::RenderWindow& _window)
{
	for (int i = 0; i < LevelDefaultBlocks.size(); i++)
	{
		_window.draw(*LevelDefaultBlocks[i]);
	}
}

void cLevel::DrawObsticalBlocks(sf::RenderWindow& _window)
{
	for (int i = 0; i < LevelObsticalBlocks.size(); i++)
	{
		_window.draw(*LevelObsticalBlocks[i]);
	}
}

void cLevel::DrawCheckPointBlocks(sf::RenderWindow& _window)
{
	for (int i = 0; i < LevelCheckPointBlocks.size(); i++)
	{
		_window.draw(*LevelCheckPointBlocks[i]);
	}
}

void cLevel::DrawFlowerBlocks(sf::RenderWindow& _window)
{
	for (int i = 0; i < LevelFLowerBlocks.size(); i++)
	{
		_window.draw(*LevelFLowerBlocks[i]);
	}
}

void cLevel::DrawPlatformBlocks(sf::RenderWindow& _window)
{
	for (int i = 0; i < LevelPlatformBlocks.size(); i++)
	{
		_window.draw(*LevelPlatformBlocks[i]);
	}
}

void cLevel::DrawSunlightBlocks(sf::RenderWindow& _window)
{
	for (int i = 0; i < LevelSunlightBlocks.size(); i++)
	{
		_window.draw(*LevelSunlightBlocks[i]);
	}
}



/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ COLLISIONS ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

sf::Shape* cLevel::CollisionWallBlocks(sf::RectangleShape* _collidingWith)
{
	for (int i = 0; i < LevelDefaultBlocks.size(); i++)
	{
		if (_collidingWith->getGlobalBounds().findIntersection(LevelDefaultBlocks[i]->getGlobalBounds()))
		{
			return LevelDefaultBlocks[i];
		}
	}
	// has passed all checks and is not colliding with anything, therefore return nullptr
	return nullptr;
}

sf::Shape* cLevel::CollisionObsticalBlocks(sf::RectangleShape* _collidingWith)
{
	for (int i = 0; i < LevelObsticalBlocks.size(); i++)
	{
		if (_collidingWith->getGlobalBounds().findIntersection(LevelObsticalBlocks[i]->getGlobalBounds()))
		{
			return LevelObsticalBlocks[i];
		}
	}
	// has passed all checks and is not colliding with anything, therefore return nullptr
	return nullptr;
}

sf::Shape* cLevel::CollisionCheckPointBlocks(sf::RectangleShape* _collidingWith)
{
	for (int i = 0; i < LevelCheckPointBlocks.size(); i++)
	{
		if (_collidingWith->getGlobalBounds().findIntersection(LevelCheckPointBlocks[i]->getGlobalBounds()))
		{
			return LevelCheckPointBlocks[i];
		}
	}
	// has passed all checks and is not colliding with anything, therefore return nullptr
	return nullptr;
}

sf::Shape* cLevel::CollisionFlowerBlocks(sf::RectangleShape* _collidingWith)
{
	for (int i = 0; i < LevelFLowerBlocks.size(); i++)
	{
		// ignore the flower if it has already been collided with
		if (_collidingWith->getGlobalBounds().findIntersection(LevelFLowerBlocks[i]->getGlobalBounds()) && !FlowerFound[i])
		{
			FlowerFound[i] = true; // flower is found, so set to true

			return LevelFLowerBlocks[i];
		}
	}
	// has passed all checks and is not colliding with anything, therefore return nullptr
	return nullptr;
}

sf::Shape* cLevel::CollisionPlatformBlocks(sf::RectangleShape* _collidingWith, ActiveCharacter _character, float _yVelocity)
{
	// a collision will happen if sister al is active, OR sister niki is active and she is not jumping upwards
	if (_character == SisterAl || (_character == SisterNiki && _yVelocity >= 0))
	{
		for (int i = 0; i < LevelPlatformBlocks.size(); i++)
		{
			if (_collidingWith->getGlobalBounds().findIntersection(LevelPlatformBlocks[i]->getGlobalBounds()))
			{
				return LevelPlatformBlocks[i];
			}
		}
	}
	// will let the player phase through if Niki is active and playe is jumping up
	return nullptr;
}

sf::Shape* cLevel::CollisionSunlightBlocks(sf::RectangleShape* _collidingWith, ActiveCharacter _character)
{
	if (_character == SisterNiki) // will only look for collision if niki is active
	{
		for (int i = 0; i < LevelSunlightBlocks.size(); i++)
		{
			if (_collidingWith->getGlobalBounds().findIntersection(LevelSunlightBlocks[i]->getGlobalBounds()))
			{
				return LevelSunlightBlocks[i];
			}
		}
	}
	return nullptr;
}


/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ FLOWER FOUND CHECK ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

bool cLevel::FoundAllFlowersInLevel()
{
	for (int i = 0; i < FlowerFound.size(); i++)
	{
		if (!FlowerFound[i]) // if there is one flower that has not been found, not all flowers hve been found so return false
		{
			return false;
		}
	}
	return true; // all flowers have been found, therefore return true
}