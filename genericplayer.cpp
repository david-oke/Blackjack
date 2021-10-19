// David Oke
// genericplayer.cpp
// GenericPlayer function definitions

#include <iostream>
#include <vector>
#include "genericplayer.h"
#include "hand.h"
#include "card.h"

using namespace std;

bool GenericPlayer::isBusted(int &valueTotal)
{
    if(valueTotal > 21)
    {
        return true;
    }
    else
    {
        return false;
    }
}
void GenericPlayer::bust() const
{
    cout << "Your total exceeded 21 so you have busted and lost." <<endl;
}

