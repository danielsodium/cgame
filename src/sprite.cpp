
#include "sprite.hpp"

void Sprite::setTexture(int _texture, float _tx, float _ty, float _tw, float _th) {
    src.resize(0);
    texture = _texture;
    src.push_back(SDL_Rect());
    src[0].x = _tx;
    src[0].y = _ty;
    src[0].w = _tw;
    src[0].h = _th;
}

void Sprite::setTexture(int _texture, float _tx, float _ty, float _tw, float _th, int frames) {
    texture = _texture;
    for (int i = 0; i < frames; i++) {
        src.push_back(SDL_Rect());
        src[i].x = _tx;
        src[i].y = _ty;
        src[i].w = _tw;
        src[i].h = _th;
    }
}