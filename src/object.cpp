#include "object.hpp"
#include "hub.hpp"

Object::Object(Hub* h) {
    active = true;
    hub = h;
    type = "object";
};

void Object::setPosition(float _x, float _y) {
    x = _x;
    y = _y;
    dst.x = _x;
    dst.y = _y;
}

// This is to move in floats 
void Object::move(float _x, float _y) {
    x += _x;
    y += _y;
    dst.x = x;
    dst.y = y;
}

void Object::setDimensions(int _w, int _h) {
    dst.w = _w;
    dst.h = _h;
    hitbox.w = _w;
    hitbox.h = _h;
}

void Object::setSprite(std::string _name) {
    sprite = _name;
} 

bool Object::boxCollision(float _x, float _y, float _w, float _h) {
    if (!(((_x > x + hitbox.x) && (_x < x + hitbox.x + hitbox.w)) ||
        ((_x + _w > x + hitbox.x) && (_x + _w < x + hitbox.x + hitbox.w)))) {
        return false;
    }
    if (!(((_y > y + hitbox.y) && (_y < y + hitbox.y + hitbox.h)) ||
        ((_y + _h > y + hitbox.y) && (_y + _h < y + hitbox.y + hitbox.h)))) {
        return false;
    }
    return true;
}

Object* Object::instancePlace(float _x, float _y, std::string type) {
    return hub->instancePlace(_x, _y, hitbox.w, hitbox.h, type, this);
}
