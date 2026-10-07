/*******************************
Bachelor of Software Engineering
Media Design School
Auckland
New Zealand
(c) 2026 Media Design School at Strayer
File Name : [cText.h]
Description : [Headder file for class cText, uses base class cUIElement allongside SFML's font and text systems]
Author : [Alastor Spear]
Mail : alastor.spear@mds.ac.nz
*******************************/

#pragma once

#include "cUIElement.h"

class cText :
    public cUIElement
{
private:
protected:
    /*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ FONT MEMBER VARIABLES ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
    
    sf::Font* m_ptrFont = nullptr;
    std::string m_Text = "Hello World";
    int m_FontSize;


    /*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ TEXT POINTER MEMBER VARIABLE ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

    sf::Text* m_ptrText = nullptr;


public:

    /*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ CON/DESTRUCTORS ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

    cText();
    ~cText();

    // all text will have the same font, so no need to set the font
    cText(sf::Vector2f _position, sf::Font& _font,  std::string _text, int _fontSize); // size is not needed here


    /*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ SETTER ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

    void SetTextPosition(sf::Vector2f _position);


    /*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ DRAW TEXT TO WINDOW ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
    
    void DrawText(sf::RenderWindow& _window); // is this needed?
};
