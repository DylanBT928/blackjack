#include <algorithm>
#include <iostream>
#include <random>
#include "card.cpp"


std::vector<Card> makeDeck();
std::vector<Card> shuffleDeck(std::vector<Card> deck);


int main()
{
    std::vector<Card> deck = shuffleDeck(makeDeck());

    std::cout << "Deck: ";
    for (auto &card : deck)
    {
        std::cout << card.getCard() << ' ';
    }
    std::cout << '\n';

    std::cout << "Cards Left: " << deck.size() << std::endl;
    std::cout << "Dealer's Hand: " << std::endl;
    std::cout << "Your Hand: " << std::endl;

    return 0;
}


std::vector<Card> makeDeck()
{
    return {
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


std::vector<Card> shuffleDeck(std::vector<Card> deck)
{
    std::random_device rd;
    std::mt19937 generator(rd());
    std::shuffle(deck.begin(), deck.end(), generator);
    return deck;
}
