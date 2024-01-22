#include <stddef.h>

#define MEMORY_SIZE 0x10000 //define the size of the memory allocated for the Virtual pprocessor (16 bits)

// define all operations that can be performed by the processor
#define OPCODE_ADD 0x00 // define the operation code for the ADD operation
#define OPCODE_SUB 0x01
#define OPCODE_MUL 0x02
#define OPCODE_DIV 0x03
#define OPCODE_MOV 0x04
#define OPCODE_AND 0x05
#define OPCODE_OR  0x06
#define OPCODE_XOR 0x07
#define OPCODE_NOT 0x08
#define OPCODE_CMP 0x09
#define OPCODE_JMP 0x0A
#define OPCODE_INC 0x0B
#define OPCODE_DEC 0x0C
#define OPCODE_NEG 0x0D
#define OPCODE_PUSH 0x0E
#define OPCODE_POP 0x0F
#define OPCODE_LOOP 0x10
#define OPCODE_CALL 0x11
#define OPCODE_RET 0x12
#define OPCODE_INT 0x13

// define all registers that can be used by the processor
#define REG_AH 0x00
#define REG_AL 0x01
#define REG_BH 0x02
#define REG_BL 0x03
#define REG_CH 0x04
#define REG_CL 0x05
#define REG_DH 0x06
#define REG_DL 0x07
#define REG_SP 0x08
#define REG_SI 0x09
