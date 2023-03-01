#include <SFML/Graphics.hpp>
#include "Game.h"
#include <stdlib.h>
#include <time.h>


int main()

{
    //initalise the random number generator
    srand(time(NULL));

   //Create game

    Game gameInstance;

    gameInstance.RunGameLoop();

    //if we get here game is over end program by returning

    return 0;
}