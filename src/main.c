#include "cpu.h"
#include <stdio.h>
#include <stdbool.h>
#include <SDL/SDL.h>

#define MPF 1000 / 60

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

#if DEBUG != 1
	uint32_t ticks = SDL_GetTicks();
	int16_t delay_time = 0;
#endif

	bool running = true;
	while (running) {
		emulate_cycle();
#if DEBUG == 1
		bool wait = true;
		while (wait) {
			SDL_Event debug_event;
			while (SDL_PollEvent(&debug_event)) {
				switch (debug_event.type) {
					case SDL_QUIT:
						running = false;
						wait = false;
						break;
					case SDL_KEYDOWN:
						if (debug_event.key.keysym.sym == SDLK_SPACE) {
							wait = false;
						}
						break;
					default:
						break;
				}
			}
		}
#else
		ticks += MPF;
		delay_time = ticks - SDL_GetTicks();

		if (delay_time >= 0) {
			SDL_Delay(delay_time);
		}
#endif
	}
	quit();
	return 0;
}
