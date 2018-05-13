#include "PLANET.H"

Planet::Planet(int nTextureSize, float posX, float posY, string newName):Sprite(nTextureSize), gForce(1,1)
{
    //ctor
    position = Vector2(posX, posY);
    drawSprite(0,0, position);
    name = newName;
}

//Allows for planets to rotate around a point
void Planet::orbit(Planet *target, float angle)
{
    //coverts from Rads
    angle = angle * (3.14/180);
    float rotationX = cos(angle) * (position.x - target->position.x) - sin(angle) * (position.y - target->position.y) + target->position.x;

    float rotationY = sin(angle) * (position.x - target->position.x) + cos(angle) * (position.y - target-> position.y) + target->position.y;

    position.x = rotationX;
    position.y = rotationY;

    drawSprite(0,0, position);
}

Planet::~Planet()
{
    //dtor
}
