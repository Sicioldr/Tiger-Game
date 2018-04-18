#ifndef TOKEN_H_INCLUDED
#define TOKEN_H_INCLUDED

#include "Node.h"

class Token{
private:
    int location; //Make this a pointer to node object?
    bool attached;

public:
    //Overridden constructor
    Token();

    //Getter function for the active node
    int getLocation();

    //Virtual space for set responses of children
    virtual bool isTiger();

    //Used for mouse movement
    bool isAttached();

    //Change value of location
    void moveToNode(int destination);
};

class Hunter : public Token{
private:
    bool isAlive;

public:
    //Adds value for isAlive to constructor
    Hunter();

    //Return true
    bool isTiger();
};

class Tiger : public Token{
private:

public:
    //Return true
    bool isTiger();
};

#endif // TOKEN_H_INCLUDED
