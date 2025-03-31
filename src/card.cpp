class Card
{
   protected:
    char card;
    int value;

   public:
    Card(char c, int v) : card(c), value(v) {}

    char getCard() { return card; }

    int getValue() { return value; }
};
