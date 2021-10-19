// David Oke
// card.cpp
// Card class function definitions

#include <iostream>
#include "card.h"
#include <ctime>
#include <cstdlib>

using namespace std;

Card::Card(int f, char s)       // constructor
{
    face = f;
    suit = s;
}
void Card::setCard(int f, char s)
{
    face = f;
    suit = s;
}
int Card::getFace()     // returns the face value of the card
{
    if(face == 1)       // offer option for 1/11 for ace cards
    {
        int userResponse;
        //cout <<endl;
        cout << "Ace: ";
        cout << "'1'/'11' ";
        cin >> userResponse;

        if(userResponse == 1)
        {
            face = 1;
        }
        else if(userResponse == 11)
        {
            face = 11;
        }
        else                            // sanitization
        {
            cout << "Enter '1' or '11' " <<endl;
            cin >> userResponse;
        }
    }

    faceValue = face;
    return face;
}

int Card::getFaceForValue()     // gets the value of the face of the card (to be used in various intermediary steps during the game)
{
    return faceValue;
}

int Card::getFaceNoAce()        // returns the face value of the card for the house with automated pick for ace (1/11)
{

    if(face == 1)
    {
        int x;
        srand(time(NULL));
        x = rand()%(10-1+1)+1;

        if(x >= 5)
        {
            face = 1;
        }
        else
        {
            face = 11;
        }
    }

    return face;
}

char Card::getSuit()        // returns the suit of the card
{
    return suit;
}
