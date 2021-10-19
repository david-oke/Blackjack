// David Oke
// OOP Blackjack Project
// August 1, 2020

#include <iostream>
#include "card.h"
#include "deck.h"
#include "game.h"
#include "genericplayer.h"
#include "hand.h"
#include "house.h"
#include "player.h"

using namespace std;

int main()
{
    Game g;
    int playerCount;
    int playResponse = 1;

    while(playResponse == 1)            // to allow the player to play again at the end
    {
        cout << "Welcome to Blackjack! Enter the number of players: ";
        cin >> playerCount;

        if(playerCount == 0)            // sanitization
        {
            cout << "You need at least one player. Enter the number of players: ";
            cin >> playerCount;
        }

        cout << endl << "Note:" <<endl <<endl << "Jack, Queen, and King cards will be denoted with '10' as this represents their value.";
        cout << endl << "If you draw an ace card, you will be given the option to pick its value as 1 or 11." <<endl <<endl;

        g.play(playerCount);

        cout << "Enter '1' to play again, or any other key to stop playing" <<endl;
        cin >> playResponse;
    }

    return 0;
}
