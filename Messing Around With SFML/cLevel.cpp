#include "cLevel.h"

cLevel::cLevel(int _levelWidth, int _levelHeight)
{
	for (int i = 0; i < g_LevelWidth; i++)
	{
		for (int j = 0; j < g_LevelHight; j++)
		{

		}
	}

	WallTexture.loadFromFile("textures/alastorsphere.png");

	LoadLevel("Levels/Level1.txt");
}


cLevel::~cLevel()
{

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
	
	for (int y = 0; y < g_LevelHight; y++)
	{
		for (int x = 0; x < g_LevelWidth; x++)
		{
			// check for blocks in the level
			if (levelArray[x][y] == 'X') // X -> default block
			{
				sf::RectangleShape* newBox = new sf::RectangleShape({ 64,64 });
				newBox->setPosition(sf::Vector2f(x * 64, y * 64));
				newBox->setTexture(&WallTexture);

				// we may need extra logic for setting up colliders

				LevelWallTiles.push_back(newBox);
			}

			// check for obsticals
			if (levelArray[x][y] == 'V') // V -> obstical
			{
				sf::RectangleShape* newBox = new sf::RectangleShape({ 64,64 });
				newBox->setPosition(sf::Vector2f(x * 64, y * 64));
				//newBox->setTexture(&WallTexture);
				newBox->setFillColor(sf::Color::Red);

				LevelObsticalTiles.push_back(newBox);
			}
		}
	}
}


void cLevel::UnloadLevel()
{
	// for the given level. delete everything inside it
}



void cLevel::DrawAllTiles(sf::RenderWindow& _window)
{
	DrawWallTiles(_window);
	DrawObsticalTiles(_window);
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


