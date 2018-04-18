#ifndef NODE_H_INCLUDED
#define NODE_H_INCLUDED

class Node{
private:
    bool occupied;
    int relativeX, relativeY; //Set w/in containing Board

public:
    //Overridden constructor
    Node();

    //Switch for occupation
    void setOccupied(bool status);

    //Set coordinates; used in Board construction
    void setX(int x); //Col
    void setY(int y); //Row

    //Retrieve coordinates
    int getX(); //Col
    int getY(); //Row
};

#endif // NODE_H_INCLUDED
