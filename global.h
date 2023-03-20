#ifndef GLOBAL_H
#define GLOBAL_H

#define sizeX 31
#define sizeY 31

int maze[sizeX][sizeY];
int solution[sizeX][sizeY];

void push(int x, int y);
void pop();
int canMove(int x, int y);
void createMaze(int x, int y);
void drawBackground();
bool solve(int x, int y);
void move(int x, int y);

#endif