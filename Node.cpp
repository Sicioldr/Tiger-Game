#include "Node.h"

//Constructor
Node::Node(){
    this->occupied = false;
    this->identity = -1;
}

//Switch state of occupied
void Node::setOccupied(bool status){
    this->occupied = status;
}

void Node::setIdentity(int nomDeGuerre){
    this->identity = nomDeGuerre;
}

/*
//Set column
void Node::setX(int x){
    this->relativeX = x;
}

//Set row
void Node::setY(int y){
    this->relativeY = y;
}

//Get column
int Node::getX(){

    return this->relativeX;
}

//Get row
int Node::getY(){

    return this->relativeY;
}
*/
