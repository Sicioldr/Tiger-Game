/*
 * Author: Luke Barron
 * Assignment Title: Group Project (Tiger Game)
 * Assignment Description: This program implements a graphical representation
 *      of selected sorting algorithms using the SDL2 framework
 * Due Date: 4/26/2018
 * Date Created: 4/11/2018
 * Date Last Modified: 4/11/2018
 */

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
    SDL_Plotter* g = new SDL_Plotter(500, 500);
    Board gameBoard;

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
