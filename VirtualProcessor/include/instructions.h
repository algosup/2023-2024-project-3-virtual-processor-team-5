
uint16_t lastResult = 0; 
#define MAX_LABELS 100

//****************************** ALGORITHMIC OPERATIONS ******************************//
//*************************** IMPLEMENT ADD, MUL, DIV, SUB ***************************//

// ADD instruction execution function
int executeADD(uint16_t operand1, uint16_t operand2) {
    lastResult = operand1 + operand2;
    printf("Result of ADD: %hu\n", lastResult);
    return lastResult;
}

// SUB instruction execution function
int executeSUB(uint16_t operand1, uint16_t operand2) {
    lastResult = operand1 - operand2;
    printf("Result of SUB: %hu\n", lastResult);
    return lastResult;
}

// MUL instruction execution function
int executeMUL(uint16_t operand1, uint16_t operand2) {
    lastResult = operand1 * operand2;
    printf("Result of MUL: %hu\n", lastResult);
    return lastResult;
}

// DIV instruction execution function
int executeDIV(uint16_t operand1, uint16_t operand2) {
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

void executeCMP(ProcessorState *state, int registerIndex1, int registerIndex2) {
    if (registerIndex1 >= 0 && registerIndex1 < NUM_REGISTERS && registerIndex2 >= 0 && registerIndex2 < NUM_REGISTERS) {
        if (state->R[registerIndex1].value == state->R[registerIndex2].value) {
            printf("Values in register R%d and R%d are equal.\n", registerIndex1, registerIndex2);
        } else if (state->R[registerIndex1].value > state->R[registerIndex2].value) {
            printf("Value in register R%d is greater than value in register R%d.\n", registerIndex1, registerIndex2);
        } else {
            printf("Value in register R%d is less than value in register R%d.\n", registerIndex1, registerIndex2);
        }
    } else {
        fprintf(stderr, "\x1b[31mError: Invalid register index\x1b[0m\n");
    }
}

//****************************** DATA MOVEMENT ******************************//

void executeST(ProcessorState *state, int registerIndex, int result) {
    if (registerIndex >= 0 && registerIndex < NUM_REGISTERS) {
        state->R[registerIndex].value = result; // Use result instead of lastResult
        update_flags(state);
        printf("Stored result %d in register R%d\n", result, registerIndex);
    } else {
        fprintf(stderr, "\x1b[31mError: Invalid register index\x1b[0m\n");
    }
}
// LD instruction execution function (loading)
void executeLD(ProcessorState *state, Register *destination, int registerIndex) {
    if (registerIndex >= 0 && registerIndex < NUM_REGISTERS) {
        destination->value = state->R[registerIndex].value;
        update_flags(state);
        printf("Loaded value %hu from register R%d to R%ld\n", destination->value, registerIndex, destination - state->R);
    } else {
        fprintf(stderr, "\x1b[31mError: Invalid register index\x1b[0m\n");
    }
}

void executeCOPY(ProcessorState *state, int srcRegisterIndex, int destRegisterIndex) {
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
//****************************** CONTROL FLOW ******************************//

typedef struct {
    char name[10];  // The name of the label
    int instructionIndex;  // The index of the instruction the label refers to
} Label;

int readLabel(Label *labels, int numLabels, const char *labelName) {
    for (int i = 0; i < numLabels; i++) {
        if (strcmp(labels[i].name, labelName) == 0) {
            return labels[i].instructionIndex;
        }
    }
    // If the label is not found, return an invalid value
    return -1;
}

void jumpToLabel(Label *labels, int numLabels, const char *labelName, int *instructionPointer) {
    int labelFound = 0;
    for (int i = 0; i < numLabels; i++) {
        if (strcmp(labels[i].name, labelName) == 0) {
            *instructionPointer = labels[i].instructionIndex;
            labelFound = 1;
            break;
        }
    }
    // If the label is not found, set the instruction pointer to an invalid value
    if (!labelFound) {
        *instructionPointer = -1;
    }
}