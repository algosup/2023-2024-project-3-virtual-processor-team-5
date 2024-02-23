#include "../header/utils.h"

// Declaring functions to avoid compiler warnings
void ExecuteADD(ProcessorState* cpu, int destination, int register1, int register2);
void ExecuteSUB(ProcessorState* cpu, int destination, int register1, int register2);
void ExecuteMUL(ProcessorState* cpu, int destination, int register1, int register2);
void ExecuteDIV(ProcessorState* cpu, int destination, int register1, int register2);
void ExecuteAND(ProcessorState* cpu, int destination, int register1, int register2);
void ExecuteXOR(ProcessorState* cpu, int destination, int register1, int register2);
void ExecuteOR(ProcessorState* cpu, int destination, int register1, int register2);
void ExecuteNOT(ProcessorState* cpu, int destination, int register1, int register2);
void ExecuteCMP(ProcessorState* cpu, int destination, int register1, int register2);
void ExecuteMOV(ProcessorState* cpu, int destination, char* source);
void ExecuteSTR(ProcessorState *cpu, uint8_t reg, char* destination);
void ExecuteLDR(ProcessorState* cpu, int destination, char* source);
void ExecuteCOPY(ProcessorState* cpu, int destination, int source);
void executeRMV(ProcessorState *cpu, int destination);
void executeJMP(ProcessorState *cpu, int address);
void executeJZ(ProcessorState *cpu, int address);
void executeJNZ(ProcessorState *cpu, int address);
void executeJE(ProcessorState *cpu, int address);
void executeJNE(ProcessorState *cpu, int address);
void executeNOP(ProcessorState *cpu);

// Function for parsing instructions
int parser(FILE *file);

// Function to read a file
uint16_t mem_read(Memory *memory, uint16_t address);
void read_file(char *filename, char *file_directory);

//Memory allocation function
void update_flags(ProcessorState *state);

// Function to execute instructions
void execute_instruction(instruction_t instruction, ProcessorState *cpu);

int main() {
    Memory memory = {{0}};  // Initializes memory with zeros

    ProcessorState cpu = {0};  // Initializes processor with default values

    printf("Simple Terminal\n");

    read_file("code.txt", "code.txt");
}
