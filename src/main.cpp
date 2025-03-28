#include "game.cpp"


int main()
{
    Game blackjack;

    while (blackjack.isRunning())
    {
        blackjack.printGameState();
        blackjack.endRound();
    }

    return 0;
}
