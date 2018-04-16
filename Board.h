#ifndef BOARD_H_INCLUDED
#define BOARD_H_INCLUDED

#include "Token.h"
#include "Node.h"

const int GAME_SIZE = 90;
const int HUNTER_COUNT = 18;

class Board{
private:
    Tiger shereKhan;
    Hunter jaeger[HUNTER_COUNT];
    Node spots[GAME_SIZE];

public:

};

#endif // BOARD_H_INCLUDED
