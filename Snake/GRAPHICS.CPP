#include "GRAPHICS.H"
#include <iostream>
#include <memory>
#include <chrono>
#include <thread>

Graphics::Graphics():newSprite(32), sprite(32)
{
    //ctor

}


void  Graphics::loadSprite()
{
    newSprite.loadSpriteSheet("Resources/WorldTextures.png");

}

void Graphics::loadFont(string font)
{

    if(!newfont.loadFromFile(font))
    {
        cerr<<"Error loading file"<<endl;
    }

    newtext.setFont(newfont);

}



void Graphics::createWindow(int height, int width, string name)
{
    gWindow = new sf::RenderWindow (sf::VideoMode(width, height), name);

}

// update function which draws whatever is currently waiting in the buffer to the screen
bool Graphics::update()
{

    // if the window is not open don't update
    if (!gWindow->isOpen())
    {
        return false;
    }


    // Handle any pending SFML events
    // These cover keyboard, mouse,joystick etc.
    sf::Event event;
    while (gWindow->pollEvent(event))
    {
        switch(event.type)
        {
        case sf::Event::Closed:
            gWindow->close();
        default:
            break;
        }
    }
    //This block introduces delay in the snake's movement.
    while (clock.getElapsedTime().asMilliseconds()<100);
    clock.restart();

    // Get the window to display its contents
    gWindow->display();


    gWindow->setFramerateLimit(120);
    return true;
}


//takes in a string plus values to draw text on the screen as well as set its colour, if colour is not defind it will defualt to white
void Graphics::showText(string text, int txtSize,float posX, float posY, int r, int g, int b)
{

    newtext.setString(text);

    newtext.setCharacterSize(txtSize);

    newtext.setColor(sf::Color(r,g,b));

    newtext.setPosition(posX, posY);

    gWindow->draw(newtext);

}

Graphics::~Graphics()
{

    delete gWindow;
    //dtor
}
