#include "Token.h"
#include "Board.h"

///Token
//Consider a different placeholder location
Token::Token(){
    this->location = 0;
    this->attached = false;
}

//Return location indicator int
int Token::getLocation(){

    return this->location;
}

//Virtual in parent class; children will have set responses here
bool Token::isTiger(){

    return false;
}

//Get status of mouse connectivity
bool Token::isAttached(){

    return this->attached;
}

//Change location indicator int
void Token::moveToNode(int destination){
    this->location = destination;
    ///Needs to be able to communicate w/ connected Node(s)
    ///Do bulk of work in Board?
}


bool Token::checkAdjacent(int target){
    //Set default state
    bool decision = false;

    ///The most recently updated version of this function is on my (Luke's) machine; will upload later this evening

    return decision;
}


///Hunter
//Constructor
Hunter::Hunter(){
    this->isAlive = true;
}

//Simple getter
bool Hunter::vivaciousness(){

    return this->isAlive;
}

//Ouch
void Hunter::kill(){
    this->isAlive = false;
}

//Hard false
bool Hunter::isTiger(){

    return false;
}

///Tiger
//Hard true
bool Tiger::isTiger(){

    return true;
}

