//****************************** ALGORITHMIC OPERATIONS ******************************//
//*************************** IMPLEMENT ADD, MUL, DIV, SUB ***************************//

void ExecuteADD(ProcessorState* cpu, int destination, int operand1, int operand2) {
    cpu->R[destination] = cpu->R[operand1] + cpu->R[operand2];
}

void ExecuteSUB(ProcessorState* cpu, int destination, int operand1, int operand2) {
    cpu->R[destination] = cpu->R[operand1] - cpu->R[operand2];
}

void ExecuteMUL(ProcessorState* cpu, int destination, int operand1, int operand2) {
    cpu->R[destination] = cpu->R[operand1] * cpu->R[operand2];
}

void ExecuteDIV(ProcessorState* cpu, int destination, int operand1, int operand2) {
    if (cpu->R[operand2] == 0) {
        // Handle division by zero error
        printf("Error: Division by zero\n");
    } else {
        cpu->R[destination] = cpu->R[operand1] / cpu->R[operand2];
    }
}

//*************************** LOGICAL OPERATIONS ****************************//
//******************** IMPLEMENT AND, OR, XOR, NOT, CMP *********************//

void ExecuteAND(ProcessorState* cpu, int destination, int operand1, int operand2) {
    cpu->R[operand1] &= cpu->R[operand2];
}

void ExecuteXOR(ProcessorState* cpu, int destination, int operand1, int operand2) {
    cpu->R[operand1] ^= cpu->R[operand2];
}

void ExecuteOR(ProcessorState* cpu, int destination, int operand1, int operand2) {
    cpu->R[operand1] |= cpu->R[operand2];
}

void ExecuteNOT(ProcessorState* cpu, int destination, int operand1, int operand2) {
    cpu->R[operand1] = ~cpu->R[operand2];
}

void ExecuteCMP(ProcessorState* cpu, int destination, int operand1, int operand2) {
    cpu->flags.sign = (cpu->R[operand1] < cpu->R[operand2]) ? 1 : 0;
    cpu->flags.zero = (cpu->R[operand1] == cpu->R[operand2]) ? 1 : 0;
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

void ExecuteLDR(ProcessorState* cpu, int destination, char* source) {
        int address;
        sscanf(source, "[%x]", &address);
        if (address < MEMORY_SIZE) {  // Parse the memory address as a hexadecimal number
        cpu->R[destination] = cpu->memory[address];  // Load the data from the memory address into the register
    } else {
        // Handle out of bounds memory access error
        printf("Error: Memory address out of bounds\n");
    }
}

void ExecuteCOPY(ProcessorState* cpu, int destination, int source) {
    cpu->R[destination] = cpu->R[source];
}

void executeRMV(ProcessorState *cpu, int destination) {
    cpu->R[destination] = 0;
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
