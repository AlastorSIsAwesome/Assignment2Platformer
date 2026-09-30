#pragma once
#include <SFML/Graphics.hpp>

class cEntity
{
private:
protected:
	sf::RectangleShape m_EntityShape;
	sf::Vector2f m_Size;

	sf::Texture m_Texture; // needed?

public:

	cEntity(sf::Vector2f _size);
	cEntity(sf::Vector2f _size, std::string _textureFilePath);


	cEntity();
	~cEntity();


	// why would a setter for charactershape be nessesary??

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