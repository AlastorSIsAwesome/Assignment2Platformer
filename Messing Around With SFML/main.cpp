#include <SFML/Graphics.hpp>
#include "Collisions.h"


float UpdatePlayer(float _playerYVelocity, float _YVelocity, float _dt)
{
    if (_playerYVelocity < 4.f)
    {
        _playerYVelocity += _YVelocity * _dt * 2; // (in/de)creaces
        return _playerYVelocity;
    }
}




int main()
{
    sf::RenderWindow window(sf::VideoMode({ 1280, 720 }), "ALASTOR SPHERE RETURNS");

    // create objects
    sf::RectangleShape Player({ 100.f, 100.f });
    sf::RectangleShape Ground({ 100.f, 100.f });
    sf::RectangleShape Ground1({ 100.f, 100.f });
    sf::RectangleShape Ground2({ 100.f, 100.f });
    
    Player.setPosition({ 300, 200 });
    Ground.setPosition({ 300, 400 });
    Ground1.setPosition({ 500, 400 });
    Ground2.setPosition({ 700, 400 });


    // Texture Setting
    sf::Texture PlayerTexture;
    PlayerTexture.loadFromFile("textures/alastorsphere.png");
    Player.setTexture(&PlayerTexture);

    float PlayerYVelocity = 0.0f;
    float PlayerXVelocity = 0.0f;

    while (window.isOpen())
    {
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
            PlayerYVelocity = -2;
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Scancode::S))
        {
            PlayerYVelocity = 1;
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Scancode::A))
        {
            PlayerXVelocity = -1;
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Scancode::D))
        {
            PlayerXVelocity = 1;
        }


        window.clear();


        PlayerYVelocity = UpdatePlayer(PlayerYVelocity, 1.0f, 0.0167); 
        
        Player.move({ 0, PlayerYVelocity });
        if (Player.getGlobalBounds().findIntersection(Ground.getGlobalBounds()))
        {
            Collisions::ResolveYCollisions(&Player, &Ground, 1);
        }
        else if (Player.getGlobalBounds().findIntersection(Ground1.getGlobalBounds()))
        {
            Collisions::ResolveYCollisions(&Player, &Ground1, 1);
        }
        else if (Player.getGlobalBounds().findIntersection(Ground2.getGlobalBounds()))
        {
            Collisions::ResolveYCollisions(&Player, &Ground2, 1);
        }

        Player.move({ PlayerXVelocity, 0 });
        if (Player.getGlobalBounds().findIntersection(Ground.getGlobalBounds()))
        {
            Collisions::ResolveXCollisions(&Player, &Ground, 1);
        }
        else if (Player.getGlobalBounds().findIntersection(Ground1.getGlobalBounds()))
        {
            Collisions::ResolveXCollisions(&Player, &Ground1, 1);
        }
        else if (Player.getGlobalBounds().findIntersection(Ground2.getGlobalBounds()))
        {
            Collisions::ResolveXCollisions(&Player, &Ground2, 1);
        }


        window.draw(Player);
        window.draw(Ground);
        window.draw(Ground1);
        window.draw(Ground2);

        window.display();
    }
    return 0;
}
