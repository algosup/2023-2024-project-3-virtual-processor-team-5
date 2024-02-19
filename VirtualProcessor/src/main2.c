#include "../header/utils2.h"

// Declaring functions to avoid compiler warnings
void executeADD(ProcessorState *cpu, uint8_t regA, uint8_t regB);
void executeSUB(ProcessorState *cpu, uint8_t regA, uint8_t regB);
void executeMUL(ProcessorState *cpu, uint8_t regA, uint8_t regB);
void executeDIV(ProcessorState *cpu, uint8_t regA, uint8_t regB);
void executeAND(ProcessorState *cpu, uint8_t regA, uint8_t regB);
void executeXOR(ProcessorState *cpu, uint8_t regA, uint8_t regB);
void executeOR(ProcessorState *cpu, uint8_t regA, uint8_t regB);
void executeNOT(ProcessorState *cpu, uint8_t regA);
void executeCMP(ProcessorState *cpu, uint8_t regA, uint8_t regB);
void executeSTR(ProcessorState *cpu, uint8_t regA, uint8_t regB);
void executeLDR(ProcessorState *cpu, uint8_t regA, uint8_t regB);
void executeCOPY(ProcessorState *cpu, uint8_t regA, uint8_t regB);

// Function for parsing instructions
int parser(FILE *file);

// Function to read a file
uint16_t mem_read(Register *register_value);
void read_file(char *filename, char *file_directory);

//Memory allocation function
void update_flags(ProcessorState *state);

// Function to execute instructions
void execute_instruction(uint8_t opcode, ProcessorState *cpu);

int main() {
    Memory memory = {{0}};  // Initializes memory with zeros

    ProcessorState cpu = {0};  // Initializes processor with default values

    char input[100];
    printf("Simple Terminal\n");

    read_file("code.txt", "code.txt");
}
