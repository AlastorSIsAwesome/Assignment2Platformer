#include "ShapeMath.h"

sf::Vector2f ResizeRect(sf::Vector2f _origin)
{
	//Get mosue position and convert to Vector2f
	sf::Vector2f MousePosition(sf::Mouse::getPosition()); // this vector is relative to the Desktop

	// A = origin
	// B = mouse location
	// size vector = xB - xA, yB - yA

	sf::Vector2f ResizeVector = {(MousePosition.x - _origin.x),(MousePosition.y - _origin.y)};


	return ResizeVector;
}
