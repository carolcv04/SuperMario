#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

class Grid;

class GameObject{

    public:
        GameObject();
        virtual ~GameObject();
        double getPercentage(); //access percentage 
        void setPercentage(int newPercentage, int gridDimension); //sets percentage and calculate grid spaces
        virtual int instancesOf(); //calculates intances of a character
        virtual char getCharacter() = 0;
    private:
        double percentage;
        int instances; 
        char character;  
        int gridDimension;
};

#endif