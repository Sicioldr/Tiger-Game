#include "../Board.h"

//Constructor
Board::Board(){
    //Place tiger
    this->shereKhan.moveToNode((LAIR_ROOT * LAIR_ROOT) / 2);
    this->spots[(LAIR_ROOT * LAIR_ROOT) / 2].setOccupied(true);

    cout << "Placing Tiger at " << (LAIR_ROOT * LAIR_ROOT) / 2 << endl;

    //Populate bottom w/ hunters
    this->hunterPopulation = HUNTER_COUNT;

    for(int i = 0; i < HUNTER_COUNT; i++){
        this->jaeger[i].moveToNode(GAME_SIZE - HUNTER_COUNT + i);
        this->spots[GAME_SIZE - HUNTER_COUNT + i].setOccupied(true);

        cout << "Hunter at " << GAME_SIZE - HUNTER_COUNT + i << endl;
    }

    this->arrangeNodes();
}

///Might be able to obviate the stuff in the comment block; coords might be unneeded
void Board::arrangeNodes(){
    for(int i = 0; i < GAME_SIZE; i++){
        this->spots[i].setPosition(i);
    }

    /*
    int manicule = -1; //Holds current row; moves up to 0 immediately

    //Assign coords to Lair
    for(int i = 0; i < LAIR_ROOT * LAIR_ROOT - 1; i++){
        ///This is a placeholder for a subfunction that can arrange Lair on diagonal
        //When at beginning of row, advance indicator
        if(i % LAIR_ROOT == 0){
            manicule++;
        }

        spots[i].setY(manicule);
        spots[i].setX(i % LAIR_ROOT);

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

        spots[i + LAIR_ROOT * LAIR_ROOT].setY(manicule);
        spots[i + LAIR_ROOT * LAIR_ROOT].setX(i % FIELD_ROOT);

        cout << "Node " << i + LAIR_ROOT * LAIR_ROOT
             << ": (" << spots[i + LAIR_ROOT * LAIR_ROOT].getX()
             << ", " << spots[i + LAIR_ROOT * LAIR_ROOT].getY()
             << ")" << endl;
    }
     */
}

//WIP
bool Board::checkAdjacency(int first, int second){
    //On Luke's computer

    return true;
}

//Need target to detect when it is hit
bool Board::setUpPounce(Tiger emptyStomach, int target){
    bool canPounce = false;
    int midpoint = (emptyStomach.getLocation() + snack.getLocation) / 2;

    //Make sure that:
    //  points are adjacent in relevant pairs
    //  midpoint is actually occupied
    if(checkAdjacency(emptyStomach.getLocation(), midpoint) && checkAdjacency(midpoint, snack.getLocation)
            && this->spots[midpoint].isOccupied() && ){

    }
}
