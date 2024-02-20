// uint16_t lastResult = 0; 

// //****************************** ALGORITHMIC OPERATIONS ******************************//
// //*************************** IMPLEMENT ADD, MUL, DIV, SUB ***************************//

// // ADD instruction execution function
// // int ExecuteADD(uint16_t operand1, uint16_t operand2) {
// //     lastResult = operand1 + operand2;
// //     printf("Result of ADD: %hu\n", lastResult);
// //     return lastResult;
// // }

// void ExecuteADD(ProcessorState* cpu, int destination, int operand1, int operand2) {
//     cpu->R[destination] = cpu->R[operand1] + cpu->R[operand2];
// }

// // SUB instruction execution function
// int ExecuteSUB(ProcessorState* cpu, int destination, int operand1, int operand2) {
//     cpu->R[destination] = cpu->R[operand1] - cpu->R[operand2];
//     printf("Result of SUB: %hu\n", lastResult);
//     return lastResult;
// }

// // MUL instruction execution function
// int ExecuteMUL(uint16_t operand1, uint16_t operand2) {
//     lastResult = operand1 * operand2;
//     printf("Result of MUL: %hu\n", lastResult);
//     return lastResult;
// }

// // DIV instruction execution function
// int ExecuteDIV(uint16_t operand1, uint16_t operand2) {
//     if (operand2 != 0) {
//         lastResult = operand1 / operand2;
//         printf("Result of DIV: %hu\n", lastResult);
//         return lastResult;
//     } else {
//         fprintf(stderr, "Error: Division by zero\n");
//         return 0;
//     }
// }

// //****************************** LOGICAL OPERATIONS ******************************//
// //*********************** IMPLEMENT AND, OR, XOR, NOT, CMP ***********************//

// bool ExecuteCMP(ProcessorState *state, int registerIndex1, int registerIndex2) {
//     if (registerIndex1 >= 0 && registerIndex1 < NUM_REGISTERS && registerIndex2 >= 0 && registerIndex2 < NUM_REGISTERS) {
//         if (state->R[registerIndex1] == state->R[registerIndex2]) {
//             printf("Values in register R%d and R%d are equal.\n", registerIndex1, registerIndex2);
//             return true;
//         } else if (state->R[registerIndex1] > state->R[registerIndex2]) {
//             printf("Value in register R%d is greater than value in register R%d.\n", registerIndex1, registerIndex2);
//             return false;
//         } else {
//             printf("Value in register R%d is less than value in register R%d.\n", registerIndex1, registerIndex2);
//             return false;
//         }
//     } else {
//         fprintf(stderr, "\x1b[31mError: Invalid register index\x1b[0m\n");
//         return false;
//     }
// }

// // AND instruction execution function
// void ExecuteAND(ProcessorState *state, int registerIndex1, int registerIndex2) {
//     if (registerIndex1 >= 0 && registerIndex1 < NUM_REGISTERS && registerIndex2 >= 0 && registerIndex2 < NUM_REGISTERS) {
//         state->R[registerIndex1] = state->R[registerIndex1] & state->R[registerIndex2];
//         printf("Result of AND: %hu\n", state->R[registerIndex1]);
//     } else {
//         fprintf(stderr, "\x1b[31mError: Invalid register index\x1b[0m\n");
//     }
// }

// // XOR instruction execution function
// void ExecuteXOR(ProcessorState *state, int registerIndex1, int registerIndex2) {
//     if (registerIndex1 >= 0 && registerIndex1 < NUM_REGISTERS && registerIndex2 >= 0 && registerIndex2 < NUM_REGISTERS) {
//         state->R[registerIndex1] = state->R[registerIndex1] ^ state->R[registerIndex2];
//         printf("Result of XOR: %hu\n", state->R[registerIndex1]);
//     } else {
//         fprintf(stderr, "\x1b[31mError: Invalid register index\x1b[0m\n");
//     }
// }

// // NOT instruction execution function
// void ExecuteNOT(ProcessorState *state, int registerIndex) {
//     if (registerIndex >= 0 && registerIndex < NUM_REGISTERS) {
//         state->R[registerIndex] = ~(state->R[registerIndex]);
//         printf("Result of NOT: %hu\n", state->R[registerIndex]);
//     } else {
//         fprintf(stderr, "\x1b[31mError: Invalid register index\x1b[0m\n");
//     }
// }

// // OR instruction execution function (use binary operators)
// void ExecuteOR(ProcessorState *state, int registerIndex1, int registerIndex2) {
//     if (registerIndex1 >= 0 && registerIndex1 < NUM_REGISTERS && registerIndex2 >= 0 && registerIndex2 < NUM_REGISTERS) {
//         state->R[registerIndex1] = state->R[registerIndex1] | state->R[registerIndex2];
//         printf("Result of OR: %hu\n", state->R[registerIndex1]);
//     } else {
//         fprintf(stderr, "\x1b[31mError: Invalid register index\x1b[0m\n");
//     }
// }

// //****************************** DATA MOVEMENT ******************************//

// // Define the registers
// int registers[NUM_REGISTERS];

// // Define the operand types
// typedef enum {
//     IMMEDIATE,
//     REGISTER,
//     MEMORY
// } OperandType;

// void ExecuteMOV(int* operand1, int* operand2, OperandType operand2type) {
//     switch(operand2type) {
//         case IMMEDIATE:
//             *operand1 = *operand2; // Copie directe pour une valeur immédiate
//             printf("%d\n",*operand1);
//             break;
//         case REGISTER:
//             *operand1 = *(int*)operand2; // Déreference pour copier la valeur
//             printf("%d\n",*operand1);
//             break;
//         case MEMORY:
//             *operand1 = *(int*)operand2; // Déreference pour copier la valeur
//             printf("%d\n",*operand1);
//             break;
//         default:
//             printf("Unknown operand.\n");
//     }
// }

// // STR instruction execution function (storing)
// void ExecuteSTR(ProcessorState* cpu, int source, char* destination) {
//     int address;
//     sscanf(destination, "[%x]", &address);  // Parse the memory address as a hexadecimal number
//     cpu->memory[address] = cpu->R[source];  // Store the data from the register into the memory address
// }

// // LDR instruction execution function (loading)
// void ExecuteLDR(ProcessorState* cpu, int destination, char* source) {
//     int address;
//     sscanf(source, "[%x]", &address);  // Parse the memory address as a hexadecimal number
//     cpu->R[destination] = cpu->memory[address];  // Load the data from the memory address into the register
// }

// void ExecuteCOPY(ProcessorState *state, int srcRegisterIndex, int destRegisterIndex) {
//     if (srcRegisterIndex >= 0 && srcRegisterIndex < NUM_REGISTERS) {
//         if (destRegisterIndex >= 0 && destRegisterIndex < NUM_REGISTERS) {
//             state->R[destRegisterIndex] = state->R[srcRegisterIndex];
//             update_flags(state);
//             printf("Copied from register R%d to R%d\n", srcRegisterIndex, destRegisterIndex);
//         } else {
//             fprintf(stderr, "\x1b[31mError: Invalid destination register index\x1b[0m\n");
//         }
//     } else {
//         fprintf(stderr, "\x1b[31mError: Invalid source register index\x1b[0m\n");
//     }
// }

// // RMV instruction execution function (remove the value from the register)
// void ExecuteRMV(ProcessorState *state, int registerIndex) {
//     if (registerIndex >= 0 && registerIndex < NUM_REGISTERS) {
//         state->R[registerIndex] = 0;
//         update_flags(state);
//         printf("Removed value from register R%d\n", registerIndex);
//     } else {
//         fprintf(stderr, "\x1b[31mError: Invalid register index\x1b[0m\n");
//     }
// }

// //****************************** CONTROL FLOW ******************************//

// typedef struct {
//     char name[10];
//     int instructionIndex;
//     uint16_t address;
//     int lineNumber;
//     long filePosition; // Remember the file position of each label
// } Label;

// //************************** SPECIAL INSTRUCTIONS **************************//


