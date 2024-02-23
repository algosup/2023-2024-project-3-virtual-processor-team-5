// #include <stdio.h>

// typedef struct {
//     int PC;  // Program counter
//     int R[8];  // Registers
//     int memory[256];  // Memory
//     // Add other fields as needed...
// } ProcessorState;

// void printState(ProcessorState *cpu) {
//     printf("PC: %d\n", cpu->PC);
//     for (int i = 0; i < 8; i++) {
//         printf("R%d: %d\n", i, cpu->R[i]);
//     }
//     // Print other state information as needed...
// }

// void step(ProcessorState *cpu) {
//     // Execute the next instruction
//     // This will depend on how your virtual processor is implemented
// }

// void run(ProcessorState *cpu) {
//     // Run the program until it finishes or a breakpoint is hit
//     // This will depend on how your virtual processor is implemented
// }

// void debug(ProcessorState *cpu) {
//     char command[10];
//     while (1) {
//         printf("debug> ");
//         scanf("%s", command);
//         if (strcmp(command, "run") == 0) {
//             run(cpu);
//         } else if (strcmp(command, "step") == 0) {
//             step(cpu);
//         } else if (strcmp(command, "print") == 0) {
//             printState(cpu);
//         } else if (strcmp(command, "quit") == 0) {
//             break;
//         } else {
//             printf("Unknown command: %s\n", command);
//         }
//     }
// }

// int main() {
//     ProcessorState cpu = {0};
//     debug(&cpu);
//     return 0;
// }



// void step(ProcessorState *cpu) {
//     // Fetch the instruction at the program counter
//     int instruction = cpu->memory[cpu->PC];

//     // Decode the instruction
//     // This will depend on your instruction set architecture
//     int opcode = instruction >> 12;
//     int operand1 = (instruction >> 8) & 0xF;
//     int operand2 = (instruction >> 4) & 0xF;
//     int operand3 = instruction & 0xF;

//     // Execute the instruction
//     // This will depend on your instruction set architecture
//     switch (opcode) {
//         case 0:  // Example: ADD
//             cpu->R[operand1] = cpu->R[operand2] + cpu->R[operand3];
//             break;
//         // Add other cases as needed...
//     }

//     // Increment the program counter
//     cpu->PC++;
// }

// void run(ProcessorState *cpu) {
//     // Run the program until it finishes or a breakpoint is hit
//     while (cpu->PC < MEMORY_SIZE) {
//         step(cpu);
//     }
// }