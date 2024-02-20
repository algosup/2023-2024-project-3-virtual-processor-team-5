//****************************** ALGORITHMIC OPERATIONS ******************************//
//*************************** IMPLEMENT ADD, MUL, DIV, SUB ***************************//

void ExecuteADD(ProcessorState* cpu, int destination, int register1, int register2) {
    cpu->R[destination] = cpu->R[register1] + cpu->R[register2];
}

void ExecuteSUB(ProcessorState* cpu, int destination, int register1, int register2) {
    cpu->R[destination] = cpu->R[register1] - cpu->R[register2];
}

void ExecuteMUL(ProcessorState* cpu, int destination, int register1, int register2) {
    cpu->R[destination] = cpu->R[register1] * cpu->R[register2];
}

void ExecuteDIV(ProcessorState* cpu, int destination, int register1, int register2) {
    if (cpu->R[register2] == 0) {
        // Handle division by zero error
        printf("Error: Division by zero\n");
    } else {
        cpu->R[destination] = cpu->R[register1] / cpu->R[register2];
    }
}

//*************************** LOGICAL OPERATIONS ****************************//
//******************** IMPLEMENT AND, OR, XOR, NOT, CMP *********************//

void ExecuteAND(ProcessorState* cpu, int destination, int register1, int register2) {
    cpu->R[register1] &= cpu->R[register2];
}

void ExecuteXOR(ProcessorState* cpu, int destination, int register1, int register2) {
    cpu->R[register1] ^= cpu->R[register2];
}

void ExecuteOR(ProcessorState* cpu, int destination, int register1, int register2) {
    cpu->R[register1] |= cpu->R[register2];
}

void ExecuteNOT(ProcessorState* cpu, int destination, int register1, int register2) {
    cpu->R[register1] = ~cpu->R[register2];
}

void ExecuteCMP(ProcessorState* cpu, int destination, int register1, int register2) {
    cpu->flags.sign = (cpu->R[register1] < cpu->R[register2]) ? 1 : 0;
    cpu->flags.zero = (cpu->R[register1] == cpu->R[register2]) ? 1 : 0;
}

//****************************** DATA MOVEMENT ******************************//

void ExecuteMOV(ProcessorState* cpu, int destination, char* source) {
    if (source[0] == '#') {
        // If the source starts with '#', it's an immediate value
        int immediateValue;
        sscanf(source, "#%d", &immediateValue);  // Parse the immediate value
        cpu->R[destination] = immediateValue;  // Store the immediate value in the destination register
    } else {
        // Otherwise, the source is a register
        int srcIndex = source[1] - '0';  // Parse the register index
        cpu->R[destination] = cpu->R[srcIndex];  // Copy the value from the source register to the destination register
    }
}

void executeSTR(ProcessorState *cpu, uint8_t reg, char* destination) {
    int address;
    sscanf(destination, "[%x]", &address);  // Parse the memory address as a hexadecimal number
    if (address < MEMORY_SIZE) {
        cpu->memory->memory[address] = cpu->R[reg];  // Store the data from the register into the memory address
    } else {
        // Handle out of bounds memory access error
        printf("Error: Memory address out of bounds\n");
    }
}

void ExecuteLDR(ProcessorState* cpu, int destination, char* source) {
        int address;
        sscanf(source, "[%x]", &address);
        if (address < MEMORY_SIZE) {  // Parse the memory address as a hexadecimal number
        cpu->R[destination] = cpu->memory->memory[address];  // Load the data from the memory address into the register
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

void executeJMP(ProcessorState *cpu, int address) {
    if (address < MEMORY_SIZE) {
        cpu->PC = address;
    } else {
        // Handle out of bounds memory access error
        printf("Error: Jump address out of bounds\n");
    }
}

void executeJZ(ProcessorState *cpu, int address) {
    if (cpu->flags.zero) {
        if (address < MEMORY_SIZE) {
            cpu->PC = address;
        } else {
            // Handle out of bounds memory access error
            printf("Error: Jump address out of bounds\n");
        }
    }
}

void executeJNZ(ProcessorState *cpu, int address) {
    if (!cpu->flags.zero) {
        if (address < MEMORY_SIZE) {
            cpu->PC = address;
        } else {
            // Handle out of bounds memory access error
            printf("Error: Jump address out of bounds\n");
        }
    }
}

void executeJE(ProcessorState *cpu, int address) {
    if (cpu->flags.equal) {
        if (address < MEMORY_SIZE) {
            cpu->PC = address;
        } else {
            // Handle out of bounds memory access error
            printf("Error: Jump address out of bounds\n");
        }
    }
}

void executeJNE(ProcessorState *cpu, int address) {
    if (!cpu->flags.equal) {
        if (address < MEMORY_SIZE) {
            cpu->PC = address;
        } else {
            // Handle out of bounds memory access error
            printf("Error: Jump address out of bounds\n");
        }
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
