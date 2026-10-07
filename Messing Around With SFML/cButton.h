/*******************************
Bachelor of Software Engineering
Media Design School
Auckland
New Zealand
(c) 2026 Media Design School at Strayer
File Name : [cButton.h]
Description : [Headder file for class cButton, is a child of class cUIElement. Is a blueprint for all other buttons]
Author : [Alastor Spear]
Mail : alastor.spear@mds.ac.nz
*******************************/

#pragma once

#include "cUIElement.h"

class cButton
	: public cUIElement
{
private:
protected:
public:
	/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ CON/DESTRUCTORS ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
	cButton();
	~cButton();

	cButton(sf::Vector2f _position, sf::Vector2f _size);
	

	/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ BUTTON FUNCTIONALITY ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

	virtual void OnPressed() = 0;
};

