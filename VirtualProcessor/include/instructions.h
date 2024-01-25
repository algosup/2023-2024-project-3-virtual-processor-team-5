
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
    if (registerIndex >= 0 && registerIndex < 5) {
        destination->value = state->R0.value;
        update_flags(state);
        printf("Loaded value %hu from register R%d to R%ld\n", destination->value, registerIndex, destination - &state->R0);
    } else {
        fprintf(stderr, "\x1b[31mError: Invalid register index\x1b[0m\n");
    }
}

void executeCOPY(ProcessorState *state, int srcRegisterIndex, int destRegisterIndex) {
    if (srcRegisterIndex >= 0 && srcRegisterIndex < NUM_REGISTERS) {
        if (destRegisterIndex >= 0 && destRegisterIndex < NUM_REGISTERS) {
            state->R[destRegisterIndex].value = state->R[srcRegisterIndex].value;
            update_flags(state);
            printf("Copied value %hu from R%d to R%d\n", state->R[destRegisterIndex].value, srcRegisterIndex, destRegisterIndex);
        } else {
            fprintf(stderr, "\x1b[31mError: Invalid destination register index\x1b[0m\n");
        }
    } else {
        fprintf(stderr, "\x1b[31mError: Invalid source register index\x1b[0m\n");
    }

    
}
//****************************** CONTROL FLOW ******************************//


