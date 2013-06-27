#ifndef INPUT_H
#define INPUT_H
#include <stdlib.h>
#include "SDL/SDL.h"

enum key_state {
	up,
	down
};

enum key_state keys[0xf];

/* Functions */
void get_input();
#endif
