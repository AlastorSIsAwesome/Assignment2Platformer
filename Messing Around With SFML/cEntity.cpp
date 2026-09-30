#include "cEntity.h"

cEntity::cEntity(sf::Vector2f _size)
	: m_Size(_size)
{
	m_Texture.loadFromFile("textures/alastorsphere.png"); // default texture if none was given
}

cEntity::cEntity(sf::Vector2f _size, std::string _textureFilePath)
	: m_Size(_size)
{
	m_Texture.loadFromFile(_textureFilePath);
	m_EntityShape.setTexture(&m_Texture);
}

cEntity::cEntity()
{

}

cEntity::~cEntity()
{
}



