#include "cEntity.h"

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
	sf::Texture Texture;
	Texture.loadFromFile("textures/alastorsphere.png"); // default texture if none was given
	m_EntityShape.setTexture(&Texture);
}

cEntity::~cEntity()
{
}


