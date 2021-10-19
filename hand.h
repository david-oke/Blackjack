// David Oke
// hand.h
// Hand data members and function prototypes

#ifndef HAND_H
#define HAND_H
#include <vector>
#include "card.h"
#include "deck.h"

using namespace std;

class Hand : public Deck
{
    private:
    public:
        vector<Card>hand;
        void add(vector<Card> &hand, Deck &d);
        int getTotal(vector<Card> &hand);
        void displayHand(vector<Card> &hand);
        void houseCompare(int &playerTotal, int &houseTotal);
        int getTotalforHouse(vector<Card> &hand);

};

#endif
