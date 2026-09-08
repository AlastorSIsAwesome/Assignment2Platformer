#pragma once
#include "SFML/Graphics.hpp"
//#include <iostream>

static class Controls
{
public:
	// bools that check for if a specific key has been pressed (may do acitons?)


	// WASD Keys (movement keys) 

	static bool IfKeyWPressed()
	{
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Scancode::W))
		{
			return true;
		}

		return false;
	}

	static bool IfKeySPressed()
	{
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Scancode::S))
		{
			return true;
		}

		return false;
	}

	static bool IfKeyAPressed()
	{
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Scancode::A))
		{
			return true;
		}

		return false;
	}

	static bool IfKeyDPressed()
	{
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Scancode::D))
		{
			return true;
		}

		return false;
	}


	// Debugging keys

	static bool IfKeyRPressed()
	{
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Scancode::R))
		{
			return true;
		}

		return false;
	}



};

