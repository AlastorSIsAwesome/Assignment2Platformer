#pragma once
#include "cBlock.h"
#include "CustomLibrary.h"
class cSelectiveBlock :
    public cBlock
{
private:
protected:
    ActiveCharacter m_LookingForCharacter; // this indicates which character the block is looking for

public:
    cSelectiveBlock();
    ~cSelectiveBlock();

    cSelectiveBlock(char _identity, sf::Vector2f _position, sf::Vector2f _size, sf::Texture* _texture, ActiveCharacter _lookingForCharacter);

    bool CollidingWithSelectiveBlock(sf::RectangleShape* _collidingWith, ActiveCharacter _activeCharacter);
};

