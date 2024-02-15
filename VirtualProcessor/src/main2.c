#include "../header/utils2.h"

// Déclaration de fonctions pour éviter les avertissements de compilation
void executeADD(ProcessorState *cpu, uint8_t regA, uint8_t regB);
void executeSUB(ProcessorState *cpu, uint8_t regA, uint8_t regB);
void executeMUL(ProcessorState *cpu, uint8_t regA, uint8_t regB);
void executeDIV(ProcessorState *cpu, uint8_t regA, uint8_t regB);
int parser(char *line, FILE *file);
uint16_t mem_read(Register *register_value);
void update_flags(ProcessorState *state);
void read_file(char *filename, char *file_directory);
void execute_instruction(uint8_t opcode, ProcessorState *cpu);

int main() {
    Memory memory = {{0}};  // Initializes memory with zeros

    ProcessorState cpu = {0};  // Initializes processor with default values

    char input[100];
    printf("Simple Terminal\n");

    read_file("code.txt", "code.txt");
}
