#pragma once

#include "cUIElement.h"

class cButton
	: public cUIElement
{
private:
protected:


public:
	cButton();
	~cButton();

	cButton(sf::Vector2f _position, sf::Vector2f _size);
	
	virtual void OnPressed() = 0;
};

