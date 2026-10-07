#include "cButton.h"

cButton::cButton()
{
	cUIElement(); // calls default constructor for UIElement
}

cButton::~cButton()
{
}

cButton::cButton(sf::Vector2f _position, sf::Vector2f _size)
	: cUIElement(_position, _size) // calls cUIElement's constructor
{
}
