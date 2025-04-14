#ifndef CARD_HPP
#define CARD_HPP

class Card
{
   protected:
    char card;
    int value;

   public:
    Card(char c, int v);
    char getCard();
    int getValue();
    void setValue(int v);
};

#endif
