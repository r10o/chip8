#ifndef CPU_H
#define CPU_H
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

struct chip8_cpu {
	/* Registers */
	uint8_t v[16];
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

/* For internal use only */
void cls_0();
void ret_0();
void jp_1(uint16_t address);
void call_2(uint16_t address);
void se_3(uint8_t nib, uint8_t byte);
void sne_4(uint8_t nib, uint8_t byte);
void se_5(uint8_t nib1, uint8_t nib2);
void ld_6(uint8_t nib, uint8_t byte);
void add_7(uint8_t nib, uint8_t byte);
void ld_8(uint8_t nib1, uint8_t nib2);
void or_8(uint8_t nib1, uint8_t nib2);
void and_8(uint8_t nib1, uint8_t nib2);
void xor_8(uint8_t nib1, uint8_t nib2);
void add_8(uint8_t nib1, uint8_t nib2);
void sub_8(uint8_t nib1, uint8_t nib2);
void shr_8(uint8_t nib);
void subn_8(uint8_t nib1, uint8_t nib2);
void shl_8(uint8_t nib);
void sne_9(uint8_t nib1, uint8_t nib2);
void ld_a(uint16_t address);
void jp_b(uint16_t address);
void rnd_c(uint8_t nib, uint8_t byte);
void drw_d(uint8_t nib1, uint8_t nib2, uint8_t nib3);
void skp_e(uint8_t nib);
void sknp_e(uint8_t nib);
void ld_f07(uint8_t nib);
void ld_f0a(uint8_t nib);
void ld_f15(uint8_t nib);
void ld_f18(uint8_t nib);
void add_f(uint8_t nib);
void ld_f29(uint8_t nib);
void ld_f33(uint8_t nib);
void ld_f55(uint8_t nib);
void ld_f65(uint8_t nib);
#endif
