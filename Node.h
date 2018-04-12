
#ifndef GROUP_PROJECT_NODE_H
#define GROUP_PROJECT_NODE_H

#include <cmath>
#include <cstdlib>

class Token{};

class Node{
private:
    char type;
    Token* toke;

public:
    bool isAdjacent(int oldPosition, int newPosition);
    Token* getToken();
    char getType();
};

bool Node::isAdjacent(int oldPosition, int newPosition) {
    bool adjacent = false;

    if(oldPosition == 6 && newPosition > 8)
        oldPosition = 13;
    if(oldPosition == 13 && newPosition <= 8)
        oldPosition = 6;

    //if possible move
    if(abs(oldPosition - newPosition <= 10)){
        //big square
        if(oldPosition > 8 && newPosition > 8){
            //move left
            if(oldPosition - newPosition == 1 && oldPosition % 9 > newPosition % 9)
                adjacent = true;

            //move right
            if(oldPosition - newPosition == -1 && oldPosition % 9 < newPosition % 9)
                adjacent = true;

            //move down
            if(oldPosition - newPosition == -9 && newPosition < 89)
                adjacent = true;

            //move up
            if(oldPosition - newPosition == 9)
                adjacent = true;
        }
        //little square
        else if(oldPosition <= 8 && newPosition <= 8){
            //move left
            if(oldPosition - newPosition == 1 && oldPosition % 3 > newPosition % 3)
                adjacent = true;

            //move right
            if(oldPosition - newPosition == -1 && oldPosition % 3 < newPosition % 3)
                adjacent = true;

            //move down
            if(oldPosition - newPosition == -3)
                adjacent = true;

            //move up
            if(oldPosition - newPosition == 3 && newPosition >= 0)
                adjacent = true;
        }
        //square swap
        else{
            //really complicated
        }
    }



    return adjacent;
}

Token* Node::getToken() {
    return toke;
}

char Node::getType() {
    return type;
}

#endif //GROUP_PROJECT_NODE_H
