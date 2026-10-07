#include "cUIElement.h"

cUIElement::cUIElement()
{
	// default values given
	m_Postiton = sf::Vector2f(64.f, 64.f);
	m_Size = sf::Vector2f(64.f, 64.f);
}

cUIElement::~cUIElement()
{
}

cUIElement::cUIElement(sf::Vector2f _position, sf::Vector2f _size)
	: m_Postiton(_position), m_Size(_size)
{
}
