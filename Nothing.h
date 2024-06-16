#ifndef NOTHING_H
#define NOTHING_H
#include "GameObject.h"

class Nothing: public GameObject{
    public:
        Nothing();
        ~Nothing();
        char getCharacter() override;

    private:
        char character = 'x'; //nothing character
};

#endif