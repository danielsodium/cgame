#ifndef OBJECT_H_
#define OBJECT_H_

#include <SDL2/SDL.h>

#include <iostream>
#include <unordered_map>
#include <string>
#include "hitbox.hpp"

class Hub;

class Object {
public:

    Object(Hub* h);
    
    std::string& getSprite() { return sprite; }
    SDL_Rect* getPosition() { return &dst; }
    virtual std::string getType() { return "object"; }
    bool isActive() { return active; }

    Object* instancePlace(float x, float y, std::string type);
    bool boxCollision(float x, float y, float _w, float _h);
    
    virtual void update(float& delta_time, std::unordered_map<int, bool>& keys) { return; }
    void move(float _x, float _y);
    void setPosition(float _x, float _y);
    void setDimensions(int _w, int _h);
    void setSprite(std::string _name);

    virtual ~Object() {};

protected:
    float x, y;
    SDL_Rect dst;
    std::string sprite;
    Hitbox hitbox;
    bool active;
    std::string type;
    Hub* hub;
};

#endif