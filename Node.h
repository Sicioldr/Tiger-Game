#ifndef NODE_H_INCLUDED
#define NODE_H_INCLUDED

class Node{
private:
    bool occupied;
    //int identity;
    //As below, these are hopefully going away
    int relativeX, relativeY; //Set w/in containing Board

public:
    //Overridden constructor
    Node();

    //Setters for statuses
    void setOccupied(bool status);
    //void setIdentity(int nomDeGuerre);

    bool getOccupied();


    //Trying to ditch this system; the functions don't need 2D locations to work
    //Set coordinates; used in Board construction
    void setX(int x); //Col
    void setY(int y); //Row
    //Retrieve coordinates
    int getX(); //Col
    int getY(); //Row

};

//Constructor
Node::Node(){
    this->occupied = false;
    //this->identity = -1;
}

//Switch state of occupied
void Node::setOccupied(bool status){
    this->occupied = status;
}

/*void Node::setIdentity(int nomDeGuerre){
    this->identity = nomDeGuerre;
}
*/
bool Node::getOccupied(){
    return  this->occupied;
}


//Set column
void Node::setX(int x){
    this->relativeX = x;
}
//Set row
void Node::setY(int y){
    this->relativeY = y;
}
//Get column
int Node::getX(){
    return this->relativeX;
}
//Get row
int Node::getY(){
    return this->relativeY;
}


#endif // NODE_H_INCLUDED