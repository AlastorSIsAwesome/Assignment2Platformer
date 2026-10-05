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
	static const int m_LevelWidth = 30;
	static const int m_LevelHight = 15;

	const float m_TileSize = 64.f;

	char levelArray[m_LevelWidth][m_LevelHight];

	sf::Vector2f m_PlayerPosition;
	ActiveCharacter m_StartingCharacter;


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


	/*
	
	LEVEL LOADING KEY:

	O -> Nothing
	X -> Default block
	V -> Obstical // both Sister Al and Niki can't go through these

	S -> Sunlight // only sister al can pass through, niki is vampire
	L -> Platform // sister niki can jump through these. for al, this is a regular wall

	C -> Checkpoint
	 // Load Zone???



	P
	A
	
	or

	P
	N

	is player
	
	
	*/

	/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ TILE VECTORS ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
	/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ COLLISIONS ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
	
	std::vector<sf::RectangleShape*> LevelWallTiles; // tiles with collision
	std::vector<sf::RectangleShape*> LevelPlatformTiles; // with collison, fully blocked off for al, niki can phase through the bottom
	std::vector<sf::RectangleShape*> LevelObsticalTiles; // tiles with collision and are obsticals
	std::vector<sf::RectangleShape*> LevelSunlightTiles; // with collison, but only for sister niki 




	/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~  NO COLLISIONS ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
	
	std::vector<sf::RectangleShape*> LevelCheckPointTiles; // tiles that are checkpoints // no collision
	std::vector<sf::RectangleShape*> LevelTiles; // vecors of pointers to tiles that already exist // no collision





	// if this doesnt work, try se floatrect vector



		/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ CON/DE STRUCTORS ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/


	cLevel(int _levelWidth, int _levelHeight);
	~cLevel();

	/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ LOAD/UNLOAD LEVEL ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

	void LoadLevel(std::string _filePath);
	void UnloadLevel();

	/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ DRAW TILES ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
	void DrawAllTiles(sf::RenderWindow& _window);


	void DrawWallTiles(sf::RenderWindow &_window);
	void DrawPlatformTiles(sf::RenderWindow& _window);
	void DrawObsticalTiles(sf::RenderWindow& _window);
	void DrawSunlightTiles(sf::RenderWindow& _window);
	void DrawCheckPointTiles(sf::RenderWindow& _window);


		/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ COLLISIONS ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

	/// <summary>
	/// Checks every object of this type if there is a collision
	/// if there is no collision, will return a nullptr
	/// </summary>
	/// <param name="_collidingWith"> the object being collided with </param>
	/// <returns> returns pointer of the object that was collided with </returns>
	sf::Shape* CollisionWallTiles(sf::RectangleShape* _collidingWith);

	sf::Shape* CollisionPlatformTiles(sf::RectangleShape* _collidingWith, ActiveCharacter _character, float _yVelocity);

	sf::Shape* CollisionObsticalTiles(sf::RectangleShape* _collidingWith);

	// make sure to only do this collision when niki is the active one
	sf::Shape* CollisionSunlightTiles(sf::RectangleShape* _collidingWith, ActiveCharacter _character);

	sf::Shape* CollisionCheckPointTiles(sf::RectangleShape* _collidingWith);




	inline sf::Vector2f GetPlayerPosition()
	{
		return m_PlayerPosition;
	}

	inline ActiveCharacter GetActiveCharacter() // NEEDED?
	{
		return m_StartingCharacter;
	}

};

