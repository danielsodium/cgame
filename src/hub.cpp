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
	return objects.size() - 1;
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
        buffer.push_back(std::make_pair(object->getPosition(), &sprite));
	}
    window->render(buffer);
}

void Hub::loadResources() {
    std::vector<std::string> paths = {"res/gfx/ground_grass_1.png"};
    window->loadTextures(paths);
	createSprite("grass", 0, 0, 0, 32, 32);
}
Object* Hub::instancePlace(float _x, float _y, float _w, float _h, std::string type, Object* self) {
    for (auto obj : objects) {
        if (obj != self && obj->getType() == type && obj->boxCollision(_x, _y, _w, _h)) {
            return obj;
        }
    }
    return nullptr;
}