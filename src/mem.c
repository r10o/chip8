#include "mem.h"
#include <stdlib.h>
#include <stdio.h>

void init_mem(char *file_name)
{
	FILE *file = fopen(file_name, "r");
	if (file == NULL) { printf("error: Could not open %s.\n", file_name); }
	fseek(file, 0L, SEEK_END);
	uint16_t file_size = ftell(file);
	fseek(file, 0L, SEEK_SET);
	mem = malloc(file_size + 0x200);
	fread(mem + 0x200, file_size, 1, file);
	fclose(file);

	for (int j = 0; j < sizeof(font); j++) {
		mem[j] = font[j];
	}
}

void free_mem() { free(mem); }
