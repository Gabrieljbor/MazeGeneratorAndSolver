#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include "graphics.h"
#include "global.h"

bool solve(int x, int y)
{
    if (maze[y][x] == 3) {
        solution[y][x] = 1;
        return true;
    }
 
    if ((maze[y][x] == 1 || maze[y][x] == 2) && solution[y][x] == 0) 
    {
        solution[y][x] = 1;
        if (solve(x + 1, y) || solve(x, y + 1) || solve(x - 1, y) || solve(x, y - 1))
        {
            return true;
        }
        else 
        {
            solution[y][x] = 0;
            return false;
        }
    }
    else
    {
        return false;
    }
}

void drawRobot(int x, int y, int direction)
{
    if (direction == 1)
    {
        int lx[] = {x*25, x*25+25, x*25};
        int ly[] = {y*25, y*25+12.5, y*25+25};
        fillPolygon(3, lx, ly); //triangle
    }
    else if (direction == 2)
    {
        int lx[] = {x*25+25, x*25, x*25+25};
        int ly[] = {y*25, y*25+12.5, y*25+25};
        fillPolygon(3, lx, ly);
    }
    else if (direction == 3)
    {
        int lx[] = {x*25, x*25+12.5, x*25+25};
        int ly[] = {y*25, y*25+25, y*25};
        fillPolygon(3, lx, ly);
    }
    else if (direction == 4)
    {
        int lx[] = {x*25, x*25+12.5, x*25+25};
        int ly[] = {y*25+25, y*25, y*25+25};
        fillPolygon(3, lx, ly);
    }
    
}

void move(int x, int y)
{
    solve(x, y);
    foreground(); 
    int complete = 0;
    while (complete == 0)
    {
        clear();
        setColour(red);
        if (solution[y][x+1] == 1) //right
        {
            solution[y][x] = 0;
            x+=1;
            drawRobot(x, y, 1);
        }
        else if (solution[y][x-1] == 1) //left
        {
            solution[y][x] = 0;
            x -= 1;
            drawRobot(x, y, 2);
        }
        else if (solution[y+1][x] == 1) //down
        {
            solution[y][x] = 0;
            y += 1;
            drawRobot(x, y, 3);
        }
        else if (solution[y-1][x] == 1) //up
        {
            solution[y][x] = 0;
            y -= 1;
            drawRobot(x, y, 4);
        }
        else
        {
            solution[y][x] = 0;
            complete = 1;
            drawRobot(x, y, 1);
        }
        sleep(80);
    }
}