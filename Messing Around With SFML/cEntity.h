/*******************************
Bachelor of Software Engineering
Media Design School
Auckland
New Zealand
(c) 2026 Media Design School at Strayer
File Name : [cEntity.h]
Description : [Headder file for class cEntity, has many construtors for different implimentations]
Author : [Alastor Spear]
Mail : alastor.spear@mds.ac.nz
*******************************/

#pragma once

#include <SFML/Graphics.hpp>

class cEntity
{
private:
protected:
	/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ RECTANGLE SHAPE MEMBER VARIABLES ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
	
	sf::RectangleShape m_EntityShape;
	sf::Vector2f m_Size;

	sf::Texture m_EntityTexure;


public:
	/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ CON/DESTRUCTORS ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
	
	cEntity(sf::Vector2f _size, sf::Vector2f _position);
	cEntity(sf::Vector2f _position);
	cEntity(sf::Vector2f _position, std::string _textureFilePath);
	cEntity(sf::Vector2f _size, sf::Vector2f _position, std::string _textureFilePath);


	cEntity();
	~cEntity();

	// why would a setter for charactershape be nessesary??
	/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ GETTERS/SETTERS ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

	inline sf::RectangleShape* GetShape()
	{
		return &m_EntityShape;
	}

	inline void SetSize(sf::Vector2f &_size)
	{
		m_Size = _size;
	}

	inline sf::Vector2f* GetSize()
	{
		return &m_Size;
	}
};