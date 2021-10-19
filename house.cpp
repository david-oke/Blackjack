// David Oke
// house.cpp
// House function definitions

#include <iostream>
#include "house.h"
#include "hand.h"
#include "card.h"

using namespace std;

void House::flipFirstCard(Hand h)
{
    cout << h.hand.at(0).getFace() << h.hand.at(0).getSuit() << " ";
}

bool House::isHitting(House &h, vector<Card> &houseHand)
{
    if(h.getTotalforHouse(houseHand) <= 16)
    {
        return true;
    }
    else
    {
        return false;
    }
}

void House::displayHouseHiddenHand(vector<Card> &hand)
{
    cout << "XX" << " ";

    for(size_t i{1}; i < hand.size(); i++)
    {
        cout << hand.at(i).getFaceNoAce() << hand.at(i).getSuit() << " ";
    }
}

void House::displayHouseHand(vector<Card> &hand)
{
    for(size_t i{0}; i < hand.size(); i++)
    {
        cout << hand.at(i).getFaceNoAce() << hand.at(i).getSuit() << " ";
    }
}
