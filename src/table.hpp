#ifndef TABLE_HPP
#define TABLE_HPP

#include <SFML/Graphics.hpp>

#include "game.hpp"

class Table
{
   public:
    Table();
    void handleMouseClick();
    void drawEmptyCards();
    void drawButtons();
    void drawScores();
    void drawRound();

   private:
    sf::RenderWindow window;
    sf::Font font;
    Game game;
    bool isMousePressed;
    bool waitingToReset;
    bool gameOver;
};

#endif
