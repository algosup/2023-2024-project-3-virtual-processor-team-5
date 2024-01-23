#include <stdio.h>
#include <string.h>
#include <stdint.h>

#include "processor.h"

//****************************** ALGORITHMIC OPERATIONS ******************************//

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

//****************************** DATA MOVEMENT ******************************//

void executeST(ProcessorState *state, uint16_t r0, uint16_t memoryAddress, Memory *memory) {
    // Vérification des limites de la mémoire
    if (memoryAddress >= MEMORY_SIZE) {
        fprintf(stderr, "Error: Memory write out of bounds\n");
        return;
    }
    // Écriture de la valeur du registre à l'adresse mémoire spécifiée
    memory->memory[memoryAddress] = state->R0.value;
}

// STR instruction execution function (store data from register in memory)
void executeSTR(uint16_t instr, uint16_t *reg, uint16_t *mem) {
    uint16_t DR =  (instr & 0x0E00) >> 9;
    uint16_t BaseR = (instr & 0x01C0) >> 6;
    uint16_t offset6 = instr & 0x003F;
    uint16_t address = reg[BaseR] + offset6;
    mem[address] = reg[DR];
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

// LDR instruction execution function (load data from memory in register)
void executeLDR() {

}

// LEA instruction execution function (load effective address in register)
void executeLEA() {

}
