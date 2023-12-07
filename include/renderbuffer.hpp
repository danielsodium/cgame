#ifndef RENDERBUFFER 
#define RENDERBUFFER 

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

struct RenderBuffer {

    RenderBuffer(int x, int y, int w, int h, SDL_Rect* s, int t) : src(s), texture(t) {
        dst.x = x;
        dst.y = y;
        dst.w = w;
        dst.h = h;
    }; 

    SDL_Rect* src;
    SDL_Rect dst; 
    int texture;


};

#endif