#include <iostream>


class Card
{
public:
    std::string card;
    int value;


    Card(char c, int v)
    {
        card = c;
        value = v;
    }


    std::string getCard()
    {
        return card;
    }


    int getValue()
    {
        return value;
    }
};
