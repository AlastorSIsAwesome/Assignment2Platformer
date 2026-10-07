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

class cDebugWindow
{
private:
protected:
	/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ EDITABLE MEMBER-VARIABLES ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
	float m_PlayerXVelocity;
	float m_PlayerYVelocity;


public:
	/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ CON/DESTRUCTORS ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
	
	cDebugWindow();
	~cDebugWindow();


	/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ DEBUG WINDOW FUNCTIONALITY ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

	void OpenDebugWindow();

};

