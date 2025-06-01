#include "table.hpp"

Table::Table()
{
    window = sf::RenderWindow(sf::VideoMode({1200, 800}), "Blackjack",
                              sf::Style::Titlebar | sf::Style::Close);

    if (!font.openFromFile("assets/Arial.tff"))
        std::cerr << "Failed to load font\n";

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

        drawEmptyCards();
        drawButtons();

        window.display();
    }
}

void Table::drawEmptyCards()
{
    for (int i = 0; i < 5; ++i)
    {
        sf::RectangleShape dealerCard({152.86f, 214.0f});
        dealerCard.setFillColor(sf::Color(217, 217, 217));
        dealerCard.setPosition({73.0f + (225.0f * i), 117.0f});
        window.draw(dealerCard);

        sf::RectangleShape playerCard({152.86f, 214.0f});
        playerCard.setFillColor(sf::Color(217, 217, 217));
        playerCard.setPosition({73.0f + (225.0f * i), 489.0f});
        window.draw(playerCard);
    }
}

void Table::drawButtons() { ; }
