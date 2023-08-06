#ifndef OBJECT_H_
#define OBJECT_H_

#include <SDL2/SDL.h>

#include <string>
#include "hitbox.hpp"

class Object {
public:

    Object() : active(true) {};
    
    void update();

    void setPosition(float _x, float _y);
    void setDimensions(float _w, float _h);
    void setSprite(std::string _name);

    std::string& getSprite() { return sprite; }
    SDL_Rect* getPosition() { return &dst; }
private:
    SDL_Rect dst;
    std::string sprite;
    Hitbox hitbox;
    bool active;
};

#endif