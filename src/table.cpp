#include "table.hpp"

Table::Table() = default;

void Table::setupTable()
{
    sf::RenderWindow window(sf::VideoMode({1200, 800}), "Blackjack",
                            sf::Style::Titlebar | sf::Style::Close);

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

        window.clear(sf::Color(20, 60, 50));

        window.display();
    }
}
