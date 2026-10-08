/*******************************
Bachelor of Software Engineering
Media Design School
Auckland
New Zealand
(c) 2026 Media Design School at Strayer
File Name : [cPlayer.h]
Description : [Headder file for class cPlayer, inherits from cEntity and controls animations]
Author : [Alastor Spear]
Mail : alastor.spear@mds.ac.nz
*******************************/

#pragma once

#include <iostream>
#include "CustomLibrary.h"

#include "cEntity.h"

class cPlayer :
    public cEntity
{
private:
protected:
    /*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ PLAYER MEMBER VARIABLES ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
    //std::string m_TextureFilePath = ;
    sf::Texture m_Texture;

    ActiveCharacter m_ActiveCharacter;


    /*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ ANIMATION MEMBER VARIABLES ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
    
    sf::IntRect m_AnimationRect;
    sf::Clock m_Clock;

public:
    /*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ CON/DESTRUCTORS ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

    cPlayer(sf::Vector2f _position, ActiveCharacter _character); // the player's size should be constant, 64 by 128, texture is also constant

    cPlayer();
    ~cPlayer();


    /*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ ANIMATIONS ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

    void AnimatePlayer(AnimationType _animationType);


    /*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ ACTIVE CHARACTER SETTERS/GETTERS ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

    void SetActiveCharacter(ActiveCharacter _character);

    void SetActiveCharacter();

    inline ActiveCharacter GetActiveCharacter()
    {
        return m_ActiveCharacter;
    }



    void SetPlayerPosition(sf::Vector2f _position);
};