#include "cpu.h"
#include <stdio.h>
#include <stdbool.h>
#include "SDL/SDL.h"

#define MSPF 1000 / 180

extern void init_cpu(char *file_name);
extern void emulate_cycle();
extern void quit();

int main(int argc, char *argv[])
{
	if (argc == 1) {
		printf("Usage: chip8 [option] [file]\n");
		return 1;
	}
	init_cpu(argv[1]);

//	if (SDL_Init(SDL_INIT_EVERYTHING) == -1) {
//		fprintf(stderr, "error: Could not initialize SDL: %s.\n", SDL_GetError());
//		return 1;
//	}

	uint32_t ticks = SDL_GetTicks();
	int16_t delay_time = 0;

	bool running = true;

	while (running) {
		emulate_cycle();

		ticks += MSPF;
		delay_time = ticks - SDL_GetTicks();

		if (delay_time >= 0) {
			SDL_Delay(delay_time);
		}
	}
	quit();
	SDL_Quit();
	return 0;
}
