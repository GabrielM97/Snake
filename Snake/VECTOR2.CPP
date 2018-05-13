#include "VECTOR2.H"
#include <math.h>
Vector2::Vector2()
{
    x = 0;
    y = 0;
}
Vector2::Vector2(float newX, float newY ) : x{newX}, y{newY}
{

}

float Vector2::dotProduct(const Vector2 &v1, const Vector2 &v2)
{
    return (v1.x * v2.x)+(v1.y * v2.y);
}

float Vector2::crossProduct(const Vector2 &v1, const Vector2 &v2)
{
    return (v1.x * v2.x)-(v1.y * v2.y);
}

float Vector2::distance()
{
    return sqrt((x*x) +(y*y));
}

void Vector2::normalise(float &dist)
{
    x /= dist;
    y /= dist;
}

Vector2::~Vector2()
{
    //dtor
}
