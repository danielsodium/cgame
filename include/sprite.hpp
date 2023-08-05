#ifndef SPRITE
#define SPRITE

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

class Sprite 
{
public:
    void setTexture(int _texture, float _tx, float _ty, float _tw, float _th);

    // Will have to modify later to return the texture for the specific frame in parameter
    SDL_Rect* getTexture() { return &src; }
    int getTextureIndex() { return texture; }

private:
    SDL_Rect src;

    // Index of the texture sheet
    int texture;
    int frames;
};

#endif