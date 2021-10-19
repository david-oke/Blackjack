// David Oke
// game.h
// Game data members and function prototypes

#ifndef GAME_H
#define GAME_H
#include "hand.h"
#include "player.h"

class Game : public Hand
{
    private:
    public:
        void play(int);
};

#endif
