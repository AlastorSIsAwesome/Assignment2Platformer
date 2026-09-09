#include "cEntity.h"

cEntity::cEntity(sf::Vector2f _size)
	: m_Size(_size)
{
	m_Texture.loadFromFile("textures/alastorsphere.png");
}

cEntity::cEntity(sf::Vector2f _size, std::string _textureFilePath)
	: m_Size(_size)
{
	m_Texture.loadFromFile("textures/alastorsphere.png");
}

cEntity::cEntity()
{

}

cEntity::~cEntity()
{
}



