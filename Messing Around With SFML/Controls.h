/*******************************
Bachelor of Software Engineering
Media Design School
Auckland
New Zealand
(c) 2026 Media Design School at Strayer
File Name : [Controls.h]
Description : [Outlines and impliments the static class Controls, a series of boolean returning functions that check for keyboard input]
Author : [Alastor Spear]
Mail : alastor.spear@mds.ac.nz
*******************************/

#pragma once

#include "SFML/Graphics.hpp"

static class Controls
{
public:
	/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ WASD/MOVEMENT ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

	static bool IfUpPressed()
	{
		// scans for W key, Up arrow and space bar
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Scancode::W) || sf::Keyboard::isKeyPressed(sf::Keyboard::Scancode::Up) || sf::Keyboard::isKeyPressed(sf::Keyboard::Scancode::Space))
		{
			return true;
		}

		reurn false;
	}

	static bool IfDownPressed()
	{
		// scans for S key and Down arrow
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Scancode::S) || sf::Keyboard::isKeyPressed(sf::Keyboard::Scancode::Down))
		{
			return true;
		}
		return false;
	}

	static bool IfLeftPressed()
	{
		// scans for A key and left arrow
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Scancode::A) || sf::Keyboard::isKeyPressed(sf::Keyboard::Scancode::Left))
		{
			return true;
		}
		return false;
	}

	static bool IfRightPressed()
	{
		// scans for D key and right arrow
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Scancode::D) || sf::Keyboard::isKeyPressed(sf::Keyboard::Scancode::Left))
		{
			return true;
		}
		return false;
	}


	/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ SPECIAL ABILTIY ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

	static bool IfChangePressed()
	{
		// scans for C key
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Scancode::C))
		{
			return true;
		}
		return false;
	}


	/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ DEBUGGING ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
	static bool IfResetPressed()
	{
		// scans for R key
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Scancode::R))
		{
			return true;
		}
		return false;
	}

	static bool IfDebugPressed()
	{
		// scans for the Escape button
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Scancode::Escape))
		{
			return true;
		}
		return false;
	}

};

