#include "hub.hpp"
#include <iostream>

void Hub::updateObjects(float& delta_time) {
	for (auto object : objects) {
		if (object->isActive()) {
			object->update(delta_time, keys);
		}	
	}
}

// Returns index of object in vector
int Hub::addObject(Object* object) {
	objects.push_back(object);
    object->create();
	return objects.size() - 1;
}

int Hub::addTiles(Tiles* tile) {
	tiles.push_back(tile);
	return tiles.size() - 1;
}


void Hub::cleanUp() {
    for (size_t i = 0; i < objects.size(); i++) {
		delete objects[i];
	}
    window->cleanUp();
}

void Hub::keyUp(int key) {
	keys[key] = false;
}

void Hub::keyDown(int key) {
	keys[key] = true;
}

void Hub::createSprite(std::string name, int _texture, float _tx, float _ty, float _tw, float _th) {
	sprites[name] = Sprite();
	sprites[name].setTexture(_texture, _tx, _ty, _tw, _th);
}

Object* Hub::getObject(int index) {
	return objects[index];
}

void Hub::render() {
    for (Object* object : objects) {
		Sprite& sprite = sprites[object->getSprite()];
        auto pos = object->getPosition();
        buffer.push_back(RenderBuffer(pos->x, pos->y, pos->w, pos->h, sprite.getTexture(), sprite.getTextureIndex()));
	}
    for (Tiles* tile : tiles) {
        int s = tile->size;
        for (size_t i = 0; i < tile->map.size(); i++) {
            for (size_t j = 0; j < tile->map[0].size(); j++) {
                if (tile->map[i][j] != 0) {
                    auto sprite = sprites[tile->sprites[tile->map[i][j]]];
                    buffer.push_back(RenderBuffer(s*i, s*j, s, s, sprite.getTexture(), sprite.getTextureIndex()));
                }
            }
        }
    }
    window->render(buffer);
    buffer.clear();
}

void Hub::loadResources() {
    std::vector<std::string> paths = {"res/gfx/spritesheet.png"};
    window->loadTextures(paths);
	createSprite("grass", 0, 96, 0, 32, 32);
    createSprite("player", 0, 352, 0, 32, 32);
}

Object* Hub::instancePlace(float _x, float _y, float _w, float _h, std::string type, Object* self) {
    for (auto obj : objects) {
        if (obj != self && obj->getType() == type && obj->boxCollision(_x, _y, _w, _h)) {
            return obj;
        }
    }
    return nullptr;
}

bool Hub::tilePlace(float _x, float _y, float _w, float _h, std::string name) {
    for (auto t : tiles) {
        if (t->name == name && t->boxCollision(_x, _y, _w, _h)) {
            return true;
        }
    }
    return false;
}

