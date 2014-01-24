#ifndef INPUT_H
#define INPUT_H
#include <stdlib.h>
#include "SDL/SDL.h"

enum key_state {
	up,
	down
};

enum key_state keys[0x10];
SDL_Event event;

/* Functions */
void init_input();
void get_input();
void clear_input();
#endif

