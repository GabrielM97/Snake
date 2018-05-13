#include "WORLD.H"
#include <iostream>
#include <memory>
#include <chrono>
#include <thread>
#include "GRAPHICS.H"
#include <vector>
#include <stdlib.h>
#include <time.h>
#include "linkedlist.h"
World::World()
{

}
void World::setup() //sets up the level by instantiating sprites and loading in textures for the sprites
{
    graphics->loadFont("Resources/Antreas.ttf");//loads the font the game will be using


    //allows for different game modes to be setup depending on the value of the gameMode variable, changes amount and type of snake
    switch(gameMode)
    {

    case 1:
        //instantiates my object
        snake = new Snake(32, 50, 600, "Gabriel");
        //allows for the player controls to be changed
        snake->setControls((int)sf::Keyboard::Up, (int)sf::Keyboard::Down, (int)sf::Keyboard::Left, (int)sf::Keyboard::Right);
        snakes.push_back(snake);
        break;
    case 2:
        snake = new Snake(32, 50, 600, "Gabriel");
        snake2 = new Snake(32, 1800, 600, "Aleks");
        snake->setControls((int)sf::Keyboard::W, (int)sf::Keyboard::S, (int)sf::Keyboard::A, (int)sf::Keyboard::D);
        snake2->setControls((int)sf::Keyboard::Up, (int)sf::Keyboard::Down, (int)sf::Keyboard::Left, (int)sf::Keyboard::Right);
        snakes.push_back(snake);
        snakes.push_back(snake2);

        break;
    case 3:
        snake = new Snake(32, 50, 600, "Gabriel");
        snake->setControls((int)sf::Keyboard::Up, (int)sf::Keyboard::Down, (int)sf::Keyboard::Left, (int)sf::Keyboard::Right);
        snakes.push_back(snake);
        snake3 = new AISnake(32, 1600, 600, "AI");
        snakes.push_back(snake3);
        break;

    }

    //allow for the difficulty to change depending on the value of difficulty, this will change the number of planets on in game
    switch(difficulty)
    {
    case 1:
        sun = new Planet(96, 960, 550, "sun");
        mercury = new Planet(32, 1030, 610, "mercury");
        venus = new Planet(50,1080, 660, "venus");

        //loads sprite sheet of the planet
        sun->loadSpriteSheet("Resources/Sun.png");
        mercury->loadSpriteSheet("Resources/Mercury.png");
        venus->loadSpriteSheet("Resources/Venus.png");

        planets.push_back(sun);
        planets.push_back(mercury);
        planets.push_back(venus);
        break;

    case 2:
        sun = new Planet(96, 960, 550, "sun");
        mercury = new Planet(32, 1030, 610, "mercury");
        venus = new Planet(50,1080, 660, "venus");
        earth = new Planet(64, 1140, 710, "earth");
        mars = new Planet(32,1200, 760, "mars");

        sun->loadSpriteSheet("Resources/Sun.png");
        mars->loadSpriteSheet("Resources/Mars.png");
        mercury->loadSpriteSheet("Resources/Mercury.png");
        earth->loadSpriteSheet("Resources/Earth.png");
        venus->loadSpriteSheet("Resources/Venus.png");

        planets.push_back(sun);
        planets.push_back(mars);
        planets.push_back(mercury);
        planets.push_back(earth);
        planets.push_back(venus);

        break;
    case 3:
        sun = new Planet(96, 960, 550, "sun");
        mercury = new Planet(32, 1030, 610, "mercury");
        venus = new Planet(50,1080, 660, "venus");
        earth = new Planet(64, 1140, 710, "earth");
        mars = new Planet(32,1200, 760, "mars");
        jupitor = new Planet(80, 1260, 810, "jupitor");
        saturn = new Planet(80,1320, 860, "saturn");

        sun->loadSpriteSheet("Resources/Sun.png");
        mars->loadSpriteSheet("Resources/Mars.png");
        mercury->loadSpriteSheet("Resources/Mercury.png");
        earth->loadSpriteSheet("Resources/Earth.png");
        venus->loadSpriteSheet("Resources/Venus.png");
        jupitor->loadSpriteSheet("Resources/Jupitor.png");
        saturn->loadSpriteSheet("Resources/Saturn.png");

        planets.push_back(sun);
        planets.push_back(mars);
        planets.push_back(mercury);
        planets.push_back(earth);
        planets.push_back(venus);
        planets.push_back(jupitor);
        planets.push_back(saturn);
        break;
    }


    numOfApples = 5;
    for(int i = 0; i < numOfApples; i ++)
    {
        apples.push_back(new Sprite(32));
        Vector2 applePos(rand()%(screenWidth-100)+50, rand()%(screenHeight-300)+200);
        randomPos[i] = applePos;
        apples[i]->loadSpriteSheet("Resources/Apple.png");
    }

}
//used to create the planet rotation in the main menu without touching the in game planets
void World::mainMenuAni()
{

//controls running the game
    float planetSpeed = 6;
    if(menuSetup)
    {
        sun = new Planet(96, 960, 550, "sun");
        mercury = new Planet(32, 1030, 610, "mercury");
        venus = new Planet(50,1080, 660, "venus");
        earth = new Planet(64, 1140, 710, "earth");
        mars = new Planet(32,1200, 760, "mars");
        jupitor = new Planet(80, 1260, 810, "jupitor");
        saturn = new Planet(80,1320, 860, "saturn");

        sun->loadSpriteSheet("Resources/Sun.png");
        mars->loadSpriteSheet("Resources/Mars.png");
        mercury->loadSpriteSheet("Resources/Mercury.png");
        earth->loadSpriteSheet("Resources/Earth.png");
        venus->loadSpriteSheet("Resources/Venus.png");
        jupitor->loadSpriteSheet("Resources/Jupitor.png");
        saturn->loadSpriteSheet("Resources/Saturn.png");

        planetsToAni.push_back(sun);
        planetsToAni.push_back(mars);
        planetsToAni.push_back(mercury);
        planetsToAni.push_back(earth);
        planetsToAni.push_back(venus);
        planetsToAni.push_back(jupitor);
        planetsToAni.push_back(saturn);

        menuSetup = false;
    }


    for(unsigned int i = 0; i < planetsToAni.size(); i ++)
    {
        graphics->drawSprite<sf::Sprite>(planetsToAni[i]->getSprite());

        if(i > 0)
        {
            planetsToAni[i]->orbit(planetsToAni[0],planetSpeed);
            planetSpeed-=0.5;
        }

    }

}
void World::run()
{
    srand(time(0));

    sf::Time elaspsedTime;

    setRemainingTime(90);

    //while loop used to keep the game running while the condition is still met
    while (gameRunning)
    {
        int textXpos = 70;
        float planetSpeed = 6;
        elaspsedTime = clock.getElapsedTime();
        graphics->clearWindow(48, 59, 79);

        //loops through the planets vector and draws each planet and sets their orbit
        for(unsigned int i = 0; i < planets.size(); i ++)
        {
            graphics->drawSprite<sf::Sprite>(planets[i]->getSprite());

            if(i > 0)
            {
                planets[i]->orbit(planets[0],planetSpeed);
                planetSpeed-=0.5;
            }

        }


        //loops through and  draws apple
        for(int i =0; i < numOfApples; i++)
        {
            graphics->drawSprite<sf::Sprite>(apples[i]->drawSprite(0,0, randomPos[i]));
        }


        //loops through all snakes draws them and handles any check that has to be done by individual snakes
        for(auto s : snakes)
        {
            s->addToSnake(new Snake(32, 0, 0, s->getName()));
            s->render(graphics);

            if(s->getName() == "AI")
            {
                AISnake * aiSnake = (AISnake*)s;
                aiSnake->findPath( aiSnake->findTarget(randomPos), snakes, planets);
                aiSnake->aiMove();
            }
            else
                s->Move();
            checkCollision(apples, s->getBody(), planets,snakes, s);

            graphics->showText(s->getName() +" Score= "+intToString(s->getFood()),50, textXpos, 50, 255, 0, 0);
            textXpos+= 500;
        }


        //keeps track of time
        countTimer();

        checkRemaining();
        //updates the screen to draw updated graphics
        graphics->update();

    }
}
//keeps track of number of snakes left
void World::checkRemaining()
{
    for(size_t i = 0; i < snakes.size(); i ++)
    {
        if(!snakes[i]->getIsAlive())
        {
            cout << "deleting snake at " << i << snakes[i]->getName() << endl;
            snakes.erase(snakes.begin()+i);
        }
    }

    if(gameMode == 1)
    {
        if(snakes.size() == 0)
        {
            gameOver(snakes[0]->getName(), intToString(snakes[0]->getFood()));
            gameRunning = false;
        }
    }
    else if(snakes.size() == 1)
    {
        gameOver(snakes[0]->getName(), intToString(snakes[0]->getFood()));
        gameRunning = false;
    }


}
//tell the player who is the winner, run after check remaining has a value of 0 if single player or 1 multi
void World::gameOver(string name, string score)
{

    while (clock.getElapsedTime().asMilliseconds()<2000)
    {
        graphics->clearWindow(19, 26, 61);
        graphics->showText(name + " has won! with a score of "+ score, 30, 800, 500, 255,255,255);
        graphics->update();
    }
    clock.restart();

}

void World::countTimer()
{
    int highscore = 0;
    string name;

    if(clock.getElapsedTime().asSeconds() >1)
    {
        remainingTime --;
        clock.restart();
    }

    string strTime = intToString(remainingTime);

    graphics->showText(strTime,100, 895, 10, 255, 0, 0);

    if(remainingTime == 0)
    {
        for(auto s : snakes)
        {
            if(s->getFood() > highscore)
            {
                highscore = s->getFood();
                name = s->getName();
            }
        }

        gameOver(snakes[0]->getName(), intToString(snakes[0]->getFood()));
    }

}

//allows for int to string conversions
string World::intToString(int value)
{

    int strInt = value;

    stringstream newIntstr;

    newIntstr << strInt;

    return newIntstr.str();;

}

//checks collison agaist all posible objects
void World::checkCollision(const vector<Sprite*> collectable, LinkedList snakeBody, vector<Planet*> planet, vector<Snake*> otherSnake, Snake* snakes)
{
    //check collision with collectables
    for(unsigned int i = 0; i < collectable.size(); i++)
    {
        if(snakeBody.getItemAtPos(0).boundingRect.intersects(collectable[i]->boundingRect))
        {

            snakes->eat();
            Vector2 newPos(rand()%(screenWidth-100)+50, rand()%(screenHeight-300)+200);
            randomPos[i] = newPos;
        }
    }
    //check collision on itself
    for(int i = 1; i < snakeBody.getSize(); i++)
    {
        if(snakeBody.getItemAtPos(0).boundingRect.intersects(snakeBody.getItemAtPos(i).boundingRect))
        {
            cout << "die" << endl;
            snakes->setIsAlive(false);
        }
    }

    //check collision with other snakes
    for (unsigned int i =0; i < otherSnake.size(); i ++)
    {
        for(int j = 0; j  < otherSnake[i]->getBody().getSize(); j ++)
        {
            if(snakes->getName() != otherSnake[i]->getName())
            {

                if(snakeBody.getItemAtPos(0).boundingRect.intersects(otherSnake[i]->getBody().getItemAtPos(j).boundingRect))
                {
                    cout << "die" << endl;
                    snakes->setIsAlive(false);
                }
            }

        }

    }

    //collisions with planets
    for(size_t j = 0; j < planets.size(); j ++)
    {
        for ( int i  =  1; i < snakeBody.getSize(); i ++ )
        {
            if(snakeBody.getItemAtPos(i).boundingRect.intersects(planet[j]->boundingRect))
            {
                snakes->Hurt();
                snakeBody.popAt(i);
            }
        }

        if(snakeBody.getItemAtPos(0).boundingRect.intersects(planets[j]->boundingRect))
        {
            // cout << "You DIED"<< snakes->getName() << endl;
            snakes->setIsAlive(false);


        }
    }

    //check apple collision with planet random position again if there is a collision

    for(unsigned int j = 0; j < planets.size(); j ++)
    {
        for(unsigned int i = 0; i < collectable.size(); i++)
        {
            if(collectable[i]->boundingRect.intersects(planets[j]->boundingRect))
            {
                Vector2 newPos(rand()%(screenWidth-100)+50, rand()%(screenHeight-300)+200);
                randomPos[i] = newPos;
            }
        }

    }


    cout << snakes->getPos() << endl;
    //check out of bounds

    if(snakes->getPos().x <0)
    {
        snakes->setIsAlive(false);

    }
    else if(snakes->getPos().x >= screenWidth-20)
    {
        snakes->setIsAlive(false);

    }
    else if(snakes->getPos().y < 0)
    {
        snakes->setIsAlive(false);

    }
    else if(snakes->getPos().y >= screenHeight-20)
    {
        snakes->setIsAlive(false);

    }

}

//ask the user whether they want to restart the game
bool World::restart()
{
    bool reset = false;

    bool keyDown = false;

    while (!keyDown)
    {
        graphics->clearWindow(19, 26, 61);
        graphics->showText(" Would You like to play again ?", 30, 800, 300, 255,255,255);
        graphics->showText(" Q: Quit       R: Reset", 30, 850, 500, 255,255,255);

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::R))
        {
            reset = true;
            keyDown= true;

        }
        else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Q))
        {

            reset = false;
            keyDown=true;
        }
        graphics->update();
    }
    clock.restart();
    graphics->clearWindow(19, 26, 61);

    return reset;
}

//creates the window in which the game runs
void World::createWindow(int w, int h)
{

    screenHeight = h;
    screenWidth = w;
    graphics = new Graphics();
    graphics->createWindow(screenHeight, screenWidth, "SnakeICA: Gabriel S6088315");

}

// changed the mode of the game by getting an input from the user and setting the variable gameMode accordingly
void World::changeGameMode()
{
    bool inMenu = true;
    graphics->loadFont("Resources/Antreas.ttf");
    while (inMenu)
    {

        graphics->clearWindow(19, 26, 61);
        graphics->showText("Select Game Mode", 90, 10, 10, 255,255,255);
        graphics->showText("1: Singleplayer\n2: Player Vs Player \n3: Player Vs AI  \n4: Back", 70, 10, 200, 255,255,255);

        mainMenuAni();

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num1))
        {
            gameMode = 1;
            inMenu=false;


        }
        else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Num2))
        {

            gameMode = 2;
            inMenu=false;


        }
        else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Num3))
        {


            gameMode = 3;
            inMenu=false;

        }
        else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Num4))
        {


            inMenu=false;

        }

        graphics->update();

    }

    clock.restart();

}

//changes difficulty, same way as changeMode
void World::changeDificulty()
{


    bool inMenu = true;
    graphics->loadFont("Resources/Antreas.ttf");
    while (inMenu)
    {

        graphics->clearWindow(19, 26, 61);
        graphics->showText("Select Game Difficulty ", 90, 10, 10, 255,255,255);
        graphics->showText("(This will change the number of planets active in game)", 30, 10, 150, 255,255,255);
        graphics->showText("1: Easy\n2: Normal \n3: Hard  \n4: Back", 70, 10, 200, 255,255,255);

        mainMenuAni();

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num1))
        {
            difficulty = 1;
            inMenu=false;


        }
        else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Num2))
        {

            difficulty = 2;
            inMenu=false;


        }
        else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Num3))
        {


            difficulty = 3;
            inMenu=false;

        }
        else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Num4))
        {


            inMenu=false;

        }

        graphics->update();

    }

    clock.restart();


}
bool World::mainMenu()
{
    bool start = false;
    bool inMenu = true;

    cout<<"in Menu"<<endl;

    graphics->loadFont("Resources/Antreas.ttf");
    while (inMenu)
    {

        graphics->clearWindow(19, 26, 61);
        graphics->showText("SNAKES IN SPACE!", 90, 10, 10, 255,255,255);
        graphics->showText("P: Play\nG: GameMode \nD: Difficulty \nQ: Quit", 70, 10, 200, 255,255,255);

        mainMenuAni();

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::P))
        {
            start = true;
            inMenu= false;


        }
        else if(sf::Keyboard::isKeyPressed(sf::Keyboard::G))
        {

            changeGameMode();

        }
        else if(sf::Keyboard::isKeyPressed(sf::Keyboard::D))
        {

            changeDificulty();

        }
        else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Q))
        {

            start = false;
            inMenu=false;

        }

        graphics->update();

    }

    clock.restart();

    return start;
}


World::~World()
{
    delete graphics;
    delete snake;
    delete snake2;
    delete apple;
    delete sun;
    delete earth;
    delete mercury;
    delete venus;
    delete mars;
    delete saturn;
    delete jupitor;
}


