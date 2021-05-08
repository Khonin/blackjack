#ifndef CARD_H
#define CARD_H
#include <string>


class Card
{
public:
    enum Suit{
        Clubs, Diamonds, Hearts, Spades
    };
    Card(Suit suit, int value);
    Suit suit();
    int value();
    std::string text();

private:
    Suit m_suit;
    int m_value;
};

#endif // CARD_H
