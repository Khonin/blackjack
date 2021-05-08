#include "card.h"

Card::Card(Suit suit, int value)
{
    m_suit = suit;
    m_value=value;

}

Card::Suit Card::suit(){
    return m_suit;
}

int Card::value(){
    return m_value;
}

std::string Card::text(){
    std::string textString;
    if(m_value==1)
        textString.append("Ace of ");
    else if(m_value>1 && m_value < 11)
        textString.append(std::to_string(m_value)+" of ");
    else if(m_value==11)
        textString.append("Jack of ");
    else if(m_value==12)
        textString.append("Queen of ");
    else if(m_value==13)
        textString.append("King of ");
    if(m_suit==0)
        textString.append("Clubs");
    else if(m_suit==1)
        textString.append("Diamonds");
    else if(m_suit==2)
        textString.append("Hearts");
    else if(m_suit==3)
        textString.append("Spades");
    return textString;
}
