#ifndef TABLE_HPP
#define TABLE_HPP

#include <SFML/Graphics.hpp>

#include "game.hpp"

class Table
{
   public:
    Table();
    void drawEmptyCards();
    void drawButtons();

   private:
    sf::RenderWindow window;
    sf::Font font;
    Game game;
};

#endif
