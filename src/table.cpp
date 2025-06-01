#include "table.hpp"

Table::Table()
{
    window = sf::RenderWindow(sf::VideoMode({1200, 800}), "Blackjack",
                              sf::Style::Titlebar | sf::Style::Close);

    if (!font.openFromFile("assets/Arial.ttf"))
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

void Table::drawButtons()
{
    sf::RectangleShape hitButton({378.0f, 81.0f});
    hitButton.setFillColor(sf::Color(171, 230, 234));
    hitButton.setPosition({73.0f, 369.0f});
    window.draw(hitButton);

    sf::Text hitLabel(font);
    hitLabel.setString("Hit");
    hitLabel.setCharacterSize(48);
    hitLabel.setFillColor(sf::Color::Black);

    auto textBounds = hitLabel.getLocalBounds();
    hitLabel.setOrigin({textBounds.position.x + textBounds.size.x / 2.f,
                        textBounds.position.y + textBounds.size.y / 2.f});

    hitLabel.setPosition(hitButton.getPosition() + hitButton.getSize() / 2.f);

    window.draw(hitLabel);

    sf::RectangleShape standButton({378.0f, 81.0f});
    standButton.setFillColor(sf::Color(254, 185, 170));
    standButton.setPosition({748.0f, 369.0f});
    window.draw(standButton);

    sf::Text standLabel(font);
    standLabel.setString("Stand");
    standLabel.setCharacterSize(48);
    standLabel.setFillColor(sf::Color::Black);

    textBounds = standLabel.getLocalBounds();
    standLabel.setOrigin({textBounds.position.x + textBounds.size.x / 2.f,
                          textBounds.position.y + textBounds.size.y / 2.f});

    standLabel.setPosition(standButton.getPosition() +
                           standButton.getSize() / 2.f);

    window.draw(standLabel);
}
