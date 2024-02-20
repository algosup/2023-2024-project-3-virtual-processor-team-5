#include "../header/utils.h"

// Déclaration de fonctions pour éviter les avertissements de compilation
void ExecuteADD(ProcessorState* cpu, int destination, int operand1, int operand2);
int ExecuteSUB(ProcessorState* cpu, int destination, int operand1, int operand2);
int ExecuteMUL(uint16_t operand1, uint16_t operand2);
int ExecuteDIV(uint16_t operand1, uint16_t operand2);
bool ExecuteCMP(ProcessorState *state, int registerIndex1, int registerIndex2);
void ExecuteSTR(ProcessorState* cpu, int source, char* destination);
void ExecuteLDR(ProcessorState* cpu, int destination, char* source);
void ExecuteCOPY(ProcessorState *state, int srcRegisterIndex, int destRegisterIndex);
void ExecuteAND(ProcessorState *state, int registerIndex1, int registerIndex2);
void ExecuteXOR(ProcessorState *state, int registerIndex1, int registerIndex2);
void ExecuteNOT(ProcessorState *state, int registerIndex);
void ExecuteOR(ProcessorState *state, int registerIndex1, int registerIndex2);
void ExecuteMOV(int* operand1, int* operand2, OperandType operand2type);
void ExecuteRMV( ProcessorState *state, int registerIndex);
// uint16_t mem_read(Register *register_value);
void update_flags(ProcessorState *state);
void read_file(char *filename, char *file_directory);
void execute_instruction(instruction_t instruction, ProcessorState *cpu);

int main() {
    Memory memory = {{0}};  // Initializes memory with zeros

    ProcessorState cpu = {0};  // Initializes processor with default values

    char input[100];
    printf("Simple Terminal\n");

    read_file("code.txt", "C:\\Users\\LucasMEGNAN\\Desktop\\2023-2024-project-3-virtual-processor-team-5\\code.txt");
    printf("\n\n");

    while (1) {
        printf("\n> ");
        fgets(input, sizeof(input), stdin);

        // Deletes the newline character from the buffer
        size_t len = strlen(input);
        if (len > 0 && input[len - 1] == '\n') {
            input[len - 1] = '\0';
        }

        // Analyzes the instruction
        if (strcmp(input, "exit") == 0) {
            printf("\x1b[36mExiting...\x1b[0m\n");
            break;
        } else if (strcmp(input, "ADD") == 0) {
            uint16_t operand1, operand2;
            printf("Enter operand 1: ");
            scanf("%hu", &operand1);
            printf("Enter operand 2: ");
            scanf("%hu", &operand2);
            while (getchar() != '\n');
            ExecuteADD(&cpu, destination, operand1, operand2);
            
        } else if (strcmp(input, "SUB") == 0) {
            uint16_t operand1, operand2;
            printf("Enter operand 1: ");
            scanf("%hu", &operand1);
            printf("Enter operand 2: ");
            scanf("%hu", &operand2);
            while (getchar() != '\n');
            ExecuteSUB(&cpu, destination, operand1, operand2);

        } else if (strcmp(input, "MUL") == 0) {
            uint16_t operand1, operand2;
            printf("Enter operand 1: ");
            scanf("%hu", &operand1);
            printf("Enter operand 2: ");
            scanf("%hu", &operand2);
            while (getchar() != '\n');
            ExecuteMUL(operand1, result);

        } else if (strcmp(input, "DIV") == 0) {
            uint16_t operand1, operand2;
            printf("Enter operand 1: ");
            scanf("%hu", &operand1);
            printf("Enter operand 2: ");
            scanf("%hu", &operand2);
            while (getchar() != '\n');
            ExecuteDIV(operand1, operand2);

        } else if (strcmp(input, "AND") == 0) {
            uint16_t operand1, operand2;
            printf("Enter operand 1: ");
            scanf("%hu", &operand1);
            printf("Enter operand 2: ");
            scanf("%hu", &operand2);
            while (getchar() != '\n');
            ExecuteAND(&cpu, operand1, operand2);

        } else if (strcmp(input, "OR") == 0) {
            uint16_t operand1, operand2;
            printf("Enter operand 1: ");
            scanf("%hu", &operand1);
            printf("Enter operand 2: ");
            scanf("%hu", &operand2);
            while (getchar() != '\n');
            ExecuteOR(&cpu, operand1, operand2);

        } else if (strcmp(input, "XOR") == 0) {
            uint16_t operand1, operand2;
            printf("Enter operand 1: ");
            scanf("%hu", &operand1);
            printf("Enter operand 2: ");
            scanf("%hu", &operand2);
            while (getchar() != '\n');
            ExecuteXOR(&cpu, operand1, operand2);

        } else if (strcmp(input, "NOT") == 0) {
            uint16_t operand1;
            printf("Enter operand 1: ");
            scanf("%hu", &operand1);
            while (getchar() != '\n');
            ExecuteNOT(&cpu, operand1);

        } else if (strcmp(input, "STR") == 0) {
            int registerIndex;
            printf("Enter register index (0-8) to store the result: ");
            if (scanf("%d", &registerIndex) == 1) {
                while (getchar() != '\n');
                ExecuteSTR(&cpu, registerIndex, result);
            } else {
                fprintf(stderr, "\x1b[31mError: Invalid input\x1b[0m\n");
                while (getchar() != '\n');
            }
        } else if (strcmp(input, "LDR") == 0) {
            int registerIndex;
            printf("Enter register index (0-8): ");
            if (scanf("%d", &registerIndex) == 1) {
                // verify if the conversion succeeded
                while (getchar() != '\n');  // Consumes newline character remaining in buffer
                ExecuteLDR(&cpu, &cpu.R[0], registerIndex);
            } else {
                fprintf(stderr, "\x1b[31mError: Invalid input\x1b[0m\n");
                // Cleans buffer in case of incorrect input
                while (getchar() != '\n');
            }
        } else if (strcmp(input, "COPY") == 0 || strcmp(input, "copy") == 0) {
            int srcRegisterIndex, destRegisterIndex;
            printf("Enter source register index (0-8): ");
            if (scanf("%d", &srcRegisterIndex) == 1 && srcRegisterIndex >= 0 && srcRegisterIndex < NUM_REGISTERS) {
                while (getchar() != '\n');
                printf("Enter destination register index (0-8): ");
                if (scanf("%d", &destRegisterIndex) == 1 && destRegisterIndex >= 0 && destRegisterIndex < NUM_REGISTERS) {
                    while (getchar() != '\n');
                    ExecuteCOPY(&cpu, srcRegisterIndex, destRegisterIndex);
                } else {
                    fprintf(stderr, "\x1b[31mError: Invalid destination register index\x1b[0m\n");
                    while (getchar() != '\n');
                }
            } else {
                fprintf(stderr, "\x1b[31mError: Invalid source register index\x1b[0m\n");
                while (getchar() != '\n');
            }
        } else if (strcmp(input, "CMP") == 0) {
            uint16_t operand1, operand2;
            printf("Enter operand 1: ");
            scanf("%hu", &operand1);
            printf("Enter operand 2: ");
            scanf("%hu", &operand2);
            while (getchar() != '\n');
            ExecuteCMP(&cpu, operand1, operand2);

        } else if (strcmp(input, "RMV") == 0) {
            uint16_t operand1;
            printf("Enter operand 1: ");
            scanf("%hu", &operand1);
            while (getchar() != '\n');
            ExecuteRMV(&cpu, operand1);
        } else {
            printf("\x1b[33mUnknown instruction. Try ADD, SUB, MUL, DIV, AND, OR, XOR, NOT, STR, LDR, COPY, CMP, RMV or exit.\x1b[0m\n");
        }
    }
    return 0;
}
