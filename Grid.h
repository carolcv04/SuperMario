#ifndef GRID_H
#define GRID_H

#include "Boss.h"
#include "Koopas.h"
#include "Mushroom.h"
#include "Coin.h"
#include "WarpPipe.h"
#include "Level.h"
#include "Mario.h"
#include "Goombas.h"
#include "Nothing.h"

#include <fstream>
#include<iostream>
#include <stdlib.h>

class World; 

using namespace std;

class Grid{

    public:
        Grid();
        ~Grid();
        Grid(string fileName, string logFileName);
        void setPercentages(string fileName); //sets the percentages of all members
        void print(Level *L, int row, int column, ofstream &output); //prints the world
        void insertCharacter(GameObject *o, int level, char*** grid); //inserts a character on the grid on a random position
        void randomPosition(char c, int level, char*** grid); //selects a random position for the character
        int getGridSize(); //grid dimension

    private:
        GameObject* k;
        GameObject* b;
        GameObject* c;
        GameObject* w;
        GameObject* m;
        GameObject* n;
        World* world;
        Level* L;
        Mario* H;
        GameObject* g;
        char*** grid;
        int row, column, value;
        ifstream percentageFile;
        int gridDimension;
};

#endif