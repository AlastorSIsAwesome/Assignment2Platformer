#include "cLevel.h"

//#include "cPlayer.h" // is throwing a hissy fit if if put this in the ,h file >:(


cLevel::cLevel(int _levelWidth, int _levelHeight)
{
	for (int i = 0; i < m_LevelHight; i++)
	{
		for (int j = 0; j < m_LevelWidth; j++)
		{

		}
	}
	// set the wall's texture
	m_WallTexture.loadFromFile(m_WallTextureFilePath);

	LoadLevel("Levels/Level1.txt");
}


cLevel::~cLevel()
{
	UnloadLevel();
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
				sf::RectangleShape* newBox = new sf::RectangleShape({ 64,64 });
				newBox->setPosition(sf::Vector2f(x * 64, y * 64));
				newBox->setTexture(&m_WallTexture);

				// we may need extra logic for setting up colliders

				LevelWallTiles.push_back(newBox);
			}

			// check for obsticals
			if (levelArray[x][y] == 'V') // V -> obstical
			{
				sf::RectangleShape* newBox = new sf::RectangleShape({ 64,64 });
				newBox->setPosition(sf::Vector2f(x * 64, y * 64));
				//newBox->setTexture(&); // obstical texture
				newBox->setFillColor(sf::Color::Red);

				LevelObsticalTiles.push_back(newBox);
			}


			// check for Checkpoints
			if (levelArray[x][y] == 'C') // C -> check point
			{
				sf::RectangleShape* newBox = new sf::RectangleShape({ 64,64 });
				newBox->setPosition(sf::Vector2f(x * 64, y * 64));
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
				m_PlayerPosition = sf::Vector2f(x * 64.f, y * 64.f);

				if (levelArray[x][y + 1] == 'A')
				{
					m_ActiveCharacter = SisterAl;
				}
				else
				{
					m_ActiveCharacter = SisterNiki;
				}

			}
		}
	}
}


void cLevel::UnloadLevel()
{
	// for the given level. delete everything inside it
}

/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ DRAW TILES ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

void cLevel::DrawAllTiles(sf::RenderWindow& _window)
{
	DrawWallTiles(_window);
	DrawObsticalTiles(_window);
	DrawCheckPointTiles(_window);
}


void cLevel::DrawWallTiles(sf::RenderWindow& _window)
{
	for (int i = 0; i < LevelWallTiles.size(); i++)
	{
		_window.draw(*LevelWallTiles[i]);
	}
}


void cLevel::DrawObsticalTiles(sf::RenderWindow& _window)
{
	for (int i = 0; i < LevelObsticalTiles.size(); i++)
	{
		_window.draw(*LevelObsticalTiles[i]);
	}
}

void cLevel::DrawCheckPointTiles(sf::RenderWindow& _window)
{
	for (int i = 0; i < LevelCheckPointTiles.size(); i++)
	{
		_window.draw(*LevelCheckPointTiles[i]);
	}
}

/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ COLLISIONS ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

sf::Shape* cLevel::CollisionWallTiles(sf::RectangleShape* _collidingWith)
{
	for (int i = 0; i < LevelWallTiles.size(); i++)
	{
		if (_collidingWith->getGlobalBounds().findIntersection(LevelWallTiles[i]->getGlobalBounds()))
		{
			return LevelWallTiles[i];
		}
	}
	// has passed all checks and is not colliding with anything, therefore return nullptr
	return nullptr;
}

sf::Shape* cLevel::CollisionObsticalTiles(sf::RectangleShape* _collidingWith)
{
	for (int i = 0; i < LevelObsticalTiles.size(); i++)
	{
		if (_collidingWith->getGlobalBounds().findIntersection(LevelObsticalTiles[i]->getGlobalBounds()))
		{
			return LevelObsticalTiles[i];
		}
	}
	// has passed all checks and is not colliding with anything, therefore return nullptr
	return nullptr;
}

sf::Shape* cLevel::CollisionCheckPointTiles(sf::RectangleShape* _collidingWith)
{
	for (int i = 0; i < LevelCheckPointTiles.size(); i++)
	{
		if (_collidingWith->getGlobalBounds().findIntersection(LevelCheckPointTiles[i]->getGlobalBounds()))
		{
			return LevelCheckPointTiles[i];
		}
	}
	// has passed all checks and is not colliding with anything, therefore return nullptr
	return nullptr;
}


