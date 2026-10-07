/*******************************
Bachelor of Software Engineering
Media Design School
Auckland
New Zealand
(c) 2026 Media Design School at Strayer
File Name : [cEntity.cpp]
Description : [Implimentation of class cEntity, describes many different ways to construct said class]
Author : [Alastor Spear]
Mail : alastor.spear@mds.ac.nz
*******************************/

#include "cEntity.h"

/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ CON/DESTRUCTORS ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

cEntity::cEntity(sf::Vector2f _size, sf::Vector2f _position)
	: m_Size(_size)
{
	// set size
	m_EntityShape.setSize(_size);

	// set position
	m_EntityShape.setPosition(_position);

	// set texture
	sf::Texture Texture;
	Texture.loadFromFile("textures/alastorsphere.png"); // default texture if none was given
	m_EntityShape.setTexture(&Texture);
}

cEntity::cEntity(sf::Vector2f _position)
{
	// set position
	m_EntityShape.setPosition(_position);
}

cEntity::cEntity(sf::Vector2f _position, std::string _textureFilePath)
{
	// set position
	m_EntityShape.setPosition(_position);

	// set texture
	sf::Texture Texture;
	Texture.loadFromFile(_textureFilePath); // default texture if none was given
	m_EntityShape.setTexture(&Texture);
}

cEntity::cEntity(sf::Vector2f _size, sf::Vector2f _position, std::string _textureFilePath)
	: m_Size(_size)
{
	// set size
	m_EntityShape.setSize(_size);

	// set position
	m_EntityShape.setPosition(_position);

	// set texture
	sf::Texture Texture;
	Texture.loadFromFile(_textureFilePath);
	m_EntityShape.setTexture(&Texture);
}

cEntity::cEntity()
{
	// set texture
	sf::Texture Texture;
	Texture.loadFromFile("textures/alastorsphere.png"); // default texture if none was given
	m_EntityShape.setTexture(&Texture);
}

cEntity::~cEntity()
{
	// no pointers, no need to do anything here
}


