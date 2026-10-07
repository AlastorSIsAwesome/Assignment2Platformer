/*******************************
Bachelor of Software Engineering
Media Design School
Auckland
New Zealand
(c) 2026 Media Design School at Strayer
File Name : [cBlock.cpp]
Description : [Implimentation for class cBlock, uses SFML to draw block to console and check for collisions]
Author : [Alastor Spear]
Mail : alastor.spear@mds.ac.nz
*******************************/

#include "cBlock.h"

/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ CON/DESTRUCTORS ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
cBlock::cBlock() 
{
}

cBlock::~cBlock()
{
	delete m_ptrBlockShape; // prevent memory leak
	m_ptrBlockShape = nullptr;
	// m_ptrTexture will be destroyed before it turns into a wild pointer so no need to deal with it here
}

cBlock::cBlock(char _identity, sf::Vector2f _position, sf::Vector2f _size, sf::Texture* _texture)
	: m_IdentityChar(_identity), m_Position(_position), m_Size(_size), m_ptrTexture(_texture) // sets the member cariables
{
	m_ptrBlockShape = new sf::RectangleShape(m_Size); // create a new Rectangle shape
	m_ptrBlockShape->setPosition(m_Position); // adjust the block's position
}

sf::RectangleShape* cBlock::GetBlockShape()
{
	return m_ptrBlockShape;
}


/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ SETTERS ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

void cBlock::SetPosition(sf::Vector2f _position)
{
	m_Position = _position;
	m_ptrBlockShape->setPosition(m_Position); // update position at same time as updating it as a member variable
}

void cBlock::SetSize(sf::Vector2f _size)
{
	m_Size = _size;
	m_ptrBlockShape->setSize(m_Size);
}


/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ BLOCK FUNCTIONALITY ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

void cBlock::DrawBlock(sf::RenderWindow& _window)
{
	_window.draw(*m_ptrBlockShape);
}

//bool cBlock::CollidingWithBlock(sf::RectangleShape* _collidingWith)
//{
//	if (m_ptrBlockShape->getGlobalBounds().findIntersection(_collidingWith->getGlobalBounds()))
//	{
//		return true; // if there is a collision, return true
//	}
//	return false; // otherwise false
//}

//_collidingWith->getGlobalBounds().findIntersection(m_ptrBlockShape->getGlobalBounds())