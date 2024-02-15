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



//****************************** DATA MOVEMENT ******************************//



//****************************** CONTROL FLOW *******************************//



//************************** SPECIAL INSTRUCTIONS ***************************//
