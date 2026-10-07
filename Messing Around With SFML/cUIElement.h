/*******************************
Bachelor of Software Engineering
Media Design School
Auckland
New Zealand
(c) 2026 Media Design School at Strayer
File Name : [cUIElement.h]
Description : [Headder file for cUIElement, is an abstract class that functions as a base for all other UI objects]
Author : [Alastor Spear]
Mail : alastor.spear@mds.ac.nz
*******************************/

#pragma once

#include "SFML/Graphics.hpp"

class cUIElement
{
private:
protected:
	/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ SHAPE RECT MEMBER VARIABLES ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

	sf::Vector2f m_Position;
	sf::Vector2f m_Size;


public:

	/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ CON/DESTRUCTORS ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
	cUIElement();
	~cUIElement();

	cUIElement(sf::Vector2f _position);
	cUIElement(sf::Vector2f _position, sf::Vector2f _size);
	

	/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ GETTERS/SETTERS ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

	inline sf::Vector2f GetPosition()
	{
		return m_Position;
	}

	inline void SetPosition(sf::Vector2f _position)
	{
		m_Position = _position;
	}

	inline sf::Vector2f GetSize()
	{
		return m_Size;
	}

	inline void SetSize(sf::Vector2f _size)
	{
		m_Size = _size;
	}
};

