#include "table.hpp"

Table::Table() : game(10)
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
    auto dealerHand = game.getDealerHand();
    auto playerHand = game.getPlayerHand();

    for (int i = 0; i < 5; ++i)
    {
        sf::RectangleShape dealerCard({152.86f, 214.0f});
        dealerCard.setFillColor(sf::Color(217, 217, 217));
        dealerCard.setPosition({73.0f + (225.0f * i), 117.0f});
        window.draw(dealerCard);

        if (i < dealerHand.size())
        {
            sf::Text dealerLabel(font);
            dealerLabel.setString(std::string(1, dealerHand[i].getCard()));
            dealerLabel.setCharacterSize(48);
            dealerLabel.setFillColor(sf::Color::Black);

            auto bounds = dealerLabel.getLocalBounds();
            dealerLabel.setOrigin({bounds.position.x + bounds.size.x / 2.f,
                                   bounds.position.y + bounds.size.y / 2.f});

            dealerLabel.setPosition(dealerCard.getPosition() +
                                    dealerCard.getSize() / 2.f);
            window.draw(dealerLabel);
        }

        sf::RectangleShape playerCard({152.86f, 214.0f});
        playerCard.setFillColor(sf::Color(217, 217, 217));
        playerCard.setPosition({73.0f + (225.0f * i), 489.0f});
        window.draw(playerCard);

        if (i < playerHand.size())
        {
            sf::Text playerLabel(font);
            playerLabel.setString(std::string(1, playerHand[i].getCard()));
            playerLabel.setCharacterSize(48);
            playerLabel.setFillColor(sf::Color::Black);

            auto bounds = playerLabel.getLocalBounds();
            playerLabel.setOrigin({bounds.position.x + bounds.size.x / 2.f,
                                   bounds.position.y + bounds.size.y / 2.f});

            playerLabel.setPosition(playerCard.getPosition() +
                                    playerCard.getSize() / 2.f);
            window.draw(playerLabel);
        }
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

    auto hitBounds = hitLabel.getLocalBounds();
    hitLabel.setOrigin({hitBounds.position.x + hitBounds.size.x / 2.f,
                        hitBounds.position.y + hitBounds.size.y / 2.f});

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

    auto standBounds = standLabel.getLocalBounds();
    standLabel.setOrigin({standBounds.position.x + standBounds.size.x / 2.f,
                          standBounds.position.y + standBounds.size.y / 2.f});

    standLabel.setPosition(standButton.getPosition() +
                           standButton.getSize() / 2.f);

    window.draw(standLabel);
}
