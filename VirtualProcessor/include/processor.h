#define MEMORY_SIZE 0x1000

// Register structure
typedef struct {
    int value;
} Register;

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
    int PC;  // Program counter
    int LR; // link register
    int PSR; // processor status register
    int USP; // user stack pointer
    int SSP; // system stack pointer
} ProcessorState;

typedef struct {
    uint16_t memory[MEMORY_SIZE];
} Memory;


//typedef struct {
//    uint16_t memory[MEMORY_SIZE];
//} uint16_t;
