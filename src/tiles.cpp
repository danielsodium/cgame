#include "tiles.hpp"


Tiles::Tiles(std::string n, int t) : name(n), size(t) {
    sprites.resize(0);
    sprites.push_back("");
    map.resize(100);
    for (int i = 0; i < 100; i++) {
        map[i].resize(100, 0);
    }
}

void Tiles::addSprite(std::string name) {
    sprites.push_back(name);
}

bool Tiles::boxCollision(float x, float y, float w, float h) {
    size_t startX = static_cast<int>(x/size);
    size_t endX = static_cast<int>((x+w)/size);
    size_t startY = static_cast<int>(y/size);
    size_t endY = static_cast<int>((y+h)/size);

    if (map[startX][startY] != 0 ||
        map[endX][startY] != 0 ||
        map[startX][endY] != 0 ||
        map[endX][endY] != 0) {
            return true;
    }

    return false;

}

