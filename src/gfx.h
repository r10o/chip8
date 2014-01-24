#ifndef GFX_H
#define GFX_H
#include <stdint.h>
#include <stdbool.h>
#include "SDL/SDL.h"

#define WIDTH 64
#define HEIGHT 32

struct chip8_gfx {
	bool draw;
	uint8_t screen[WIDTH][HEIGHT];
};

struct chip8_gfx gfx;

SDL_Surface *screen;

void init_gfx(char *title);
void draw();
#endif

