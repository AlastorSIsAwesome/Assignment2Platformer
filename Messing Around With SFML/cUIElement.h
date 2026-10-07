#pragma once

#include "SFML/Graphics.hpp"

class cUIElement
{
private:
protected:
	sf::Vector2f m_Position;
	sf::Vector2f m_Size;
public:
	cUIElement();
	~cUIElement();

	cUIElement(sf::Vector2f _position);
	cUIElement(sf::Vector2f _position, sf::Vector2f _size);


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

