#ifndef TOKEN_H_INCLUDED
#define TOKEN_H_INCLUDED

class Token{
private:
    int location; //Make this a pointer to node object?
    bool alive;

public:
    //Overridden constructor
    Token();

    //Getter function for the active node
    int getLocation();

    //Reports alive/dead
    bool isAlive();

    //Set alive to false
    void kill();

};

Token::Token(){
    this->location = 0;
    this->alive = true;
}

int Token::getLocation(){

    return this->location;
}

bool Token::isAlive(){

    return this->alive;
}

void Token::kill(){
    this->alive = false;
}

#endif // TOKEN_H_INCLUDED
