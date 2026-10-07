#pragma once

#include "SFML/Graphics.hpp"

class cUIElement
{
private:
protected:
	sf::Vector2f m_Postiton;
	sf::Vector2f m_Size;
public:
	cUIElement();
	~cUIElement();

	cUIElement(sf::Vector2f _position, sf::Vector2f _size);


};

