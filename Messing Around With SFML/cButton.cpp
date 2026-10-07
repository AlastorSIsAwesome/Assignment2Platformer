/*******************************
Bachelor of Software Engineering
Media Design School
Auckland
New Zealand
(c) 2026 Media Design School at Strayer
File Name : [cButton.cpp]
Description : [Implimentation for class cButton, outlines different constructors and how they are implimented]
Author : [Alastor Spear]
Mail : alastor.spear@mds.ac.nz
*******************************/

#include "cButton.h"

/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ CON/DESTRUCTORS ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

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
