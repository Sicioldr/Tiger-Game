#include "Board.h"

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

    //this->arrangeNodes();
}

///Rework when coordinates are known; use coefficient on iterator
void Board::arrangeNodes(){
    int manicule = -1; //Holds current row; moves up to 0 immediately

    //Assign coords to Lair
    for(int i = 0; i < LAIR_ROOT * LAIR_ROOT - 1; i++){
        ///This is a placeholder for a subfunction that can arrange Lair on diagonal
        //When at beginning of row, advance indicator
        if(i % LAIR_ROOT == 0){
            manicule++;
        }

        spots[i].setY(manicule * SPOT_SPACING);
        spots[i].setX((i % LAIR_ROOT) * SPOT_SPACING);

        cout << "Node " << i << ": (" << spots[i].getX()
             << ", " << spots[i].getY()
             << ")" << endl;
    }

    manicule = -1; //Reset for Field

    //Assign coords to Field
    for(int i = 0; i < FIELD_ROOT * FIELD_ROOT; i++){
        if(i % FIELD_ROOT == 0){
            manicule++;
        }

        spots[i + LAIR_ROOT * LAIR_ROOT].setY(manicule * SPOT_SPACING);
        spots[i + LAIR_ROOT * LAIR_ROOT].setX((i % FIELD_ROOT) * SPOT_SPACING);

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
       this->checkAdjacency(hobbes.getLocation(), quarry) != None &
       this->checkAdjacency(quarry, target) &&
       this->checkAdjacency(hobbes.getLocation(), quarry) == this->checkAdjacency(quarry, target)){
        canPounce = true;
    }

    return canPounce;
}
