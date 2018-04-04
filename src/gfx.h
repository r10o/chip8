#ifndef CHIP8_GFX_H
#define CHIP8_GFX_H

#include <stdbool.h>
#include <stdint.h>

#include <SDL/SDL.h>

#define WIDTH 64
#define HEIGHT 32

struct chip8_gfx {
	bool draw;
	uint8_t screen[WIDTH][HEIGHT];
};

struct chip8_gfx gfx;

void init_gfx(char *title);
void draw();

#endif

