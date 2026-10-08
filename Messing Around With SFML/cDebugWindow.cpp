/*******************************
Bachelor of Software Engineering
Media Design School
Auckland
New Zealand
(c) 2026 Media Design School at Strayer
File Name : [cDebugWindow.cpp]
Description : [Implimentation for cDebugWindow, directly edits the data of the active game]
Author : [Alastor Spear]
Mail : alastor.spear@mds.ac.nz
*******************************/

#include "cDebugWindow.h"

/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ CON/DESTRUCTORS ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

cDebugWindow::cDebugWindow()
{
    // create all text
    sf::Text* ptrText;

    for (int i = 1; i < 2; i++)
    {
        ptrText = new sf::Text(MainFont, "Hello World", 24);
        ptrText->setFillColor(sf::Color::Black);

        DebugWindowText.push_back(ptrText);
    }


    // create all buttons
    sf::Vector2f ButtonSize(300.f, 100.f); // size of buttons

    int ButtonNum = 1;// keep track of buttons

    cIncrimentButton* ptrButton = new cIncrimentButton(ButtonSize, ButtonSize, "textures/IncreaseYButton.png", 1.f);
    DebugWindowButtons.push_back(ptrButton);
    ButtonNum++;

    ptrButton = new cIncrimentButton(sf::Vector2f(ButtonSize.x, ButtonSize.y * ButtonNum), ButtonSize, "textures/DecreaseYButton.png", -1.f); // makes the button position go down the window
    DebugWindowButtons.push_back(ptrButton);
    ButtonNum++;

    ptrButton = new cIncrimentButton(sf::Vector2f(ButtonSize.x, ButtonSize.y * ButtonNum), ButtonSize, "textures/IncreaseXButton.png", 1.f); // makes the button position go down the window
    DebugWindowButtons.push_back(ptrButton);
    ButtonNum++;

    ptrButton = new cIncrimentButton(sf::Vector2f(ButtonSize.x, ButtonSize.y * ButtonNum), ButtonSize, "textures/DecreaseXButton.png", -1.f); // makes the button position go down the window
    DebugWindowButtons.push_back(ptrButton);
    // last button, dont need to increase ButtonNum
}

cDebugWindow::~cDebugWindow()
{
}

void cDebugWindow::OpenDebugWindow()
{
}


/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ DEBUG WINDOW FUNCTIONALITY ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

void cDebugWindow::CheckIfButtonPressed(sf::Vector2f _mouseInput, float* _xVelocity, float* _yVelocity)
{
    for (int i = 0; i < DebugWindowButtons.size(); i++)
    {
        if (DebugWindowButtons[i]->CheckIfPressed(_mouseInput)) // if the button is being pressed 
        {
            float IncrimentBy = DebugWindowButtons[i]->GetIncriment();

            if (i < 2) // the Y buttons
            {
                *_yVelocity += IncrimentBy;
            }
            else // the x buttons
            {
                *_xVelocity += IncrimentBy;
            }
        }
    }
}

void cDebugWindow::DrawDebugWindow(sf::RenderWindow& _window)
{
    for (int i = 0; i < DebugWindowText.size(); i++)
    {
        _window.draw(*DebugWindowText[i]);
    }

    for (int i = 0; i < DebugWindowButtons.size(); i++)
    {
        DebugWindowButtons[i]->DrawButton(_window);
    }

}
