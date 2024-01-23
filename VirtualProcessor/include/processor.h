#include <stdio.h>
#include <stdint.h>
#include <string.h>

#define MEMORY_SIZE 1000

// Register structure
typedef struct {
    int value;
} Register;

// Processor status structure
typedef struct {
    Register R0; // general register
    Register R1;
    Register R2;
    Register R3;
    Register R4;
    Register R5;
    Register R6;
    Register R7;
    int PC;  // Program counter
    int LR; // link register
} ProcessorState;

typedef struct {
    uint16_t memory[MEMORY_SIZE];
} Memory;


// ADD instruction execution function
void executeADD(ProcessorState *state, int operand1, int operand2, Register *destination) {
    destination->value = operand1 + operand2;
}

// MUL instruction execution function
void executeMUL(ProcessorState *state, int operand1, int operand2, Register *destination) {
    int result = 0;
    // Iteration to simulate multiplication
    for (int i = 0; i < operand2; ++i) {
        result += operand1;
    }
    destination->value = result;
}

// DIV instruction execution function
void executeDIV(ProcessorState *state, int operand1, int operand2, Register *destination) {
    destination->value = operand1 / operand2;
}

// SUB instruction execution function
void executeSUB(ProcessorState *state, int operand1, int operand2, Register *destination) {
    destination->value = operand1 - operand2;
}

void executeST(ProcessorState *state, uint16_t r0, uint16_t memoryAddress, Memory *memory) {
    // Vérification des limites de la mémoire
    if (memoryAddress >= MEMORY_SIZE) {
        fprintf(stderr, "Error: Memory write out of bounds\n");
        return;
    }
    // Écriture de la valeur du registre à l'adresse mémoire spécifiée
    memory->memory[memoryAddress] = state->R0.value;
}

void executeLD(ProcessorState *state, uint16_t r0, uint16_t memoryAddress, Memory *memory) {
    // Vérification des limites de la mémoire
    if (memoryAddress >= MEMORY_SIZE) {
        fprintf(stderr, "Error: Memory read out of bounds\n");
        return;
    }
    // Écriture de la valeur du registre à l'adresse mémoire spécifiée
    memory->memory[memoryAddress] = state->PC;
    printf("PC: %d\n", state->R0.value);
}
// void executeLD(ProcessorState *state, int destinationRegister, uint16_t pc_offset) {
//     uint16_t address = state->PC + sign_extend(pc_offset, 9);
//     state->registers[destinationRegister] = mem_read(address);
// }


// ST instruction execution function (store data from register in memory)
// ST
// {
//     uint16_t r0 = (instr >> 9) & 0x7;
//     uint16_t pc_offset = sign_extend(instr & 0x1FF, 9);
//     mem_write(reg[R_PC] + pc_offset, reg[r0]);
// }

// LDR instruction execution function (load data from memory in register)

// LEA instruction execution function (load effective address in register)
