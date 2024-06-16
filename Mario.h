#ifndef MARIO_H
#define MARIO_H

#include<iostream>
#include <fstream>
using namespace std;

class Mario{
    public:
        Mario();
        ~Mario();
        int instancesOf();
        void collectCoin();
        void currPowerLevel(ofstream &output); //outputs mario's current level
        char move(char*** &grid, int gridDimension, int currLevel, ofstream &output); //Mario's movements UP, DOWN, LEFT, RIGHT, STAY PUT
        void currCordinates(ofstream &output); //outputs Mario's current coordinates
        char warp(int x, int y, char*** &grid, int currLevel, ofstream &output); //Warps Mario to a new level & coordinate
        bool fightEnemy(char c, ofstream &output); 
        bool fightBoss(ofstream &output);
        void endGame(ofstream &output, int turnsTakens); //End game outro 
        void powerUp();
        void move();

    private:
        char character = 'H';
        int numLives;
        int coins;
        int powerLevel;
        int coordinates[2] = {0,0};
        int gridDimension;
        bool wonGame;
        int enemyDefeated;

    public:
        //helper fuctions!
        void setLives(int lives);
        char getCharacter();
        int getLives();
        void removeLive();
        int getCoins();
        void setXCoordinate(int x);
        void setYCoordinate(int y);
        int getXCoord();
        int getYCoord();
        void setWonGame(bool wonGame);
        bool getWonGame();

};

#endif