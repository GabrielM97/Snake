#ifndef PLANET_H
#define PLANET_H
#include "VECTOR2.H"
#include "SPRITE.H"
#include <math.h>
#include<time.h>


class Planet:public Sprite
{
public:
    string name;
    Planet(int nTextureSize, float posX, float posY, string newName);
    virtual ~Planet();
    void orbit(Planet *target, float angle);

protected:

private:
    time_t time;
    Vector2 gForce;
    Vector2 localPos;


};

#endif // PLANET_H
