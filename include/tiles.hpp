#ifndef TILES_H
#define TILES_H

#include <SDL2/SDL.h>
#include <vector>
#include "sprite.hpp"
#include <string>

struct Tiles {
    
    Tiles(std::string n, int t);

    void addSprite(std::string name);
    bool boxCollision(float x, float y, float w, float h);

    std::string name;
    int size;
    int texture;
    std::vector<std::string> sprites;
    std::vector<std::vector<int>> map;

};

#endif