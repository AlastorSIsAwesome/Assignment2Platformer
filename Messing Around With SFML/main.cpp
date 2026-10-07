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

#include "cLevel.h"
#include "Controls.h"
#include "cPlayer.h"

/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ FUNCTION DELEARATIONS ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

void XCollisions();
void YCollisions();

float UpdatePlayer(float _playerYVelocity, float _YVelocity);

/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ INITALISING ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

cLevel MainLevel(15, 10);
cPlayer g_Player(MainLevel.GetPlayerPosition(), MainLevel.GetActiveCharacter());


sf::Clock Clock;
float DeltaTime = 0.f;

const float g_ConstXSpeed = 5.f;
const float g_ConstYSpeed = 10.f;

float g_PlayerYVelocity = 0.0f;
float g_PlayerXVelocity = 0.0f;

sf::Shape* g_CollidingWith;
sf::Vector2f g_CheckPointLocation({ 300.f, 300.f });


int main()
{
    sf::RenderWindow window(sf::VideoMode({ 1800, 960 }), "The Wacky Adventures of Sister Al and Sister Niki!");

    AnimationType CurrentAnimationType = Idle;

    MainLevel.LoadLevel("Levels/Level1.txt");

    /*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ MAIN GAME LOOP ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

    while (window.isOpen())
    {
        // delta time
        DeltaTime = Clock.restart().asSeconds();
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
        XCollisions();


        // update y position
        g_PlayerYVelocity = UpdatePlayer(g_PlayerYVelocity, 0.1f);

        // update collisons
        g_Player.GetShape()->move({ 0, g_PlayerYVelocity });

        // check collisions and resolve y collisions
        YCollisions();


        /*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ ANIMATIONS ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

        // animate player
        g_Player.AnimatePlayer(CurrentAnimationType);


        /*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ DRAW TO WINDOW ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

        window.clear(); // clear everything

        MainLevel.DrawAllBlocks(window);

        window.draw(*g_Player.GetShape()); // player is above blocks

        window.display();
    }
    return 0;
}


/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ UPDATE PLAYER WITH GRAVITY ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

float UpdatePlayer(float _g_PlayerYVelocity, float _YVelocity)
{
    if (_g_PlayerYVelocity < 10.f)
    {
        _g_PlayerYVelocity += _YVelocity * DeltaTime * 100; // (in/de)creaces
        // add lerp?
    }
    return _g_PlayerYVelocity;
}


/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ X COLLISIONS ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

void XCollisions()
{

    // checking collisions with wall tiles
    g_CollidingWith = MainLevel.CollisionWallBlocks(g_Player.GetShape());
    if (g_CollidingWith != nullptr) // if there is a collision
    {
        Collisions::ResolveXCollisions(g_Player.GetShape(), g_CollidingWith, 0); // resolve collision
    }

    // Checking collisions with obsticals
    g_CollidingWith = MainLevel.CollisionObsticalBlocks(g_Player.GetShape());
    if (g_CollidingWith != nullptr) // if there is a collision
    {
        g_Player.GetShape()->setPosition(g_CheckPointLocation); // Send player back to last checkpoint
    }

    // Checking collisions with checkpoints
    g_CollidingWith = MainLevel.CollisionCheckPointBlocks(g_Player.GetShape());
    if (g_CollidingWith != nullptr) // if there is a collision
    {
        g_CheckPointLocation = g_CollidingWith->getPosition(); // set the checkpoint location to be the one that was collided with
    }

    // check collisions wth platforms
    g_CollidingWith = MainLevel.CollisionPlatformBlocks(g_Player.GetShape(), g_Player.GetActiveCharacter(), g_PlayerYVelocity);
    if (g_CollidingWith != nullptr)// if there is a collision
    {
        Collisions::ResolveXCollisions(g_Player.GetShape(), g_CollidingWith, 0); // resolve collisions as normal
    }

    // check sunlight collision
    g_CollidingWith = MainLevel.CollisionSunlightBlocks(g_Player.GetShape(), g_Player.GetActiveCharacter());
    if (g_CollidingWith != nullptr) // if there is a collision
    {
        g_Player.GetShape()->setPosition(g_CheckPointLocation); // Send player back to last checkpoint
    }
}


/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ Y COLLISIONS ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

void YCollisions()
{
    // checking collisions with wall tiles
    g_CollidingWith = MainLevel.CollisionWallBlocks(g_Player.GetShape());
    if (g_CollidingWith != nullptr) // if there is a collision
    {
        Collisions::ResolveYCollisions(g_Player.GetShape(), g_CollidingWith, 0);
        g_PlayerYVelocity = 0.f;

    }

    // Checking collisions with obsticals
    g_CollidingWith = MainLevel.CollisionObsticalBlocks(g_Player.GetShape());
    if (g_CollidingWith != nullptr) // if there is a collision
    {
        g_Player.GetShape()->setPosition(g_CheckPointLocation); // Send player back to last checkpoint
        g_PlayerYVelocity = 0.f;
    }

    // Checking collisions with checkpoints
    g_CollidingWith = MainLevel.CollisionCheckPointBlocks(g_Player.GetShape());
    if (g_CollidingWith != nullptr) // if there is a collision
    {
        g_CheckPointLocation = g_CollidingWith->getPosition(); // set the checkpoint location to be the one that was collided with

        // delete checkpoint?
    }

    // check collisions wth platforms
    g_CollidingWith = MainLevel.CollisionPlatformBlocks(g_Player.GetShape(), g_Player.GetActiveCharacter(), g_PlayerYVelocity);
    if (g_CollidingWith != nullptr)// if there is a collision
    {
        Collisions::ResolveYCollisions(g_Player.GetShape(), g_CollidingWith, 0);
        g_PlayerYVelocity = 0.f;
    }

    // check sunlight collision
    g_CollidingWith = MainLevel.CollisionSunlightBlocks(g_Player.GetShape(), g_Player.GetActiveCharacter());
    if (g_CollidingWith != nullptr) // if there is a collision
    {
        g_Player.GetShape()->setPosition(g_CheckPointLocation); // Send player back to last checkpoint
        g_PlayerYVelocity = 0.f;
    }
}
