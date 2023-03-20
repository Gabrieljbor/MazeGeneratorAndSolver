#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include "graphics.h"
#include "global.h"

void drawFlag(int j, int i)
{
    fillRect(j*25,      i*25,       5, 5);
    fillRect(j*25,      i*25+10,    5, 5);
    fillRect(j*25,      i*25+20,    5, 5);
    fillRect(j*25+5,    i*25+5,     5, 5);
    fillRect(j*25+5,    i*25+15,    5, 5);
    fillRect(j*25+10,   i*25,       5, 5);
    fillRect(j*25+10,   i*25+10,    5, 5);
    fillRect(j*25+10,   i*25+20,    5, 5);
    fillRect(j*25+15,   i*25+5,     5, 5);
    fillRect(j*25+15,   i*25+15,    5, 5);
    fillRect(j*25+20,   i*25,       5, 5);
    fillRect(j*25+20,   i*25+10,    5, 5);
    fillRect(j*25+20,   i*25+20,    5, 5);
}

void drawBackground()
{
    createMaze(1, 1);
    setWindowSize(sizeX*25, sizeY*25);
    background();
    maze[0][0] = 0;
    maze[1][0] = 2; //start position
    int endY = rand()%(sizeY-2);
    if (endY == 0 || endY%2 == 0)
    {
        endY += 1;
    }
    int endX = sizeX;
    if (sizeX == 0 || sizeX%2 == 0)
    {
        endX -= 1;
    }
    maze[endY][endX-1] = 3;
    for (int i = 0; i < sizeY; i++)
    {
        for (int j = 0; j < sizeX; j++)
        {
            if (maze[i][j] == 0) //walls
            {
                setColour(darkgray); 
                fillRect(j*25, i*25, 25, 25);
            }
            if (maze[i][j] == 2) //start
            {
                setColour(green);
                fillRect(j*25, i*25, 25, 25);
            }
            if (maze[i][j] == 3) //end
            {
                setColour(black);
                drawFlag(j, i);
            }
        }
    }  
}