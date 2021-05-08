#ifndef DECK_H
#define DECK_H
#include <vector>
#include <card.h>
#include <ctime>

class Deck
{
public:
    Deck();
    void clear();
    int amountOfCards();
    Card card(int value);
    Card giveCard();
    void placeCard(Card card);
    void restartDeck();
    void shuffle();

private:
    std::vector<Card> m_deck;

};

#endif // DECK_H
