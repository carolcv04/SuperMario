#include "Grid.h"
#include "World.h"

Grid::Grid(){}

Grid::~Grid(){
    //deletes the grid(world) and all members
    for (int l = 0; l < L->getLevels(); ++l) {
        for (int r = 0; r < row; ++r) {
            delete[] grid[l][r];
        }
        delete[] grid[l];
    }

    delete[] grid;

    delete k;
    delete b;
    delete c;
    delete w;
    delete m;
    delete n;
    delete L;
    delete H;
    delete g;
}

Grid::Grid(string fileName, string logFileName){
    //initialize all members
    k = new Koopas(); //koopa
    b = new Boss(); //boss
    c = new Coin(); //coins
    w = new WarpPipe(); //warp
    m = new Mushroom(); //mushrom
    n = new Nothing(); //nothing
    L = new Level(); //level
    H = new Mario(); //Mario
    g = new Goombas(); //goomba

    //File for Mario log output
    ofstream outputFile;
    outputFile.open(logFileName);

    //resets random
    srand(time(NULL));

    //sets the percentages of all chacaters, Mario's lives, grid dimension and number of levels.
    setPercentages(fileName);

    //populates the grid with x's
    grid = new char**[L->getLevels()];
    for(int l = 0; l < L->getLevels(); ++l){
        grid[l] = new char*[row];

        for(int r = 0; r < row; ++r){
            grid[l][r] = new char[column];

            for(int c = 0; c < column; ++c){
                grid[l][r][c] = 'x';
            }
        }
    }
    //inserts all the characters into the grid
    for(int l = 0; l < L->getLevels(); ++l){
        insertCharacter(n, l, grid);
        insertCharacter(k, l, grid);
        insertCharacter(c, l, grid);
        insertCharacter(m, l, grid);
        insertCharacter(g, l, grid);
        insertCharacter(b, l, grid);

        //checks that it is not the last level to insert a warp
        if(L->getLevels() - 1 != l)
            insertCharacter(w, l, grid);
    }
    //prints all the worlds
    print(L,row,column, outputFile);

    //starts the game/world
    world = new World(grid, row, H, L, outputFile);

    //closing file
    outputFile.close();

    //dealocating
    delete world;
    delete grid;
}

void Grid::setPercentages(string fileName){
    string fileString; //to read contents of file
    int set = -1; //to set all the values for percentages, lives, levels and dimensions. 

    percentageFile.open(fileName); //opens the file
    if(percentageFile.fail()){ //if file fails to open, error is thrown
        cerr << "File does not exist." << endl;
    }else{
        while(percentageFile){ //while there is contents within the file
            set++; //increases to ensure all values are set
            percentageFile >> fileString; //reads the file
            value = stoi(fileString); //converts the string to an int value

            switch(set){
                case 0: 
                    L->setLevels(value); //sets number of levels
                    break;
                case 1:
                    row = value; //sets row value
                    column = row; //sets column value
                    break;
                case 2:
                    H->setLives(value); //sets Mario's lives
                    break;
                case 3:
                    c->setPercentage(value, row); //sets percentage of coins
                    break;
                case 4:
                    n->setPercentage(value, row); //sets percentage of nothing
                    break;
                case 5:
                    g->setPercentage(value, row); //sets percentage of goombas
                    break;
                case 6:
                    k->setPercentage(value, row); //sets percentage of koopas
                    break;
                case 7: 
                    m->setPercentage(value, row); //sets percentage of mushrooms
                    break;
            }
        }
    }
}

int Grid::getGridSize(){
    return row * column; //grid dimension 
}

void Grid::randomPosition(char c, int level, char*** grid){
    int randRow, randCol;

    //looks for a random position within the grid
    do{
        randRow = rand() % row;
        randCol = rand() % column;
    }while(grid[level][randRow][randCol] != 'x'); //ensures that the space selected is empty 

    grid[level][randRow][randCol] = c; //sets the character to the selected index of the grid
}

void Grid::insertCharacter(GameObject* o, int level, char*** grid){
    int instanceOfCharacter = o->instancesOf(); //gets the instances of the object based on percetage and grid dimension

    while(instanceOfCharacter > 0){ 
       randomPosition(o->getCharacter(), level, grid); //places the character ina random postion until there are no instances left
        --instanceOfCharacter;
    }
}

void Grid::print(Level *L, int row, int column, ofstream &output){
    
    //prints the world/grid
    for(int l = 0; l < L->getLevels(); ++l){
        for(int r = 0; r < row; ++r){
            for(int c = 0; c < column; ++c){
                output << grid[l][r][c]; 
            }
            output << endl;
        }
        output << "===============================" << endl;
    }
}
