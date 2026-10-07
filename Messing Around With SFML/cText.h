#pragma once
#include "cUIElement.h"
class cText :
    public cUIElement
{
private:
protected:
    sf::Font* m_ptrFont = nullptr;
    std::string m_Text = "Hello World";
    int m_FontSize;

    sf::Text* m_ptrText = nullptr;

public:
    cText();
    ~cText();

    // all text will have the same font, so no need to set the font
    cText(sf::Vector2f _position, sf::Font& _font,  std::string _text, int _fontSize); // size is not needed here

    void SetTextPosition(sf::Vector2f _position);


    void DrawText(sf::RenderWindow& _window); // is this needed?
};
