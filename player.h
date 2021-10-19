// David Oke
// player.h
// Player data members and function prototypes

#ifndef PLAYER_H
#define PLAYER_H
#include "genericplayer.h"

using namespace std;

class Player : public GenericPlayer
{
    private:
    public:
        void win() const;
        void lose() const;
        void push() const;
};

#endif
