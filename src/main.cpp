#include <SFML/Graphics.hpp>

#include "game.cpp"

int main()
{
    sf::RenderWindow window(sf::VideoMode({1200, 800}), "Blackjack");

    while (window.isOpen())
    {
        while (const std::optional event = window.pollEvent())
        {
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Scan::Escape) ||
                event->is<sf::Event::Closed>())
            {
                window.close();
            }
        }

        window.clear(sf::Color::Black);

        window.display();
    }

    return 0;
}
