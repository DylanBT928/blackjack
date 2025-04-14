#include "card.hpp"

Card::Card(char c, int v) : card(c), value(v) {}

char Card::getCard() { return card; }

int Card::getValue() { return value; }

void Card::setValue(int v) { value = v; }
