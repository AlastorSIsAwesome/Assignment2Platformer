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


cLevel::cLevel(int _levelWidth, int _levelHeight)
{
	m_ptrBlockTexture = new sf::Texture();
	m_ptrBlockTexture->loadFromFile(m_WallTextureFilePath);
}


cLevel::~cLevel()
{
	UnloadLevel();

	delete m_ptrBlockTexture;
	m_ptrBlockTexture = nullptr;
}


void cLevel::LoadLevel(std::string _filePath)
{
	// open level file and read from it
	std::fstream loadFileStream;
	loadFileStream.open(_filePath, std::ios::in);

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
			}


			// check for Platforms
			if (levelArray[x][y] == 'L') // L -> Platform 
			{
				sf::RectangleShape* newBox = new sf::RectangleShape({ m_TileSize, m_TileSize });
				newBox->setPosition(sf::Vector2f(x * m_TileSize, y * m_TileSize));
				//newBox->setTexture(&); // Sunlight texture
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

/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ DRAW TILES ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

void cLevel::DrawAllBlocks(sf::RenderWindow& _window)
{
	DrawWallBlocks(_window);
	DrawObsticalBlocks(_window);
	DrawCheckPointBlocks(_window);
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



/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ COLLISIONS ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

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



//
//
///*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ CON/DESTRUCTORS ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
//
//cLevel::cLevel(int _levelWidth, int _levelHeight)
//{
//	m_ptrBlockTexture = new sf::Texture();
//	m_ptrBlockTexture->loadFromFile(m_WallTextureFilePath);
//}
//
//cLevel::~cLevel()
//{
//	UnloadLevel();
//
//	delete m_ptrBlockTexture;
//	m_ptrBlockTexture = nullptr;
//}
//
///*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ LOAD/UNLOAD LEVEL ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
//
//void cLevel::LoadLevel(std::string _filePath)
//{
//	std::string loadFileString;
//	int lineCount = 0;
//
//	// open level file and read from it
//	std::fstream loadFileStream;
//	loadFileStream.open(_filePath, std::ios::in);
//
//
//	// retrive all characters from file and put them in levelArray
//	if (loadFileStream.is_open())
//	{
//		std::cout << "file is open" << std::endl;
//		while (std::getline(loadFileStream, loadFileString))
//		{
//			std::cout << "Reading from file" << std::endl;
//			for (int i = 0; i < loadFileString.size(); i++)
//			{
//				std::cout << "setting from file" << std::endl;
//				levelArray[i][lineCount] = loadFileString[i];
//			}
//			lineCount++;
//		}
//
//		loadFileStream.close(); // close stream bc we are no longer using it
//	}
//	else
//	{
//		std::cout << "file is not open" << std::endl;
//	}
//
//	std::cout << "Loading a level" << std::endl;
//
//	for (int y = 0; y < m_LevelHight; y++) // for every y tile
//	{
//		std::cout << "For height" << std::endl;
//		for (int x = 0; x < m_LevelWidth; x++) // for every x tile
//		{
//			std::cout << "for width" << std::endl;
//			// check for blocks in the level
//			if (levelArray[x][y] == 'X') // X -> default block
//			{
//				std::cout << "default block" << std::endl;
//				// uses cBlock constructor to create the new block
//				cBlock* newBlock = new cBlock('X', sf::Vector2f(m_TileSize * x, m_TileSize * y), sf::Vector2f(m_TileSize, m_TileSize), m_ptrBlockTexture);
//				LevelDefaultBlocks.push_back(newBlock); // pushes block onto vector
//			}
//
//			// check for obsticals
//			if (levelArray[x][y] == 'V') // V -> obstical
//			{
//				std::cout << "obstical" << std::endl;
//				// uses cBlock constructor to create the new Obstical
//				cBlock* newBlock = new cBlock('V', sf::Vector2f(m_TileSize * x, m_TileSize * y), sf::Vector2f(m_TileSize, m_TileSize), m_ptrBlockTexture); // will have the block texture
//				newBlock->GetBlockShape()->setFillColor(sf::Color::Red); // sets the obsical colour to be red
//				LevelObsticalBlocks.push_back(newBlock); // pushes obstical onto vector
//			}
//
//			// check for Checkpoints
//			if (levelArray[x][y] == 'C') // C -> check point
//			{
//				std::cout << "checkpoint" << std::endl;
//				// uses cBlock constructor to create the new Checkpoint
//				cBlock* newBlock = new cBlock('C', sf::Vector2f(m_TileSize * x, m_TileSize * y), sf::Vector2f(m_TileSize, m_TileSize), m_ptrBlockTexture); // will have the block texture
//				newBlock->GetBlockShape()->setFillColor(sf::Color::Green); // sets the checkpoint colour to be green
//				LevelCheckPointBlocks.push_back(newBlock); // pushes checkpoint onto vector
//			}
//
//			// check for Platforms
//			if (levelArray[x][y] == 'L') // L -> Platform 
//			{
//				std::cout << "platform" << std::endl;
//				// uses cSelectiveBlock constructor to create the new block
//				// is looking for SisterAl, as SisterNiki can phase through the block if her y velocity is negative
//				cSelectiveBlock* newBlock = new cSelectiveBlock('L', sf::Vector2f(m_TileSize * x, m_TileSize * y), sf::Vector2f(m_TileSize, m_TileSize), m_ptrBlockTexture, SisterAl);
//				//newBlock->GetBlockShpae()->setFillColor(sf::Color::Magenta); // sets the platform colour to be magenta
//				LevelPlatformBlocks.push_back(newBlock); // pushes block onto vector
//			}
//
//			// check for Sunlight
//			if (levelArray[x][y] == 'S') // S -> Sunlight 
//			{
//				std::cout << "sunlight" << std::endl;
//				// uses cSelectiveBlock constructor to create the new block
//				// is looking for SisterNiki, as SisterAl can phase through sunlight but Niki can't
//				cSelectiveBlock* newBlock = new cSelectiveBlock('S', sf::Vector2f(m_TileSize * x, m_TileSize * y), sf::Vector2f(m_TileSize, m_TileSize), m_ptrBlockTexture, SisterNiki);
//				//newBlock->GetBlockShpae()->setFillColor(sf::Color::Yellow); // sets the sunlight colour to be yellow
//				LevelSunlightBlocks.push_back(newBlock); // pushes block onto vector
//			}
//
//			// check for the player
//			if (levelArray[x][y] == 'P') // P -> Player position
//			{
//				m_PlayerPosition = sf::Vector2f(x * m_TileSize, y * m_TileSize);
//
//				if (levelArray[x][y + 1] == 'A')
//				{
//					m_StartingCharacter = SisterAl;
//				}
//				else
//				{
//					m_StartingCharacter = SisterNiki;
//				}
//			}
//		}
//	}
//}
//
//void cLevel::UnloadLevel()
//{
//}
//
//
///*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ DRAW BLOCKS ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
//
//void cLevel::DrawAllBlocks(sf::RenderWindow& _window)
//{
//	// go through each function and draw all blocks
//	DrawWallBlocks(_window);
//	DrawObsticalBlocks(_window);
//	DrawCheckPointBlocks(_window);
//	DrawPlatformBlocks(_window);
//	DrawSunlightBlocks(_window);
//}
//
//void cLevel::DrawWallBlocks(sf::RenderWindow& _window)
//{
//	for (int i = 0; i < LevelDefaultBlocks.size(); i++) // for every block
//	{
//		LevelDefaultBlocks[i]->DrawBlock(_window); // draw it to the render window
//	}
//}
//
//void cLevel::DrawObsticalBlocks(sf::RenderWindow& _window)
//{
//	for (int i = 0; i < LevelObsticalBlocks.size(); i++) // for every obstical
//	{
//		LevelObsticalBlocks[i]->DrawBlock(_window); // draws obstical to render window
//	}
//}
//
//void cLevel::DrawCheckPointBlocks(sf::RenderWindow& _window)
//{
//	for (int i = 0; i < LevelCheckPointBlocks.size(); i++) // for every checkpoint
//	{
//		LevelCheckPointBlocks[i]->DrawBlock(_window); // draws checkpoint to render window
//	}
//}
//
//void cLevel::DrawPlatformBlocks(sf::RenderWindow& _window)
//{
//	for (int i = 0; i < LevelPlatformBlocks.size(); i++) // for every platform
//	{
//		LevelPlatformBlocks[i]->DrawBlock(_window); // draw it to the render window
//	}
//}
//
//void cLevel::DrawSunlightBlocks(sf::RenderWindow& _window)
//{
//	for (int i = 0; i < LevelSunlightBlocks.size(); i++) // for every sunlight block
//	{
//		LevelSunlightBlocks[i]->DrawBlock(_window); // draw it to the render window
//	}
//}
//
//
///*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ COLLISIONS ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
//
//sf::Shape* cLevel::CollisionWallBlocks(sf::RectangleShape* _collidingWith)
//{
//	for (int i = 0; i < LevelDefaultBlocks.size(); i++)// for every object in vector, check if there is a collision
//	{
//		if (LevelDefaultBlocks[i]->GetBlockShape()->getGlobalBounds().findIntersection(_collidingWith->getGlobalBounds())) // if there is a collision
//		{
//			return LevelDefaultBlocks[i]->GetBlockShape(); // return the shape that it collided with
//		}
//	}
//	return nullptr; // there was no collision found
//}
//
//sf::Shape* cLevel::CollisionObsticalBlocks(sf::RectangleShape* _collidingWith)
//{
//	for (int i = 0; i < LevelObsticalBlocks.size(); i++)// for every obstical in vector, check if there is a collision
//	{
//		if (LevelObsticalBlocks[i]->m_ptrBlockShape->getGlobalBounds().findIntersection(_collidingWith->getGlobalBounds())) // if there is a collision
//		{
//			return LevelObsticalBlocks[i]->GetBlockShape(); // return the shape of the obstical that it collided with
//		}
//	}
//	return nullptr; // there was no collision found
//}
//
//sf::Shape* cLevel::CollisionCheckPointBlocks(sf::RectangleShape* _collidingWith)
//{
//	for (int i = 0; i < LevelCheckPointBlocks.size(); i++)// for every checkpoint in vector, check if there is a collision
//	{
//		if (LevelCheckPointBlocks[i]->m_ptrBlockShape->getGlobalBounds().findIntersection(_collidingWith->getGlobalBounds())) // if there is a collision
//		{
//			return LevelCheckPointBlocks[i]->GetBlockShape(); // return the shape of the checkpoint that it collided with
//		}
//	}
//	return nullptr; // there was no collision found
//}
//
//sf::Shape* cLevel::CollisionPlatformBlocks(sf::RectangleShape* _collidingWith, ActiveCharacter _character, float _yVelocity)
//{
//	// only do the collision check if Sister Al is active, or Sister Niki is active and is not jumping up
//	if (_character == SisterAl || (_character == SisterNiki && _yVelocity >= 0))
//	{
//		for (int i = 0; i < LevelPlatformBlocks.size(); i++)// for every Platform in vector, check if there is a collision
//		{
//			if (LevelPlatformBlocks[i]->CollidingWithSelectiveBlock(_collidingWith, _character)) // if there is a collision
//			{
//				return LevelPlatformBlocks[i]->GetBlockShape(); // return the shape of the platform that it collided with
//			}
//		}
//	}
//	return nullptr; // no collision was found
//}
//
//sf::Shape* cLevel::CollisionSunlightBlocks(sf::RectangleShape* _collidingWith, ActiveCharacter _character)
//{
//	// uses Selective collision, if Sister Al is active, the collision will return as false, otherwise it will check to see if SisterNiki is colliding with anything
//	for (int i = 0; i < LevelSunlightBlocks.size(); i++)// for every sunlight block in vector, check if there is a collision
//	{
//		if (LevelSunlightBlocks[i]->CollidingWithSelectiveBlock(_collidingWith, _character)) // if there is a collision
//		{
//			return LevelSunlightBlocks[i]->GetBlockShape(); // return the shape of the sunlight block that it collided with
//		}
//	}
//	return nullptr; // there was no collision found
//}
//
//

