#ifndef INPUT_H
#define INPUT_H

enum key_state {
	up,
	down
};

#include <stdlib.h>
#include "SDL/SDL.h"

enum key_state keys[0x10];

/* Functions */
void init_input();
void get_input();

#endif

