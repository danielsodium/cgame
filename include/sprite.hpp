#ifndef SPRITE
#define SPRITE

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

class Sprite 
{
public:
    Sprite();
    Sprite(float _x, float _y);
    float getX();
    float getY();
    void setX();
    void setY();
private:
    float x, y;

};

#endif