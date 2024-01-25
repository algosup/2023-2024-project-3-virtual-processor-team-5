
uint16_t lastResult = 0; 

//****************************** ALGORITHMIC OPERATIONS ******************************//
//*************************** IMPLEMENT ADD, MUL, DIV, SUB ***************************//

// ADD instruction execution function
void executeADD(uint16_t operand1, uint16_t operand2) {
    lastResult = operand1 + operand2;
    printf("Result of ADD: %hu\n", lastResult);
}

// SUB instruction execution function
void executeSUB(uint16_t operand1, uint16_t operand2) {
    lastResult = operand1 - operand2;
    printf("Result of SUB: %hu\n", lastResult);
}

// MUL instruction execution function
void executeMUL(uint16_t operand1, uint16_t operand2) {
    lastResult = operand1 * operand2;
    printf("Result of MUL: %hu\n", lastResult);
}

// DIV instruction execution function
void executeDIV(uint16_t operand1, uint16_t operand2) {
    if (operand2 != 0) {
        lastResult = operand1 / operand2;
        printf("Result of DIV: %hu\n", lastResult);
    } else {
        fprintf(stderr, "Error: Division by zero\n");
    }
}

//****************************** LOGICAL OPERATIONS ******************************//
//************************** IMPLEMENT AND, OR, XOR, NOT *************************//



//****************************** DATA MOVEMENT ******************************//

void executeST(ProcessorState *state, int registerIndex) {
    if (registerIndex >= 0 && registerIndex < 5) {
        switch (registerIndex) {
            case 0:
                state->R0.value = lastResult;
                break;
            case 1:
                state->R1.value = lastResult;
                break;
            case 2:
                state->R2.value = lastResult;
                break;
            case 3:
                state->R3.value = lastResult;
                break;
            case 4:
                state->R4.value = lastResult;
                break;
        }
        printf("Stored last result %hu in register R%d\n", lastResult, registerIndex);
    } else {
        fprintf(stderr, "\x1b[31mError: Invalid register index\x1b[0m\n");
    }
}

// LD instruction execution function (loading)
void executeLD(ProcessorState *state, Register *destination, int registerIndex) {
    if (registerIndex >= 0 && registerIndex < 5) {
        destination->value = state->R0.value;
        update_flags(state);
        printf("Loaded value %hu from register R%d to R%ld\n", destination->value, registerIndex, destination - &state->R0);
    } else {
        fprintf(stderr, "\x1b[31mError: Invalid register index\x1b[0m\n");
    }
}

void copy(ProcessorState *state, Register *source, Register *destination) {
    destination->value = source->value;
    update_flags(state);
}

//****************************** CONTROL FLOW ******************************//


