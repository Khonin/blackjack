#include "deck.h"
#include <cassert>

Deck::Deck()
{
    std::vector<Card> deck;
    m_deck = deck;
}

void Deck::clear(){
    m_deck.clear();
}

int Deck::amountOfCards(){
    return m_deck.size();
}
Card Deck::card(int i){
    assert(i<m_deck.size());
    return m_deck[i];
}

Card Deck::giveCard(){
    assert(m_deck.size()!=0);
    Card temp=m_deck[0];
    m_deck.erase(m_deck.begin());
    return temp;
}

void Deck::placeCard(Card card){
    m_deck.push_back(card);
}

void Deck::restartDeck(){
    m_deck.clear();
    for(int j=1;j<14;j++){
        Card card(Card::Clubs,j);
        m_deck.push_back(card);
    }
    for(int j=1;j<14;j++){
        Card card(Card::Diamonds,j);
        m_deck.push_back(card);
    }
    for(int j=1;j<14;j++){
        Card card(Card::Hearts,j);
        m_deck.push_back(card);
    }
    for(int j=1;j<14;j++){
        Card card(Card::Spades,j);
        m_deck.push_back(card);
    }
    shuffle();



}

void Deck::shuffle(){
    srand(time(nullptr));
    for(int i=0;i<52;i++){
        int random = rand()%52;
        while(random==i)
            random = rand()%52;
        std::swap(m_deck[i],m_deck[random]);
    }
}
