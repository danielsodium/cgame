#include "object.hpp"

void Object::setPosition(float _x, float _y) {
    dst.x = _x;
    dst.y = _y;
}

void Object::setDimensions(float _w, float _h) {
    dst.w = _w;
    dst.h = _h;
}

void Object::setSprite(std::string _name) {
    sprite = _name;
} 

void Object::update() {
    setPosition(dst.x + 1, dst.y + 1);
}