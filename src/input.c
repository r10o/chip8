#include <SDL.h>
#include "input.h"

SDL_Event event;

void init_input()
{
	memset(keys, 0, sizeof(keys));
}

void get_input()
{
	while (SDL_PollEvent(&event)) {
		switch (event.type) {
			case SDL_QUIT:
				exit(0);
				break;
			case SDL_KEYDOWN:
				switch (event.key.keysym.sym) {
					case SDLK_ESCAPE: exit(0); break;
					case SDLK_x: keys[0x0] = down; break;
					case SDLK_1: keys[0x1] = down; break;
					case SDLK_2: keys[0x2] = down; break;
					case SDLK_3: keys[0x3] = down; break;
					case SDLK_q: keys[0x4] = down; break;
					case SDLK_w: keys[0x5] = down; break;
					case SDLK_e: keys[0x6] = down; break;
					case SDLK_a: keys[0x7] = down; break;
					case SDLK_s: keys[0x8] = down; break;
					case SDLK_d: keys[0x9] = down; break;
					case SDLK_z: keys[0xa] = down; break;
					case SDLK_c: keys[0xb] = down; break;
					case SDLK_4: keys[0xc] = down; break;
					case SDLK_r: keys[0xd] = down; break;
					case SDLK_f: keys[0xe] = down; break;
					case SDLK_v: keys[0xf] = down; break;
					default: break;
				}
				break;
			case SDL_KEYUP:
				switch (event.key.keysym.sym) {
					case SDLK_ESCAPE: exit(0); break;
					case SDLK_x: keys[0x0] = up; break;
					case SDLK_1: keys[0x1] = up; break;
					case SDLK_2: keys[0x2] = up; break;
					case SDLK_3: keys[0x3] = up; break;
					case SDLK_q: keys[0x4] = up; break;
					case SDLK_w: keys[0x5] = up; break;
					case SDLK_e: keys[0x6] = up; break;
					case SDLK_a: keys[0x7] = up; break;
					case SDLK_s: keys[0x8] = up; break;
					case SDLK_d: keys[0x9] = up; break;
					case SDLK_z: keys[0xa] = up; break;
					case SDLK_c: keys[0xb] = up; break;
					case SDLK_4: keys[0xc] = up; break;
					case SDLK_r: keys[0xd] = up; break;
					case SDLK_f: keys[0xe] = up; break;
					case SDLK_v: keys[0xf] = up; break;
					default: break;
				}
				break;
		}
	}
}

