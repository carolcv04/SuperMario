#include "World.h"
using namespace std;

World::World(){}

World::~World(){}

World::World(char*** grid, int gridDimension, Mario* H, Level* L, ofstream &outputFile){
    setGrid(grid); //sets the grid for future use
    setDimension(gridDimension); //sets the grid dimension value for future use

    char x = 'E'; //allows to replace/keep certain characters on the grid. E for Error 
    currLevel = 0; //starting level

    //Random row & column
    int randRow = rand() % gridDimension; 
    int randCol = rand() % gridDimension;

    //Sets random row & column
    H->setXCoordinate(randRow); 
    H->setYCoordinate(randCol);

    //saves the current world character
    currentWorldChar = worldGrid[currLevel][randRow][randCol];

    outputFile << "Mario is starting in position: ";
    H->currCordinates(outputFile); //outputs Mario's coordinates
    outputFile << endl;

    //places Mario on the grid
    worldGrid[currLevel][randRow][randCol] = H->getCharacter();    
    outputFile << "===============================" << endl;

    while(endGame == false){ //Loops until the game has eneded
        bool won;
        printWorld(currLevel, outputFile); //prints the current level world

        outputFile << "Level: " << currLevel << ". "; //current level
        outputFile << "Mario is at position: ";
        H->currCordinates(outputFile); // Mario's current coordiates

        //mario position 
        switch(currentWorldChar){

            //Searhes to see what game object mario is interacting with
            case 'w': 
            //warp pipe
                outputFile << "Mario found a warp pipe. ";
                currLevel++; //Mario moves onto next level
                break;

            case 'x':
            //nothing happens
                outputFile << "Mario visited an empty space. ";
                x = 'x';
                break;

            case 'm':
            //mushroom
                outputFile << "Mario ate a mushroom. ";
                H->powerUp(); //Mario gains a power level
                x = 'x';
                break;

            case 'k':
            //koopa
                won = H->fightEnemy(currentWorldChar, outputFile); // Mario fights the enemy

                if (won) {
                    x = 'x'; // if he wins the spot is replaced with nothing
                } else {
                    // Mario loses the fight
                    x = 'k'; // koopa remains on the grid
                }

                if (H->getLives() == -1) {
                    // Mario has lost all lives, end the game
                    H->setWonGame(false);
                    endGame = true;
                }
                break;

            case 'g':
            //goomba
                won = H->fightEnemy(currentWorldChar, outputFile); // Mario fights the enemy

                if (won) {
                    x = 'x'; //if he wins the spot is replaced with nothing
                } else {
                    // Mario loses the fight
                    x = 'g'; // goomba remains on the grid
                }

                if (H->getLives() == -1) {
                    // Mario has lost all lives, end the game
                    H->setWonGame(false);
                    endGame = true;
                }
                break;

            case 'c':
            //coin
                outputFile << "Mario collected a coin. ";
                H->collectCoin(); //adds a coin
                x = 'x'; //replaces the spot with nothing
                break;

            case 'b':
            //boss
                endGame = H->fightBoss(outputFile); //Mario fights the boss

                if(endGame && L->getLevels()-1 == currLevel){ //if matio won, and it is the last level, mario has won the game. 
                    H->setWonGame(endGame);

                }else if(!endGame && L->getLevels()-1 == currLevel){ //if mario has lost, mario has lost the game.
                    H->setWonGame(endGame);
                    endGame = true; //game over . . . 
                    x = 'x';

                }else if(endGame && L->getLevels()-1 > currLevel){ //if mario has won BUT it is not the last level, mario proceeds to the next level.
                    currLevel++; //next level.
                    endGame = false; //game is not yet over!
                    x = 'x';
                }
                break;
        }

        H->currPowerLevel(outputFile); //Mario's current power level
        outputFile << "Mario has " << H->getLives() << " lives left. "; //outputs Mario's remaining lives
        outputFile <<  "Mario has " << H->getCoins() << " coins."; //outputs Mario's current coin count. 

        worldGrid[currLevel][H->getXCoord()][H->getYCoord()] = x; //replaces the grid space with either 'x','k','g'

        if (currentWorldChar == 'w'){ //if Mario encountered a warp pipe
            currentWorldChar = H->warp(randomXCoord(), randomYCoord(), grid, currLevel, outputFile); //Mario warps!
            outputFile << endl;
        }else{
            currentWorldChar = H->move(grid, gridDimension, currLevel, outputFile); //Mario moves onto a next direction
            outputFile << endl;
        }
        outputFile << "===============================" << endl;

        if(H->getLives() == -1){
            H->setWonGame(false);
            endGame = true;
        }
        turnsTaken++;
    }
    H->endGame(outputFile, turnsTaken);
}

void World::printWorld(int currLevel, ofstream &output){

    for(int r = 0; r < gridDimension; ++r){
        for(int c = 0; c < gridDimension; ++c){
            output << worldGrid[currLevel][r][c]; 
        }
        output << endl;
    }
    output << "===============================" << endl;
}

void World::setGrid(char*** worldGrid){
    this->worldGrid = worldGrid;
}

void World::setDimension(int gridDimension){
    this->gridDimension = gridDimension;
}

int World::randomXCoord(){
    int randRow = rand() % this->gridDimension;
    return randRow;
}

int World::randomYCoord(){
    int randCol = rand() % this->gridDimension;
    return randCol;
}
