
#include <iostream>
#include "loader.hpp"
#include "tiles.hpp"
#include "game/player.hpp"
#include "game/wall.hpp"

void loadLevel(Hub& hub) {
    Player* block = new Player(&hub);
    block->setSprite("grass");
    block->setDimensions(32, 32);
    block->setPosition(132,132);
    hub.addObject(block);
    /*
    for (size_t i = 0; i < 20; i++) {
        Wall* wall = new Wall(&hub);
        wall->setSprite("grass");
        wall->setDimensions(32, 32);
        wall->setPosition(130+32*i,200);
        hub.addObject(wall);
    }
    */
    Tiles* ts = new Tiles("walls", 32);
    ts->addSprite("grass");
    ts->map.resize(30);
    for (size_t i = 0; i < ts->map.size(); i++) {
        ts->map[i].resize(40);
    }
    ts->map[6][3] = 1;
    for (size_t i = 0; i < 10; i++) ts->map[i+4][6] = 1;
    hub.addTiles(ts);

}