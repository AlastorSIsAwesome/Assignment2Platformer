#include "cBlock.h"

cBlock::cBlock()
{
}

cBlock::~cBlock()
{
	delete m_ptrBlockShape;
	m_ptrBlockShape = nullptr;
}

cBlock::cBlock(char _identity, sf::Vector2f _position, sf::Vector2f _size, sf::Texture* _texture)
	: m_IdentityChar(_identity), m_Position(_position), m_Size(_size), m_ptrTexture(_texture)
{
	m_ptrBlockShape = new sf::RectangleShape(m_Size);
	m_ptrBlockShape->setPosition(m_Position);
}

void cBlock::SetPosition(sf::Vector2f _position)
{
	m_Position = _position;
	m_ptrBlockShape->setPosition(m_Position);
}

void cBlock::SetSize(sf::Vector2f _size)
{
	m_Size = _size;
	m_ptrBlockShape->setSize(m_Size);
}

void cBlock::DrawBlock(sf::RenderWindow& _window)
{
	_window.draw(*m_ptrBlockShape);
}

bool cBlock::CollidingWithBlock(sf::RectangleShape* _collidingWith)
{
	if (_collidingWith->getGlobalBounds().findIntersection(m_ptrBlockShape->getGlobalBounds()))
	{
		return true; // if there is a collision, return true
	}
	return false; // otherwise false
}
