#ifndef CPU_H
#define CPU_H

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct chip8_cpu {
	/* Registers */
	uint8_t v[0x10];
	uint16_t i;
	uint8_t dt;
	uint8_t st;
	uint16_t pc;
	uint8_t sp;
	uint16_t stack[16];
};

struct chip8_cpu cpu;

/* Initializes the values of the registers and the timers */
void init_cpu();
void execute_opcode(uint16_t opcode);
void emulate_cycle();
void quit();

#endif

