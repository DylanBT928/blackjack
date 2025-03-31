#include "game.cpp"

int main()
{
    Game blackjack(10);

    while (blackjack.isRunning())
    {
        blackjack.playRound();
    }

    return 0;
}
