#include "table.hpp"

Table::Table() : game(5), isMousePressed(false)
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
        handleMouseClick();

        if (!game.isPlayerTurn())
            game.playDealerTurn();

        if (game.isRoundOver() && !waitingToReset)
        {
            // Don't go past the last round
            if (game.getCurrentRound() < game.getRounds())
            {
                waitingToReset = true;
            }
            else
            {
                gameOver = true;
            }
        }

        drawScores();
        drawRound();

        window.display();
    }
}

void Table::handleMouseClick()
{
    if (gameOver)
        return;

    sf::FloatRect hitButtonBounds({73.0f, 369.0f}, {378.0f, 81.0f});
    sf::FloatRect standButtonBounds({748.0f, 369.0f}, {378.0f, 81.0f});
    sf::FloatRect nextRoundButtonBounds = {{973.f, 723.f}, {154.f, 61.f}};

    sf::Vector2f mousePos =
        static_cast<sf::Vector2f>(sf::Mouse::getPosition(window));
    bool mouseIsCurrentlyPressed =
        sf::Mouse::isButtonPressed(sf::Mouse::Button::Left);

    if (mouseIsCurrentlyPressed && !isMousePressed)
    {
        if (waitingToReset && nextRoundButtonBounds.contains(mousePos))
        {
            std::cout << "Next Round clicked\n";
            game.finishRound();
            waitingToReset = false;
            isMousePressed = mouseIsCurrentlyPressed;
            return;
        }

        if (!waitingToReset)
        {
            if (hitButtonBounds.contains(mousePos))
            {
                std::cout << "Hit clicked\n";
                game.playerHit();
            }
            else if (standButtonBounds.contains(mousePos))
            {
                std::cout << "Stand clicked\n";
                game.playerStand();
            }
        }
    }

    isMousePressed = mouseIsCurrentlyPressed;
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

    if (waitingToReset)
    {
        sf::RectangleShape nextRoundBtn({154.f, 61.f});
        nextRoundBtn.setFillColor(sf::Color(166, 153, 147));
        nextRoundBtn.setPosition({973.f, 723.f});
        window.draw(nextRoundBtn);

        sf::Text nextLabel(font);
        nextLabel.setString("Next Round");
        nextLabel.setCharacterSize(24);
        nextLabel.setFillColor(sf::Color::Black);

        auto nextBounds = nextLabel.getLocalBounds();
        nextLabel.setOrigin({nextBounds.position.x + nextBounds.size.x / 2.f,
                             nextBounds.position.y + nextBounds.size.y / 2.f});

        nextLabel.setPosition(nextRoundBtn.getPosition() +
                              nextRoundBtn.getSize() / 2.f);
        window.draw(nextLabel);
    }
}

void Table::drawScores()
{
    sf::Text scoreLabel(font);
    scoreLabel.setString("Score:\n " + std::to_string(game.getPlayerScore()) +
                         " - " + std::to_string(game.getDealerScore()));
    scoreLabel.setCharacterSize(36);
    scoreLabel.setFillColor(sf::Color::White);
    scoreLabel.setStyle(sf::Text::Bold);

    auto bounds = scoreLabel.getLocalBounds();
    scoreLabel.setOrigin({bounds.position.x + bounds.size.x / 2.f,
                          bounds.position.y + bounds.size.y / 2.f});

    sf::Vector2f boxPosition = {494.f, 366.f};
    sf::Vector2f boxSize = {225.f, 83.f};
    sf::Vector2f centerPosition = boxPosition + boxSize / 2.f;

    scoreLabel.setPosition(centerPosition);
    window.draw(scoreLabel);
}

void Table::drawRound()
{
    sf::Text roundLabel(font);

    if (gameOver)
    {
        int player = game.getPlayerScore();
        int dealer = game.getDealerScore();
        if (player > dealer)
            roundLabel.setString("Player Wins!");
        else if (dealer > player)
            roundLabel.setString("Dealer Wins!");
        else
            roundLabel.setString("Tie!");
    }
    else
        roundLabel.setString("Round " + std::to_string(game.getCurrentRound()) +
                             " / " + std::to_string(game.getRounds()));

    roundLabel.setCharacterSize(36);
    roundLabel.setFillColor(sf::Color::White);
    roundLabel.setStyle(sf::Text::Bold);

    auto bounds = roundLabel.getLocalBounds();
    roundLabel.setOrigin({bounds.position.x + bounds.size.x / 2.f,
                          bounds.position.y + bounds.size.y / 2.f});

    sf::Vector2f boxPos = {450.f, 22.f};
    sf::Vector2f boxSize = {299.f, 68.f};
    sf::Vector2f center = boxPos + boxSize / 2.f;

    roundLabel.setPosition(center);
    window.draw(roundLabel);
}
