#define MEMORY_SIZE 10000
#define NUM_REGISTERS 8

uint16_t reg;
uint16_t result;

// Define opcodes for instructions
#define ADD_OPCODE 0x01
#define SUB_OPCODE 0x02
#define MUL_OPCODE 0x03
#define DIV_OPCODE 0x04
#define AND_OPCODE 0x05
#define OR_OPCODE 0x06
#define XOR_OPCODE 0x07
#define NOT_OPCODE 0x08
#define CMP_OPCODE 0x09
#define STR_OPCODE 0x0A
#define LDR_OPCODE 0x0B
#define COPY_OPCODE 0x0C
#define RMV_OPCODE 0x0D

// Define register indices
#define REG_A 0
#define REG_B 1
#define REG_C 2
#define REG_D 3
#define REG_E 4
#define REG_F 5
#define REG_G 6
#define REG_H 7

// Register structure
typedef struct {
    int value;
} Register;

typedef struct {
    uint8_t sign;
    uint8_t zero;
} Flags;

// Processor status structure
typedef struct {
    Register R0; // general register
    Register R1;
    Register R2;
    Register R3;
    Register R4;
    Register R5;
    Register R6;
    Register R7;
    Register R[NUM_REGISTERS];// general register array
    uint16_t PC;  // Program counter
    Flags flags;  // Flags register
    int LR; // link register
    int PSR; // processor status register
    int USP; // user stack pointer
    int SSP; // system stack pointer
    int instructionPointer;
    Memory *memory;  // Pointer to Memory structure
} ProcessorState;

typedef struct {
    uint16_t memory[MEMORY_SIZE];
} Memory;

uint16_t mem_read(Register *register_value) {
    return register_value->value;
}

void update_flags(ProcessorState *state) {
    // Met à jour le bit de signe
    state->flags.sign = (state->R0.value & 0x8000) ? 1 : 0;

    // Met à jour le bit de zéro
    state->flags.zero = (state->R0.value == 0) ? 1 : 0;
}

// Function to execute instructions
void execute_instruction(uint8_t opcode, ProcessorState *cpu) {
    switch(opcode) {
        case ADD_OPCODE:
            cpu->R[REG_A].value += cpu->R[REG_B].value;
            break;
        case SUB_OPCODE:
            cpu->R[REG_A].value -= cpu->R[REG_B].value;
            break;
        case MUL_OPCODE:
            cpu->R[REG_A].value *= cpu->R[REG_B].value;
            break;
        case AND_OPCODE:
            cpu->R[REG_A].value &= cpu->R[REG_B].value;
            break;
        case XOR_OPCODE:
            cpu->R[REG_A].value ^= cpu->R[REG_B].value;
            break;
        case OR_OPCODE:
            cpu->R[REG_A].value |= cpu->R[REG_B].value;
            break;
        case NOT_OPCODE:
            cpu->R[REG_A].value = ~cpu->R[REG_A].value;
            break;
        case CMP_OPCODE:
            cpu->flags.sign = (cpu->R[REG_A].value < cpu->R[REG_B].value) ? 1 : 0;
            cpu->flags.zero = (cpu->R[REG_A].value == cpu->R[REG_B].value) ? 1 : 0;
            break;
        case DIV_OPCODE:
            if (cpu->R[REG_B].value == 0) {
                // Handle division by zero error
                printf("Error: Division by zero\n");
            } else {
                cpu->R[REG_A].value /= cpu->R[REG_B].value;
            }
            break;
        case STR_OPCODE:
            if (cpu->R[REG_A].value < MEMORY_SIZE) {
                cpu->memory[cpu->R[REG_A].value] = cpu->R[REG_B].value;
            } else {
                // Handle out of bounds memory access error
                printf("Error: Memory address out of bounds\n");
            }
            break;
        case LDR_OPCODE:
            if (cpu->R[REG_B].value < MEMORY_SIZE) {
                cpu->R[REG_A].value = cpu->memory[cpu->R[REG_B].value];
            } else {
                // Handle out of bounds memory access error
                printf("Error: Memory address out of bounds\n");
            }
            break;
        case COPY_OPCODE:
            cpu->R[REG_A].value = cpu->R[REG_B].value;
            break;
        case RMV_OPCODE:
            cpu->R[REG_A].value = 0;
            break;
        default:
            // Handle unknown opcode error
            printf("Error: Unknown opcode\n");
            break;
    }
}
