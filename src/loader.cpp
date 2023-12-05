
#include <iostream>
#include "loader.hpp"
#include "game/player.hpp"
#include "game/wall.hpp"

void loadLevel(Hub& hub) {
    Player* block = new Player(&hub);
    block->setSprite("grass");
    block->setDimensions(32, 32);
    block->setPosition(132,132);
    hub.addObject(block);
    for (int i = 0; i < 20; i++) {
        Wall* wall = new Wall(&hub);
        wall->setSprite("grass");
        wall->setDimensions(32, 32);
        wall->setPosition(130+32*i,200);
        hub.addObject(wall);
    }

}