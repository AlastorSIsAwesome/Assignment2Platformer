#include <SFML/Graphics.hpp>
#include "Collisions.h"
#include <iostream>

#include "cLevel.h"

#include<vector>


cLevel MainLevel(15, 10);


sf::Clock Clock;
float DeltaTime = 0.f;

float UpdatePlayer(float _playerYVelocity, float _YVelocity)
{
    if (_playerYVelocity < 1.f)
    {
        _playerYVelocity += _YVelocity * DeltaTime * 2; // (in/de)creaces
    }
    return _playerYVelocity;
}

const float ConstSpeed = .1f;


int main()
{
    sf::RenderWindow window(sf::VideoMode({ 1280, 720 }), "ALASTOR SPHERE RETURNS");

    // create objects
    sf::RectangleShape Player({ 100.f, 100.f });
    Player.setPosition({ 200.f, 300.f });

   

    // Texture Setting
    sf::Texture PlayerTexture;
    PlayerTexture.loadFromFile("textures/alastorsphere.png");
    Player.setTexture(&PlayerTexture);

    float PlayerYVelocity = 0.0f;
    float PlayerXVelocity = 0.0f;



    while (window.isOpen())
    {
        DeltaTime = Clock.restart().asSeconds();

        while (const std::optional event = window.pollEvent()) // checks if the window is open
        {
            if (event->is<sf::Event::Closed>())
                window.close();
        }


        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Scancode::R))
        {
            Player.setPosition({ 300,200 });
        }

        PlayerXVelocity = 0.0f;

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Scancode::W))
        {
            PlayerYVelocity = -ConstSpeed;
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Scancode::S))
        {
            PlayerYVelocity = ConstSpeed;
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Scancode::A))
        {
            PlayerXVelocity = -ConstSpeed;
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Scancode::D))
        {
            PlayerXVelocity = ConstSpeed;
        }








        window.clear();




        // move player on y axix
        PlayerYVelocity = UpdatePlayer(PlayerYVelocity, 0.1f);
        Player.move({ 0, PlayerYVelocity });

        // resolve collisions
        for (int i = 0; i < MainLevel.LevelWallTiles.size(); i++)
        {
            if (Player.getGlobalBounds().findIntersection(MainLevel.LevelWallTiles[i]->getGlobalBounds()))
            {
                Collisions::ResolveYCollisions(&Player, MainLevel.LevelWallTiles[i], 0);
                PlayerYVelocity = 0.f;
            }
        }




        // move player on x axis
        Player.move({ PlayerXVelocity, 0.0000167 });

        // resolve collisions
        for (int i = 0; i < MainLevel.LevelWallTiles.size(); i++)
        {
            if (Player.getGlobalBounds().findIntersection(MainLevel.LevelWallTiles[i]->getGlobalBounds()))
            {
                Collisions::ResolveXCollisions(&Player, MainLevel.LevelWallTiles[i], 0);
            }
        }





       


        for (int i = 0; i < MainLevel.LevelWallTiles.size(); i++)
        {
            window.draw(*MainLevel.LevelWallTiles[i]);
        }
      


        window.draw(Player);


        window.display();
    }
    return 0;
}


/*
 std::vector<sf::RectangleShape> GroundBlocks;

    for (int i = 0; i < 4; i++)
    {
        GroundBlocks();
    }


    sf::RectangleShape Ground({ 100.f, 100.f });
    sf::RectangleShape Ground1({ 100.f, 100.f });
    sf::RectangleShape Ground2({ 100.f, 100.f });



    Player.setPosition({ 300, 200 });
    Ground.setPosition({ 300, 400 });
    Ground1.setPosition({ 500, 400 });
    Ground2.setPosition({ 700, 400 });

*/