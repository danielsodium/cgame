#ifndef RENDERWINDOW
#define RENDERWINDOW

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include "sprite.hpp"
#include "object.hpp"
#include "renderbuffer.hpp"
#include <vector>
#include <unordered_map>
#include <string>
#include <iostream>

class RenderWindow {
public:
	RenderWindow(const char* p_title, int p_w, int p_h);
	void loadTexture(const std::string p_filePath);
	int loadTextures(std::vector<std::string> filePaths);

	void cleanUp();

	void clear();
	void render(std::vector<RenderBuffer>& sprites);
	void display();
private:
	SDL_Window* window;
	SDL_Renderer* renderer;

	std::vector<SDL_Texture*> textures;
};
#endif