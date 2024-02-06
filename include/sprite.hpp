#ifndef SPRITE
#define SPRITE

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <vector>

class Sprite 
{
public:
    void setTexture(int _texture, float _tx, float _ty, float _tw, float _th);
    void setTexture(int _texture, float _tx, float _ty, float _tw, float _th, int frames);

    // Will have to modify later to return the texture for the specific frame in parameter
    SDL_Rect* getTexture() { return &(src[0]); }
    SDL_Rect* getTexture(int frame) { return &(src[frame]); }
    int getTextureIndex() { return texture; }

private:
    std::vector<SDL_Rect> src;

    // Index of the texture sheet
    int texture;
    int frames;
};

#endif