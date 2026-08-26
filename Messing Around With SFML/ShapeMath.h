#pragma once

#include <SFML/Graphics.hpp>

// this is a series of functions that will be used througout the program
// this is not a class

/// <summary>
/// Returns a size for shape Rectange with respect to the shape's origin and the user's mosue position
/// </summary>
/// <param name="_origin"> The origin of the shape (Vector2f) </param>
/// <returns></returns>
sf::Vector2f ResizeRect(sf::Vector2f _origin); 
