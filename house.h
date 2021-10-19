// David Oke
// house.h
// House data members and function prototypes

#ifndef HOUSE_H
#define HOUSE_H
#include "genericplayer.h"

class House : public GenericPlayer
{
    private:
    public:
        void flipFirstCard(Hand);
        bool isHitting(House &h, vector<Card> &houseHand);
        void displayHouseHiddenHand(vector<Card> &hand);
        void displayHouseHand(vector<Card> &hand);
};

#endif
