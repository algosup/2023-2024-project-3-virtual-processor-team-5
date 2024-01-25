#include "../include/utils.h"

// Déclaration de fonctions pour éviter les avertissements de compilation
int executeADD(uint16_t operand1, uint16_t operand2);
int executeMUL(uint16_t operand1, uint16_t operand2);
int executeDIV(uint16_t operand1, uint16_t operand2);
int executeSUB(uint16_t operand1, uint16_t operand2);
void executeST(ProcessorState *state, int registerIndex, int result);
void executeLD(ProcessorState *state, Register *destination, int registerIndex);
uint16_t mem_read(Register *register_value);
void update_flags(ProcessorState *state);
void executeCOPY(ProcessorState *state, int srcRegisterIndex, int destRegisterIndex);
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
                executeST(&cpu, registerIndex, result);
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
        } else if (strcmp(input, "COPY") == 0 || strcmp(input, "copy") == 0) {
            int srcRegisterIndex, destRegisterIndex;
            printf("Enter source register index (0-4): ");
            if (scanf("%d", &srcRegisterIndex) == 1 && srcRegisterIndex >= 0 && srcRegisterIndex < NUM_REGISTERS) {
                while (getchar() != '\n');
                printf("Enter destination register index (0-4): ");
                if (scanf("%d", &destRegisterIndex) == 1 && destRegisterIndex >= 0 && destRegisterIndex < NUM_REGISTERS) {
                    while (getchar() != '\n');
                    executeCOPY(&cpu, srcRegisterIndex, destRegisterIndex);
                } else {
                    fprintf(stderr, "\x1b[31mError: Invalid destination register index\x1b[0m\n");
                    while (getchar() != '\n');
                }
            } else {
                fprintf(stderr, "\x1b[31mError: Invalid source register index\x1b[0m\n");
                while (getchar() != '\n');
            }
        }else if (strcmp(input, "COPY") == 0 || strcmp(input, "copy") == 0) {
            int srcRegisterIndex, destRegisterIndex;
            printf("Enter source register index (0-4): ");
            if (scanf("%d", &srcRegisterIndex) == 1 && srcRegisterIndex >= 0 && srcRegisterIndex < NUM_REGISTERS) {
                while (getchar() != '\n');
                printf("Enter destination register index (0-4): ");
                if (scanf("%d", &destRegisterIndex) == 1 && destRegisterIndex >= 0 && destRegisterIndex < NUM_REGISTERS) {
                    while (getchar() != '\n');
                    executeCOPY(&cpu, srcRegisterIndex, destRegisterIndex);
                } else {
                    fprintf(stderr, "\x1b[31mError: Invalid destination register index\x1b[0m\n");
                    while (getchar() != '\n');
                }
            } else {
                fprintf(stderr, "\x1b[31mError: Invalid source register index\x1b[0m\n");
                while (getchar() != '\n');
            }
        } else {
            printf("Unknown instruction. Try ADD, SUB, MUL, DIV, ST, LD, COPY, or exit.\n");
        }
    }

    return 0;
}