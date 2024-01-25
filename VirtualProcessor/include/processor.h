#define MEMORY_SIZE 10000
#define NUM_REGISTERS 8

uint16_t reg;
uint16_t result;

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
