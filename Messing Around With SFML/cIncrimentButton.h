/*******************************
Bachelor of Software Engineering
Media Design School
Auckland
New Zealand
(c) 2026 Media Design School at Strayer
File Name : [cIncrimentButton.h]
Description : [Headder file for class cIncrimentButton, outlines how the button should funciton when pressed]
Author : [Alastor Spear]
Mail : alastor.spear@mds.ac.nz
*******************************/

#pragma once

#include "cButton.h"

class cIncrimentButton :
    public cButton
{
private:
protected:
    /*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ MEMBER VARIABLE, INCRIMENT ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
    float m_IncrimentBy = 0.f;

public:
    /*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ CON/DESTRUCTORS ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
    cIncrimentButton();
    ~cIncrimentButton();

    cIncrimentButton(sf::Vector2f _position, sf::Vector2f _size, std::string _textureFilePath, float _incrimentBy);


    /*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ ACTIONS ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

    void OnPressed(float* _propertyBeingAltered) override;

    inline float GetIncriment()
    {
        return m_IncrimentBy;
    }
};