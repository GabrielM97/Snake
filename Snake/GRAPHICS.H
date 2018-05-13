#ifndef GRAPHICS_H
#define GRAPHICS_H
#include <string>
#include <SFML/Graphics.hpp>
#include "SPRITE.H"
using namespace std;

class Graphics
{
public:
    Graphics();
    sf::RenderWindow *gWindow{nullptr};
    void createWindow(int height, int width, string name );
    void loadSprite();
    void setupLevels();
    void generateMap(int levelToLoad);
    void clearWindow(float r, float g, float b) // We must clear the window
    {
        gWindow->clear(sf::Color(r, g, b));
    }
    //can only as an inlines
    // uses templeting to allow any object to be passed in
    template<typename type>
    void drawSprite(type drawable)
    {

        gWindow->draw(drawable);
    };
    void showText(string text,int txtSize,float posX, float posY, int r = 0, int g =0, int b=0);
    void loadFont(string font);
    bool update();
    void draw();

    virtual ~Graphics();

protected:

private:
    int posX = 0;
    int posY = 3;
    int offset = 25;
    Sprite newSprite;
    Sprite sprite;
    sf::Clock clock;
    sf::Font newfont;
    sf::Text newtext;

    vector<vector<int>> levels;
};

#endif // GRAPHICS_H
