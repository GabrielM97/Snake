#include "SPRITE.H"

Sprite::Sprite(int nTextureSize)
{
    textureSize = nTextureSize;

}
//loads sprite sheet
bool Sprite::loadSpriteSheet(string filename)
{
    if(!spriteTexture.loadFromFile(filename))
    {
        cerr << "Failed to load texture"<<endl;
        return false;
    }

    sprite.setTexture(spriteTexture);
    return true;

}

//check the sprite rotations based on the diretion of its movement
void Sprite::rotation(const Vector2 &velocity)
{

    if (velocity.x == 32)
        rotations = 90;
    else if (velocity.x == -32)
        rotations = 270;
    else if (velocity.y == -32)
        rotations = 0;
    else if (velocity.y == 32)
        rotations = 180;
    sprite.setRotation(rotations);

}

//creates the SF sprite and returns it;
sf::Sprite Sprite::drawSprite(int textureRow, int textureCol, Vector2 pos)
{

    position = pos;
    sprite.setOrigin(textureSize/2, textureSize/2);
    sprite.setPosition(position.x, position.y);
    sprite.setTextureRect(sf::IntRect(textureRow*textureSize, textureCol*textureSize,textureSize,textureSize));
    boundingRect = sprite.getGlobalBounds();
    return sprite;
}



Sprite::~Sprite()
{
    //dtor
}
