#include <cmath>
#include "Color.h"

using namespace std;



class Circle{
private:
    Color c;
    int x_location, y_location;

public:
    Circle(int x, int y, Color co){
        c.setColor(co);
        x_location = x;
        y_location = y;
    }

    void setLocation(int x, int y){
        x_location = x;
        y_location = y;
    }

    int getX(){
        return x_location;
    }

    int getY(){
        return y_location;
    }

    Color getColor(){
        return c;
    }

    void setColor(Color co){
        c = co;
    }

    void setColor(int r, int g, int b){
        c.R = r;
        c.G = g;
        c.B = b;
    }
};
