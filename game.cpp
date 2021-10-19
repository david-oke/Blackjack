// David Oke
// game.cpp
// Game function definitions
// Includes general flow of blackjack round

#include <iostream>
#include <vector>
#include "game.h"
#include "player.h"
#include "house.h"


void Game::play(int numOfPlayers)           // Plays a round of blackjack
{
    vector<Player> playerList;              // Stores each player
    Player p;
    Deck d;
    House h;
    int hitResponse, valueTotal, houseTotal;

    d.populate(d);
    d.shuffleCards(d);

    h.add(h.hand, d);               // Adds two cards to the house's hand
    h.add(h.hand, d);

    for(int i{0}; i < numOfPlayers; i++)        // Adds a Player class for each player playing
    {
        playerList.push_back(p);
    }

    for(size_t i{0}; i < playerList.size(); i++)        // Adds two cards to each player's hand
    {
        playerList.at(i).add(playerList.at(i).hand, d);
        playerList.at(i).add(playerList.at(i).hand, d);
    }

    cout << "House: ";
    h.displayHouseHiddenHand(h.hand);                       // Displays house's hand with hidden card
    cout << endl;

    for(size_t i{0}; i < playerList.size(); i++)            // Displays each player's hand
    {
        cout << "Player " << i+1 << ": ";
        playerList.at(i).displayHand(playerList.at(i).hand);
        cout << " value: (";
        cout << playerList.at(i).getTotal(playerList.at(i).hand);
        cout << ")";
        cout <<endl;
    }

    for(size_t i{0}; i < playerList.size(); i++)            // Asks player if they want to hit or not
    {
        valueTotal = 0;
        cout << endl << "Player " << i+1 << " do you want a hit?" <<endl;
        cout << "(1) yes (2) no: ";
        cin >> hitResponse;

        while(playerList.at(i).isBusted(valueTotal) == false)       // To stop running if the player busts
        {
            if(hitResponse == 1)                                    // Adds card to hand and displays hand
            {
                playerList.at(i).add(playerList.at(i).hand, d);
                playerList.at(i).displayHand(playerList.at(i).hand);
                cout << " value: (" << playerList.at(i).getTotal(playerList.at(i).hand) << ")" <<endl;

                valueTotal = playerList.at(i).getTotal(playerList.at(i).hand);

                if(playerList.at(i).isBusted(valueTotal) == false)      // Asks for additional hits
                {
                    cout << "Do you want another hit? ";
                    cin >> hitResponse;
                }
                else if(playerList.at(i).isBusted(valueTotal) == true)  // Stops the iteration if the player busts
                {
                    playerList.at(i).bust();
                    break;
                }
            }
            else if(hitResponse == 2)                       // Stops the iteration if the player does not want to hit
            {
                playerList.at(i).displayHand(playerList.at(i).hand);
                cout << " value: (" << playerList.at(i).getTotal(playerList.at(i).hand) << ")" <<endl;
                break;
            }
            else            // sanitization
            {
                cout << "Please enter (1) yes or (2) no." <<endl;
                cin >> hitResponse;
            }
        }
    }


    cout << endl << "House: ";
    h.displayHouseHand(h.hand);         // Displays the house's hand with revealed card
    cout << " value: (";
    cout << h.getTotalforHouse(h.hand);
    cout << ")";
    cout <<endl;

    while(h.isHitting(h, h.hand) == true)       // Adds cards to house's hand until 16 is reached
    {
        h.add(h.hand, d);
        cout <<endl << "House is hitting...";
        cout << endl << "House: ";
        h.displayHouseHand(h.hand);
        cout << " value: (";
        cout << h.getTotalforHouse(h.hand);
        cout << ")";
        cout <<endl;
    }

    houseTotal = h.getTotalforHouse(h.hand);

    if(h.isBusted(houseTotal) == true)      // If the house busts
    {
        h.bust();
        for(size_t i{0}; i < playerList.size(); i++)        // Checks for the players who did not bust
        {
            valueTotal = 0;
            valueTotal = playerList.at(i).getTotal(playerList.at(i).hand);

            if(playerList.at(i).isBusted(valueTotal) == false)
            {
                cout << endl << "Player " << i+1 << ":";
                playerList.at(i).win();
                cout <<endl;
            }
        }
    }
    else if(h.isBusted(houseTotal) == false)            // If the house does not bust
    {
        for(size_t i{0}; i < playerList.size(); i++)    // Checks if the other players beat the house or lost
        {
            valueTotal = 0;
            valueTotal = playerList.at(i).getTotal(playerList.at(i).hand);

            if(playerList.at(i).isBusted(valueTotal) == false)
            {
                cout << endl << "Player " << i+1 << ":";
                playerList.at(i).houseCompare(valueTotal, houseTotal);
                cout <<endl;
            }
        }
    }

}
