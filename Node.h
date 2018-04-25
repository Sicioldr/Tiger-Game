#ifndef NODE_H_INCLUDED
#define NODE_H_INCLUDED

class Node{
private:
    bool occupied;
    int identity;
    //As below, these are hopefully going away
    //int relativeX, relativeY; //Set w/in containing Board

public:
    //Overridden constructor
    Node();

    //Setters for statuses
    void setOccupied(bool status);
    void setIdentity(int nomDeGuerre);

    /*
    //Trying to ditch this system; the functions don't need 2D locations to work
    //Set coordinates; used in Board construction
    void setX(int x); //Col
    void setY(int y); //Row

    //Retrieve coordinates
    int getX(); //Col
    int getY(); //Row
    */
};

#endif // NODE_H_INCLUDED
