// David Oke
// deck.h
// Deck data members and function prototypes

#ifndef DECK_H
#define DECK_H
#include <vector>
#include "card.h"

class Deck
{
    private:
    public:
        void populate(Deck &d);
        void shuffleCards(Deck &d);
        std::vector<Card>deck;
};

#endif
