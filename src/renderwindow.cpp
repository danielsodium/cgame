#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <iostream>

#include "RenderWindow.hpp"

RenderWindow::RenderWindow(const char* p_title, int p_w, int p_h)
	:window(NULL), renderer(NULL)
{
	window = SDL_CreateWindow(p_title, SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, p_w, p_h, SDL_WINDOW_SHOWN);

	if (window == NULL)
	{
		std::cout << "Window failed to init. Error: " << SDL_GetError() << std::endl;
	}

	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
}

void RenderWindow::keyUp(int key) {
	keys[key] = false;
}

void RenderWindow::keyDown(int key) {
	keys[key] = true;
}

void RenderWindow::loadTexture(const char* p_filePath)
{
	SDL_Texture* texture = NULL;
	texture = IMG_LoadTexture(renderer, p_filePath);

	if (texture == NULL)
		std::cout << "Failed to load texture. Error: " << SDL_GetError() << std::endl;

	textures.push_back(texture);
}
void RenderWindow::createSprite(std::string name, int _texture, float _tx, float _ty, float _tw, float _th) {
	sprites[name] = Sprite();
	sprites[name].setTexture(_texture, _tx, _ty, _tw, _th);
}

void RenderWindow::loadResources() {
	

}

// Returns index of object in vector
int RenderWindow::addObject(Object* object) {
	objects.push_back(object);
	return objects.size() - 1;
}

Object* RenderWindow::getObject(int index) {
	return objects[index];
}

void RenderWindow::cleanUp()
{
	for (size_t i = 0; i < objects.size(); i++) {
		delete objects[i];
	}
	SDL_DestroyWindow(window);
}

void RenderWindow::clear()
{
	SDL_RenderClear(renderer);
}

void RenderWindow::updateObjects(float& delta_time) {

	for (Object* object : objects) {
		if (object->isActive()) {
			object->update(delta_time, keys);
		}	
	}
}

void RenderWindow::render()
{
	for (Object* object : objects) {
		Sprite& sprite = sprites[object->getSprite()];
		SDL_RenderCopy(renderer, textures[sprite.getTextureIndex()], sprite.getTexture(), object->getPosition());
	}
}

void RenderWindow::display()
{
	SDL_RenderPresent(renderer);
}