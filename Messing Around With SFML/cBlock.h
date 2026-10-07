/*******************************
Bachelor of Software Engineering
Media Design School
Auckland
New Zealand
(c) 2026 Media Design School at Strayer
File Name : [cBlock.h]
Description : [Headder file for class cBlock, outlines how cBlock]
Author : [Alastor Spear]
Mail : alastor.spear@mds.ac.nz
*******************************/

#pragma once

#include "SFML/Graphics.hpp"

class cBlock
{
private:
protected:
	/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ IDENTITY MEMBER ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
	char m_IdentityChar = 'X'; //default block identity


	/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ RECTANGLE SHAPE MEMBERS ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
	sf::Vector2f m_Position;
	sf::Vector2f m_Size;


	/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ POINTER MEMBERS ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
	sf::Texture* m_ptrTexture = nullptr;
	sf::RectangleShape* m_ptrBlockShape = nullptr;

public:

	/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ CON/DESTRUCTORS ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
	cBlock();
	~cBlock();

	cBlock(char _identity, sf::Vector2f _position, sf::Vector2f _size, sf::Texture* _texture);

	/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ GETTERS/SETTERS ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
	inline sf::RectangleShape* GetBlockShpae()
	{
		return m_ptrBlockShape;
	}
	// BlockShape shouldn't need a setter


	inline char GetBlockIdentity()
	{
		return m_IdentityChar;
	}


	inline sf::Vector2f GetPosition()
	{
		return m_Position;
	}

	void SetPosition(sf::Vector2f _position); // updates the position of the RectangleShape object


	inline sf::Vector2f GetSize()
	{
		return m_Size;
	}

	void SetSize(sf::Vector2f _size); // updates the size of the RectangleShpae object



	/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ BLOCK FUNCTIONALITY ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

	void DrawBlock(sf::RenderWindow& _window);

	bool CollidingWithBlock(sf::RectangleShape* _collidingWith);
};

