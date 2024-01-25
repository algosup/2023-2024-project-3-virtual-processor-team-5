#include "../include/instructions.h"

// Déclaration de fonctions pour éviter les avertissements de compilation
void executeADD(uint16_t operand1, uint16_t operand2);
void executeMUL(uint16_t operand1, uint16_t operand2);
void executeDIV(uint16_t operand1, uint16_t operand2);
void executeSUB(uint16_t operand1, uint16_t operand2);
void executeST(ProcessorState *state, int registerIndex);
void executeLD(ProcessorState *state, Register *destination, int registerIndex);
uint16_t mem_read(Register *register_value);
void update_flags(ProcessorState *state);
void copy(ProcessorState *state, Register *source, Register *destination);
void read_file(char *filename, char *file_directory);

int main() {
    Memory memory = {{0}};  // Initializes memory with zeros

    ProcessorState cpu = {0};  // Initializes processor with default values

    char input[100];
    printf("Simple Terminal\n");

    read_file("code.txt", "/Users/gregory-pagnoux/Documents/project/project3_virtual-processor/2023-2024-project-3-virtual-processor-team-5/code.txt");

    while (1) {
        printf("> ");
        fgets(input, sizeof(input), stdin);

        // Deletes the newline character from the buffer
        size_t len = strlen(input);
        if (len > 0 && input[len - 1] == '\n') {
            input[len - 1] = '\0';
        }

        // Analyzes the instruction
        if (strcmp(input, "exit") == 0) {
            printf("Exiting...\n");
            break; 
    } else if (strcmp(input, "ADD") == 0) {
            uint16_t operand1, operand2;
            printf("Enter operand 1: ");
            scanf("%hu", &operand1);
            printf("Enter operand 2: ");
            scanf("%hu", &operand2);
            while (getchar() != '\n');
            executeADD(operand1, operand2);
            
        } else if (strcmp(input, "MUL") == 0) {
            uint16_t operand1, operand2;
            printf("Enter operand 1: ");
            scanf("%hu", &operand1);
            printf("Enter operand 2: ");
            scanf("%hu", &operand2);
            while (getchar() != '\n');
            executeMUL(operand1, operand2);

        } else if (strcmp(input, "DIV") == 0) {
            uint16_t operand1, operand2;
            printf("Enter operand 1: ");
            scanf("%hu", &operand1);
            printf("Enter operand 2: ");
            scanf("%hu", &operand2);
            while (getchar() != '\n');
            executeDIV(operand1, operand2);

        } else if (strcmp(input, "SUB") == 0) {
            uint16_t operand1, operand2;
            printf("Enter operand 1: ");
            scanf("%hu", &operand1);
            printf("Enter operand 2: ");
            scanf("%hu", &operand2);
            while (getchar() != '\n');
            executeSUB(operand1, operand2);

        } else if (strcmp(input, "ST") == 0) {
            int registerIndex;
            printf("Enter register index (0-4) to store the result: ");
            if (scanf("%d", &registerIndex) == 1) {
                while (getchar() != '\n');
                executeST(&cpu, registerIndex);
            } else {
                fprintf(stderr, "\x1b[31mError: Invalid input\x1b[0m\n");
                while (getchar() != '\n');
            }
        } else if (strcmp(input, "LD") == 0) {
            int registerIndex;
            printf("Enter register index (0-4): ");
            if (scanf("%d", &registerIndex) == 1) {
                // verify if the conversion succeeded
                while (getchar() != '\n');  // Consumes newline character remaining in buffer
                executeLD(&cpu, &cpu.R1, registerIndex);
            } else {
                fprintf(stderr, "\x1b[31mError: Invalid input\x1b[0m\n");
                // Cleans buffer in case of incorrect input
                while (getchar() != '\n');
            }
        }else if (strcmp(input, "COPY") == 0 || strcmp(input, "copy") == 0) {
            copy(&cpu, &cpu.R0, &cpu.R2);
            printf("Value in R2: %hu\n", cpu.R2.value);
        } else {
            printf("Unknown instruction. Try ADD, SUB, MUL, DIV, ST, LD, COPY, or exit.\n");
        }
    }

    return 0;
}