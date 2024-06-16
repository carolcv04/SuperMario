#include "Boss.h"

Boss::Boss(){}

Boss::~Boss(){}

int Boss::instancesOf(){
    return 1; //one instance of boss per grid
}

char Boss::getCharacter(){
    return 'b'; //boss character
}