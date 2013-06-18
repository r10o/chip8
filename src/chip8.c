#include "cpu.h"
#include "mem.h"
#include "input.h"

int main(int argc, char *argv[])
{
	init_cpu();
	init_gfx();
	init_mem();
	free_mem();
}
