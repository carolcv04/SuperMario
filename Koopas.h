#ifndef KOOPAS_H
#define KOOPAS_H

#include "GameObject.h"

class Koopas: public GameObject{

    public:
        Koopas();
        ~Koopas();
        char getCharacter() override;
    private:
        char character = 'k'; //koopa character
};

#endif