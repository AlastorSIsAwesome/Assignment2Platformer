#pragma once
#include <SFML/Graphics.hpp>
#include <fstream>
#include <iostream>

// do getters and setters later

class cLevel
{
private:
protected:
public:

	// work out level dimentions
	// require:
		// sprite size 
		//	Characters are 32*32
		// level size in tiles or sprites

	sf::Texture WallTexture;

	static const int g_LevelWidth = 15;
	static const int g_LevelHight = 10;

	std::vector<sf::RectangleShape*> LevelTiles; // vecors of pointers to tiles that already exist // no collision
	std::vector<sf::RectangleShape*> LevelWallTiles; // tiles with collision
	// if this doesnt work, try se floatrect vector

	char levelArray[g_LevelWidth][g_LevelHight];



	cLevel(int _levelWidth, int _levelHeight);
	~cLevel();

	void LoadLevel(std::string _filePath);
	void UnloadLevel();


};

