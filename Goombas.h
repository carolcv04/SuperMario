#ifndef GOOMBAS_H
#define GOOMBAS_H
#include "GameObject.h"

class Goombas: public GameObject{

    public:
        Goombas();
        ~Goombas();
        char getCharacter() override; //access character
    private:
        char character = 'g'; //goomba character
};

#endif