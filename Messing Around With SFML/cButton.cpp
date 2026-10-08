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
	:cUIElement() // calls default constructor for UIElement
{
	//cUIElement(); 
	// set position and size
	m_ButtonShape.setPosition(m_Position);
	m_ButtonShape.setSize(m_Size);

	// set textures
	m_ptrButtonTexture = new sf::Texture();
	m_ptrButtonTexture->loadFromFile(m_TextureFilePath);

	// add texture to button
	m_ButtonShape.setTexture(m_ptrButtonTexture);
}

cButton::~cButton()
{
	delete m_ptrButtonTexture;
	m_ptrButtonTexture = nullptr; // delete pointer and set to null, prevent memory leaks
}

cButton::cButton(sf::Vector2f _position, sf::Vector2f _size, std::string _textureFilePath)
	: cUIElement(_position, _size), /* calls cUIElement's constructor */ m_TextureFilePath(_textureFilePath)
{
	// set position and size
	m_ButtonShape.setPosition(m_Position);
	m_ButtonShape.setSize(m_Size);

	// set textures
	m_ptrButtonTexture = new sf::Texture();
	m_ptrButtonTexture->loadFromFile(m_TextureFilePath);

	// add texture to button
	m_ButtonShape.setTexture(m_ptrButtonTexture);
}

/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ BUTTON FUNCTIONALITY ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

bool cButton::CheckIfPressed(sf::Vector2f _mouseInput)
{
	if (m_ButtonShape.getGlobalBounds().contains(_mouseInput))
	{
		return true; // mouse is within the bounds of the button
	}
	return false;
}

void cButton::DrawButton(sf::RenderWindow& _window)
{
	_window.draw(m_ButtonShape);
}

