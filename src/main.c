#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#include <SDL/SDL.h>

#include "cpu.h"

#define MSPF 1000 / 80

extern void init_cpu(char *file_name);
extern void emulate_cycle();
extern void quit();

int main(int argc, char *argv[]) {
	if (argc > 1) {
		init_cpu(argv[i]);

		uint32_t ticks = SDL_GetTicks();
		int16_t delay_time = 0;

		bool running = true;

		while (running) {
			emulate_cycle();

			ticks += MSPF;
			delay_time = ticks - SDL_GetTicks();

			if (delay_time >= 0)
				SDL_Delay(delay_time);
		}

		quit();
		SDL_Quit();
	} else {
		printf("Usage: chip8 -[hv] [file]\n");
	}
}

return 0;
}

