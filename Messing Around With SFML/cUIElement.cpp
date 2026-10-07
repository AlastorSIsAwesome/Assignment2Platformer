/*******************************
Bachelor of Software Engineering
Media Design School
Auckland
New Zealand
(c) 2026 Media Design School at Strayer
File Name : [cUIElement.cpp]
Description : [Implimentation for cUIElement, has several different constructors for different types of UIElements]
Author : [Alastor Spear]
Mail : alastor.spear@mds.ac.nz
*******************************/

#include "cUIElement.h"


/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ CON/DESTRUCTORS ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

cUIElement::cUIElement()
{
	// default values given
	m_Position = sf::Vector2f(1.f, 1.f);
	m_Size = sf::Vector2f(1.f, 1.f);
}

cUIElement::cUIElement(sf::Vector2f _position)
	: m_Position(_position)
{
	m_Size = sf::Vector2f(1.f, 1.f);
	// this is the constructor used for text, size refers to scale in this instance
}

cUIElement::cUIElement(sf::Vector2f _position, sf::Vector2f _size)
	: m_Position(_position), m_Size(_size)
{
}

cUIElement::~cUIElement()
{
}