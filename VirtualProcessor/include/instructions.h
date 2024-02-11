uint16_t lastResult = 0; 

//****************************** ALGORITHMIC OPERATIONS ******************************//
//*************************** IMPLEMENT ADD, MUL, DIV, SUB ***************************//

// ADD instruction execution function
int ExecuteADD(uint16_t operand1, uint16_t operand2) {
    lastResult = operand1 + operand2;
    printf("Result of ADD: %hu\n", lastResult);
    return lastResult;
}

// SUB instruction execution function
int ExecuteSUB(uint16_t operand1, uint16_t operand2) {
    lastResult = operand1 - operand2;
    printf("Result of SUB: %hu\n", lastResult);
    return lastResult;
}

// MUL instruction execution function
int ExecuteMUL(uint16_t operand1, uint16_t operand2) {
    lastResult = operand1 * operand2;
    printf("Result of MUL: %hu\n", lastResult);
    return lastResult;
}

// DIV instruction execution function
int ExecuteDIV(uint16_t operand1, uint16_t operand2) {
    if (operand2 != 0) {
        lastResult = operand1 / operand2;
        printf("Result of DIV: %hu\n", lastResult);
        return lastResult;
    } else {
        fprintf(stderr, "Error: Division by zero\n");
        return 0;
    }
}

//****************************** LOGICAL OPERATIONS ******************************//
//*********************** IMPLEMENT AND, OR, XOR, NOT, CMP ***********************//

bool ExecuteCMP(ProcessorState *state, int registerIndex1, int registerIndex2) {
    if (registerIndex1 >= 0 && registerIndex1 < NUM_REGISTERS && registerIndex2 >= 0 && registerIndex2 < NUM_REGISTERS) {
        if (state->R[registerIndex1].value == state->R[registerIndex2].value) {
            printf("Values in register R%d and R%d are equal.\n", registerIndex1, registerIndex2);
            return true;
        } else if (state->R[registerIndex1].value > state->R[registerIndex2].value) {
            printf("Value in register R%d is greater than value in register R%d.\n", registerIndex1, registerIndex2);
            return false;
        } else {
            printf("Value in register R%d is less than value in register R%d.\n", registerIndex1, registerIndex2);
            return false;
        }
    } else {
        fprintf(stderr, "\x1b[31mError: Invalid register index\x1b[0m\n");
        return false;
    }
}

// AND instruction execution function
void ExecuteAND(ProcessorState *state, int registerIndex1, int registerIndex2) {
    if (registerIndex1 >= 0 && registerIndex1 < NUM_REGISTERS && registerIndex2 >= 0 && registerIndex2 < NUM_REGISTERS) {
        state->R[registerIndex1].value = state->R[registerIndex1].value & state->R[registerIndex2].value;
        printf("Result of AND: %hu\n", state->R[registerIndex1].value);
    } else {
        fprintf(stderr, "\x1b[31mError: Invalid register index\x1b[0m\n");
    }
}

// XOR instruction execution function
void ExecuteXOR(ProcessorState *state, int registerIndex1, int registerIndex2) {
    if (registerIndex1 >= 0 && registerIndex1 < NUM_REGISTERS && registerIndex2 >= 0 && registerIndex2 < NUM_REGISTERS) {
        state->R[registerIndex1].value = state->R[registerIndex1].value ^ state->R[registerIndex2].value;
        printf("Result of XOR: %hu\n", state->R[registerIndex1].value);
    } else {
        fprintf(stderr, "\x1b[31mError: Invalid register index\x1b[0m\n");
    }
}

// NOT instruction execution function
void ExecuteNOT(ProcessorState *state, int registerIndex) {
    if (registerIndex >= 0 && registerIndex < NUM_REGISTERS) {
        state->R[registerIndex].value = ~(state->R[registerIndex].value);
        printf("Result of NOT: %hu\n", state->R[registerIndex].value);
    } else {
        fprintf(stderr, "\x1b[31mError: Invalid register index\x1b[0m\n");
    }
}

// OR instruction execution function (use binary operators)
void ExecuteOR(ProcessorState *state, int registerIndex1, int registerIndex2) {
    if (registerIndex1 >= 0 && registerIndex1 < NUM_REGISTERS && registerIndex2 >= 0 && registerIndex2 < NUM_REGISTERS) {
        state->R[registerIndex1].value = state->R[registerIndex1].value | state->R[registerIndex2].value;
        printf("Result of OR: %hu\n", state->R[registerIndex1].value);
    } else {
        fprintf(stderr, "\x1b[31mError: Invalid register index\x1b[0m\n");
    }
}

//****************************** DATA MOVEMENT ******************************//

void ExecuteSTR(ProcessorState *state, int registerIndex, int result) {
    if (registerIndex >= 0 && registerIndex < NUM_REGISTERS) {
        if (state->R[registerIndex].value != 0) {
            state->R[registerIndex].value = state->R[registerIndex].value + result; // add result to lastResult
            update_flags(state);
            printf("Stored result %d in register R%d\n", result, registerIndex);
        } else {
            state->R[registerIndex].value = result; // Use result instead of lastResult
            update_flags(state);
            printf("Stored result %d in register R%d\n", result, registerIndex);
        }
    } else {
        fprintf(stderr, "\x1b[31mError: Invalid register index\x1b[0m\n");
    }
}
// LD instruction execution function (loading)
void ExecuteLDR(ProcessorState *state, Register *destination, int registerIndex) {
    if (registerIndex >= 0 && registerIndex < NUM_REGISTERS) {
        destination->value = state->R[registerIndex].value;
        update_flags(state);
        printf("Loaded value %hu from register R%d to R%ld\n", destination->value, registerIndex, destination - state->R);
    } else {
        fprintf(stderr, "\x1b[31mError: Invalid register index\x1b[0m\n");
    }
}

void ExecuteCOPY(ProcessorState *state, int srcRegisterIndex, int destRegisterIndex) {
    if (srcRegisterIndex >= 0 && srcRegisterIndex < NUM_REGISTERS) {
        if (destRegisterIndex >= 0 && destRegisterIndex < NUM_REGISTERS) {
            state->R[destRegisterIndex].value = state->R[srcRegisterIndex].value;
            update_flags(state);
            printf("Copied from register R%d to R%d\n", srcRegisterIndex, destRegisterIndex);
        } else {
            fprintf(stderr, "\x1b[31mError: Invalid destination register index\x1b[0m\n");
        }
    } else {
        fprintf(stderr, "\x1b[31mError: Invalid source register index\x1b[0m\n");
    }
}

// RMV instruction execution function (remove the value from the register)
void ExecuteRMV( ProcessorState *state, int registerIndex) {
    if (registerIndex >= 0 && registerIndex < NUM_REGISTERS) {
        state->R[registerIndex].value = 0;
        update_flags(state);
        printf("Removed value from register R%d\n", registerIndex);
    } else {
        fprintf(stderr, "\x1b[31mError: Invalid register index\x1b[0m\n");
    }
}

//****************************** CONTROL FLOW ******************************//

typedef struct {
    char name[10];
    int instructionIndex;
    uint16_t address;
    int lineNumber;
    long filePosition; // Remember the file position of each label
} Label;

// CALL instruction execution function (call the subroutine after in the file with the name labelName and save the return address in the return stack)
//!TODO

// RET instruction execution function (return to the position where the last CALL was made with thename labelName with the return stack)
//!TODO

//************************** SPECIAL INSTRUCTIONS **************************//


