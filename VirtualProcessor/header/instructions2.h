//****************************** ALGORITHMIC OPERATIONS ******************************//
//*************************** IMPLEMENT ADD, MUL, DIV, SUB ***************************//

void executeADD(ProcessorState *cpu, uint8_t regA, uint8_t regB) {
    cpu->R[regA].value += cpu->R[regB].value;
}

void executeSUB(ProcessorState *cpu, uint8_t regA, uint8_t regB) {
    cpu->R[regA].value -= cpu->R[regB].value;
}

void executeMUL(ProcessorState *cpu, uint8_t regA, uint8_t regB) {
    cpu->R[regA].value *= cpu->R[regB].value;
}

void executeDIV(ProcessorState *cpu, uint8_t regA, uint8_t regB) {
    if (cpu->R[regB].value == 0) {
        // Handle division by zero error
        printf("Error: Division by zero\n");
    } else {
        cpu->R[regA].value /= cpu->R[regB].value;
    }
}

//*************************** LOGICAL OPERATIONS ****************************//
//******************** IMPLEMENT AND, OR, XOR, NOT, CMP *********************//

void executeAND(ProcessorState *cpu, uint8_t regA, uint8_t regB) {
    cpu->R[regA].value &= cpu->R[regB].value;
}

void executeXOR(ProcessorState *cpu, uint8_t regA, uint8_t regB) {
    cpu->R[regA].value ^= cpu->R[regB].value;
}

void executeOR(ProcessorState *cpu, uint8_t regA, uint8_t regB) {
    cpu->R[regA].value |= cpu->R[regB].value;
}

void executeNOT(ProcessorState *cpu, uint8_t regA) {
    cpu->R[regA].value = ~cpu->R[regA].value;
}

void executeCMP(ProcessorState *cpu, uint8_t regA, uint8_t regB) {
    cpu->flags.sign = (cpu->R[regA].value < cpu->R[regB].value) ? 1 : 0;
    cpu->flags.zero = (cpu->R[regA].value == cpu->R[regB].value) ? 1 : 0;
}

//****************************** DATA MOVEMENT ******************************//

void executeSTR(ProcessorState *cpu, uint8_t regA, uint8_t regB) {
    if (cpu->R[regA].value < MEMORY_SIZE) {
        cpu->memory->memory[cpu->R[regA].value] = cpu->R[regB].value;
    } else {
        // Handle out of bounds memory access error
        printf("Error: Memory address out of bounds\n");
    }
}

void executeLDR(ProcessorState *cpu, uint8_t regA, uint8_t regB) {
    if (cpu->R[regB].value < MEMORY_SIZE) {
        cpu->R[regA].value = cpu->memory->memory[cpu->R[regB].value];
    } else {
        // Handle out of bounds memory access error
        printf("Error: Memory address out of bounds\n");
    }
}

void executeCOPY(ProcessorState *cpu, uint8_t regA, uint8_t regB) {
    cpu->R[regA].value = cpu->R[regB].value;
}

void executeRMV(ProcessorState *cpu, uint8_t regA) {
    cpu->R[regA].value = 0;
}

//****************************** CONTROL FLOW *******************************//

void executeJMP(ProcessorState *cpu, uint8_t regA) {
    cpu->PC = cpu->R[regA].value;
}

void executeJZ(ProcessorState *cpu, uint8_t regA) {
    if (cpu->flags.zero) {
        cpu->PC = cpu->R[regA].value;
    }
}

void executeJNZ(ProcessorState *cpu, uint8_t regA) {
    if (!cpu->flags.zero) {
        cpu->PC = cpu->R[regA].value;
    }
}

void executeJE(ProcessorState *cpu, uint8_t regA) {
    if (cpu->flags.sign) {
        cpu->PC = cpu->R[regA].value;
    }
}

void executeJNE(ProcessorState *cpu, uint8_t regA) {
    if (!cpu->flags.sign) {
        cpu->PC = cpu->R[regA].value;
    }
}

//************************** SPECIAL INSTRUCTIONS ***************************//

void executeNOP(ProcessorState *cpu) {
    // Do nothing
}

/*
void executePUSH(ProcessorState *cpu, uint8_t regA) {
    if (cpu->SP > 0) {
        cpu->memory->memory[--cpu->SP] = cpu->R[regA].value;
    } else {
        // Handle stack overflow error
        printf("Error: Stack overflow\n");
    }
}


void executePOP(ProcessorState *cpu, uint8_t regA) {
    if (cpu->SP < MEMORY_SIZE) {
        cpu->R[regA].value = cpu->memory->memory[cpu->SP++];
    } else {
        // Handle stack underflow error
        printf("Error: Stack underflow\n");
    }
}

void executeCALL(ProcessorState *cpu, uint8_t regA) {
    if (cpu->SP > 0) {
        cpu->memory->memory[--cpu->SP] = cpu->PC;
        cpu->PC = cpu->R[regA].value;
    } else {
        // Handle stack overflow error
        printf("Error: Stack overflow\n");
    }
}

void executeRET(ProcessorState *cpu) {
    if (cpu->SP < MEMORY_SIZE) {
        cpu->PC = cpu->memory->memory[cpu->SP++];
    } else {
        // Handle stack underflow error
        printf("Error: Stack underflow\n");
    }
}
*/
