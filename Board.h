#ifndef BOARD_H_INCLUDED
#define BOARD_H_INCLUDED

#include <cmath>
#include <iostream>

#include "Token.h"

using namespace std;

const int GAME_SIZE = 90;
const int HUNTER_COUNT = 18;
const int LAIR_ROOT = 3;
const int FIELD_ROOT = 9;

enum Direction{None, Up, Down, Left, Right, UpLeft, DownLeft, UpRight, DownRight};

class Board{
private:
    Node spots[GAME_SIZE];
    Tiger shereKhan;
    Hunter jaeger[HUNTER_COUNT];
    int hunterPopulation;

    void arrangeNodes();

public:
    Board();

    //To be replaced with function on Luke's computer, ETA 2018-04-24
    bool checkAdjacency(Hunter first, Hunter second);

    //For capturing Hunter tokens; uses Board::checkAdjacent() and Node::moveToNode()
    bool setUpPounce(Tiger emptyStomach, Hunter snack);
};

#endif // BOARD_H_INCLUDED
