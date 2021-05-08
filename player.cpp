#include "player.h"
#include <iostream>
#include <chrono>
#include <thread>


Player::Player(Deck& deck, bool isBank): m_deck(deck){
    m_deck = deck;
    m_isBank=isBank;
    m_Hand = Deck();
}

int Player::pointsOnHand(){
    int handSize= m_Hand.amountOfCards();
    int aceCounter=0;
    int points=0;
    for(int i=0;i<handSize;i++){
        if(m_Hand.card(i).value()==1){
            aceCounter++;
        }
        else if(m_Hand.card(i).value()!=1){
            points+=m_Hand.card(i).value();
        }
        if(aceCounter!=0){
            if((points+13+aceCounter)>21)
                points=points + 1;
            else points= points+13+aceCounter;
            aceCounter--;
        }
    }
    return points;
}

int Player::performRound(){
    std::string check;
    std::string play="y";
    std::string quit ="n";
    if(!m_isBank){
        while(true){
            if(pointsOnHand()>21){
                std::cout<< "You Bust!"<<std::endl;
                break;
            }
            if(pointsOnHand()==21){
                break;
            }
            if(m_Hand.amountOfCards()!=0){
            std::cout<< "Draw another card? (y/n)"<<std::endl;
            std::cin>>check;
            }
            else check="y";
            std::this_thread::sleep_for(std::chrono::seconds(2));
            if(check==play){
                Card drawnCard = m_deck.giveCard();
                m_Hand.placeCard(drawnCard);
                std::cout<< "You drew: "<< drawnCard.text()<<std::endl;
                 std::this_thread::sleep_for(std::chrono::seconds(1));
                std::cout<< "Your points: "<< pointsOnHand()<<std::endl;
                std::cout<<std::endl;


            }
            else if(check==quit){

                std::cout<< "You said no (y/n)"<<std::endl;
                break;
            }
            else
                std::cout<< "Input Error"<<std::endl;
        }
    }
    else
        while(pointsOnHand()<17){
            Card drawnCard = m_deck.giveCard();
            m_Hand.placeCard(drawnCard);
            std::this_thread::sleep_for(std::chrono::seconds(2));
            std::cout<< "Computer drew: "<< drawnCard.text()<<std::endl;
             std::this_thread::sleep_for(std::chrono::seconds(1));
            std::cout<< "Computers points "<< pointsOnHand()<<std::endl;
            std::cout<<std::endl;


        }

    return pointsOnHand();

}
//    else{

//    }

