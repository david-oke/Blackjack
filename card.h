// David Oke
// card.h
// Card data members and function prototypes

#ifndef CARD_H
#define CARD_H

class Card
{
    private:
        char suit;
        int face;
        int faceValue;
  public:
        void setCard(int, char);
        int getFace();
        char getSuit();
        int getFaceForValue();
        int getFaceNoAce();
        Card(int = 0, char = ' ');
};








#endif
