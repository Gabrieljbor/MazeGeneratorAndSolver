#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include "global.h"

typedef struct Node
{
    int x;
    int y;
    struct Node *next;
} Node;

Node *head = NULL;

void push(int x, int y)
{
    Node * newNode = malloc(sizeof(Node));
    if (newNode == NULL)
    {
        return;
    }
    newNode->x = x;
    newNode->y = y;
    newNode->next = head;
    head = newNode;
    return;
}

void pop()
{
    if (head == NULL)
    {
        return;
    }
    Node *temp = head;
    head = head->next;
    free(temp);
    return;
}

int canMove(int x, int y)
{
    int options[4];
    for (int i = 0; i < 4; i++)
    {
        options[i] = 0;
    }
    
    if (((x+2) > 0 && (x+2) < sizeX-1 && y > 0 && y < sizeY-1) && maze[y][x+2] == 0) //is right square free
    {
        options[0] = 1;
    }
    if (((x-2) > 0 && (x-2) < sizeX-1 && y > 0 && y < sizeY-1) && maze[y][x-2] == 0) //left
    {
        options[1] = 2;
    }
    if ((x > 0 && x < sizeX-1 && (y+2) > 0 && (y+2) < sizeY-1) && maze[y+2][x] == 0) //down
    {
        options[2] = 3;
    }
    if ((x > 0 && x < sizeX-1 && (y-2) > 0 && (y-2) < sizeY-1) && maze[y-2][x] == 0) //up
    {
        options[3] = 4;
    }

    if (options[0] == 1 || options[1] == 2 || options[2] == 3 || options[3] == 4)
    {
        int direction = 0;
        while (direction == 0)
        {
            direction = options[rand()%4];
        }
        return direction;
    }
    else
    {
        return 0;
    }
}

void createMaze(int x, int y)
{
    maze[y][x] = 1;
    if (canMove(x, y) != 0)
    {
        push(x, y);
        int direction = canMove(x, y);
        if (direction == 1) //right
        {   
            x += 2;
            maze[y][x-1] = 1;
        }
        else if (direction == 2) //left
        {
            x -= 2;
            maze[y][x+1] = 1;
        }
        else if (direction == 3) //down
        {
            y += 2;
            maze[y-1][x] = 1;
        }
        else if (direction == 4) //up
        {
            y -= 2;
            maze[y+1][x] = 1;
        }
        createMaze(x, y);
    }
    else if(head->next != NULL)
    {
        pop();
        createMaze(head->x, head->y);
    }
}