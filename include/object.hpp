#ifndef OBJECT_H_
#define OBJECT_H_

#include <SDL2/SDL.h>

#include <iostream>
#include <unordered_map>
#include <string>
#include "hitbox.hpp"

class Object {
public:

    Object() : active(true) {};
    
    void update(float& delta_time, std::unordered_map<int, bool>& keys);

    void move(float _x, float _y);
    void setPosition(float _x, float _y);
    void setDimensions(int _w, int _h);
    void setSprite(std::string _name);

    std::string& getSprite() { return sprite; }
    SDL_Rect* getPosition() { return &dst; }
    bool isActive() { return active; }
private:
    float x, y;
    SDL_Rect dst;
    std::string sprite;
    Hitbox hitbox;
    bool active;
};

#endif