#ifndef MUSHROOM_H
#define MUSHROOM_H

#include "GameObject.h"

class Mushroom: public GameObject{
    public:
        Mushroom();
        ~Mushroom();
        char getCharacter() override;

    private:
        char character = 'm'; //mushroom character
};

#endif