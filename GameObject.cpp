#include "GameObject.h"
#include <iostream>
using namespace std;

GameObject::GameObject(){}

GameObject::~GameObject(){}

double GameObject::getPercentage(){
    return percentage; //access percentage value
}

void GameObject::setPercentage(int newPercentage, int gridDimension){
    this->gridDimension = gridDimension * gridDimension; //calculates the total grid spaces
    this->percentage = (double)(newPercentage)/100.0; //calculates the percentage of a charcter based on given value
}

int GameObject::instancesOf(){
    instances = (int)(gridDimension * getPercentage()); //calculates the instances of a character based on grid dimension and percentage
    return instances;
}

char GameObject::getCharacter(){
    return character; //access character
}
