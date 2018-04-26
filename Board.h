#ifndef BOARD_H_INCLUDED
#define BOARD_H_INCLUDED

#include <cmath>
#include <iostream>

#include "Token.h"
#include "GameEngine.h"

using namespace std;

enum Direction {None, Up, Down, Left, Right, UpLeft, DownLeft, UpRight, DownRight};

const int GAME_SIZE = 90;
const int HUNTER_COUNT = 18;
const int LAIR_ROOT = 3;
const int FIELD_ROOT = 9;

class Board{
//private:
public:
    Tiger shereKhan;
    Hunter jaeger[HUNTER_COUNT];
    Node spots[GAME_SIZE];
    int hunterPopulation;
    //Yes, this is gross, and yes, it's only used for one function - thank my stupid layout system
    int topLandmark = ceil(FIELD_ROOT / 2 ) + LAIR_ROOT * LAIR_ROOT,
            botLandmark = GAME_SIZE - 1 - (FIELD_ROOT / 2),
            center = (LAIR_ROOT * LAIR_ROOT) + (FIELD_ROOT * FIELD_ROOT / 2);




//public:
    Board();

    //Might become obsolete
    void arrangeNodes();

    //print functions
    void plotTokens(SDL_Plotter &g);
    void plotBoard(SDL_Plotter &g);

    //Saves space in other functions
    bool isOnBoard(int location);
    bool isInLair(int location);

    //Supporting function for checkAdjacent
    bool onDiagonal(int location);

    //Check adjacencies
    Direction checkAdjacency(int origin, int target);

    //See if a Node index is a possible candidate for landing over a Hunter
    bool tryPounce(int target, Tiger hobbes);

    bool tigerSurrounded();

    int gameComplete();
};


//Constructor
Board::Board(){
    //Place tiger
    this->shereKhan.moveToNode((LAIR_ROOT * LAIR_ROOT) / 2);
    this->spots[(LAIR_ROOT * LAIR_ROOT) / 2].setOccupied(true);

    //Populate bottom w/ hunters
    this->hunterPopulation = HUNTER_COUNT;

    for(int i = 0; i < HUNTER_COUNT; i++){
        this->jaeger[i].moveToNode(GAME_SIZE - HUNTER_COUNT + i);
        this->spots[GAME_SIZE - HUNTER_COUNT + i].setOccupied(true);
    }

    this->arrangeNodes();
}

///Rework when coordinates are known; use coefficient on iterator
void Board::arrangeNodes(){
    int manicule = -1; //Holds current row; moves up to 0 immediately

    //Assign coords to Lair
    for(int i = 0; i < LAIR_ROOT * LAIR_ROOT - 1; i++){
        switch(i){
            case 0:
                this->spots[i].setX(XREF + 2*SCALE);
                this->spots[i].setY(YREF - 2*SCALE);
                break;
            case 1:
                this->spots[i].setX(XREF + 3*SCALE);
                this->spots[i].setY(YREF - 3*SCALE);
                break;
            case 2:
                this->spots[i].setX(XREF + 4*SCALE);
                this->spots[i].setY(YREF - 4*SCALE);
                break;
            case 3:
                this->spots[i].setX(XREF + 3*SCALE);
                this->spots[i].setY(YREF - SCALE);
                break;
            case 4:
                this->spots[i].setX(XREF + 4*SCALE);
                this->spots[i].setY(YREF - 2*SCALE);
                break;
            case 5:
                this->spots[i].setX(XREF + 5*SCALE);
                this->spots[i].setY(YREF - 3*SCALE);
                break;
            case 6:
                this->spots[i].setX(XREF + 4*SCALE);
                this->spots[i].setY(YREF);
                break;
            case 7:
                this->spots[i].setX(XREF + 5*SCALE);
                this->spots[i].setY(YREF - SCALE);
                break;
            default:
                this->spots[i].setX(XREF + 6*SCALE);
                this->spots[i].setY(YREF - 2*SCALE);
                break;
        }
        /*
        ///This is a placeholder for a subfunction that can arrange Lair on diagonal
        //When at beginning of row, advance indicator
        if(i % LAIR_ROOT == 0){
            manicule++;
        }

        spots[i].setY(manicule * SCALE);
        spots[i].setX((i % LAIR_ROOT) * SCALE);

        cout << "Node " << i << ": (" << spots[i].getX()
             << ", " << spots[i].getY()
             << ")" << endl;
        */
    }

    manicule = -1; //Reset for Field

    //Assign coords to Field
    for(int i = 0; i < FIELD_ROOT * FIELD_ROOT; i++){
        if(i % FIELD_ROOT == 0){
            manicule++;
        }

        spots[i + LAIR_ROOT * LAIR_ROOT].setY(YREF + manicule * SCALE);
        spots[i + LAIR_ROOT * LAIR_ROOT].setX(XREF + (i % FIELD_ROOT) * SCALE);

        cout << "Node " << i + LAIR_ROOT * LAIR_ROOT
             << ": (" << spots[i + LAIR_ROOT * LAIR_ROOT].getX()
             << ", " << spots[i + LAIR_ROOT * LAIR_ROOT].getY()
             << ")" << endl;
    }
}

bool Board::isOnBoard(int location){
    bool returnValue = false;

    if(location >= 0 && location < GAME_SIZE){
        returnValue = true;
    }

    return returnValue;
}

bool Board::isInLair(int location){
    bool returnValue = false;

    if(location >= 0 && location < LAIR_ROOT * LAIR_ROOT){
        returnValue = true;
    }

    return returnValue;
}

bool Board::onDiagonal(int target){
    //Create references for modular arithmetic w/ diagonal; default is to use top left
    bool decision = false;

    if((target <= center + (FIELD_ROOT / 2) && //Is in top half; check left and right
        ((target - this->topLandmark) % (FIELD_ROOT - 1) == 0 ||
         (target - this->topLandmark) % (FIELD_ROOT + 1) == 0 ||
         target == this->topLandmark)) || //OR:
       (target >= center - (FIELD_ROOT / 2) && //Is is bottom half; check left and right
        ((target - this->botLandmark) % (FIELD_ROOT - 1) == 0 ||
         (target - this->botLandmark) % (FIELD_ROOT + 1) == 0 ||
         target == this->botLandmark))){
        //At long last
        decision = true;
    }

    return decision;
}

Direction Board::checkAdjacency(int origin, int target){
    //Set default state
    Direction decision = None;
    int relevantBase;

    //Account for transition b/w Lair & Field
    //If moving out of Lair
    if(origin == LAIR_ROOT * (LAIR_ROOT - 1) && !this->isInLair(target)){
        //Set origin to middle of top row in Field
        origin = LAIR_ROOT * LAIR_ROOT + FIELD_ROOT / 2;
    }
        //If moving into Lair
    else if(origin == LAIR_ROOT * LAIR_ROOT + FIELD_ROOT / 2 && this->isInLair(target)){
        //Set origin to bottom corner of Lair
        origin = LAIR_ROOT * LAIR_ROOT - LAIR_ROOT;
    }

    //Set base of adjacency calculation (saves duplication of U/D/L/R calculation)
    //If w/in Lair
    if(this->isInLair(target)){
        relevantBase = LAIR_ROOT;
    }
        //If w/in Field
    else if(!this->isInLair(target)){
        relevantBase = FIELD_ROOT;
    }

    //This is going to be pretty hairy while I flesh out the logic; it can be greatly simplified PRN
    //Check above
    if(target == origin - relevantBase && abs(origin - target) == relevantBase){
        decision = Up;
    }
        //Check below
    else if(target == origin + relevantBase && abs(origin - target) == relevantBase){
        decision = Down;
    }
        //Check right
    else if(target == origin + 1 && target % relevantBase > origin % relevantBase){
        decision = Right;
    }
        //Check left
    else if(target == origin - 1 && target % relevantBase < origin % relevantBase){
        decision = Left;
    }
        //Check diagonals
    else if(this->onDiagonal(origin) && this->onDiagonal(target) && //Both on diagonals
            abs(origin - target <= FIELD_ROOT + 1) &&   //W/in poss. bounds
            !(target % FIELD_ROOT == 0 && origin % FIELD_ROOT == FIELD_ROOT - 1) && //Not crossing sides
            !(origin % FIELD_ROOT == 0 && target % FIELD_ROOT == FIELD_ROOT - 1)){
        switch(origin - target){
            case FIELD_ROOT + 1:
                decision = UpLeft;
                break;
            case FIELD_ROOT - 1:
                decision = UpRight;
                break;
            case -1 * FIELD_ROOT - 1:
                decision = DownLeft;
                break;
            case -1 * FIELD_ROOT + 1:
                decision = DownRight;
                break;
        }
    }

    //Make sure parts are segregated
    if(this->isInLair(origin) != this->isInLair(target)){
        decision = None;
    }

    return decision;
}

bool Board::tryPounce(int target, Tiger hobbes){
    bool canPounce = false;
    int quarry = (hobbes.getLocation() + target) / 2;

    if(this->spots[quarry].getOccupied() && !spots[target].getOccupied() &&
       this->checkAdjacency(hobbes.getLocation(), quarry) != None &&
       this->checkAdjacency(quarry, target) &&
       this->checkAdjacency(hobbes.getLocation(), quarry) == this->checkAdjacency(quarry, target)){
        canPounce = true;
    }

    return canPounce;
}

bool Board::tigerSurrounded(){
    bool doomed = true;
    int proximalTarget, distalTarget;
    int relevantRoot = LAIR_ROOT;

    for(int i = -1; i <= 1; i++){
        for(int j = -1; j <= 1; j++){
            proximalTarget = shereKhan.getLocation() + i + j*FIELD_ROOT;
            distalTarget = shereKhan.getLocation() + 2*i + 2*j*FIELD_ROOT;
            if(!this->spots[proximalTarget].getOccupied() ||
               this->tryPounce(distalTarget, this->shereKhan)){
                doomed = false;
            }
        }
    }

    return doomed;
}

//0: ongoing
//1: Tiger win
//-1: Hunter win
int Board::gameComplete(){
    int gameState = 0;

    //Check for Tiger win
    if(this->hunterPopulation < 4){
        gameState = 1;
    }
    else if(this->tigerSurrounded()){
        gameState = -1;
    }

    return gameState;
}

void Board::plotTokens(SDL_Plotter &g){
    //print tiger
    drawCircle(g, spots[shereKhan.getLocation()].getX(), spots[shereKhan.getLocation()].getY(), shereKhan.getColor());

    //print hunters
    for(int i = 0; i < HUNTER_COUNT; i++)
        if(jaeger[i].isAlive())
            drawCircle(g, spots[jaeger[i].getLocation()].getX(), spots[jaeger[i].getLocation()].getY(), jaeger[i].getColor());
}

void Board::plotBoard(SDL_Plotter &g)
{
    int X = 450;
    int Y = 650;

    // horizontal line
    for(int i = X-425; i < X-25; i++){
        for(int j = Y-26; j < Y-25; j++){
            g.plotPixel(i, j, 0, 0, 0);
        }
        for(int j = Y-76; j < Y-75; j++){
            g.plotPixel(i, j, 0, 0, 0);
        }
        for(int j = Y-126; j < Y-125; j++){
            g.plotPixel(i, j, 0, 0, 0);
        }
        for(int j = Y-176; j < Y-175; j++){
            g.plotPixel(i, j, 0, 0, 0);
        }
        for(int j = Y-226; j < Y-225; j++){
            g.plotPixel(i, j, 0, 0, 0);
        }
        for(int j = Y-276; j < Y-275; j++){
            g.plotPixel(i, j, 0, 0, 0);
        }
        for(int j = Y-326; j < Y-325; j++){
            g.plotPixel(i, j, 0, 0, 0);
        }
        for(int j = Y-376; j < Y-375; j++){
            g.plotPixel(i, j, 0, 0, 0);
        }
        for(int j = Y-426; j < Y-425; j++){
            g.plotPixel(i, j, 0, 0, 0);
        }
    }

    // vertical line
    for(int i = Y-425; i < Y-25; i++){
        for(int j = X-26; j < X-25; j++){
            g.plotPixel(j, i, 0, 0, 0);
        }
        for(int j = X-76; j < X-75; j++){
            g.plotPixel(j, i, 0, 0, 0);
        }
        for(int j = X-126; j < X-125; j++){
            g.plotPixel(j, i, 0, 0, 0);
        }
        for(int j = X-176; j < X-175; j++){
            g.plotPixel(j, i, 0, 0, 0);
        }
        for(int j = X-226; j < X-225; j++){
            g.plotPixel(j, i, 0, 0, 0);
        }
        for(int j = X-276; j < X-275; j++){
            g.plotPixel(j, i, 0, 0, 0);
        }
        for(int j = X-326; j < X-325; j++){
            g.plotPixel(j, i, 0, 0, 0);
        }
        for(int j = X-376; j < X-375; j++){
            g.plotPixel(j, i, 0, 0, 0);
        }
        for(int j = X-426; j < X-425; j++){
            g.plotPixel(j, i, 0, 0, 0);
        }
    }

    // right slash
    for(int i = X-325; i < X-25; i++){
        int j = i;
        g.plotPixel(i, j, 0, 0, 0);
    }
    for(int i = X-425; i < X-225; i++){
        int j = i+400;
        g.plotPixel(i, j, 0, 0, 0);
    }
    for(int i = X-275; i < X-175; i++){
        int j = i-100;
        g.plotPixel(i, j, 0, 0, 0);
    }
    for(int i = X-225; i < X-125; i++){
        int j = i-200;
        g.plotPixel(i, j, 0, 0, 0);
    }

    // left slash
    for(int i = X-325; i < X-25; i++){
        int j = i;
        g.plotPixel(-i, j, 0, 0, 0);
    }
    for(int i = X-425; i < X-225; i++){
        int j = i+400;
        g.plotPixel(-i, j, 0, 0, 0);
    }
    for(int i = X-275; i < X-175; i++){
        int j = i-100;
        g.plotPixel(-i, j, 0, 0, 0);
    }
    for(int i = X-225; i < X-125; i++){
        int j = i-200;
        g.plotPixel(-i, j, 0, 0, 0);
    }
}
#endif // BOARD_H_INCLUDED