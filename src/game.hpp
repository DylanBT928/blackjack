#ifndef GAME_HPP
#define GAME_HPP

#include <algorithm>
#include <iostream>
#include <random>

#include "card.hpp"

class Game
{
   private:
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

   public:
    Game(int r = 1);
    std::vector<Card> getDeck();
    std::vector<Card> getDealerHand();
    std::vector<Card> getPlayerHand();
    bool isRunning();
    int getCurrentRound();
    int getRounds();
    int getDealerScore();
    int getPlayerScore();
    bool getStand();
    void makeDeck();
    void shuffleDeck();
    void hit(std::vector<Card> &hand);
    void resetRound();
    void playRound();
    int chooseWinner();
    void printWinner(int winner);
    void printScores();
    void printDeck();
    void printHand(std::vector<Card> hand);
    int getHandTotal(std::vector<Card> hand);
    void printHandTotal(std::vector<Card> hand);
    void printGameState();
    void playGame();
    void endGame();
};

#endif
