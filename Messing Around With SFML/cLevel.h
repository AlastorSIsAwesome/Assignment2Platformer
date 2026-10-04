#pragma once
#include <SFML/Graphics.hpp>
#include <fstream>
#include <iostream>

#include "cPlayer.h"



// do getters and setters later

class cLevel
{
private:
protected:
	// maximum level dimentions
	static const int m_LevelWidth = 20;
	static const int m_LevelHight = 15;

	char levelArray[m_LevelWidth][m_LevelHight];

	sf::Vector2f m_PlayerPosition;
	ActiveCharacter m_ActiveCharacter;


	std::string m_WallTextureFilePath = "textures/alastorsphere.png";
	sf::Texture m_WallTexture;

public:

	// work out level dimentions
	// require:
		// sprite size 
		//	Characters are 32*32
		// level size in tiles or sprites

	/*
		LEVEL DIMENTIONS:
		
		Tiles: 64*64

		Player: 64*128

		LEVEL IS MESURED IN TILES

	*/

	



	std::vector<sf::RectangleShape*> LevelTiles; // vecors of pointers to tiles that already exist // no collision
	std::vector<sf::RectangleShape*> LevelWallTiles; // tiles with collision
	std::vector<sf::RectangleShape*> LevelObsticalTiles; // tiles with collision and are obsticals
	std::vector<sf::RectangleShape*> LevelCheckPointTiles; // tiles that are checkpoints // no collision
	// if this doesnt work, try se floatrect vector






	cLevel(int _levelWidth, int _levelHeight);
	~cLevel();

	void LoadLevel(std::string _filePath);
	void UnloadLevel();


	void DrawAllTiles(sf::RenderWindow& _window);


	void DrawWallTiles(sf::RenderWindow &_window);
	void DrawObsticalTiles(sf::RenderWindow& _window);
	void DrawCheckPointTiles(sf::RenderWindow& _window);

	/// <summary>
	/// Checks every object of this type if there is a collision
	/// if there is no collision, will return a nullptr
	/// </summary>
	/// <param name="_collidingWith"> the object being collided with </param>
	/// <returns> returns pointer of the object that was collided with </returns>
	sf::Shape* CollisionWallTiles(sf::RectangleShape* _collidingWith);

	sf::Shape* CollisionObsticalTiles(sf::RectangleShape* _collidingWith);

	sf::Shape* CollisionCheckPointTiles(sf::RectangleShape* _collidingWith);



	inline sf::Vector2f GetPlayerPosition()
	{
		return m_PlayerPosition;
	}

	inline ActiveCharacter GetActiveCharacter()
	{
		return m_ActiveCharacter;
	}

};

