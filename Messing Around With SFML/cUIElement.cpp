#include "cUIElement.h"

cUIElement::cUIElement()
{
	// default values given
	m_Position = sf::Vector2f(1.f, 1.f);
	m_Size = sf::Vector2f(1.f, 1.f);
}

cUIElement::~cUIElement()
{
}

cUIElement::cUIElement(sf::Vector2f _position)
	: m_Position(_position)
{
	m_Size = sf::Vector2f(1.f, 1.f);
}

cUIElement::cUIElement(sf::Vector2f _position, sf::Vector2f _size)
	: m_Position(_position), m_Size(_size)
{
}
