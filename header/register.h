#define MEMORY_SIZE 0x10000 //define the size of the memory allocated for the Virtual pprocessor (16 bits)

#define AX 0x00 
#define BX 0x01
#define CX 0x02
#define DX 0x03
#define SI 0x04
#define IX 0x05

// define all operations that can be performed by the processor
#define ADD 0x00 // define the operation code for the ADD operation
#define SUB 0x01
#define MUL 0x02
#define DIV 0x03
#define MOV 0x04
#define CMP 0x05
#define JMP 0x06
#define CALL 0x07
#define RET 0x08
#define INT 0x09
/*
#define OPCODE_AND 0x0A
#define OPCODE_OR  0x0B
#define OPCODE_XOR 0x0C
#define OPCODE_NOT 0x0D
#define OPCODE_INC 0x0E
#define OPCODE_DEC 0x0F
#define OPCODE_NEG 0x10
#define OPCODE_LOOP 0x11
#define OPCODE_PUSH 0x12
#define OPCODE_POP 0x13
*/

char registerArr[6] = {AX, BX, CX, DX, SI, IX};
