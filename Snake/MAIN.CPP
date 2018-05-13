/*
    Circle Drawing start code for Practical 10
*/

#include "WORLD.H"
#include <iostream>
#include <vector>
#include <stdlib.h>
#include <time.h>


using namespace std;


int main()
{
    // Seed the random
    bool reset = true;
    bool start =true;

    while(reset)
    {
        cout<<"in main"<<endl;
        World *snakeGame = new World;
        snakeGame->createWindow(1920, 1080);
        start = snakeGame->mainMenu();

        if(start)
        {
            snakeGame->setup();
            snakeGame->run();
            reset = snakeGame->restart();

        }
        else
        {
            reset = false;
        }
        delete snakeGame;

    }



    return 0;
}
