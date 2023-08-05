#ifndef RENDERWINDOW
#define RENDERWINDOW

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include "sprite.hpp"
#include "object.hpp"
#include <vector>
#include <unordered_map>
#include <string>

class RenderWindow 
{
public:
	RenderWindow(const char* p_title, int p_w, int p_h);
	void loadTexture(const char* p_filePath);
	void loadResources();
	void createSprite(std::string name, int _texture, float _tx, float _ty, float _tw, float _th);
	void cleanUp();
	void clear();
	void render(Object& object);
	void display();
private:
	SDL_Window* window;
	SDL_Renderer* renderer;
	std::vector<SDL_Texture*> textures;
	std::unordered_map<std::string, Sprite> sprites;
};

#endif