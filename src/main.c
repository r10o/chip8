#include "cpu.h"
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include "SDL/SDL.h"

#define MSPF 1000 / 80

extern void init_cpu(char *file_name);
extern void emulate_cycle();
extern void quit();

int main(int argc, char *argv[])
{
	if (argc == 1) {
		printf("Usage: chip8 -[hv] [file]\n");
		printf("\t-h\tShow this text.\n");
		printf("\t-v\tShow program version.\n");
	} else if (argc > 1) {
		for (int i = 1; i < argc; i++) {
			if (argv[i][0] == '-') {
				int length = strlen(argv[i]) - 1;
				for (int j = 0; j < length; j++) {
					if (argv[i][1] == 'v') {
						printf("chip8 version %s\n", VERSION);
					} else if (argv[i][1] == 'h') { 
						printf("Usage: chip8 -[hv] [file]\n");
						printf("\t-h\tShow this text.\n");
						printf("\t-v\tShow program version.\n");
					}
				}
			} else {
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
			}
		}
	}

	return 0;
}

