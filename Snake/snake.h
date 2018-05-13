#ifndef SNAKE_H
#define SNAKE_H
#include "SPRITE.H"
#include "linkedlist.h"
#include <string.h>
#include "GRAPHICS.H"
class Snake: public Sprite
{
public:

    Snake(int nTextureSize, float x, float y, string nName);
    virtual ~Snake();
    void eat();
    void addToSnake(Sprite *sprite);
    sf::Sprite changeToHead(sf::Sprite sprite, int textureRow,int textureCol);
    void Move();
    void Hurt();
    void setControls(int nUp, int nDown, int nLeft, int nRight);
    void render(Graphics* graphics);
    int getFood()
    {
        return foodConsumed;
    }
    LinkedList getBody()
    {
        return body;
    }
    void setSnakeSize(int newSize)
    {
        sizeOfSnake = newSize;
    };
    int getSnakeSize()
    {
        return sizeOfSnake;
    };
    bool getIsAlive()
    {
        return isAlive;
    };
    string getName()
    {
        return name;
    };
    void setIsAlive(bool nIsAlive)
    {
        isAlive = nIsAlive;
    };
    LinkedList body;

protected:
    sf::Sprite tempSprite;
    int sizeOfSnake{5};
    int foodConsumed{0};

    int ptrpos{0};
    Vector2 direction;
    int forwards;
    int backwards;
    int left;
    int right;
    bool isAlive{true};
    string name;

private:


};

#endif // SNAKE_H
