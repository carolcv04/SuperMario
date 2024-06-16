#ifndef BOSS_H
#define BOSS_H

#include "GameObject.h"

class Boss : public GameObject{
    public:
        Boss();
        ~Boss();
        char getCharacter() override; //get boss character
        int instancesOf() override; //instances of boss on grid
    private:
        char character = 'b';
    
};

#endif