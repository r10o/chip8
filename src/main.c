#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#include <SDL/SDL.h>

#include "cpu.h"

#define MILISECONDS_PER_FRAME 1000 / 80

int main(int argc, char *argv[])
{
	if (argc > 1) {
		init_cpu(argv[1]);

		uint32_t ticks = SDL_GetTicks();
		int16_t delay_time = 0;

		bool running = true;

		while (running) {
			emulate_cycle();

			ticks += MILISECONDS_PER_FRAME;
			delay_time = ticks - SDL_GetTicks();

			if (delay_time >= 0)
				SDL_Delay(delay_time);
		}

		quit();
		SDL_Quit();
	} else {
		printf("Usage: chip8 -[hv] [file]\n");
	}

	return 0;
}

