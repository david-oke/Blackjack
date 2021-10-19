// David Oke
// player.cpp
// Player function definitions

#include <iostream>
#include "player.h"
#include "genericplayer.h"

using namespace std;

void Player::win() const                // Win message
{
    cout << endl << " You have won!" <<endl;
}

void Player::lose() const               // Loss message
{
    cout << " You have lost." <<endl;
}

void Player::push() const               // Push message
{
    cout << " You have pushed." <<endl;
}
