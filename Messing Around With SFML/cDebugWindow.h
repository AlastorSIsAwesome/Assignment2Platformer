/*******************************
Bachelor of Software Engineering
Media Design School
Auckland
New Zealand
(c) 2026 Media Design School at Strayer
File Name : [cDebugWindow.h]
Description : [Headder file for class cDebug window, outlines how the Debug Window will function]
Author : [Alastor Spear]
Mail : alastor.spear@mds.ac.nz
*******************************/

#pragma once

#include <vector>

#include "CustomLibrary.h"
#include "cIncrimentButton.h"

class cDebugWindow
{
protected:
	/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ EDITABLE MEMBER-VARIABLES ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
	float m_PlayerXVelocity;
	float m_PlayerYVelocity;

	std::vector<cIncrimentButton*> DebugWindowButtons;
	std::vector<sf::Text*> DebugWindowText;

public:
	/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ CON/DESTRUCTORS ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
	
	cDebugWindow();
	~cDebugWindow();

	
	/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ DEBUG WINDOW FUNCTIONALITY ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

	void OpenDebugWindow();

	void CheckIfButtonPressed(sf::Vector2f _mouseInput, float* _xVelocity, float* _yVelocity);

	void DrawDebugWindow(sf::RenderWindow& _window);

};

