#include "cpu.h"
#include <stdio.h>
#include <string.h>
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

	uint32_t ticks = SDL_GetTicks();
	int16_t delay_time = 0;

	bool running = true;

	while (running) {
		emulate_cycle();
		ticks += MPF;
		delay_time = ticks - SDL_GetTicks();

		if (delay_time >= 0) {
			SDL_Delay(delay_time);
		} else if (delay_time < 0) {
			fprintf(stderr, "warning: Game is running slowly.\n");
		}
	}

	quit();

//	init_cpu();
//	init_gfx();
//	uint16_t file_size;
//	bool running = true;

//	printf("%d bytes\n", file_size);
//	for (int i = 0; i < (file_size + 0x200); i++) {
//		if ((i % 0x10) == 0) {
//			printf("\n%04x ", i);
//		}
//		printf(" %02x", mem[i]);
//	}
//	printf("\n");

//	while (running) {
//		get_input();
//		emulate_cycle();
//
//		// Draw here
//
//		// Play sound here
//	}

//	free_mem();
	return 0;
}
