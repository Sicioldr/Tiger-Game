#include <iostream>

#include "SDL_Plotter.h"
#include "Board.h"

using namespace std;

int main(int argc, char ** argv)
{
    SDL_Plotter g(650, 450);
    int gameStatus = 0;
    int x,y;
    Board b;
    bool tigerTurn = false;
    bool changed = true;

    printStartScreen(g);
    b.arrangeNodes();

    while (gameStatus == 0)
    {
        if(g.getMouseClick(x,y)){
            if(tigerTurn){
                if(abs(x - b.spots[b.shereKhan.getLocation()].getX()) < CIRCLE_RADIUS && abs(y - b.spots[b.shereKhan.getLocation()].getY()) < CIRCLE_RADIUS){
                    b.shereKhan.setColor(lightcoral);
                    int oldX = b.spots[b.shereKhan.getLocation()].getX();
                    int oldY = b.spots[b.shereKhan.getLocation()].getY();
                    while(!g.getMouseClick(x, y)){

                        if(g.getMouseMotion(x,y)) {
                            drawCircle(g, oldX, oldY, BACKGROUND);

                            b.plotBoard(g);
                            b.plotTokens(g);

                            g.getMouseLocation(x, y);
                            drawCircle(g, x, y, GREEN);
                            oldX = x;
                            oldY = y;
                            g.update();
                        }
                    }
                    b.shereKhan.setColor(RED);
                    drawCircle(g, x, y, BACKGROUND);
                    drawCircle(g, b.spots[b.shereKhan.getLocation()].getX(), b.spots[b.shereKhan.getLocation()].getY(), BACKGROUND);
                    if(closestVertex(x,y) && !b.spots[vertexToNode(x,y)].getOccupied() /*&& VALID MOVE FUNCTION*/){

                        //Kill possible man function needed here

                        b.spots[b.shereKhan.getLocation()].setOccupied(false);
                        b.shereKhan.setLocation(vertexToNode(x, y));
                        b.spots[b.shereKhan.getLocation()].setOccupied(true);

                        tigerTurn = false;
                    }
                    changed = true;
                }
            }
            else{
                for(int i = 0; i < HUNTER_COUNT; i++){
                    if(abs(x - b.spots[b.jaeger[i].getLocation()].getX()) < CIRCLE_RADIUS && abs(y - b.spots[b.jaeger[i].getLocation()].getY()) < CIRCLE_RADIUS){
                        b.jaeger[i].setColor(cornflowerblue);
                        int oldX = b.spots[b.jaeger[i].getLocation()].getX();
                        int oldY = b.spots[b.jaeger[i].getLocation()].getY();
                        while(!g.getMouseClick(x, y)){

                            if(g.getMouseMotion(x,y)) {
                                drawCircle(g, oldX, oldY, BACKGROUND);

                                b.plotBoard(g);
                                b.plotTokens(g);

                                g.getMouseLocation(x, y);
                                drawCircle(g, x, y, GREEN);
                                oldX = x;
                                oldY = y;
                                g.update();
                            }
                        }
                        b.jaeger[i].setColor(BLUE);
                        drawCircle(g, x, y, BACKGROUND);
                        drawCircle(g, b.spots[b.jaeger[i].getLocation()].getX(), b.spots[b.jaeger[i].getLocation()].getY(), BACKGROUND);
                        if(closestVertex(x,y) && !b.spots[vertexToNode(x,y)].getOccupied() /*&& VALID MOVE FUNCTION*/){
                            b.spots[b.jaeger[i].getLocation()].setOccupied(false);
                            b.jaeger[i].setLocation(vertexToNode(x, y));
                            b.spots[b.jaeger[i].getLocation()].setOccupied(true);

                            tigerTurn = true;
                        }
                        changed = true;
                    }
                }
            }
        }

        if(changed) {
            b.plotBoard(g);
            b.plotTokens(g);

            if(tigerTurn)
                drawCircle(g, CIRCLE_RADIUS + 10, CIRCLE_RADIUS + 10, RED);
            else
                drawCircle(g, CIRCLE_RADIUS + 10, CIRCLE_RADIUS + 10, BLUE);

            g.update();
            gameStatus = b.gameComplete();
            changed = false;
        }

        if(g.kbhit()){
            if(g.getKey() == 'X'){
                gameStatus = 1;
            }
        }
    }
    printEndScreen(g);
    cout << "GAME OVER" << endl;

}
