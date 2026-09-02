#pragma once
#include <SFML/Graphics.hpp>

class cCharacter
{
private:
protected:
	sf::RectangleShape m_CharacterShape;
	sf::Vector2f m_Size;
	sf::Texture m_Texture;

public:
	cCharacter();
	~cCharacter();


	// why would a setter for charactershape be nessesary??

	inline sf::RectangleShape* GetCharacterShape()
	{
		return &m_CharacterShape;
	}


	inline void SetSize(sf::Vector2f &_size)
	{
		m_Size = _size;
	}

	inline sf::Vector2f* GetSize()
	{
		return &m_Size;
	}


	inline void SetTexture(sf::Texture& _texture)
	{
		m_Texture = _texture;
	}

	inline sf::Texture* GetTexture()
	{
		return &m_Texture;
	}
};