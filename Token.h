#ifndef TOKEN_H_INCLUDED
#define TOKEN_H_INCLUDED

#include "Node.h"
#include "Color.h"

class Token{
protected:
    int location; //Make this a pointer to node object?
    int oldLocation;
    bool attached;
    Color c;

public:
    //Overridden constructor
    Token();

    //Getter function for the active node
    int getLocation();
    int getOldLocation();

    void setLocation(int l);
    void setOldLocation(int l);

    //Virtual space for set responses of children
    virtual bool isTiger();

    //Used for mouse movement
    bool isAttached();

    //Change value of location
    void moveToNode(int destination);

    Color getColor();
    void setColor(Color co);
    void setColor(int r, int g, int b);
};

class Hunter : public Token{
private:
    bool alive;

public:
    //Adds value for isAlive to constructor, set color to blue
    Hunter();

    bool isAlive();

    //Turn isAlive to false
    void kill();

    //Return false
    bool isTiger();
};

class Tiger : public Token{
private:

public:
    //set color to red
    Tiger();
    //Return true
    bool isTiger();
};



///Token
//Consider a different placeholder location
Token::Token(){
    this->location = -1;
    this->oldLocation = -1;
    this->attached = false;
    this->c = BLACK;
    cout << "RRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRR";
}

//Return location indicator int
int Token::getLocation(){

    return this->location;
}

int Token::getOldLocation(){

    return this->oldLocation;
}

void Token::setLocation(int l){
    this->location = l;
}
void Token::setOldLocation(int l){
    this->oldLocation = l;
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

Color Token::getColor(){
    return c;
}

void Token::setColor(Color co){
    c = co;
}

void Token::setColor(int r, int g, int b){
    c.R = r;
    c.G = g;
    c.B = b;
}

///Hunter
//Constructor
Hunter::Hunter(){
    this->alive = true;
    this->c = BLUE;
}

bool Hunter::isAlive() {
    return this->alive;
}

void Hunter::kill(){
    this->alive = false;
}

//Hard false
bool Hunter::isTiger(){

    return false;
}

///Tiger
Tiger::Tiger() {
    this->c = RED;
}
//Hard true
bool Tiger::isTiger(){

    return true;
}

#endif // TOKEN_H_INCLUDED