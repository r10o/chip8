#include "input.h"

void get_input()
{
	SDL_Event event;
	while (SDL_PollEvent(&event)) {
		switch (event.type) {
			case SDL_QUIT:
				exit(0);
				break;
			case SDL_KEYDOWN:
				switch (event.key.keysym.sym) {
					case SDLK_ESCAPE:
						exit(0);
						break;
					case SDLK_w:
						
					default:
						break;
				}
				break;
		}
	}
}
