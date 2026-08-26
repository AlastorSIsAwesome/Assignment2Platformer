#pragma once
#include "SFML/Graphics.hpp"

static class Collisions
{
public:
	static void ResolveXCollisions(sf::Shape* _objA, sf::Shape* _objB, bool _secondObjectWall) // bool is here if you want collision to react differently if the second object is a wall (or something else)
	{
		// global bounds == size and position with respect to the 2D world and any transformations done to the object
		sf::Vector2f entityACenter = { (_objA->getGlobalBounds().position.x + (_objA->getGlobalBounds().size.x / 2.0f)), // .position returns the location of the top left corner, add half of the object's size and you get the center of the object!
									  (_objA->getGlobalBounds().position.y + (_objA->getGlobalBounds().size.y / 2.0f)) };

		sf::Vector2f entityBCenter = { (_objB->getGlobalBounds().position.x + (_objB->getGlobalBounds().size.x / 2.0f)), // same as for A
									  (_objB->getGlobalBounds().position.y + (_objB->getGlobalBounds().size.y / 2.0f)) };

		if (entityACenter.x <= entityBCenter.x) // if A is to the left of B
		{
			float offset = -(_objA->getGlobalBounds().position.x + _objA->getGlobalBounds().size.x - _objB->getGlobalBounds().position.x); // don't need to half anything bc its raw additon & subtraction
			_objA->move({ offset, 0 }); // moving A back to where it was before colliding
		}

		if (entityACenter.x >= entityBCenter.x) // if A is to the right of B
		{
			float offset = (_objB->getGlobalBounds().position.x + _objB->getGlobalBounds().size.x) - _objA->getGlobalBounds().position.x;
			_objA->move(sf::Vector2f(offset, 0)); // moving A back to where it was before colliding
		}
	}
	static void ResolveYCollisions(sf::Shape* _objA, sf::Shape* _objB, bool _secondObjectWall)
	{
		sf::Vector2f entityACenter = { (_objA->getGlobalBounds().position.x + _objA->getGlobalBounds().size.x / 2.0f),
									  (_objA->getGlobalBounds().position.y + _objA->getGlobalBounds().size.y / 2.0f) };

		sf::Vector2f entityBCenter = { (_objB->getGlobalBounds().position.x + _objB->getGlobalBounds().size.x / 2.0f),
									  (_objB->getGlobalBounds().position.y + _objB->getGlobalBounds().size.y / 2.0f) };

		// underneath the tile
		if (entityACenter.y <= entityBCenter.y)
		{
			float offset = -(_objA->getGlobalBounds().position.y + _objA->getGlobalBounds().size.y - _objB->getGlobalBounds().position.y);
			_objA->move({ 0, offset });
		}

		// above the tile. 
		if (entityACenter.y >= entityBCenter.y)
		{
			float offset = (_objB->getGlobalBounds().position.y + _objB->getGlobalBounds().size.y) - _objA->getGlobalBounds().position.y;
			_objA->move({ 0, offset });
		}
	}
};


