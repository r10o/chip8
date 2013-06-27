#ifndef GFX_H
#define GFX_H
#include <stdint.h>
#include <stdbool.h>
#include "SDL/SDL.h"

struct chip8_gfx {
	bool draw;
	bool screen[32][64];
};

struct chip8_gfx gfx;

SDL_Surface *screen;

void init_gfx(char *title);
void draw();
void cleanup();
#endif
