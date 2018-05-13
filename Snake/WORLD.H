#ifndef WORLD_H
#define WORLD_H
#include <SFML/Graphics.hpp>
#include "VECTOR2.H"
#include "SPRITE.H"
#include "snake.h"
#include "AISNAKE.H"
#include "PLANET.H"
#include <vector>
#include <string>
#include <sstream>

using namespace std;

class Graphics;
class World
{
public:
    World();

    void setup();
    void run();
    int getDirection(const Vector2 &velocity);
    void gameControls(Vector2 & pos, Vector2 &direction, int rotation);
    void checkCollision(const vector<Sprite*> collectable, LinkedList snakeBody, vector<Planet*> planet, vector<Snake*> otherSnake, Snake * snakes);
    string intToString(int value);
    void mainMenuAni();
    void aniSetup();
    void checkRemaining();
    void setRemainingTime(float time)
    {
        remainingTime = time;
    };
    void countTimer();
    void gameOver(string name, string score);
    bool mainMenu();
    bool restart();
    void createWindow( int w, int h);
    void changeGameMode();
    void changeDificulty();
    virtual ~World();

protected:

private:
    // Screen dimensions
    float remainingTime;
    bool gameRunning {true};
    int screenWidth{1920};
    int screenHeight{1080};
    bool menuSetup{true};
    time_t Time;
    int numOfApples;
    int gameMode{1};
    int difficulty{2};
    vector<Planet*> planets;
    vector<Snake*> snakes;
    Graphics *graphics {nullptr};
    Snake *snake{nullptr};
    Snake *snake2{nullptr};
    AISnake *snake3{nullptr};
    AISnake *snake4{nullptr};
    Sprite *apple{nullptr};
    Planet *sun{nullptr};
    Planet *mercury{nullptr};
    Planet *mars{nullptr};
    Planet *earth{nullptr};
    Planet *venus{nullptr};
    Planet *jupitor{nullptr};
    Planet *saturn{nullptr};
    vector<Planet*> planetsToAni;
    vector<Sprite*> apples;
    Vector2 randomPos[5];
    sf::Clock clock;


};

#endif // WORLD_H
