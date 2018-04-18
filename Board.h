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
    Tiger shereKhan;
    Hunter jaeger[HUNTER_COUNT];
    Node spots[GAME_SIZE];
    int hunterPopulation;

    void arrangeNodes();

public:
    Board();

    //Check adjacencies
    Direction checkAdjacent(int origin, int target);
};

#endif // BOARD_H_INCLUDED
