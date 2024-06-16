#ifndef LEVEL_H
#define LEVEL_H
#include<iostream>

class Level{
    public:
        Level();
        ~Level();
        void setLevels(int levels); //sets number of levels
        int getLevels(); //gets number of levels
    private:
        int numLevels;
};

#endif