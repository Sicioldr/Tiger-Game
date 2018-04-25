#ifndef BOARD_H_INCLUDED
#define BOARD_H_INCLUDED

#include <cmath>
#include <iostream>

#include "Token.h"

using namespace std;

enum Direction {Up, Down, Left, Right, UpLeft, DownLeft, UpRight, DownRight, None};

const int GAME_SIZE = 90;
const int HUNTER_COUNT = 18;
const int LAIR_ROOT = 3;
const int FIELD_ROOT = 9;

class Board{
private:
    Tiger shereKhan;
    Hunter jaeger[HUNTER_COUNT];
    Node spots[GAME_SIZE];
    int hunterPopulation;
    //Yes, this is gross, and yes, it's only used for one function - thank my stupid layout system
    int topLandmark = ceil(FIELD_ROOT / 2 ) + LAIR_ROOT * LAIR_ROOT,
        botLandmark = GAME_SIZE - 1 - (FIELD_ROOT / 2),
        center = (LAIR_ROOT * LAIR_ROOT) + (FIELD_ROOT * FIELD_ROOT / 2);

    //Might become obsolete
    void arrangeNodes();

public:
    Board();

    //Saves space in other functions
    bool isOnBoard(int location);
    bool isInLair(int location);

    //Supporting function for checkAdjacent
    bool onDiagonal(int location);

    //Check adjacencies
    Direction checkAdjacency(int origin, int target);
};

#endif // BOARD_H_INCLUDED
