#include <algorithm>
#include <iostream>
#include <random>
#include "card.cpp"


class Game
{
protected:
    std::vector<Card> deck = {};
    std::vector<Card> dealerHand = {};
    std::vector<Card> playerHand = {};
    bool running = true;
    int rounds = 1;


    void makeDeck()
    {
        deck = {
            Card('K', 10), Card('K', 10), Card('K', 10), Card('K', 10),
            Card('Q', 10), Card('Q', 10), Card('Q', 10), Card('Q', 10),
            Card('J', 10), Card('J', 10), Card('J', 10), Card('J', 10),
            Card('T', 10), Card('T', 10), Card('T', 10), Card('T', 10),
            Card('9', 9), Card('9', 9), Card('9', 9), Card('9', 9),
            Card('8', 8), Card('8', 8), Card('8', 8), Card('8', 8),
            Card('7', 7), Card('7', 7), Card('7', 7), Card('7', 7),
            Card('6', 6), Card('6', 6), Card('6', 6), Card('6', 6),
            Card('5', 5), Card('5', 5), Card('5', 5), Card('5', 5),
            Card('4', 4), Card('4', 4), Card('4', 4), Card('4', 4),
            Card('3', 3), Card('3', 3), Card('3', 3), Card('3', 3),
            Card('2', 2), Card('2', 2), Card('2', 2), Card('2', 2),
            Card('A', 1), Card('A', 1), Card('A', 1), Card('A', 1),
        };
    }


    void shuffleDeck()
    {
        std::random_device rd;
        std::mt19937 generator(rd());
        std::shuffle(deck.begin(), deck.end(), generator);
    }


public:
    explicit Game(int r = 1) : rounds(r)
    {
        makeDeck();
        shuffleDeck();
    }


    std::vector<Card> getDeck()
    {
        return deck;
    }


    std::vector<Card> getDealerHand()
    {
        return dealerHand;
    }


    std::vector<Card> getPlayerHand()
    {
        return playerHand;
    }


    bool isRunning()
    {
        if (rounds == 0)
            running = false;
        return running;
    }


    int getRounds()
    {
        return rounds;
    }


    void endRound()
    {
        rounds--;
    }


    void printGameState()
    {
        std::cout << "Deck: ";
        for (auto &card : deck)
        {
            std::cout << card.getCard() << ' ';
        }
        std::cout << '\n';

        std::cout << "Cards Left: " << deck.size() << std::endl;

        std::cout << "Dealer's Hand: ";
        for (auto &card : dealerHand)
        {
            std::cout << card.getCard() << ' ';
        }
        std::cout << '\n';

        std::cout << "Your Hand: ";
        for (auto &card : playerHand)
        {
            std::cout << card.getCard() << ' ';
        }
        std::cout << '\n';
    }
};
