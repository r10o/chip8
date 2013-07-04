#include "gfx.h"

void init_gfx(char *title)
{
	gfx.draw = false;
	for (int k = 0; k < WIDTH; k++) {
		for (int j = 0; j < HEIGHT; j++) {
			gfx.screen[k][j] = 0;
		}
	}

	if (SDL_Init(SDL_INIT_VIDEO) == -1) {
		fprintf(stderr, "Could not initialize SDL: %s.\n", SDL_GetError());
		exit(1);
	}

	screen = SDL_SetVideoMode(WIDTH * 10, HEIGHT * 10, 0, SDL_HWPALETTE | SDL_DOUBLEBUF);

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
		pixel.w = 10;	
		pixel.h = 10;	
		uint32_t white = SDL_MapRGB(screen->format, 0xff, 0xff, 0xff);
		uint32_t black = SDL_MapRGB(screen->format, 0x0, 0x0, 0x0);
		for (int k = 0; k < WIDTH; k++) {
			for (int j = 0; j < HEIGHT; j++) {
				pixel.x = k * 10;	
				pixel.y = j * 10;	
				if (gfx.screen[k][j]) {
					SDL_FillRect(screen, &pixel, white);
				} else {
					SDL_FillRect(screen, &pixel, black);
				}
			}
		}
		SDL_Flip(screen);
		gfx.draw = false;
	}
}

void cleanup()
{
	SDL_Quit();
}
