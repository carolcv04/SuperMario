#ifndef WORLD_H
#define WORLD_H
#include <stdlib.h>
#include <fstream>
#include "Mario.h"
#include "Level.h"

class World{
    public:
        World();
        ~World();
        World(char*** grid, int gridDimension, Mario* H, Level* L, ofstream &output); //World of Mario
        void printWorld(int currLevel, ofstream &output); //prints the current Mario world level
        void setGrid(char*** worldGrid); //sets the grid for future use
        void setDimension(int gridDimension); // sets the grid dimension for future use
        int randomXCoord();
        int randomYCoord();
    private:
        bool endGame = false;
        char*** worldGrid;
        int gridDimension;
        char currentWorldChar;
        int currLevel = 0;
        int turnsTaken;
};
#endif