#ifndef CHIP8_CPU_H
#define CHIP8_CPU_H

#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

/* Initializes the values of the registers and the timers */
void init_cpu();
void execute_opcode(uint16_t opcode);
void emulate_cycle();
void quit();

#endif

