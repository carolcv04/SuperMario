#ifndef COIN_H
#define COIN_H
#include "GameObject.h"

class Coin : public GameObject {
    public:
        Coin();
        ~Coin(); 
        char getCharacter() override;   
    private:
        char character = 'c'; //coin character
    
};
#endif