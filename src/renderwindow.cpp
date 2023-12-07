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

void RenderWindow::loadTexture(const std::string p_filePath)
{
	SDL_Texture* texture = NULL;
	texture = IMG_LoadTexture(renderer, p_filePath.c_str());

	if (texture == NULL)
		std::cout << "Failed to load texture. Error: " << SDL_GetError() << std::endl;

	textures.push_back(texture);
}

int RenderWindow::loadTextures(std::vector<std::string> filePaths) {
    for(auto path : filePaths) {
	    loadTexture(path.c_str());
    }
    return filePaths.size();
}


void RenderWindow::cleanUp()
{
	SDL_DestroyWindow(window);
}

void RenderWindow::render(std::vector<RenderBuffer>& sprites) {
    clear();
	for (auto p : sprites) {
		SDL_RenderCopy(renderer, textures[p.texture], p.src, &p.dst);
	}
    display();
}

void RenderWindow::clear()
{
	SDL_RenderClear(renderer);
}

void RenderWindow::display()
{
	SDL_RenderPresent(renderer);
}