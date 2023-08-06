
#include <iostream>
#include "loader.hpp"

void loadLevel(RenderWindow& window) {
    Object* block = new Object();
    block->setSprite("grass");
    block->setDimensions(32, 32);
    block->setPosition(32,32);
    window.addObject(block);
}