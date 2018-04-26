/*
 * Author: Arantxa Rodriguez
 * Assignment Title: Tiger Game
 * Assignment Description: This file implements a GameEngine class.
 * Due Date: 04/26/2018
 * Date Created: 04/11/2018
 * Date Last Modified: 04/25/2018
 */

/*
* This is a compilation of all the functions so far that were not within a class.
* Just a way of cleaning up the main.
*/

#ifndef GAMEENGINE_H_INCLUDED
#define GAMEENGINE_H_INCLUDED

#include <iostream>
#include <cmath>             // header needed to
#include "Token.h"           // header needed to use the Token class
#include "Circle.h"           // header needed to use the Circle class
#include "SDL_Plotter.h"

using namespace std;

const int CIRCLE_RADIUS = 12;
const int SCALE = 50;
const int XREF = 25;
const int YREF = 225;

// Jacob's drawCircle (working)(was on main)
void drawCircle(SDL_Plotter &g, int x, int y, Color c){
    for(int xd = -CIRCLE_RADIUS; xd < CIRCLE_RADIUS && x + xd < g.getCol() && x + xd > 0; xd++ ){
        for(int yd = -CIRCLE_RADIUS; yd < CIRCLE_RADIUS && y + yd < g.getRow() && y + yd > 0; yd++ ){
            if(sqrt(pow(xd,2) + pow(yd,2)) < CIRCLE_RADIUS){
                g.plotPixel( x + xd, y + yd, c.R, c.G, c.B);
            }
        }
    }
}

// returns if there is a close vertex
bool closestVertex(int &x, int &y) {
    bool valid = true;
    if (y > YREF - SCALE/2){
        x -= XREF;
        x = ((x + SCALE/2) / SCALE) * SCALE;
        if(x < 0)
            x = 0;
        if(x > SCALE * 8)
            x = SCALE * 8;
        x += XREF;

        y -= YREF;
        y = ((y + SCALE/2) / SCALE) * SCALE;
        if(y > SCALE * 8)
            y = SCALE * 8;
        y += YREF;
    }
    else{
        if(x < XREF + (1.5*SCALE) || x > XREF + (7.5*SCALE))
            valid = false;
        else{
            y -= YREF;
            y = ((y - SCALE/2) / SCALE) * SCALE;
            if(y < -(SCALE*4))
                y = -(SCALE*4);
            y += YREF;

            if(y == YREF - (4*SCALE)){
                x = XREF + (4*SCALE);
            }
            else if(y == YREF - (3*SCALE)){
                if(x < XREF + (4*SCALE))
                    x = XREF + (3*SCALE);
                else
                    x = XREF + (5*SCALE);
            }
            else if(y == YREF - (2*SCALE)){
                if(x < XREF + (3*SCALE))
                    x = XREF + (2*SCALE);
                else if(x > XREF + (5*SCALE))
                    x = XREF + (6*SCALE);
                else
                    x = XREF + (4*SCALE);
            }
            else{
                if(x < XREF + (4*SCALE))
                    x = XREF + (3*SCALE);
                else
                    x = XREF + (5*SCALE);
            }
        }
    }
    return valid;
}

int vertexToNode(int x, int y){
    int index;
    x = (x - XREF) / SCALE;
    y = (y - YREF) / SCALE;

    if(y >= 0){
        index = 9;
        for(int i = 0; i < x; i++)
            index++;
        for(int i = 0; i < y; i++)
            index += 9;
    }
    else{
        if(x == 2)
            index = 0;
        else if(x == 3){
            if(y == -3)
                index = 1;
            else
                index = 3;
        }
        else if(x == 4){
            if(y == -4)
                index = 2;
            else
                index = 4;
        }
        else if(x == 5){
            if(y == -3)
                index = 5;
            else
                index = 7;
        }
        else {
            index = 8;
        }
    }
    return index;
}

void printStartScreen(SDL_Plotter &g){
    // T
    for(int i = 50; i < 100; i++){
        for(int j = 150; j < 156; j++){
            g.plotPixel(i, j, 0, 0, 0);
        }
    }
    for(int i = 72; i < 78; i++){
        for(int j = 150; j < 200; j++){
            g.plotPixel(i, j, 0, 0, 0);
        }
    }

    // I
    for(int i = 147; i < 153; i++){
        for(int j = 150; j < 200; j++){
            g.plotPixel(i, j, 0, 0, 0);
        }
    }

    // G
    for(int i = 200; i < 250; i++){
        for(int j = 150; j < 156; j++){
            g.plotPixel(i, j, 0, 0, 0);
        }
    }
    for(int i = 200; i < 206; i++){
        for(int j = 150; j < 200; j++){
            g.plotPixel(i, j, 0, 0, 0);
        }
    }
    for(int i = 200; i < 250; i++){
        for(int j = 194; j < 200; j++){
            g.plotPixel(i, j, 0, 0, 0);
        }
    }
    for(int i = 235; i < 250; i++){
        for(int j = 172; j < 178; j++){
            g.plotPixel(i, j, 0, 0, 0);
        }
    }
    for(int i = 244; i < 250; i++){
        for(int j = 172; j < 200; j++){
            g.plotPixel(i, j, 0, 0, 0);
        }
    }

    // E
    for(int i = 275; i < 325; i++){
        for(int j = 150; j < 156; j++){
            g.plotPixel(i, j, 0, 0, 0);
        }
    }
    for(int i = 275; i < 281; i++){
        for(int j = 150; j < 200; j++){
            g.plotPixel(i, j, 0, 0, 0);
        }
    }
    for(int i = 275; i < 325; i++){
        for(int j = 194; j < 200; j++){
            g.plotPixel(i, j, 0, 0, 0);
        }
    }
    for(int i = 275; i < 320; i++){
        for(int j = 172; j < 178; j++){
            g.plotPixel(i, j, 0, 0, 0);
        }
    }

    // R
    for(int i = 350; i < 400; i++){
        for(int j = 150; j < 156; j++){
            g.plotPixel(i, j, 0, 0, 0);
        }
    }
    for(int i = 350; i < 356; i++){
        for(int j = 150; j < 200; j++){
            g.plotPixel(i, j, 0, 0, 0);
        }
    }
    for(int i = 350; i < 400; i++){
        for(int j = 166; j < 172; j++){
            g.plotPixel(i, j, 0, 0, 0);
        }
    }
    for(int i = 394; i < 400; i++){
        for(int j = 150; j < 172; j++){
            g.plotPixel(i, j, 0, 0, 0);
        }
    }
    for(int i = 384; i < 390; i++){
        for(int j = 172; j < 200; j++){
            g.plotPixel(i, j, 0, 0, 0);
        }
    }

    // G
    for(int i = 50; i < 100; i++){
        for(int j = 250; j < 256; j++){
            g.plotPixel(i, j, 0, 0, 0);
        }
    }
    for(int i = 50; i < 56; i++){
        for(int j = 250; j < 300; j++){
            g.plotPixel(i, j, 0, 0, 0);
        }
    }
    for(int i = 50; i < 100; i++){
        for(int j = 294; j < 300; j++){
            g.plotPixel(i, j, 0, 0, 0);
        }
    }
    for(int i = 85; i < 100; i++){
        for(int j = 272; j < 278; j++){
            g.plotPixel(i, j, 0, 0, 0);
        }
    }
    for(int i = 94; i < 100; i++){
        for(int j = 272; j < 300; j++){
            g.plotPixel(i, j, 0, 0, 0);
        }
    }

    // A
    for(int i = 125; i < 175; i++){
        for(int j = 250; j < 256; j++){
            g.plotPixel(i, j, 0, 0, 0);
        }
    }
    for(int i = 125; i < 131; i++){
        for(int j = 250; j < 300; j++){
            g.plotPixel(i, j, 0, 0, 0);
        }
    }
    for(int i = 169; i < 175; i++){
        for(int j = 250; j < 300; j++){
            g.plotPixel(i, j, 0, 0, 0);
        }
    }
    for(int i = 125; i < 175; i++){
        for(int j = 280; j < 286; j++){
            g.plotPixel(i, j, 0, 0, 0);
        }
    }

    // M
    for(int i = 200; i < 250; i++){
        for(int j = 250; j < 256; j++){
            g.plotPixel(i, j, 0, 0, 0);
        }
    }
    for(int i = 200; i < 206; i++){
        for(int j = 250; j < 300; j++){
            g.plotPixel(i, j, 0, 0, 0);
        }
    }
    for(int i = 244; i < 250; i++){
        for(int j = 250; j < 300; j++){
            g.plotPixel(i, j, 0, 0, 0);
        }
    }
    for(int i = 222; i < 228; i++){
        for(int j = 250; j < 290; j++){
            g.plotPixel(i, j, 0, 0, 0);
        }
    }

    // E
    for(int i = 275; i < 325; i++){
        for(int j = 250; j < 256; j++){
            g.plotPixel(i, j, 0, 0, 0);
        }
    }
    for(int i = 275; i < 281; i++){
        for(int j = 250; j < 300; j++){
            g.plotPixel(i, j, 0, 0, 0);
        }
    }
    for(int i = 275; i < 325; i++){
        for(int j = 294; j < 300; j++){
            g.plotPixel(i, j, 0, 0, 0);
        }
    }
    for(int i = 275; i < 320; i++){
        for(int j = 272; j < 278; j++){
            g.plotPixel(i, j, 0, 0, 0);
        }
    }

    //a
    for(int i = 50; i < 80; i++){
        for(int j = 500; j < 503; j++){
            g.plotPixel(i, j, 0, 0, 0);
        }
    }
    for(int i = 50; i < 53; i++){
        for(int j = 500; j < 530; j++){
            g.plotPixel(i, j, 0, 0, 0);
        }
    }
    for(int i = 77; i < 80; i++){
        for(int j = 500; j < 530; j++){
            g.plotPixel(i, j, 0, 0, 0);
        }
    }
    for(int i = 50; i < 80; i++){
        for(int j = 513; j < 516; j++){
            g.plotPixel(i, j, 0, 0, 0);
        }
    }
    //n
    for(int i = 100; i < 130; i++){
        for(int j = 500; j < 503; j++){
            g.plotPixel(i, j, 0, 0, 0);
        }
    }
    for(int i = 100; i < 103; i++){
        for(int j = 500; j < 530; j++){
            g.plotPixel(i, j, 0, 0, 0);
        }
    }
    for(int i = 127; i < 130; i++){
        for(int j = 500; j < 530; j++){
            g.plotPixel(i, j, 0, 0, 0);
        }
    }

    //y
    for(int i = 150; i < 153; i++){
        for(int j = 500; j < 515; j++){
            g.plotPixel(i, j, 0, 0, 0);
        }
    }
    for(int i = 177; i < 180; i++){
        for(int j = 500; j < 515; j++){
            g.plotPixel(i, j, 0, 0, 0);
        }
    }
    for(int i = 150; i < 180; i++){
        for(int j = 512; j < 515; j++){
            g.plotPixel(i, j, 0, 0, 0);
        }
    }
    for(int i = 164; i < 167; i++){
        for(int j = 515; j < 530; j++){
            g.plotPixel(i, j, 0, 0, 0);
        }
    }


    //k
    for(int i = 250; i < 280; i++){
        for(int j = 507; j < 510; j++){
            g.plotPixel(i, j, 0, 0, 0);
        }
    }
    for(int i = 250; i < 280; i++){
        for(int j = 520; j < 523; j++){
            g.plotPixel(i, j, 0, 0, 0);
        }
    }
    for(int i = 250; i < 253; i++){
        for(int j = 500; j < 530; j++){
            g.plotPixel(i, j, 0, 0, 0);
        }
    }
    for(int i = 277; i < 280; i++){
        for(int j = 500; j < 510; j++){
            g.plotPixel(i, j, 0, 0, 0);
        }
    }
    for(int i = 277; i < 280; i++){
        for(int j = 520; j < 530; j++){
            g.plotPixel(i, j, 0, 0, 0);
        }
    }

    //e
    for(int i = 300; i < 330; i++){
        for(int j = 500; j < 503; j++){
            g.plotPixel(i, j, 0, 0, 0);
        }
    }
    for(int i = 300; i < 330; i++){
        for(int j = 527; j < 530; j++){
            g.plotPixel(i, j, 0, 0, 0);
        }
    }
    for(int i = 300; i < 325; i++){
        for(int j = 514; j < 517; j++){
            g.plotPixel(i, j, 0, 0, 0);
        }
    }
    for(int i = 300; i < 303; i++){
        for(int j = 500; j < 530; j++){
            g.plotPixel(i, j, 0, 0, 0);
        }
    }

    //y
    for(int i = 350; i < 353; i++){
        for(int j = 500; j < 515; j++){
            g.plotPixel(i, j, 0, 0, 0);
        }
    }
    for(int i = 377; i < 380; i++){
        for(int j = 500; j < 515; j++){
            g.plotPixel(i, j, 0, 0, 0);
        }
    }
    for(int i = 350; i < 380; i++){
        for(int j = 512; j < 515; j++){
            g.plotPixel(i, j, 0, 0, 0);
        }
    }
    for(int i = 364; i < 367; i++){
        for(int j = 515; j < 530; j++){
            g.plotPixel(i, j, 0, 0, 0);
        }
    }

    g.update();

    while(!g.kbhit()){
        g.Sleep(1);
    }
    g.clear();
}

#endif // GAMEENGINE_H_INCLUDED