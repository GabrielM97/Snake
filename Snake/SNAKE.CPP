#include "snake.h"

Snake::Snake(int nTextureSize, float x, float y, string nName):Sprite(nTextureSize),direction(0, -32)
{
    position = Vector2(x, y);
    name = nName;
}

//reduce the snakes size and food by 1 to represent the lost of segments
void Snake::Hurt()
{
    foodConsumed --;
    sizeOfSnake --;

}

// in charge of rendering the different parts of teh snakes body
void Snake::render(Graphics* graphics)
{
    for(int i =0; i< body.getSize(); i ++)
    {
        if(i == 0)
        {
            tempSprite = changeToHead(body.getItemAtPos(i).getSprite(), 0, 0);
            graphics->drawSprite<sf::Sprite>(tempSprite);
        }
        else if(i == body.getSize()-1)
        {
            tempSprite = changeToHead(body.getItemAtPos(i).getSprite(), 2, 0);
            graphics->drawSprite<sf::Sprite>(tempSprite);
        }
        else
            graphics->drawSprite<sf::Sprite>(body.getItemAtPos(i).getSprite());
    }
}

//add segments to the snake body, uses a size check to determine when the snake has become to big and pop segements out of the linked list
void Snake::addToSnake(Sprite *sprite)
{

    sprite->loadSpriteSheet("Resources/Snake2.png");


    sprite->drawSprite( 1,0, position);
    body.pushFront(sprite);



    sprite->rotation(direction);

    ptrpos++;
    if(ptrpos == sizeOfSnake)
        ptrpos = 0;

    if(body.getSize() > sizeOfSnake )
    {
        body.popBack();

    }

}
void Snake::eat()
{
    foodConsumed ++;
    sizeOfSnake ++;
}

sf::Sprite Snake::changeToHead(sf::Sprite sprite, int textureRow, int textureCol)
{
    sprite.setTextureRect(sf::IntRect(textureRow*textureSize, textureCol*textureSize,textureSize,textureSize));

    return sprite;

}

void Snake::setControls(int nUp, int nDown, int nLeft, int nRight)
{
    forwards = nUp;
    backwards = nDown;
    left = nLeft;
    right = nRight;

}

//controls movement of the snake, the key presses are created in the header and use setControl funtion to make key swapable
void Snake::Move()
{

    if ((sf::Keyboard::isKeyPressed((sf::Keyboard::Key)forwards))&& direction.y != textureSize)
    {
        direction.x = 0;
        direction.y = -textureSize;
        rotation(direction);

    }

    else if ((sf::Keyboard::isKeyPressed((sf::Keyboard::Key)right))&& direction.x != -textureSize)
    {
        direction.x = textureSize;
        direction.y = 0;
        rotation(direction);

    }
    else if ((sf::Keyboard::isKeyPressed((sf::Keyboard::Key)left))&& direction.x != textureSize)
    {
        direction.x = -textureSize;
        direction.y = 0;
        rotation(direction);

    }

    else if ((sf::Keyboard::isKeyPressed((sf::Keyboard::Key)backwards))&& direction.y != -textureSize)
    {
        direction.x = 0;
        direction.y = textureSize;
        rotation(direction);

    }

    position += direction;

}



Snake::~Snake()
{
    //dtor
}
