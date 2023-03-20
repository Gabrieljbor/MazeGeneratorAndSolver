#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include "graphics.h"
#include "global.h"

int main(void)
{
    srand(time(NULL));
    drawBackground();
    move(0,1);
}