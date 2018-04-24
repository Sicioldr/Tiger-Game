#include <iostream>
#include <cstdlib>

#include "SDL_Plotter.h"
#include "Board.h"

///TO DO:
    //Token & descendants
    //Node
    //Board

using namespace std;



int main(int argc, char **argv){
    int X = 450;
    int Y = 650;
    SDL_Plotter* g = new SDL_Plotter(Y, X);
    Board gameBoard;


//board base graph *****************************************
    // horizontal line
    for(int i = X-425; i < X-25; i++){
        for(int j = Y-26; j < Y-25; j++){
            g->plotPixel(i, j, 0, 0, 0);
        }
        for(int j = Y-76; j < Y-75; j++){
            g->plotPixel(i, j, 0, 0, 0);
        }
        for(int j = Y-126; j < Y-125; j++){
            g->plotPixel(i, j, 0, 0, 0);
        }
        for(int j = Y-176; j < Y-175; j++){
            g->plotPixel(i, j, 0, 0, 0);
        }
        for(int j = Y-226; j < Y-225; j++){
            g->plotPixel(i, j, 0, 0, 0);
        }
        for(int j = Y-276; j < Y-275; j++){
            g->plotPixel(i, j, 0, 0, 0);
        }
        for(int j = Y-326; j < Y-325; j++){
            g->plotPixel(i, j, 0, 0, 0);
        }
        for(int j = Y-376; j < Y-375; j++){
            g->plotPixel(i, j, 0, 0, 0);
        }
        for(int j = Y-426; j < Y-425; j++){
            g->plotPixel(i, j, 0, 0, 0);
        }
    }

    // vertical line
    for(int i = Y-425; i < Y-25; i++){
        for(int j = X-26; j < X-25; j++){
            g->plotPixel(j, i, 0, 0, 0);
        }
        for(int j = X-76; j < X-75; j++){
            g->plotPixel(j, i, 0, 0, 0);
        }
        for(int j = X-126; j < X-125; j++){
            g->plotPixel(j, i, 0, 0, 0);
        }
        for(int j = X-176; j < X-175; j++){
            g->plotPixel(j, i, 0, 0, 0);
        }
        for(int j = X-226; j < X-225; j++){
            g->plotPixel(j, i, 0, 0, 0);
        }
        for(int j = X-276; j < X-275; j++){
            g->plotPixel(j, i, 0, 0, 0);
        }
        for(int j = X-326; j < X-325; j++){
            g->plotPixel(j, i, 0, 0, 0);
        }
        for(int j = X-376; j < X-375; j++){
            g->plotPixel(j, i, 0, 0, 0);
        }
        for(int j = X-426; j < X-425; j++){
            g->plotPixel(j, i, 0, 0, 0);
        }
    }

    // right slash
    for(int i = X-325; i < X-25; i++){
        int j = i;
        g->plotPixel(i, j, 0, 0, 0);
    }
    for(int i = X-425; i < X-225; i++){
        int j = i+400;
        g->plotPixel(i, j, 0, 0, 0);
    }
    for(int i = X-275; i < X-175; i++){
        int j = i-100;
        g->plotPixel(i, j, 0, 0, 0);
    }
    for(int i = X-225; i < X-125; i++){
        int j = i-200;
        g->plotPixel(i, j, 0, 0, 0);
    }

    // left slash
    for(int i = X-325; i < X-25; i++){
        int j = i;
        g->plotPixel(-i, j, 0, 0, 0);
    }
    for(int i = X-425; i < X-225; i++){
        int j = i+400;
        g->plotPixel(-i, j, 0, 0, 0);
    }
    for(int i = X-275; i < X-175; i++){
        int j = i-100;
        g->plotPixel(-i, j, 0, 0, 0);
    }
    for(int i = X-225; i < X-125; i++){
        int j = i-200;
        g->plotPixel(-i, j, 0, 0, 0);
    }
//**********************************************************
    g->update();

	while(!g->getQuit()){
        if(g->kbhit()){

			//Keyboard input
			switch(g->getKey()){
			    case 'X': g->setQuit(true);
                    break;
			}
		}
	}

    return 0;
}
