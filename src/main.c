#include "cpu.h"
#include <stdio.h>
#include <stdbool.h>
#include "SDL/SDL.h"

#define MSPF 1000 / 60

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

	if (SDL_Init(SDL_INIT_EVERYTHING) == -1) {
		fprintf(stderr, "Could not initialize SDL: %s.\n", SDL_GetError());
		return 1;
	}

	uint32_t ticks = SDL_GetTicks();
	int16_t delay_time = 0;

	bool running = true;
	bool cont_delay = true;
	bool wait;

	SDL_Event delay_event;

	while (running) {
		emulate_cycle();

		if (cont_delay) {
			wait = true;
		}

		while (wait) {
			while (SDL_PollEvent(&delay_event)) {
				switch (delay_event.type) {
					case SDL_KEYDOWN:
						switch (delay_event.key.keysym.sym) {
							case SDLK_SPACE:
								wait = false;
								break;
							case SDLK_p:
								if (wait) {
									wait = false;
									cont_delay = false;
								} else {
									cont_delay = true;
								}
								break;
							default:
								break;
						}
					default:
						break;
				}
			}
		}

		ticks += MSPF;
		delay_time = ticks - SDL_GetTicks();

		if (delay_time >= 0) {
			SDL_Delay(delay_time);
		}
	}
	quit();
	return 0;
}
