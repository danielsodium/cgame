
#include "sprite.hpp"

void Sprite::setTexture(int _texture, float _tx, float _ty, float _tw, float _th) {
    texture = _texture;
    src.x = _tx;
    src.y = _ty;
    src.w = _tw;
    src.h = _th;
}
