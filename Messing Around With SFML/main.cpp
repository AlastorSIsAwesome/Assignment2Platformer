#include <SFML/Graphics.hpp>
#include "Collisions.h"
#include <iostream>

#include "cLevel.h"
#include "Controls.h"
#include "cPlayer.h"

#include<vector>


cLevel MainLevel(15, 10);
cPlayer g_Player(MainLevel.GetPlayerPosition(), MainLevel.GetActiveCharacter());


sf::Clock Clock;
float DeltaTime = 0.f;


float UpdatePlayer(float _playerYVelocity, float _YVelocity);


const float g_ConstXSpeed = 5.f;
const float g_ConstYSpeed = 7.5f;


sf::Shape* g_CollidingWith;
sf::Vector2f g_CheckPointLocation({ 300.f, 300.f });


int main()
{
    sf::RenderWindow window(sf::VideoMode({ 1280, 720 }), "ALASTOR SPHERE RETURNS");



    float PlayerYVelocity = 0.0f;
    float PlayerXVelocity = 0.0f;

    AnimationType CurrentAnimationType = Idle;


    while (window.isOpen())
    {
        DeltaTime = Clock.restart().asSeconds();

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

        //while (Controls::IfChangePressed())
        //{
        //    g_Player.SetActiveCharacter();
        //    std::cout << "Change" << std::endl;
        //}

        // default animation is always idle
        CurrentAnimationType = Idle;

        // players slides when static
        if (PlayerXVelocity != 0.0f)
        {
            if (PlayerXVelocity > 0)
            {
                PlayerXVelocity -= 1;
            }
            else
            {
                PlayerXVelocity += 1;
            }
        }


        // checking if any key is pressed

        if (Controls::IfResetPressed())
        {
            g_Player.GetShape()->setPosition(g_CheckPointLocation);
        }
        
        if (Controls::IfUpPressed() && PlayerYVelocity == 0) // check if player is on the floor
        {
            PlayerYVelocity = -g_ConstYSpeed;
        }

        if (Controls::IfDownPressed())
        {
            PlayerYVelocity = g_ConstYSpeed;
        }

        if (Controls::IfLeftPressed())
        {
            PlayerXVelocity = -g_ConstXSpeed;
            CurrentAnimationType = WalkingLeft;
        }

        if (Controls::IfRightPressed())
        {
            PlayerXVelocity = g_ConstXSpeed;
            CurrentAnimationType = WalkingRight;
        }





        window.clear();




        // update y position
        PlayerYVelocity = UpdatePlayer(PlayerYVelocity, 0.1f);

        // update collisons
        g_Player.GetShape()->move({ 0, PlayerYVelocity });

        // check collisions    // resolve y collisions
    


        // checking collisions with wall tiles
        g_CollidingWith = MainLevel.CollisionWallTiles(g_Player.GetShape());
        if (g_CollidingWith != nullptr) // if there is a collision
        {
            Collisions::ResolveYCollisions(g_Player.GetShape(), g_CollidingWith, 0);
            PlayerYVelocity = 0.f;
        }

        // checking collisions with wall tiles



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
            PlayerYVelocity = 0.f;
        }






        // update x position
        g_Player.GetShape()->move({ PlayerXVelocity, 0 });

        // check collisions     // resolve x collisions
        // checking collisions with wall tiles
        g_CollidingWith = MainLevel.CollisionWallTiles(g_Player.GetShape());
        if (g_CollidingWith != nullptr) // if there is a collision
        {
            Collisions::ResolveXCollisions(g_Player.GetShape(), g_CollidingWith, 0);
            PlayerYVelocity = 0.f;
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
            PlayerYVelocity = 0.f;
        }



        // animate player
        g_Player.AnimatePlayer(CurrentAnimationType);



        MainLevel.DrawAllTiles(window);

        window.draw(*g_Player.GetShape());

        window.display();
    }
    return 0;
}


float UpdatePlayer(float _playerYVelocity, float _YVelocity)
{
    if (_playerYVelocity < 10.f)
    {
        _playerYVelocity += _YVelocity * DeltaTime * 100; // (in/de)creaces
    }
    return _playerYVelocity;
}