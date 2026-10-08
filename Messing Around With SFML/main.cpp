/*******************************
Bachelor of Software Engineering
Media Design School
Auckland
New Zealand
(c) 2026 Media Design School at Strayer
File Name : [main.cpp]
Description : [File with the main implimentation of the game, also includes other function definitions regarding collisions and collision types]
Author : [Alastor Spear]
Mail : alastor.spear@mds.ac.nz
*******************************/

#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector> // is this needed? cLevel has vector already
#include "CustomLibrary.h"

#include "Collisions.h"

#include "cDebugWindow.h"
#include "cLevel.h"
#include "Controls.h"
#include "cPlayer.h"

/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ FUNCTION DELEARATIONS ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

void RunDebugWindow();

void XCollisions(cLevel* _level);
void YCollisions(cLevel* _level);

float UpdatePlayer(float _playerYVelocity, float _YVelocity);

/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ INITALISING ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

cPlayer g_Player; // create the player

float g_ConstXSpeed = 5.f;
float g_ConstYSpeed = 10.f;

float g_PlayerYVelocity = 0.0f;
float g_PlayerXVelocity = 0.0f;

sf::Shape* g_CollidingWith;
sf::Vector2f g_CheckPointLocation({ 300.f, 300.f });


/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ TIME VALUES ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

sf::Clock g_Clock;
float g_DeltaTime = 0.f;


int main()
{

    /*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ INITALISING ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
    sf::RectangleShape Background(sf::Vector2f(1920.f, 960.f)); // create background and set to cyan
    Background.setPosition(sf::Vector2f(0.f, 0.f));
    Background.setFillColor(sf::Color::Cyan);

    sf::RectangleShape Explanation(sf::Vector2f(696.f, 361.f)); // create explanation and give it the explanation texture
    Explanation.setPosition(sf::Vector2f(1150.f, 64.f));

    sf::Texture ExplanationTexture;
    ExplanationTexture.loadFromFile("textures/Explanation.png");
    
    Explanation.setTexture(&ExplanationTexture);


    sf::RectangleShape WinScreen(sf::Vector2f(1921.f, 961.f)); // create explanation and give it the explanation texture
    WinScreen.setPosition(sf::Vector2f(1.f, 1.f));

    sf::Texture WinScreenTexture;
    WinScreenTexture.loadFromFile("textures/WinScreen1.png");

    WinScreen.setTexture(&WinScreenTexture);

    bool WinCondition = false;


    /*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ LEVEL INITALISING ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
    unsigned int CurrentLevel = 0;

    std::vector<cLevel*> LevelVector;

    cLevel* ptrLevel = new cLevel("Levels/Level1.txt");
    LevelVector.push_back(ptrLevel);

    ptrLevel = new cLevel("Levels/Level2.txt");
    LevelVector.push_back(ptrLevel);

    ptrLevel = new cLevel("Levels/Level3.txt");
    LevelVector.push_back(ptrLevel);

    LevelVector[CurrentLevel]->LoadLevel();

    g_Player.SetPlayerPosition(LevelVector[CurrentLevel]->GetPlayerPosition());

    sf::RenderWindow window(sf::VideoMode({ 1920, 960 }), "The Wacky Adventures of Sister Al and Sister Niki!");


    /*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ ANIMATION ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

    AnimationType CurrentAnimationType = Idle;

    
    /*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ MAIN GAME LOOP ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

    while (window.isOpen())
    {
        // delta time
        g_DeltaTime = g_Clock.restart().asSeconds();
        window.setFramerateLimit(60);

        while (const std::optional event = window.pollEvent()) // checks if the window is open
        {
            // check if the window is closed
            if (event->is<sf::Event::Closed>())
                window.close();

            // check if window is resized
            if (const auto* resized = event->getIf<sf::Event::Resized>())
            {
                // update the veiw to the new sive of the window
                sf::FloatRect visibleArea({ 0.f, 0.f }, sf::Vector2f(resized->size));
                window.setView(sf::View(visibleArea));
            }
            
            // check if player has pressed a key
            if (const auto* labs = event->getIf < sf::Event::KeyPressed>())
            {
                // if the player has oppended the debug window
                if (Controls::IfDebugPressed())
                {
                    // pause everything and open debug window
                    RunDebugWindow();
                }


                // player has changed character
                if (Controls::IfChangePressed())
                {
                    g_Player.SetActiveCharacter(); // changes the active character
                    std::cout << "Changed to ";

                    if (g_Player.GetActiveCharacter() == SisterAl)
                    {
                        std::cout << "Sister Al" << std::endl;
                    }
                    else
                    {
                        std::cout << "Sister Niki" << std::endl;
                    }
                }
            }
        }

        // testing
        std::cout << g_PlayerYVelocity << std::endl;


        // default animation is always idle
        CurrentAnimationType = Idle;

        g_PlayerXVelocity = 0;


        /*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ CONTROLS ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

        if (Controls::IfResetPressed())
        {
            g_Player.GetShape()->setPosition(g_CheckPointLocation);
        }
        
        if (Controls::IfUpPressed() && g_PlayerYVelocity == 0) // check if player is on the floor
        {
            g_PlayerYVelocity = -g_ConstYSpeed;
        }

        if (Controls::IfDownPressed())
        {
            g_PlayerYVelocity = g_ConstYSpeed;
        }

        if (Controls::IfLeftPressed())
        {
            g_PlayerXVelocity = -g_ConstXSpeed;
            CurrentAnimationType = WalkingLeft;
        }

        if (Controls::IfRightPressed())
        {
            g_PlayerXVelocity = g_ConstXSpeed;
            CurrentAnimationType = WalkingRight;
        }


        /*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ COLLISIONS/MOVEMENT ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

        // update x position
        g_Player.GetShape()->move({ g_PlayerXVelocity, 0 });

        // check collisions and resolve x collisions
        XCollisions(LevelVector[CurrentLevel]);


        // update y position
        g_PlayerYVelocity = UpdatePlayer(g_PlayerYVelocity, 0.1f);

        // update collisons
        g_Player.GetShape()->move({ 0, g_PlayerYVelocity });

        // check collisions and resolve y collisions
        YCollisions(LevelVector[CurrentLevel]);


        // after collisions, check if all flowers have been found
        if (LevelVector[CurrentLevel]->FoundAllFlowersInLevel())
        {
            // on all flowers being found, check if final level has been reached
            if (CurrentLevel < 2) // there are 3 levels, so if level 3 is reached nothing will happen
            {
                LevelVector[CurrentLevel]->UnloadLevel();// unload the curent level
                CurrentLevel++; //increase current level
                LevelVector[CurrentLevel]->LoadLevel();// load next level

                // spawn player at spawn point
                g_Player.SetPlayerPosition(LevelVector[CurrentLevel]->GetPlayerPosition());

                // set the player's starting character
                g_Player.SetActiveCharacter(LevelVector[CurrentLevel]->GetActiveCharacter());
            }
            else
            {
                WinCondition = true;
            }
        }



        /*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ ANIMATIONS ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

        // animate player
        g_Player.AnimatePlayer(CurrentAnimationType);


        /*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ DRAW TO WINDOW ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

        window.clear(); // clear everything

        window.draw(Background); // draw background

        if (CurrentLevel == 0)
        {
            // only show this if the current level is level 1
            window.draw(Explanation);
        }

        LevelVector[CurrentLevel]->DrawAllBlocks(window);

        window.draw(*g_Player.GetShape()); // player is above blocks

        if (WinCondition)
        {
            window.draw(WinScreen); // shows winscreen on win condition
        }


        window.display();
    }
    return 0;
}


void RunDebugWindow()
{
    sf::RenderWindow debugWindow(sf::VideoMode({ 1000, 1000 }), "Debug Window");

    cDebugWindow DebugWindowManager;

    while (debugWindow.isOpen())
    {
        while (const std::optional event = debugWindow.pollEvent()) // checks if the window is open
        {
            // check if the window is closed
            if (event->is<sf::Event::Closed>())
                debugWindow.close();

            // check if window is resized
            if (const auto* resized = event->getIf<sf::Event::Resized>())
            {
                // update the veiw to the new sive of the window
                sf::FloatRect visibleArea({ 0.f, 0.f }, sf::Vector2f(resized->size));
                debugWindow.setView(sf::View(visibleArea));
            }

            // if the user clicks anything, check all collision bounds
            if (const auto* mouseButtonPressed = event->getIf<sf::Event::MouseButtonPressed>())
            {
                sf::Vector2f MousePosition = sf::Vector2f(sf::Mouse::getPosition(debugWindow).x, sf::Mouse::getPosition(debugWindow).y);
                
                DebugWindowManager.CheckIfButtonPressed(MousePosition, &g_ConstXSpeed, &g_ConstYSpeed);
            }



        }

        /*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ DRAW TO WINDOW ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
        debugWindow.clear();

        DebugWindowManager.DrawDebugWindow(debugWindow);

        debugWindow.display();
    }
}


/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ UPDATE PLAYER WITH GRAVITY ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

float UpdatePlayer(float _g_PlayerYVelocity, float _YVelocity)
{
    if (_g_PlayerYVelocity < 10.f)
    {
        _g_PlayerYVelocity += _YVelocity * g_DeltaTime * 100; // (in/de)creaces
    }
    return _g_PlayerYVelocity;
}


/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ X COLLISIONS ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/


void XCollisions(cLevel* _level)
{

    // checking collisions with wall tiles
    g_CollidingWith = _level->CollisionWallBlocks(g_Player.GetShape());
    if (g_CollidingWith != nullptr) // if there is a collision
    {
        Collisions::ResolveXCollisions(g_Player.GetShape(), g_CollidingWith, 0); // resolve collision
    }

    // Checking collisions with obsticals
    g_CollidingWith = _level->CollisionObsticalBlocks(g_Player.GetShape());
    if (g_CollidingWith != nullptr) // if there is a collision
    {
        g_Player.GetShape()->setPosition(g_CheckPointLocation); // Send player back to last checkpoint
    }

    // Checking collisions with checkpoints
    g_CollidingWith = _level->CollisionCheckPointBlocks(g_Player.GetShape());
    if (g_CollidingWith != nullptr) // if there is a collision
    {
        g_CheckPointLocation = g_CollidingWith->getPosition(); // set the checkpoint location to be the one that was collided with
    }

    // checking collisions with flowers
    g_CollidingWith = _level->CollisionFlowerBlocks(g_Player.GetShape());
    if (g_CollidingWith != nullptr)
    {

    }

    // check collisions wth platforms
    g_CollidingWith = _level->CollisionPlatformBlocks(g_Player.GetShape(), g_Player.GetActiveCharacter(), g_PlayerYVelocity);
    // if the player is pressing the S key and is colliding with platform, allow fallthrough
    if (g_CollidingWith != nullptr && !Controls::IfDownPressed())// if there is a collision AND the player is not pressing S (or down)
    {
        Collisions::ResolveXCollisions(g_Player.GetShape(), g_CollidingWith, 0); // resolve collisions as normal
    }

    // check sunlight collision
    g_CollidingWith = _level->CollisionSunlightBlocks(g_Player.GetShape(), g_Player.GetActiveCharacter());
    if (g_CollidingWith != nullptr) // if there is a collision
    {
        g_Player.GetShape()->setPosition(g_CheckPointLocation); // Send player back to last checkpoint
    }
}


/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ Y COLLISIONS ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

void YCollisions(cLevel* _level)
{
    // checking collisions with wall tiles
    g_CollidingWith = _level->CollisionWallBlocks(g_Player.GetShape());
    if (g_CollidingWith != nullptr) // if there is a collision
    {
        Collisions::ResolveYCollisions(g_Player.GetShape(), g_CollidingWith, 0);
        g_PlayerYVelocity = 0.f;

    }

    // Checking collisions with obsticals
    g_CollidingWith = _level->CollisionObsticalBlocks(g_Player.GetShape());
    if (g_CollidingWith != nullptr) // if there is a collision
    {
        g_Player.GetShape()->setPosition(g_CheckPointLocation); // Send player back to last checkpoint
        g_PlayerYVelocity = 0.f;
    }

    // Checking collisions with checkpoints
    g_CollidingWith = _level->CollisionCheckPointBlocks(g_Player.GetShape());
    if (g_CollidingWith != nullptr) // if there is a collision
    {
        g_CheckPointLocation = g_CollidingWith->getPosition(); // set the checkpoint location to be the one that was collided with

        // delete checkpoint?
    }

    // check collisions wth platforms
    g_CollidingWith = _level->CollisionPlatformBlocks(g_Player.GetShape(), g_Player.GetActiveCharacter(), g_PlayerYVelocity);
    // if the player is pressing the S key and is colliding with platform, allow fallthrough
    if (g_CollidingWith != nullptr && !Controls::IfDownPressed())// if there is a collision AND the player is not pressing S (or down)
    {
        Collisions::ResolveYCollisions(g_Player.GetShape(), g_CollidingWith, 0);
        g_PlayerYVelocity = 0.f;
    }

    // check sunlight collision
    g_CollidingWith = _level->CollisionSunlightBlocks(g_Player.GetShape(), g_Player.GetActiveCharacter());
    if (g_CollidingWith != nullptr) // if there is a collision
    {
        g_Player.GetShape()->setPosition(g_CheckPointLocation); // Send player back to last checkpoint
        g_PlayerYVelocity = 0.f;
    }
}