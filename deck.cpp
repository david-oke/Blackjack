// David Oke
// deck.cpp
// Deck function definitions

#include <iostream>
#include <vector>
#include <algorithm>
#include <chrono>       // To shuffle deck
#include <random>       // To shuffle deck
#include "deck.h"
#include "card.h"

using namespace std;

void Deck::populate(Deck &d)    // creates a standard deck of 52 cards
{
    Card c;
    int j;

    for(int i{0}; i <= 12; i++)
    {      
        if(i >= 10)             // Jack, Queen, King cards all denoted as '10'
        {
            j = 9;
        }
        else                    // Number cards denoted as their number
        {
            j = i;
        }

        c.setCard(j+1, 'H');
        d.deck.push_back(c);
        d.deck.at(i) = c;
    }
    for(int i{13}; i <= 25; i++)
    {
        if(i >= 22)
        {
            j = 22;
        }
        else
        {
            j = i;
        }

        c.setCard(j-12, 'S');
        d.deck.push_back(c);
        d.deck.at(i) = c;
    }
    for(int i{26}; i <= 38; i++)
    {
        if(i >= 35)
        {
            j = 35;
        }
        else
        {
            j = i;
        }

        c.setCard(j-25, 'D');
        d.deck.push_back(c);
        d.deck.at(i) = c;
    }
    for(int i{39}; i <= 51; i++)
    {
        if(i >= 48)
        {
            j = 48;
        }
        else
        {
            j = i;
        }
        c.setCard(j-38, 'C');
        d.deck.push_back(c);
        d.deck.at(i) = c;
    }
}

void Deck::shuffleCards(Deck &d)        // Shuffles cards in deck
{
    unsigned seed = chrono::system_clock::now().time_since_epoch().count();
    shuffle (d.deck.begin(), d.deck.end(), default_random_engine(seed));
}

