#ifndef HUB_H
#define HUB_H

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include "sprite.hpp"
#include "object.hpp"
#include "tiles.hpp"
#include "RenderWindow.hpp"
#include "renderbuffer.hpp"
#include <vector>
#include <string>
#include <iostream>

class Hub {
public:

    Hub(RenderWindow* w) : window(w) {};

	void keyUp(int key);
	void keyDown(int key);

    void render();
    void loadResources();
	void createSprite(std::string name, int _texture, float _tx, float _ty, float _tw, float _th);
    Object* instancePlace(float _x, float _y, float _w, float _h, std::string type, Object* self);
    bool tilePlace(float _x, float _y, float _w, float _h, std::string name);

    int addObject(Object* Object);
    int addTiles(Tiles* tile);
    Object* getObject(int index);
    void deleteObject();
    void updateObjects(float& delta_time);
    void cleanUp();

private:
    RenderWindow* window;
	std::unordered_map<int, bool> keys;
	std::unordered_map<std::string, Sprite> sprites;
    std::vector<Object*> objects;
    std::vector<Tiles*> tiles;

    // Buffer of sprites to draw
    std::vector<RenderBuffer> buffer;

};


#endif