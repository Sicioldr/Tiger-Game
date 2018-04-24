#ifndef GROUPPROJECT_COLOR_H
#define GROUPPROJECT_COLOR_H

#include <cmath>

using namespace std;

struct Color{
    int R, G, B;

    Color(int r = 0, int g = 0, int b = 0){
        R = r;
        G = g;
        B = b;
    }

    void setColor(int r, int g, int b){
        R = r;
        G = g;
        B = b;
    }

    void setColor(Color c){
        R = c.R;
        G = c.G;
        B = c.B;
    }
};

const Color BACKGROUND(255, 255, 255);
const Color BLACK(0, 0, 0);
const Color RED(220, 20, 20);
const Color GREEN(20, 220, 20);
const Color BLUE(20, 20, 220);


#endif //GROUPPROJECT_COLOR_H
