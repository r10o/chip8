#include "gfx.h"

void init_gfx(char *title)
{
	gfx.draw = false;
	for (int j = 0; j < 32; j++) {
		for (int k = 0; k < 64; k++) {
			gfx.screen[j][k] = 0;
		}
	}

	if (SDL_Init(SDL_INIT_VIDEO) < 0) {
		fprintf(stderr, "Could not initialize SDL: %s.\n", SDL_GetError());
		exit(1);
	}

	screen = SDL_SetVideoMode(640, 320, 0, SDL_HWPALETTE | SDL_DOUBLEBUF);

	if (screen == NULL) {
		fprintf(stderr, "Could not set video mode: %s.\n", SDL_GetError());
		exit(1);
	}

	SDL_WM_SetCaption(title, NULL);
}

void draw()
{
	if (gfx.draw) {
		SDL_Rect pixel;
		uint32_t color = SDL_MapRGB(screen->format, 0xff, 0xff, 0xff);
		for (int j = 0; j < 32; j++) {
			for (int k = 0; k < 64; k++) {
				if (gfx.screen[j][k]) {
					pixel.x = k * 10;	
					pixel.y = j * 10;	
					pixel.w = 10;	
					pixel.h = 10;	
					SDL_FillRect(screen, &pixel, color);
				}
			}
		}
		SDL_Flip(screen);
	}

	gfx.draw = false;
}

void cleanup()
{
	SDL_Quit();
}
