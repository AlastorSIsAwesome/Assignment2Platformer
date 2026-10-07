/*******************************
Bachelor of Software Engineering
Media Design School
Auckland
New Zealand
(c) 2026 Media Design School at Strayer
File Name : [cText.cpp]
Description : [Implimentation for class cText, uses and manipulates pointers to create and display text objects using SFML]
Author : [Alastor Spear]
Mail : alastor.spear@mds.ac.nz
*******************************/

#include "cText.h"

/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ CON/DESTRUCTORS ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

cText::cText()
{
	cUIElement(); // uses cUIElement's default constructor

	m_FontSize = 24; // default font size
}

cText::~cText()
{
	delete m_ptrText; // delete pointers to prevent memory leak
	m_ptrText = nullptr;
}

cText::cText(sf::Vector2f _position, sf::Font& _font, std::string _text, int _fontSize)
	: cUIElement(_position)/* uses cUIElement's  constructor*/, m_ptrFont(&_font), m_Text(_text), m_FontSize(_fontSize) // uses cUIElement's constructor
{
	m_ptrText = new sf::Text(*m_ptrFont, _text, m_FontSize); // creates text object in heap 
	m_ptrText->setPosition(_position); // sets the position of the text
}


/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ SETTER ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

void cText::SetTextPosition(sf::Vector2f _position)
{
	m_Position = _position; // sets position member variable
	m_ptrText->setPosition(_position); // sets the actual position of the text
}


/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ DRAW TEXT TO WINDOW ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

void cText::DrawText(sf::RenderWindow& _window)
{
	_window.draw(*m_ptrText); // draws text to window
}
