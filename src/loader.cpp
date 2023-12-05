
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

    Wall* wall = new Wall(&hub);
    wall->setSprite("grass");
    wall->setDimensions(32, 32);
    wall->setPosition(130,200);
    hub.addObject(wall);
}