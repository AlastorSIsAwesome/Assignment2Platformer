#pragma once
#include "cEntity.h"
#include <iostream>;

enum ActiveCharacter
{
    Default = 0,
    SisterNiki,
    SisterAl
};

enum AnimationType
{
    Idle = 0,
    WalkingLeft,
    WalkingRight
};


class cPlayer :
    public cEntity
{
private:
protected:
    sf::Vector2f m_Velocity;

    //std::string m_TextureFilePath = ;
    sf::Texture m_Texture;

    ActiveCharacter m_ActiveCharacter;

    // animation stuff
    sf::IntRect m_AnimationRect;
    sf::Clock m_Clock;

public:
    cPlayer(sf::Vector2f _position, ActiveCharacter _character); // the player's size should be constant, 64 by 128, texture is also constant


    cPlayer();
    ~cPlayer();

    // get and set velocity
    inline float GetXVelocity()
    {
        return m_Velocity.x;
    }

    inline void SetXVelocity(float _xVelocity)
    {
        m_Velocity.x = _xVelocity;
    }


    inline float GetYVelocity()
    {
        return m_Velocity.y;
    }

    inline void SetYVelocity(float _yVelocity)
    {
        m_Velocity.y = _yVelocity;
    }
    // SORT OUT VELOCITY STUFFFF


    void AnimatePlayer(AnimationType _animationType);


    void SetActiveCharacter(ActiveCharacter _character);
    void SetActiveCharacter();

    inline ActiveCharacter GetActiveCharacter()
    {
        return m_ActiveCharacter;
    }
};

