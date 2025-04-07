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
    bool playerBust;
    bool dealerBust;
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
          dealerBust(0),
          playerBust(0),
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
        if (deck.empty())
        {
            makeDeck();
            shuffleDeck();
        }
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
        int winner;
        char choice;
        stand = false;
        while (!stand && playerHand.size() < 5)
        {
            printGameState();
            if (playerHand.size() >= 5)
            {
                break;
            }
            std::cout << "Hit or stand? (h/s): ";
            std::cin >> choice;
            if (tolower(choice) == 'h')
            {
                hit(playerHand);
                if (getHandTotal(playerHand) > 21)
                {
                    playerBust = true;
                    std::cout << "Player busted.\n";
                    break;
                }
            }
            else if (tolower(choice) == 's')
            {
                stand = true;
            }
            if (getHandTotal(dealerHand) <= 16)
            {
                hit(dealerHand);
                if (getHandTotal(dealerHand) > 21)
                {
                    dealerBust = true;
                    std::cout << "Dealer busted.\n";
                    break;
                }
            }
        }
        while (getHandTotal(dealerHand) <= 16 && !playerBust)
        {
            if (getHandTotal(dealerHand) <= 16)
            {
                hit(dealerHand);
                if (getHandTotal(dealerHand) > 21)
                {
                    dealerBust = true;
                    std::cout << "Dealer busted.\n";
                    break;
                }
            }
        }
        winner = chooseWinner();
        if (winner == 0)
        {
            playerScore++;
        }
        else if (winner == 1)
        {
            dealerScore++;
        }
        printWinner(winner);
        currentRound++;
        resetRound();
    }

    int chooseWinner()
    {
        // Player: 0, Dealer: 1, Tie: -1
        if (playerBust)
        {
            playerBust = false;
            return 1;
        }
        else if (dealerBust)
        {
            dealerBust = false;
            return 0;
        }
        else
        {
            if (getHandTotal(playerHand) > getHandTotal(dealerHand) ||
                playerHand.size() >= 5)

            {
                return 0;
            }
            else if (getHandTotal(playerHand) < getHandTotal(dealerHand))
            {
                return 1;
            }
        }
        return -1;
    }

    void printWinner(int winner)
    {
        std::cout << "\nWinner: ";
        if (winner == 0)
        {
            std::cout << "Player ";
        }
        else if (winner == 1)
        {
            std::cout << "Dealer ";
        }
        else
        {
            std::cout << "Tie ";
        }
        std::cout << '(' << getHandTotal(playerHand) << '/'
                  << getHandTotal(dealerHand) << ")\n";
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
            if (card.getCard() == 'A')
            {
                if (total + 10 <= 21)
                {
                    card.setValue(11);
                }
                else
                {
                    card.setValue(1);
                }
            }
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

    void playGame()
    {
        while (isRunning())
        {
            playRound();
        }
        endGame();
    }

    void endGame()
    {
        std::cout << "Game Over! " << std::endl;
        std::cout << playerScore << '-' << dealerScore << std::endl;
    }
};
