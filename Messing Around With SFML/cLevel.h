/*******************************
Bachelor of Software Engineering
Media Design School
Auckland
New Zealand
(c) 2026 Media Design School at Strayer
File Name : [cLevel.h]
Description : [Headder file for class cLevel, outlines how the level keeps track of what is inside it]
Author : [Alastor Spear]
Mail : alastor.spear@mds.ac.nz
*******************************/

#pragma once

#include <SFML/Graphics.hpp>
#include <fstream>
#include <iostream>

#include "CustomLibrary.h"
#include "cSelectiveBlock.h"

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

class cLevel
{
private:
protected:
	/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ LEVEL MEMBER VARIABLES ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
	// maximum level dimentions
	static const int m_LevelWidth = 30;
	static const int m_LevelHight = 15;

	const float m_TileSize = 64.f;

	char levelArray[m_LevelWidth][m_LevelHight];

	sf::Vector2f m_PlayerPosition = sf::Vector2f(0.0f, 0.0f);
	ActiveCharacter m_StartingCharacter = SisterNiki;

	/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ TEXTURE MEMBER VARIABLES ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

	std::string m_WallTextureFilePath = "textures/alastorsphere.png";
	sf::Texture* m_ptrBlockTexture = nullptr;

public:


	/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ BLOCKS ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
	
	std::vector<sf::RectangleShape*> LevelDefaultBlocks;
	std::vector<sf::RectangleShape*> LevelObsticalBlocks;
	std::vector<sf::RectangleShape*> LevelCheckPointBlocks;


	/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ SELECTIVE BLOCKS ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

	std::vector<sf::RectangleShape*> LevelPlatformBlocks;
	std::vector<sf::RectangleShape*> LevelSunlightBlocks;


	/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ CON/DESTRUCTORS ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

	cLevel(int _levelWidth, int _levelHeight); // this constructor is not needed
	~cLevel();


	/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ LOAD/UNLOAD LEVEL ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

	void LoadLevel(std::string _filePath);
	void UnloadLevel();


	/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ DRAW BLOCKS ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

	void DrawAllBlocks(sf::RenderWindow& _window);

	void DrawWallBlocks(sf::RenderWindow &_window);
	void DrawObsticalBlocks(sf::RenderWindow& _window);
	void DrawCheckPointBlocks(sf::RenderWindow& _window);
	void DrawPlatformBlocks(sf::RenderWindow& _window);
	void DrawSunlightBlocks(sf::RenderWindow& _window);



	/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ COLLISIONS ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

	/// <summary>
	/// Checks every object of this type if there is a collision
	/// if there is no collision, will return a nullptr
	/// </summary>
	/// <param name="_collidingWith"> the object being collided with </param>
	/// <returns> returns pointer of the object that was collided with </returns>
	sf::Shape* CollisionWallBlocks(sf::RectangleShape* _collidingWith);

	sf::Shape* CollisionObsticalBlocks(sf::RectangleShape* _collidingWith);

	sf::Shape* CollisionCheckPointBlocks(sf::RectangleShape* _collidingWith);

	sf::Shape* CollisionPlatformBlocks(sf::RectangleShape* _collidingWith, ActiveCharacter _character, float _yVelocity);

	// make sure to only do this collision when niki is the active one
	sf::Shape* CollisionSunlightBlocks(sf::RectangleShape* _collidingWith, ActiveCharacter _character);




	/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ GETTERS ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

	inline sf::Vector2f GetPlayerPosition()
	{
		return m_PlayerPosition;
	}

	inline ActiveCharacter GetActiveCharacter() // NEEDED?
	{
		return m_StartingCharacter;
	}

};

