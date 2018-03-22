#include "dis.h"

void op_dis(uint16_t pc, uint16_t opcode)
{
	uint8_t first_byte = opcode >> 8;
	uint8_t second_byte = opcode & 0xff;
	printf("%02x %02x %02x ", pc, first_byte, second_byte);
	switch(first_byte >> 4) {
		case 0x0:
			switch((first_byte << 8) | second_byte) {
				case 0x00e0: printf("%-10s", "CLS"); break;
				case 0x00ee: printf("%-10s", "RET"); break;
				default: printf("UNKNOWN 0"); break;
			}
			break;
		case 0x1: printf("%-10s &%x%02x", "JP", first_byte & 0xf, second_byte); break;
		case 0x2: printf("%-10s &%x%02x", "CALL", first_byte & 0xf, second_byte); break;
		case 0x3: printf("%-10s V%01x, #%02x", "SE", first_byte & 0xf, second_byte); break;
		case 0x4: printf("%-10s V%01x, #%02x", "SNE", first_byte & 0xf, second_byte); break;
		case 0x5: printf("%-10s V%01x, V%01x", "SE", first_byte & 0xf, second_byte >> 4); break;
		case 0x6: printf("%-10s V%01x, #%02x", "LD", first_byte & 0xf, second_byte); break;
		case 0x7: printf("%-10s V%01x, #%02x", "ADD", first_byte & 0xf, second_byte); break;
		case 0x8:
			  switch(second_byte & 0xf) {
				  case 0x0: printf("%-10s V%01x, V%01x", "LD", first_byte & 0xf, second_byte >> 4); break;
				  case 0x1: printf("%-10s V%01x, V%01x", "OR", first_byte & 0xf, second_byte >> 4); break;
				  case 0x2: printf("%-10s V%01x, V%01x", "AND", first_byte & 0xf, second_byte >> 4); break;
				  case 0x3: printf("%-10s V%01x, V%01x", "XOR", first_byte & 0xf, second_byte >> 4); break;
				  case 0x4: printf("%-10s V%01x, V%01x", "ADD", first_byte & 0xf, second_byte >> 4); break;
				  case 0x5: printf("%-10s V%01x, V%01x", "SUB", first_byte & 0xf, second_byte >> 4); break;
				  case 0x6: printf("%-10s V%01x, {,V%01x}", "SHR", first_byte & 0xf, second_byte >> 4); break;
				  case 0x7: printf("%-10s V%01x, V%01x", "SUBN", first_byte & 0xf, second_byte >> 4); break;
				  case 0xe: printf("%-10s V%01x, {,V%01x}", "SHL", first_byte & 0xf, second_byte >> 4); break;
				  default: printf("UNKNOWN 8");
			  }
			  break;
		case 0x9: printf("%-10s V%01x, V%01x", "SNE", first_byte & 0xf, second_byte >> 4); break;
		case 0xa: printf("%-10s I, &%x%02x", "LD", first_byte & 0xf, second_byte); break; case 0xb: printf("%-10s $%02x%02x", "JP", first_byte & 0xf, second_byte); break; case 0xc: printf("%-10s V%01x, #%02x", "RND", first_byte & 0xf, second_byte); break;
		case 0xd: printf("%-10s V%01x, V%01x, #%01x", "DRW", first_byte & 0xf, second_byte >> 4, second_byte & 0xf); break;
		case 0xe:
			  switch(second_byte) {
				  case 0x9e: printf("%-10s V%01x", "SKP", first_byte & 0xf); break;
				  case 0xa1: printf("%-10s V%01x", "SKNP", first_byte & 0xf); break;
				  default: printf("UNKNOWN E"); break;
			  }
			  break;
		case 0xf:
			  switch(second_byte) {
				  case 0x07: printf("%-10s V%01x, DELAY", "LD", first_byte & 0xf); break;
				  case 0x0a: printf("%-10s V%01x, Key", "LD", first_byte & 0xf); break;
				  case 0x15: printf("%-10s DELAY, V%01x", "LD", first_byte & 0xf); break;
				  case 0x18: printf("%-10s SOUND, V%01x", "LD", first_byte & 0xf); break;
				  case 0x1e: printf("%-10s I, V%01x", "ADD", first_byte & 0xf); break;
				  case 0x29: printf("%-10s I, V%01x", "LD", first_byte & 0xf); break;
				  case 0x33: printf("%-10s [I], V%01x", "LD", first_byte & 0xf); break;
				  case 0x55: printf("%-10s [I], V%01x", "LD", first_byte & 0xf); break;
				  case 0x65: printf("%-10s V%01x, [I]", "LD", first_byte & 0xf); break;
				  default: printf("UNKNOWN F"); break;
			  }
	}
	printf("\n");
}

