/*******************************
Bachelor of Software Engineering
Media Design School
Auckland
New Zealand
(c) 2026 Media Design School at Strayer
File Name : [cSelectiveBlock.h]
Description : [Headder file for class cSelectiveBlock, child class of cBlock adds secondary parameter to collision function]
Author : [Alastor Spear]
Mail : alastor.spear@mds.ac.nz
*******************************/

#pragma once

#include "CustomLibrary.h"

#include "cBlock.h"


class cSelectiveBlock :
    public cBlock
{
private:
protected:
    /*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ CHARACTER MEMBER VARIABLE ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

    ActiveCharacter m_LookingForCharacter; // this indicates which character the block is looking for


public:
    /*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ CON/DESTRUCTORS ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

    cSelectiveBlock();
    ~cSelectiveBlock();

    cSelectiveBlock(char _identity, sf::Vector2f _position, sf::Vector2f _size, sf::Texture* _texture, ActiveCharacter _lookingForCharacter);


    /*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ COLLISIONS ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

    bool CollidingWithSelectiveBlock(sf::RectangleShape* _collidingWith, ActiveCharacter _activeCharacter);
};

