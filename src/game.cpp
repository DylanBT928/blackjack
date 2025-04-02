#include <algorithm>
#include <iostream>
#include <random>

#include "card.cpp"

class Game
{
   protected:
    std::vector<Card> deck;
    std::vector<Card> dealerHand;
    std::vector<Card> playerHand;
    int currentRound;
    int rounds;
    int dealerScore;
    int playerScore;
    bool stand;

    void makeDeck()
    {
        deck = {Card('K', 10), Card('K', 10), Card('K', 10), Card('K', 10),
                Card('Q', 10), Card('Q', 10), Card('Q', 10), Card('Q', 10),
                Card('J', 10), Card('J', 10), Card('J', 10), Card('J', 10),
                Card('T', 10), Card('T', 10), Card('T', 10), Card('T', 10),
                Card('9', 9),  Card('9', 9),  Card('9', 9),  Card('9', 9),
                Card('8', 8),  Card('8', 8),  Card('8', 8),  Card('8', 8),
                Card('7', 7),  Card('7', 7),  Card('7', 7),  Card('7', 7),
                Card('6', 6),  Card('6', 6),  Card('6', 6),  Card('6', 6),
                Card('5', 5),  Card('5', 5),  Card('5', 5),  Card('5', 5),
                Card('4', 4),  Card('4', 4),  Card('4', 4),  Card('4', 4),
                Card('3', 3),  Card('3', 3),  Card('3', 3),  Card('3', 3),
                Card('2', 2),  Card('2', 2),  Card('2', 2),  Card('2', 2),
                Card('A', 1),  Card('A', 1),  Card('A', 1),  Card('A', 1)};
    }

    void shuffleDeck()
    {
        std::random_device rd;
        std::mt19937 generator(rd());
        std::shuffle(deck.begin(), deck.end(), generator);
    }

   public:
    explicit Game(int r = 1)
        : rounds(r),
          currentRound(1),
          dealerScore(0),
          playerScore(0),
          stand(false)
    {
        makeDeck();
        shuffleDeck();
        resetRound();
    }

    std::vector<Card> getDeck() { return deck; }

    std::vector<Card> getDealerHand() { return dealerHand; }

    std::vector<Card> getPlayerHand() { return playerHand; }

    bool isRunning() { return currentRound <= rounds; }

    int getCurrentRound() { return currentRound; }

    int getRounds() { return rounds; }

    int getDealerScore() { return dealerScore; }

    int getPlayerScore() { return playerScore; }

    bool getStand() { return stand; }

    void hit(std::vector<Card> &hand)
    {
        hand.push_back(deck.back());
        deck.pop_back();
    }

    void resetRound()
    {
        dealerHand.clear();
        playerHand.clear();
        hit(playerHand);
        hit(dealerHand);
        hit(playerHand);
        hit(dealerHand);
    }

    void playRound()
    {
        char choice;
        stand = false;
        while (!stand)
        {
            printGameState();
            std::cout << "Hit or stand? (h/s): ";
            std::cin >> choice;
            if (tolower(choice) == 'h')
            {
                hit(playerHand);
            }
            else if (tolower(choice) == 's')
            {
                chooseWinner();
                stand = true;
                currentRound++;
                resetRound();
            }
        }
    }

    void chooseWinner()
    {
        if (getHandTotal(playerHand) == getHandTotal(dealerHand))
            ;  // TODO: handle double down
        else if (getHandTotal(playerHand) > getHandTotal(dealerHand))
            playerScore++;
        else
            dealerScore++;
    }

    void printScores()
    {
        std::cout << " (" << playerScore << '-' << dealerScore << ")\n";
    }

    void printDeck()
    {
        std::cout << "Deck: ";
        for (auto &card : deck)
        {
            std::cout << card.getCard() << ' ';
        }
        std::cout << '\n';
    }

    void printHand(std::vector<Card> hand)
    {
        for (auto &card : hand)
        {
            std::cout << card.getCard() << ' ';
        }
        std::cout << '\n';
    }

    int getHandTotal(std::vector<Card> hand)
    {
        int total = 0;
        for (auto &card : hand)
        {
            total += card.getValue();
        }
        return total;
    }

    void printHandTotal(std::vector<Card> hand)
    {
        std::cout << "Total: " << getHandTotal(hand) << std::endl;
    }

    void printGameState()
    {
        std::cout << "\nRound " << currentRound << '/' << rounds;
        printScores();

        printDeck();

        std::cout << "Cards Left: " << deck.size() << std::endl;

        std::cout << "Your Hand: ";
        printHand(playerHand);
        printHandTotal(playerHand);

        std::cout << "Dealer's Hand: ";
        printHand(dealerHand);
        printHandTotal(dealerHand);
    }
};
