#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <iostream>
#include <vector>
#include <unordered_map>

#include "constants.hpp"
#include "RenderWindow.hpp"
#include "hub.hpp"
#include "sprite.hpp"
#include "object.hpp"
#include "loader.hpp"


int main(int argc, char* argv[]) {
	if (SDL_Init(SDL_INIT_VIDEO) > 0) {
		std::cout << "HEY.. STL_Init HAS FAILED. STL_ERROR: " << SDL_GetError() << std::endl;
	}
	if (!IMG_Init(IMG_INIT_PNG)) 
		std::cout << "STL_init has failed. Error: " << SDL_GetError() << std::endl;
	
	RenderWindow window("GAME v1.0", 1280, 720);
    Hub hub(&window); 
	
	// Loading Textures and Sprites
    hub.loadResources();

	loadLevel(hub);

	SDL_Event event;
	bool gameRunning = true;
	int last_frame_time = 0; 

	while (gameRunning)
	{
		// Get our controls and events
		while (SDL_PollEvent(&event))
		{
			if (event.type == SDL_KEYDOWN) 
				hub.keyDown(event.key.keysym.sym);
			if (event.type == SDL_KEYUP) 
				hub.keyUp(event.key.keysym.sym);

			if (event.type == SDL_QUIT)
				gameRunning = false;
		}


		// Only updating 
		float delta_time = (SDL_GetTicks() - last_frame_time) / 1000.0f;


		// Store the milliseconds of the current frame to be used in the next one
		last_frame_time = SDL_GetTicks();

		int time_to_wait = FRAME_TARGET_TIME - (SDL_GetTicks() - last_frame_time);
		if (time_to_wait > 0 && time_to_wait <= FRAME_TARGET_TIME) {
			SDL_Delay(time_to_wait);
		}

		hub.updateObjects(delta_time);
		hub.render();
	}

	hub.cleanUp();
	SDL_Quit();

	return 0;
}