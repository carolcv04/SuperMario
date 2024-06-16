#include "Level.h"

Level::Level(){

}
Level::~Level(){

}
void Level::setLevels(int levels){
    numLevels = levels; 
}

int Level::getLevels(){
    return numLevels;
}