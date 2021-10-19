// David Oke
// hand.cpp
// Hand function definitions

#include <iostream>
#include <vector>
#include "deck.h"
#include "hand.h"
#include "card.h"
#include "player.h"

using namespace std;

void Hand::add(vector<Card> &hand, Deck &d)     // Adds a card to the hand, (removes card from deck)
{
    hand.push_back(d.deck.at(0));
    d.deck.erase(d.deck.begin());
}

int Hand::getTotal(vector<Card> &hand)      // Returns total value of the hand
{
    int valueTotal{0};

    for(size_t i{0}; i < hand.size(); i++)
    {
        valueTotal += hand.at(i).getFaceForValue();
    }

    return valueTotal;
}

int Hand::getTotalforHouse(vector<Card> &hand)      // Returns total value of the hand of the house
{
    int valueTotal{0};

    for(size_t i{0}; i < hand.size(); i++)
    {
        valueTotal += hand.at(i).getFace();
    }

    return valueTotal;
}

void Hand::displayHand(vector<Card> &hand)      // Displays the cards of a hand
{
    for(size_t i{0}; i < hand.size(); i ++)
    {
        cout << hand.at(i).getFace() << hand.at(i).getSuit() << " ";
    }
}

void Hand::houseCompare(int &playerTotal, int &houseTotal)      // Compares the hand total value of a player and the house
{
    Player p;
    if(playerTotal > houseTotal)
    {
        p.win();
    }
    else if(playerTotal < houseTotal)
    {
        p.lose();
    }
    else
    {
        p.push();
    }
}
