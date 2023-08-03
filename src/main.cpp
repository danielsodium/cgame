#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <iostream>
#include <vector>

#include "constants.hpp"
#include "RenderWindow.hpp"


void update(float delta_time) {
	
}
void render(RenderWindow& window, SDL_Texture* grassTexture) {
	window.clear();
	window.render(grassTexture);
	window.display();
}

int main(int argc, char* argv[]) {
	if (SDL_Init(SDL_INIT_VIDEO) > 0) {
		std::cout << "HEY.. STL_Init HAS FAILED. STL_ERROR: " << SDL_GetError() << std::endl;
	}
	if (!IMG_Init(IMG_INIT_PNG)) 
		std::cout << "STL_init has failed. Error: " << SDL_GetError() << std::endl;
	
	RenderWindow window("GAME v1.0", 1280, 720);

	std::vector<SDL_Texture*> textures;
	SDL_Texture* grassTexture = window.loadTexture("res/gfx/ground_grass_1.png");

	textures.push_back(grassTexture);
	bool gameRunning = true;

	SDL_Event event;
	int last_frame_time = 0; 


	while (gameRunning)
	{
		// Get our controls and events
		while (SDL_PollEvent(&event))
		{
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

		update(delta_time);
		render(window, grassTexture);

		

	}

	window.cleanUp();
	SDL_Quit();

	return 0;
}