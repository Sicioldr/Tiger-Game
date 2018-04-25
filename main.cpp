/*
 * Author: Arantxa Rodriguez
 * Assignment Title: Tiger Game
 * Assignment Description: This file is a driver for a Tiger Game program.
 * Due Date: 04/26/2018
 * Date Created: 04/11/2018
 * Date Last Modified: 04/25/2018
 */

#include <iostream>
#include "SDL_Plotter.h"    // header needed to use the SDL_Plotter class
#include "GameEngine.h"     // header needed to use the GameEngine class
#include "Board.h"          // header needed to use the Board class

using namespace std;

int main(int argc, char ** argv)
{
    SDL_Plotter g(650, 450);
    SDL_Plotter g1(650, 450);
    bool stopped = false;
    int x, y;
    GameEngine game;
    Circle c(500, 500, BLUE);

    while (!g.getQuit())
    {
        // Main Menu
        game.printScreen(g);

        if(!stopped)
        {
            game.plotBoard(g1);
        }

        if(g.kbhit())
        {
			if(g.getKey() == 'Q')
            {
                g.setQuit(true);
            }
		}

		if(g.getMouseClick(x,y)){
			stopped = !stopped;
		}

        g.update();
    }
}
