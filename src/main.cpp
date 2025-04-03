#include "game.cpp"

int main()
{
    Game blackjack(10);

    while (blackjack.isRunning())
    {
        blackjack.playRound();
    }

    std::cout << "Game Over!" << std::endl;

    return 0;
}
