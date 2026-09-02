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
	std::fstream loadFileStream;
	loadFileStream.open(_filePath, std::ios::in);

	std::string loadFileString;
	int lineCount = 0;

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
		loadFileStream.close();
	}
	
	for (int y = 0; y < g_LevelHight; y++)
	{
		for (int x = 0; x < g_LevelWidth; x++)
		{
			if (levelArray[x][y] == 'X')
			{
				sf::RectangleShape* newBox = new sf::RectangleShape({ 64,64 });
				newBox->setPosition(sf::Vector2f(x * 64, y * 64));
				newBox->setTexture(&WallTexture);

				// we may need extra logic for setting up colliders

				LevelWallTiles.push_back(newBox);
			}
		}
	}
}


void cLevel::UnloadLevel()
{

}
