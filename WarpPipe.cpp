#include "WarpPipe.h"

WarpPipe::WarpPipe(){}

WarpPipe::~WarpPipe(){}

int WarpPipe::instancesOf(){
    return 1; //one instance of warp pipe
}

char WarpPipe::getCharacter() {
    return 'w'; //warp pipe character
}