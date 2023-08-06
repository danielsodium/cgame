#include "object.hpp"

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
}

void Object::setSprite(std::string _name) {
    sprite = _name;
} 

void Object::update(float& delta_time, std::unordered_map<int, bool>& keys) {
    
    float speed = 150;

    
    if (keys[119]) {
        move(0, -speed*delta_time);
    } 
    if (keys[97]) {
        move(-speed*delta_time, 0);
    } 
    if (keys[115]) {
        move(0, speed*delta_time);
    } 
    if (keys[100]) {
        move(speed*delta_time, 0);
    } 
}
