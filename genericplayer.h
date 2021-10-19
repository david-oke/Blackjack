// David Oke
// genericplayer.h
// GenericPlayer data members and function prototypes

#ifndef GENERICPLAYER_H
#define GENERICPLAYER_H
#include <vector>
#include "hand.h"

using namespace std;

class GenericPlayer : public Hand
{
    private:
    public:
        bool isBusted(int &valueTotal);
        void bust() const;

};

#endif
