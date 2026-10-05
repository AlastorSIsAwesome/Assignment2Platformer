#pragma once
#include "SFML/Graphics.hpp"
//#include <iostream>

static class Controls
{
public:
	// bools that check for if a specific key has been pressed (may do acitons?)


	// WASD Keys (movement keys) 

	static bool IfUpPressed()
	{
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Scancode::W) || sf::Keyboard::isKeyPressed(sf::Keyboard::Scancode::Up) || sf::Keyboard::isKeyPressed(sf::Keyboard::Scancode::Space))
		{
			return true;
		}

		return false;
	}

	static bool IfDownPressed()
	{
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Scancode::S) || sf::Keyboard::isKeyPressed(sf::Keyboard::Scancode::Down))
		{
			return true;
		}

		return false;
	}

	static bool IfLeftPressed()
	{
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Scancode::A) || sf::Keyboard::isKeyPressed(sf::Keyboard::Scancode::Left))
		{
			return true;
		}

		return false;
	}

	static bool IfRightPressed()
	{
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Scancode::D) || sf::Keyboard::isKeyPressed(sf::Keyboard::Scancode::Left))
		{
			return true;
		}

		return false;
	}

	static bool IfChangePressed()
	{
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Scancode::C))
		{
			return true;
		}
		return false;
	}


	// Debugging keys

	static bool IfResetPressed()
	{
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Scancode::R))
		{
			return true;
		}

		return false;
	}

	static bool IfDebugPressed()
	{
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Scancode::Escape))
		{
			return true;
		}

		return false;
	}


};

