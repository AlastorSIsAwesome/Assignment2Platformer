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
//
////#include "cPlayer.h" // is throwing a hissy fit if if put this in the ,h file >:(
//
//
//cLevel::cLevel(int _levelWidth, int _levelHeight)
//{
//	for (int i = 0; i < m_LevelHight; i++)
//	{
//		for (int j = 0; j < m_LevelWidth; j++)
//		{
//			// do something here?
//		}
//	}
//	// set the wall's texture
//	m_WallTexture.loadFromFile(m_WallTextureFilePath);
//
//	LoadLevel("Levels/Level1.txt");
//}
//
//
//cLevel::~cLevel()
//{
//	UnloadLevel();
//}
//
//
//void cLevel::LoadLevel(std::string _filePath)
//{
//	// open level file and read from it
//	std::fstream loadFileStream;
//	loadFileStream.open(_filePath, std::ios::in);
//
//	std::string loadFileString;
//	int lineCount = 0;
//
//	// retrive all characters from file and put them in levelArray
//	if (loadFileStream.is_open())
//	{
//		while (std::getline(loadFileStream, loadFileString))
//		{
//			for (int i = 0; i < loadFileString.size(); i++)
//			{
//				levelArray[i][lineCount] = loadFileString[i];
//			}
//			lineCount++;
//		}
//		loadFileStream.close(); // close stream bc we are no longer using it
//	}
//	
//	for (int y = 0; y < m_LevelHight; y++)
//	{
//		for (int x = 0; x < m_LevelWidth; x++)
//		{
//			// check for blocks in the level
//			if (levelArray[x][y] == 'X') // X -> default block
//			{
//				sf::RectangleShape* newBox = new sf::RectangleShape({ m_TileSize, m_TileSize });
//				newBox->setPosition(sf::Vector2f(x * m_TileSize, y * m_TileSize));
//				newBox->setTexture(&m_WallTexture);
//
//				// we may need extra logic for setting up colliders
//
//				LevelWallTiles.push_back(newBox);
//			}
//
//			// check for Platforms
//			if (levelArray[x][y] == 'L') // L -> Platform 
//			{
//				sf::RectangleShape* newBox = new sf::RectangleShape({ m_TileSize, m_TileSize });
//				newBox->setPosition(sf::Vector2f(x * m_TileSize, y * m_TileSize));
//				//newBox->setTexture(&); // Sunlight texture
//				newBox->setFillColor(sf::Color::Magenta);
//
//				LevelPlatformTiles.push_back(newBox);
//			}
//
//
//			// check for obsticals
//			if (levelArray[x][y] == 'V') // V -> obstical
//			{
//				sf::RectangleShape* newBox = new sf::RectangleShape({ m_TileSize, m_TileSize });
//				newBox->setPosition(sf::Vector2f(x * m_TileSize, y * m_TileSize));
//				//newBox->setTexture(&); // obstical texture
//				newBox->setFillColor(sf::Color::Red);
//
//				LevelObsticalTiles.push_back(newBox);
//			}
//
//
//			// check for Sunlight
//			if (levelArray[x][y] == 'S') // S -> Sunlight 
//			{
//				sf::RectangleShape* newBox = new sf::RectangleShape({ m_TileSize, m_TileSize });
//				newBox->setPosition(sf::Vector2f(x * m_TileSize, y * m_TileSize));
//				//newBox->setTexture(&); // Sunlight texture
//				newBox->setFillColor(sf::Color::Yellow);
//
//				LevelSunlightTiles.push_back(newBox);
//			}
//
//			// check for Checkpoints
//			if (levelArray[x][y] == 'C') // C -> check point
//			{
//				sf::RectangleShape* newBox = new sf::RectangleShape({ m_TileSize, m_TileSize });
//				newBox->setPosition(sf::Vector2f(x * m_TileSize, y * m_TileSize));
//				//newBox->setTexture(&); // checkpoint texture
//				newBox->setFillColor(sf::Color::Green);
//
//				LevelCheckPointTiles.push_back(newBox);
//			}
//
//
//			/*
//			player will be arranged in file like this:
//
//			XXXPXXX
//			XXXNXXX
//			= SisterNiki
//
//			or
//
//			XXXPXXX
//			XXXAXXX
//			= SisterAl
//
//			this corresponds with wich character should be active
//			if it is just 'P', then default to SisterNiki
//			*/
//
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
//
//			}
//		}
//	}
//}
//
//
//void cLevel::UnloadLevel()
//{
//	// for the given level. delete everything inside it
//	
//	// delete wall tiles
//	for (int i = 0; i < LevelWallTiles.size(); i++)
//	{
//		delete LevelWallTiles[i];
//		LevelWallTiles[i] = nullptr;
//	}
//
//	// delete Platform tiles
//	for (int i = 0; i < LevelObsticalTiles.size(); i++)
//	{
//		delete LevelPlatformTiles[i];
//		LevelPlatformTiles[i] = nullptr;
//	}
//
//	// delete Obstial Tiles
//	for (int i = 0; i < LevelObsticalTiles.size(); i++)
//	{
//		delete LevelObsticalTiles[i];
//		LevelObsticalTiles[i] = nullptr;
//	}
//
//	// delete Sunlight
//	for (int i = 0; i < LevelSunlightTiles.size(); i++)
//	{
//		delete LevelSunlightTiles[i];
//		LevelSunlightTiles[i] = nullptr;
//	}
//
//	// delete checkpoints
//	for (int i = 0; i < LevelCheckPointTiles.size(); i++)
//	{
//		delete LevelCheckPointTiles[i];
//		LevelCheckPointTiles[i] = nullptr;
//	}
//}
//
///*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ DRAW TILES ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
//
//void cLevel::DrawAllTiles(sf::RenderWindow& _window)
//{
//	DrawWallTiles(_window);
//	DrawPlatformTiles(_window);
//	DrawObsticalTiles(_window);
//	DrawSunlightTiles(_window);
//	DrawCheckPointTiles(_window);
//}
//
//
//void cLevel::DrawWallTiles(sf::RenderWindow& _window)
//{
//	for (int i = 0; i < LevelWallTiles.size(); i++)
//	{
//		_window.draw(*LevelWallTiles[i]);
//	}
//}
//
//void cLevel::DrawPlatformTiles(sf::RenderWindow& _window)
//{
//	for (int i = 0; i < LevelPlatformTiles.size(); i++)
//	{
//		_window.draw(*LevelPlatformTiles[i]);
//	}
//}
//
//
//void cLevel::DrawObsticalTiles(sf::RenderWindow& _window)
//{
//	for (int i = 0; i < LevelObsticalTiles.size(); i++)
//	{
//		_window.draw(*LevelObsticalTiles[i]);
//	}
//}
//
//void cLevel::DrawSunlightTiles(sf::RenderWindow& _window)
//{
//	for (int i = 0; i < LevelSunlightTiles.size(); i++)
//	{
//		_window.draw(*LevelSunlightTiles[i]);
//	}
//}
//
//void cLevel::DrawCheckPointTiles(sf::RenderWindow& _window)
//{
//	for (int i = 0; i < LevelCheckPointTiles.size(); i++)
//	{
//		_window.draw(*LevelCheckPointTiles[i]);
//	}
//}
//
///*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ COLLISIONS ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
//
//sf::Shape* cLevel::CollisionWallTiles(sf::RectangleShape* _collidingWith)
//{
//	for (int i = 0; i < LevelWallTiles.size(); i++)
//	{
//		if (_collidingWith->getGlobalBounds().findIntersection(LevelWallTiles[i]->getGlobalBounds()))
//		{
//			return LevelWallTiles[i];
//		}
//	}
//	// has passed all checks and is not colliding with anything, therefore return nullptr
//	return nullptr;
//}
//
//sf::Shape* cLevel::CollisionPlatformTiles(sf::RectangleShape* _collidingWith, ActiveCharacter _character, float _yVelocity)
//{
//	if (_character == SisterAl) // regular collisions for sister al
//	{
//		for (int i = 0; i < LevelPlatformTiles.size(); i++)
//		{
//			if (_collidingWith->getGlobalBounds().findIntersection(LevelPlatformTiles[i]->getGlobalBounds()))
//			{
//				return LevelPlatformTiles[i];
//			}
//		}
//	}
//	else if (_yVelocity >= 0)//  if y velocity is 0 or greater, the player isn't jumping up
//	{
//		for (int i = 0; i < LevelPlatformTiles.size(); i++)
//		{
//			if (_collidingWith->getGlobalBounds().findIntersection(LevelPlatformTiles[i]->getGlobalBounds()))
//			{
//				return LevelPlatformTiles[i];
//			}
//		}
//	}
//
//	// will let the player phase through if Niki is active and playe is jumping up
//	return nullptr;
//}
//
//sf::Shape* cLevel::CollisionObsticalTiles(sf::RectangleShape* _collidingWith)
//{
//	for (int i = 0; i < LevelObsticalTiles.size(); i++)
//	{
//		if (_collidingWith->getGlobalBounds().findIntersection(LevelObsticalTiles[i]->getGlobalBounds()))
//		{
//			return LevelObsticalTiles[i];
//		}
//	}
//	// has passed all checks and is not colliding with anything, therefore return nullptr
//	return nullptr;
//}
//
//sf::Shape* cLevel::CollisionSunlightTiles(sf::RectangleShape* _collidingWith, ActiveCharacter _character)
//{
//	if (_character == SisterNiki) // will only look for collision if niki is active
//	{
//		for (int i = 0; i < LevelSunlightTiles.size(); i++)
//		{
//			if (_collidingWith->getGlobalBounds().findIntersection(LevelSunlightTiles[i]->getGlobalBounds()))
//			{
//				return LevelSunlightTiles[i];
//			}
//		}
//	}
//
//	return nullptr;
//}
//
//sf::Shape* cLevel::CollisionCheckPointTiles(sf::RectangleShape* _collidingWith)
//{
//	for (int i = 0; i < LevelCheckPointTiles.size(); i++)
//	{
//		if (_collidingWith->getGlobalBounds().findIntersection(LevelCheckPointTiles[i]->getGlobalBounds()))
//		{
//			return LevelCheckPointTiles[i];
//		}
//	}
//	// has passed all checks and is not colliding with anything, therefore return nullptr
//	return nullptr;
//}
//
//

/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ CON/DESTRUCTORS ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

cLevel::cLevel(int _levelWidth, int _levelHeight)
{
	m_ptrWallTexture = new sf::Texture();
	m_ptrWallTexture->loadFromFile(m_WallTextureFilePath);
}

cLevel::~cLevel()
{
	delete m_ptrWallTexture;
	m_ptrWallTexture = nullptr;
}

/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ LOAD/UNLOAD LEVEL ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

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
			// uses cBlock constructor to create the new block
			cBlock* newBlock = new cBlock('X', sf::Vector2f(m_TileSize * x, m_TileSize * y), sf::Vector2f(m_TileSize, m_TileSize), m_ptrWallTexture);
			LevelDefaultBlocks.push_back(newBlock); // pushes block onto pile
		}

		// check for Platforms
		if (levelArray[x][y] == 'L') // L -> Platform 
		{
			sf::RectangleShape* newBox = new sf::RectangleShape({ m_TileSize, m_TileSize });
			newBox->setPosition(sf::Vector2f(x * m_TileSize, y * m_TileSize));
			//newBox->setTexture(&); // Sunlight texture
			newBox->setFillColor(sf::Color::Magenta);

			LevelPlatformTiles.push_back(newBox);
		}


		// check for obsticals
		if (levelArray[x][y] == 'V') // V -> obstical
		{
			sf::RectangleShape* newBox = new sf::RectangleShape({ m_TileSize, m_TileSize });
			newBox->setPosition(sf::Vector2f(x * m_TileSize, y * m_TileSize));
			//newBox->setTexture(&); // obstical texture
			newBox->setFillColor(sf::Color::Red);

			LevelObsticalTiles.push_back(newBox);
		}


		// check for Sunlight
		if (levelArray[x][y] == 'S') // S -> Sunlight 
		{
			sf::RectangleShape* newBox = new sf::RectangleShape({ m_TileSize, m_TileSize });
			newBox->setPosition(sf::Vector2f(x * m_TileSize, y * m_TileSize));
			//newBox->setTexture(&); // Sunlight texture
			newBox->setFillColor(sf::Color::Yellow);

			LevelSunlightTiles.push_back(newBox);
		}

		// check for Checkpoints
		if (levelArray[x][y] == 'C') // C -> check point
		{
			sf::RectangleShape* newBox = new sf::RectangleShape({ m_TileSize, m_TileSize });
			newBox->setPosition(sf::Vector2f(x * m_TileSize, y * m_TileSize));
			//newBox->setTexture(&); // checkpoint texture
			newBox->setFillColor(sf::Color::Green);

			LevelCheckPointTiles.push_back(newBox);
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

void cLevel::UnloadLevel()
{
}


/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ DRAW BLOCKS ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

void cLevel::DrawAllBlocks(sf::RenderWindow& _window)
{
}

void cLevel::DrawWallBlocks(sf::RenderWindow& _window)
{
}

void cLevel::DrawPlatformBlocks(sf::RenderWindow& _window)
{
}

void cLevel::DrawObsticalBlocks(sf::RenderWindow& _window)
{
}

void cLevel::DrawSunlightBlocks(sf::RenderWindow& _window)
{
}

void cLevel::DrawCheckPointBlocks(sf::RenderWindow& _window)
{
}


/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ COLLISIONS ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/