#include "game.cpp"

int main()
{
    Game blackjack(10);

    while (blackjack.isRunning())
    {
        blackjack.playRound();
    }

    blackjack.endGame();

    return 0;
}
