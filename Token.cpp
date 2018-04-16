#include "Token.h"

///Token
//Consider a different placeholder location
Token::Token(){
    this->location = 0;
    this->attached = false;
}

int Token::getLocation(){

    return this->location;
}

bool Token::isTiger(){
    //Virtual in parent class; children will have set responses here
    return false;
}

bool Token::isAttached(){

    return this->attached;
}

void Token::moveToNode(int destination){
    this->location = destination;
}

///Hunter
Hunter::Hunter(){
    this->isAlive = true;
}

bool Hunter::isTiger(){

    return false;
}

///Tiger
bool Tiger::isTiger(){

    return true;
}
