#include <SFML/Graphics.hpp>
#include "Collisions.h"
#include <iostream>
#include "CustomLibrary.h"
#include "cLevel.h"
#include "Controls.h"
#include "cPlayer.h"

#include<vector>


cLevel MainLevel(15, 10);
cPlayer g_Player(MainLevel.GetPlayerPosition(), MainLevel.GetActiveCharacter());


sf::Clock Clock;
float DeltaTime = 0.f;


float UpdatePlayer(float _playerYVelocity, float _YVelocity);

void XCollisions();
void YCollisions();

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


    while (window.isOpen())
    {
        // delta time
        DeltaTime = Clock.restart().asSeconds();
        window.setFramerateLimit(60);

        while (const std::optional event = window.pollEvent()) // checks if the window is open
        {
            if (event->is<sf::Event::Closed>())
                window.close();

            // check if window is resized
            if (const auto* resized = event->getIf<sf::Event::Resized>())
            {
                // update the veiw to the new sive of the window
                sf::FloatRect visibleArea({ 0.f, 0.f }, sf::Vector2f(resized->size));
                window.setView(sf::View(visibleArea));
            }

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

        std::cout << g_PlayerYVelocity << std::endl;


        // default animation is always idle
        CurrentAnimationType = Idle;

        // players slides when static
 
        //if (g_PlayerXVelocity != 0.0f)
        //{
        //    if (g_PlayerXVelocity > 0)
        //    {
        //        g_PlayerXVelocity -= 1;
        //    }
        //    else
        //    {
        //        g_PlayerXVelocity += 1;
        //    }
        //}
        g_PlayerXVelocity = 0;



        /*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ CONTROLS ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
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


        /*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ COLLISIONS & MOVEMENT ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/



            // update x position
        g_Player.GetShape()->move({ g_PlayerXVelocity, 0 });

        // check collisions     // resolve x collisions

        XCollisions();











            // update y position
        g_PlayerYVelocity = UpdatePlayer(g_PlayerYVelocity, 0.1f);

        // update collisons
        g_Player.GetShape()->move({ 0, g_PlayerYVelocity });

        // check collisions    // resolve y collisions

        YCollisions();



      



        /*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ ANIMATIONS ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

        // animate player
        g_Player.AnimatePlayer(CurrentAnimationType);


        /*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ DRAW EVERYTHING ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

        window.clear();

        MainLevel.DrawAllTiles(window);

        window.draw(*g_Player.GetShape());

        window.display();
    }
    return 0;
}

/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~  ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

float UpdatePlayer(float _g_PlayerYVelocity, float _YVelocity)
{
    if (_g_PlayerYVelocity < 10.f)
    {
        _g_PlayerYVelocity += _YVelocity * DeltaTime * 100; // (in/de)creaces
    }
    return _g_PlayerYVelocity;
}

/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ x COLLISIONS ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
void XCollisions()
{

    // checking collisions with wall tiles
    g_CollidingWith = MainLevel.CollisionWallTiles(g_Player.GetShape());
    if (g_CollidingWith != nullptr) // if there is a collision
    {
        Collisions::ResolveXCollisions(g_Player.GetShape(), g_CollidingWith, 0);
    }

    // check collisions wth platforms
    g_CollidingWith = MainLevel.CollisionPlatformTiles(g_Player.GetShape(), g_Player.GetActiveCharacter(), g_PlayerYVelocity);
    if (g_CollidingWith != nullptr)// if there is a collision
    {
        Collisions::ResolveXCollisions(g_Player.GetShape(), g_CollidingWith, 0);
    }


    // Checking collisions with checkpoints
    g_CollidingWith = MainLevel.CollisionCheckPointTiles(g_Player.GetShape());
    if (g_CollidingWith != nullptr) // if there is a collision
    {
        g_CheckPointLocation = g_CollidingWith->getPosition(); // set the checkpoint location to be the one that was collided with

        // delete checkpoint?
    }
    // checkpoint comes before obsticals


    // Checking collisions with obsticals
    g_CollidingWith = MainLevel.CollisionObsticalTiles(g_Player.GetShape());
    if (g_CollidingWith != nullptr) // if there is a collision
    {
        g_Player.GetShape()->setPosition(g_CheckPointLocation); // Send player back to last checkpoint
    }

    // check sunlight collision
    g_CollidingWith = MainLevel.CollisionSunlightTiles(g_Player.GetShape(), g_Player.GetActiveCharacter());
    if (g_CollidingWith != nullptr) // if there is a collision
    {
        g_Player.GetShape()->setPosition(g_CheckPointLocation); // Send player back to last checkpoint
    }
}


/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ Y COLLISIONS ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

void YCollisions()
{




    // checking collisions with wall tiles
    g_CollidingWith = MainLevel.CollisionWallTiles(g_Player.GetShape());
    if (g_CollidingWith != nullptr) // if there is a collision
    {
        Collisions::ResolveYCollisions(g_Player.GetShape(), g_CollidingWith, 0);
        g_PlayerYVelocity = 0.f;
    }



    // check collisions wth platforms
    g_CollidingWith = MainLevel.CollisionPlatformTiles(g_Player.GetShape(), g_Player.GetActiveCharacter(), g_PlayerYVelocity);
    if (g_CollidingWith != nullptr)// if there is a collision
    {
        Collisions::ResolveYCollisions(g_Player.GetShape(), g_CollidingWith, 0);
        g_PlayerYVelocity = 0.f;
    }

    // Checking collisions with checkpoints
    g_CollidingWith = MainLevel.CollisionCheckPointTiles(g_Player.GetShape());
    if (g_CollidingWith != nullptr) // if there is a collision
    {
        g_CheckPointLocation = g_CollidingWith->getPosition(); // set the checkpoint location to be the one that was collided with

        // delete checkpoint?
    }
    // checkpoint comes before obsticals


    // Checking collisions with obsticals
    g_CollidingWith = MainLevel.CollisionObsticalTiles(g_Player.GetShape());
    if (g_CollidingWith != nullptr) // if there is a collision
    {
        g_Player.GetShape()->setPosition(g_CheckPointLocation); // Send player back to last checkpoint
        g_PlayerYVelocity = 0.f;
    }

    // check sunlight collision
    g_CollidingWith = MainLevel.CollisionSunlightTiles(g_Player.GetShape(), g_Player.GetActiveCharacter());
    if (g_CollidingWith != nullptr) // if there is a collision
    {
        g_Player.GetShape()->setPosition(g_CheckPointLocation); // Send player back to last checkpoint
        g_PlayerYVelocity = 0.f;
    }
}
