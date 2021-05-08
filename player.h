#ifndef PLAYER_H
#define PLAYER_H
#include <deck.h>


class Player
{
public:
    Player(Deck& deck, bool isBank);
    int performRound();

private:
    int pointsOnHand();
    bool m_isBank;
    Deck& m_deck;
    Deck m_Hand;
};

#endif // PLAYER_H
