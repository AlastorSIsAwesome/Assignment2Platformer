#include <SFML/Graphics.hpp>

int main()
{
    sf::RenderWindow window(sf::VideoMode({ 1280, 720 }), "ALASTOR SPHERE RETURNS");
    sf::RectangleShape Player({ 100.f, 100.f });
    
    // Texture Setting
    sf::Texture PlayerTexture;
    PlayerTexture.loadFromFile("textures/alastorsphere.png");
    Player.setTexture(&PlayerTexture);



    sf::RenderTexture; 

    while (window.isOpen())
    {
        while (const std::optional event = window.pollEvent()) // checks if the window is open
        {
            if (event->is<sf::Event::Closed>())
                window.close();

            
        }

        window.clear();
        window.draw(Player);
        window.display();
    }
}
