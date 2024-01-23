#include "../include/instructions.h"

int main() {
    Memory memory = {{0}};  // Initialise la mémoire avec des valeurs par défaut
    ProcessorState cpu = {0};  // Initializes processor with default values
    char input[100];
    printf("Simple Terminal\n");
    while (1) {
        printf("> ");
        fgets(input, sizeof(input), stdin);
        // Deletes the newline character from the buffer
        size_t len = strlen(input);
        if (len > 0 && input[len - 1] == '\n') {
            input[len - 1] = '\0';
        }
        // Analyzes the instruction (here, we simplify by assuming ADD with two operands)
        if (strcmp(input, "exit") == 0) {
            printf("Exiting...\n");
            break; 
        } else if (strcmp(input, "ADD") == 0) {
            int operand1, operand2;
            printf("Enter operand 1: ");
            scanf("%d", &operand1);
            printf("Enter operand 2: ");
            scanf("%d", &operand2);
            while (getchar() != '\n'); // Consumes newline character remaining in buffer
            executeADD(&cpu, operand1, operand2, &cpu.R0); // Executes ADD instruction
            printf("Result in R0: %d\n", cpu.R0.value); // Print the result
        } else if (strcmp(input, "MUL") == 0) {
            int operand1, operand2;
            printf("Enter operand 1: ");
            scanf("%d", &operand1);
            printf("Enter operand 2: ");
            scanf("%d", &operand2);
            while (getchar() != '\n');
            executeMUL(&cpu, operand1, operand2, &cpu.R0); // Execute MUL instruction
            printf("Result in R0: %d\n", cpu.R0.value);
        } else if (strcmp(input, "DIV") == 0){
            int operand1, operand2;
            printf("Enter operand 1: ");
            scanf("%d", &operand1);
            printf("Enter operand 2: ");
            scanf("%d", &operand2);
            while (getchar() != '\n');
            executeDIV(&cpu, operand1, operand2, &cpu.R0); // Execute DIV instruction
            printf("Result in R0: %d\n", cpu.R0.value);
        } else if (strcmp(input, "SUB") == 0){
            int operand1, operand2;
            printf("Enter operand 1: ");
            scanf("%d", &operand1);
            printf("Enter operand 2: ");
            scanf("%d", &operand2);
            while (getchar() != '\n');
            executeSUB(&cpu, operand1, operand2, &cpu.R0); // Execute SUB instruction
            printf("Result in R0: %d\n", cpu.R0.value);
        } else if (strcmp(input, "ST") == 0){
            int memoryAddress;
            printf("Enter memory address: ");
            scanf("%d", &memoryAddress);
            while (getchar() != '\n');
            executeST(&cpu, cpu.R0.value, memoryAddress, &memory); // Execute ST instruction
        } else if ((strcmp(input, "STR") == 0)){
            uint16_t instr;
            uint16_t reg[8];
            uint16_t mem[MEMORY_SIZE];
            executeSTR(instr, reg, mem); // Execute STR instruction
            /*
            int memoryAddress;
            printf("Enter memory address: ");
            scanf("%d", &memoryAddress);
            while (getchar() != '\n');
            executeSTR(memoryAddress, &cpu.R0, memory.memory); // Execute STR instruction
            */
        } else if (strcmp(input, "LD")==0){
            int memoryAddress;
            printf("Enter memory address: ");
            scanf("%d", &memoryAddress);
            while (getchar() != '\n');
            executeLD(&cpu, cpu.R0.value, memoryAddress, &memory); // Execute LD instruction
        } else {
            printf("Unknown instruction. Try ADD, SUB, MUL, DIV.\n");
        }
    }
    return 0;
}
