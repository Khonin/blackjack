#include <iostream>
#include <time.h>
#include <card.h>
#include <deck.h>
#include <player.h>
#include <iostream>

using namespace std;

int main()
{
//    Deck testDeck;
//    testDeck.restartDeck();
//    Player testPlayer(testDeck,false);
//    testPlayer.performRound();


    cout << "Welcome to the Casino"<<endl;


//    srand(time(0));


    while(true){
        string userInput;
        cout<<"New Game? (y/n)"<<endl;
        cin >> userInput;
        bool boolFromUser=true;
        if(userInput=="n")
           boolFromUser=false;
        else if(userInput!="y"){
            cout<<"New Game? (y/n)"<<endl;
            cin >> userInput;
        }
        if(!boolFromUser)
        break;
        Deck deck;
        Player player(deck, false);
        Player bank(deck, true);
        deck.restartDeck();
        deck.shuffle();

        int playerPoints = player.performRound();
        if(playerPoints>21)
            break;
        else if(playerPoints==21)
            cout << "YOU WIN!"<< endl;
        else{
            int bankPoints = bank.performRound();
            if(bankPoints<21 && bankPoints>=playerPoints)
                cout << "YOU LOSE!"<<endl;
            else cout << "YOU WIN!"<<endl;
        }
    }
return 0;
}
