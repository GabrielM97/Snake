#include "AISNAKE.H"
#include <queue>

AISnake::AISnake(int nTextureSize, float x, float y, string nName):Snake(nTextureSize, x, y, nName)
{

}

//finds a target by taking in a list of all targets and comparing the didtance between itself an dthe target
//shortes distance become the target to go to.
Vector2 AISnake::findTarget(Vector2 targets[])
{
    float distance = 2000;
    Vector2 temp;
    Vector2 target;

    for(size_t i = 0; i < sizeof(targets); i ++)
    {
        temp = targets[i] - position;
        if (distance > temp.distance())
        {
            distance = temp.distance();
            target = targets[i];
        }

    }

    return target;
}
//uses a simple implementation of greedy breath first search to move to the targets position
void AISnake::findPath(Vector2 target, vector<Snake*> snakes, vector<Planet*> planet)
{
    Vector2 temp;
    float h;
    if(position == target)
    {
        return;
    }
    else
    {
        temp = target - position;
        h = temp.distance();
        queue<Vector2> open;

        open.push({0,-32});
        open.push({0,32});
        open.push({-32,0});
        open.push({32,0});
        queue<Vector2> close;

        while(!open.empty())
        {
            temp = target - (position + open.front());

            if(h > temp.distance()&& (direction.x + open.front().x !=0 || direction.y + open.front().y != 0) )
            {
                h = temp.distance();
                close.push(open.front());
                open.pop();
                direction = close.back();

                position += direction;
 {
                                    close.pop();
                                    open = close;
                                }
                drawSprite( 1,0, position);

                for(int i = 0; i < body.getSize(); i ++ )
                {
                    if(body.getItemAtPos(0).boundingRect.intersects(body.getItemAtPos(i).boundingRect))
                    {
                        if(close.size() > 0)
                        {
                            close.pop();
                            open = close;
                        }
                    }
                }

                for (unsigned int i =0; i < snakes.size(); i ++)
                {
                    for(int j = 0; j  < snakes[i]->getBody().getSize(); j ++)
                    {
                        if(name != snakes[i]->getName())
                        {

                            if(body.getItemAtPos(0).boundingRect.intersects(snakes[i]->getBody().getItemAtPos(j).boundingRect))
                            {
                                 if(close.size() > 0)
                                {
                                    close.pop();
                                    open = close;
                                }
                            }
                        }

                    }

                }

                for(size_t j = 0; j < planet.size(); j ++)
                {


                    if(body.getItemAtPos(0).boundingRect.intersects(planet[j]->boundingRect))
                    {
                        if(close.size() > 0)
                        {
                            close.pop();
                            open = close;
                        }


                    }
                }



                if(position.x <0)
                {
                    if(close.size() > 0)
                    {
                        close.pop();
                        open = close;
                    }

                }
                else if(position.x >= 1920-20)
                {
                    if(close.size() > 0)
                    {
                        close.pop();
                        open = close;
                    }

                }
                else if(position.y < 0)
                {
                    if(close.size() > 0)
                    {
                        close.pop();
                        open = close;
                    }

                }
                else if(position.y >= 1080-20)
                {
                    if(close.size() > 0)
                    {
                        close.pop();
                        open = close;
                    }

                }


                position-=direction;
                drawSprite( 1,0, position);


            }
            else
            {


                close.push(open.front());
                open.pop();

            }

        }
    }
}

void AISnake::aiMove()
{
    position += direction;

    drawSprite( 1,0, position);

}

AISnake::~AISnake()
{
    //dtor
}
