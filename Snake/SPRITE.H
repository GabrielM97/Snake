#ifndef SPRITE_H
#define SPRITE_H
#include <SFML/Graphics.hpp>
#include"VECTOR2.H"
#include"string"
#include "linkedlist.h"

using namespace std;

class Sprite
{
public:

    Sprite(int nTextureSize);
    virtual ~Sprite();
    bool loadSpriteSheet(string filename);
    void rotation (const Vector2 &velocity);
    sf::Sprite drawSprite(int textureRow, int textureCol, Vector2 pos);
    sf::FloatRect boundingRect;
    void setPos(Vector2 nPos)
    {
        position = nPos;
    }
    Vector2 getPos()
    {
        return position;
    }
    sf::Sprite getSprite()
    {
        return sprite;
    }
    int a= 10;

protected:

    int textureSize;
    Vector2 position;
    int rotations = 0;
    sf::Texture spriteTexture;
    sf::Sprite sprite;

private:



};

#endif // SPRITE_H
