/*
 * Author: Arantxa Rodriguez
 * Assignment Title: Tiger Game
 * Assignment Description: This file implements a GameEngine class.
 * Due Date: 04/26/2018
 * Date Created: 04/11/2018
 * Date Last Modified: 04/25/2018
 */

#ifndef GAMEENGINE_H_INCLUDED
#define GAMEENGINE_H_INCLUDED

#include <iostream>
#include <cmath>             // header needed to
#include "Token.h"           // header needed to use the Token class
#include "Circle.h"           // header needed to use the Circle class

using namespace std;

class GameEngine
{
private:

public:
    void plotBoard(SDL_Plotter &g); // GameBoard
    void plotTokens(SDL_Plotter &g);  // Tokens
    void printScreen(SDL_Plotter &g);   // Main Menu
    void drawCircle(SDL_Plotter &g, int x, int y, Color c);
    void closestVertex(int &x, int &y);
};

void GameEngine::plotBoard(SDL_Plotter &g)
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

  g.update();
}

void GameEngine::plotTokens(SDL_Plotter &g)
{
    // Draw circle to screen
    int x, y;
    Circle c(500, 500, BLUE);
    drawCircle(g, c.getLocation().x, c.getLocation().y, c.getColor());

    // If the
    if(g.getMouseDown(x,y))
    {
        if(abs(x - c.getLocation().x) < CIRCLE_RADIUS && abs(y - c.getLocation().y) < CIRCLE_RADIUS)
        {
            c.setColor(RED);

            // While
            while(!g.getMouseUp(x, y))
            {
                drawCircle(g, c.getLocation().x, c.getLocation().y, BACKGROUND);
                g.getMouseLocation(x, y);

                c.setLocation(x, y);

                drawCircle(g, c.getLocation().x, c.getLocation().y, c.getColor());
                g.update();
            }
            c.setColor(BLUE);
            closestVertex(x,y);
            drawCircle(g, c.getLocation().x, c.getLocation().y, BACKGROUND);
            c.setLocation(x, y);
        }
    }
}

void GameEngine::printScreen(SDL_Plotter &g)
{
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

    while(!g.kbhit())
    {
        g.Sleep(1);
    }

    g.clear();
}

void GameEngine::drawCircle(SDL_Plotter &g, int x, int y, Color c)
{
    for(int xd = -CIRCLE_RADIUS; xd < CIRCLE_RADIUS && x + xd < g.getCol() && x + xd > 0; xd++ )
        {
        for(int yd = -CIRCLE_RADIUS; yd < CIRCLE_RADIUS && y + yd < g.getRow() && y + yd > 0; yd++ )
        {
            if(sqrt(pow(xd,2) + pow(yd,2)) < CIRCLE_RADIUS)
            {
                g.plotPixel( x + xd, y + yd, c.R, c.G, c.B);
            }
        }
    }
}

void GameEngine::closestVertex(int &x, int &y)
{
    x = ((x + 50) / 100) * 100;
    y = ((y + 50) / 100) * 100;
}

#endif // GAMEENGINE_H_INCLUDED
