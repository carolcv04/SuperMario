#ifndef WARPPIPE_H
#define WARPPIPE_H

#include "GameObject.h"

class WarpPipe: public GameObject{
    public:
        WarpPipe();
        ~WarpPipe();
        char getCharacter() override;
        int instancesOf() override;
    private:
        char character = 'w'; //warp pipe character
};

#endif