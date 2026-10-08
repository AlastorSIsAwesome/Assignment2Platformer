/*******************************
Bachelor of Software Engineering
Media Design School
Auckland
New Zealand
(c) 2026 Media Design School at Strayer
File Name : [cIncrimentButton.h]
Description : [Headder file for class cIncrimentButton, outlines how the button should funciton when pressed]
Author : [Alastor Spear]
Mail : alastor.spear@mds.ac.nz
*******************************/

#include "cIncrimentButton.h"


/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ CON/DESTRUCTORS ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

cIncrimentButton::cIncrimentButton()
	:cButton() // uses cButton's default constructor
{
	m_IncrimentBy = 0;
}

cIncrimentButton::~cIncrimentButton()
{
}

cIncrimentButton::cIncrimentButton(sf::Vector2f _position, sf::Vector2f _size, std::string _textureFilePath, float _incrimentBy)
	: cButton(_position, _size, _textureFilePath), /*using cButton constuctor*/ m_IncrimentBy(_incrimentBy)
{
}


/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ ACTIONS ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

void cIncrimentButton::OnPressed(float* _propertyBeingAltered)
{
	*_propertyBeingAltered += m_IncrimentBy;
}