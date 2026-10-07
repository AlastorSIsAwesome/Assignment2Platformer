/*******************************
Bachelor of Software Engineering
Media Design School
Auckland
New Zealand
(c) 2026 Media Design School at Strayer
File Name : [cSelectiveBlock.cpp]
Description : [Implimention file for cSelectiveBlock, depending on the character this block is looking for, will read collisions differently]
Author : [Alastor Spear]
Mail : alastor.spear@mds.ac.nz
*******************************/

#include "cSelectiveBlock.h"

/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ CON/DESTRUCTORS ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

cSelectiveBlock::cSelectiveBlock()
{
}

cSelectiveBlock::~cSelectiveBlock()
{
    cBlock::~cBlock(); // destroys m_ptrBlockShape
}

cSelectiveBlock::cSelectiveBlock(char _identity, sf::Vector2f _position, sf::Vector2f _size, sf::Texture* _texture, ActiveCharacter _lookingForCharacter)
    : m_LookingForCharacter(_lookingForCharacter)
{
    cBlock(_identity, _position, _size, _texture); // uses cBlock's constructor, will also create the m_ptrBlockShape
}

/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ COLLISIONS ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

bool cSelectiveBlock::CollidingWithSelectiveBlock(sf::RectangleShape* _collidingWith, ActiveCharacter _activeCharacter)
{
    if (_activeCharacter == m_LookingForCharacter) // if the active character is the one the block is looking for, treat it as a normal collision
    {
        return CollidingWithBlock(_collidingWith); // run usual collision check
    }
    return false; // the character we are not looking is active
}
