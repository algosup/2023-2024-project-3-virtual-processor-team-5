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
#define MOV_OPCODE 0x0E
#define HLT_OPCODE 0x0F
#define JMP_OPCODE 0x10

// Define register indices
// #define REG_A 0
// #define REG_B 1
// #define REG_C 2
// #define REG_D 3
// #define REG_E 4
// #define REG_F 5
// #define REG_G 6
// #define REG_H 7

// Register structure
// typedef struct {
//     int value;
// } Register;

typedef struct {
    uint8_t sign;
    uint8_t zero;
    uint8_t equal;
} Flags;

typedef struct {
    uint16_t memory[MEMORY_SIZE];
    int value;
} Memory;

typedef struct {
    int opcode;
    uint16_t IMMEDIATE;
    int destination, register1, register2;
    int address;
} instruction_t;

// Processor status structure
typedef struct {
    int R[NUM_REGISTERS];// general register array
    uint16_t PC;  // Program counter
    Flags flags;  // Flags register
    int LR; // link register
    int PSR; // processor status register
    int USP; // user stack pointer
    int SSP; // system stack pointer
    int instructionPointer;
    Memory *memory;  // Pointer to Memory structure
} ProcessorState;

// uint16_t mem_read(Register *register_value) {
//     return register_value->value;
// }

void MemoryAllocation(ProcessorState *state) {
    state->memory = (Memory *)malloc(sizeof(Memory));
}

void update_flags(ProcessorState *state) {
    // Met à jour le bit de signe
    state->flags.sign = (state->R[0] & 0x8000) ? 1 : 0;

    // Met à jour le bit de zéro
    state->flags.zero = (state->R[0] == 0) ? 1 : 0;
}

// Function to execute instructions
void execute_instruction(instruction_t instruction, ProcessorState *cpu) {
    switch(instruction.opcode) {
        case ADD_OPCODE:
            cpu->R[instruction.destination] = cpu->R[instruction.register1] + cpu->R[instruction.register2];
            break;
        case SUB_OPCODE:
            cpu->R[instruction.destination] = cpu->R[instruction.register1] - cpu->R[instruction.register2];
            break;
        case MUL_OPCODE:
            cpu->R[instruction.destination] = cpu->R[instruction.register1] * cpu->R[instruction.register2];
            break;
        case DIV_OPCODE:
            if (cpu->R[instruction.register1] == 0) {
                // Handle division by zero error
                printf("Error: Division by zero\n");
            } else {
            cpu->R[instruction.destination] = cpu->R[instruction.register1] / cpu->R[instruction.register2];
            }
            break;
        case AND_OPCODE:
            cpu->R[instruction.destination] = cpu->R[instruction.register1] & cpu->R[instruction.register2];
            break;
        case XOR_OPCODE:
            cpu->R[instruction.destination] = cpu->R[instruction.register1] ^ cpu->R[instruction.register2];
            break;
        case OR_OPCODE:
            cpu->R[instruction.destination] = cpu->R[instruction.register1] | cpu->R[instruction.register2];
            break;
        case NOT_OPCODE:
            cpu->R[instruction.destination] = ~cpu->R[instruction.register2];
            break;
        case CMP_OPCODE:
            cpu->flags.sign = (cpu->R[instruction.register1] < cpu->R[instruction.register2]) ? 1 : 0;
            cpu->flags.zero = (cpu->R[instruction.register1] == cpu->R[instruction.register2]) ? 1 : 0;
            break;
        case STR_OPCODE:
            if (instruction.address < MEMORY_SIZE) {
                cpu->memory->memory[cpu->R[instruction.address]] = cpu->R[instruction.register1];
            } else {
                // Handle out of bounds memory access error
                printf("Error: Memory address out of bounds\n");
            }
            break;
        case LDR_OPCODE:
            if (instruction.address < MEMORY_SIZE) {
                cpu->R[instruction.destination] = cpu->memory->memory[cpu->R[instruction.address]];
            } else {
                // Handle out of bounds memory access error
                printf("Error: Memory address out of bounds\n");
            }
            break;
        case COPY_OPCODE:
            cpu->R[instruction.destination] = cpu->R[instruction.register1];
            break;
        case RMV_OPCODE:
            cpu->R[instruction.destination] = 0;
            break;
        case MOV_OPCODE:
            if (cpu->R[instruction.destination] < MEMORY_SIZE) {
                cpu->R[instruction.destination] = 0; //reinitialize the register
                cpu->R[instruction.destination] = instruction.IMMEDIATE; //store the immediate value in the destination register
                printf("Value in R%d: %d\n",instruction.register1, cpu->R[instruction.destination]); //print the value in the register
            } else {
                // Handle out of bounds memory access error
                printf("Error: Memory address out of bounds\n");
            }
            break;
        case HLT_OPCODE:
            // Halt the processor
            printf("Halting processor\n");
            break;
        case JMP_OPCODE:
            // Jump to the specified address
            cpu->PC = instruction.address;
            break;
    }
}
