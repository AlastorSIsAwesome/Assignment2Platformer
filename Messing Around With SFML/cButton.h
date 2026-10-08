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
protected:
	/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ MEMBER VARIABLES ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
	std::string m_TextureFilePath = "textures/alastorsphere.png"; // default texture if none is set
	sf::Texture* m_ptrButtonTexture = nullptr;

	sf::RectangleShape m_ButtonShape;

public:
	/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ CON/DESTRUCTORS ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
	cButton();
	~cButton();

	cButton(sf::Vector2f _position, sf::Vector2f _size, std::string _textureFilePath);



	/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ BUTTON FUNCTIONALITY ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

	bool CheckIfPressed(sf::Vector2f _mouseInput);

	virtual void OnPressed(float* _propertyBeingAltered) = 0;

	void DrawButton(sf::RenderWindow& _window);
};

