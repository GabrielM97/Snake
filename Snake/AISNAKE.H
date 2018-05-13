#ifndef AISNAKE_H
#define AISNAKE_H
#include "snake.h"
#include "PLANET.H"


class AISnake : public Snake
{
public:
    AISnake(int nTextureSize, float x, float y, string nName);
    Vector2 findTarget(Vector2 targets[]);
    void findPath(Vector2 target, vector<Snake*> snakes, vector<Planet*> planet);
    void aiMove();
    virtual ~AISnake();

protected:

private:
};

#endif // AISNAKE_H
