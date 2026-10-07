#include "cSelectiveBlock.h"

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

bool cSelectiveBlock::CollidingWithSelectiveBlock(sf::RectangleShape* _collidingWith, ActiveCharacter _activeCharacter)
{
    if (_activeCharacter == m_LookingForCharacter) // if the active character is the one the block is looking for, treat it as a normal collision
    {
        return CollidingWithBlock(_collidingWith); // run usual collision check
    }
    return false; // the character we are not looking is active
}
