#include "mem.h"
#include <stdlib.h>
#include <stdio.h>

uint16_t init_mem(char *file_name)
{
	FILE *file = fopen(file_name, "r");
	uint16_t file_size = 0;
	if (file != NULL) {
		fseek(file, 0L, SEEK_END);
		file_size = ftell(file);
		fseek(file, 0L, SEEK_SET);
		mem = malloc(file_size + 0x200);
		fread(mem + 0x200, file_size, 1, file);
		for (uint16_t j = 0; j < sizeof(font); j++) { mem[j] = font[j]; }
	} else {
		fprintf(stderr, "error: Could not open %s.\n", file_name);
		exit(EXIT_FAILURE);
	}

	return file_size;
}

void free_mem() { free(mem); }
