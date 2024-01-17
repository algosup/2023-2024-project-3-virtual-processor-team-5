#include <stdio.h>

// Define the number of registers
#define NUM_REGISTERS 2

// Define the register indices
#define AX 0
#define BX 1

// Function to perform an addition operation on registers
void add(int registers[], int dest, int src) {
    registers[dest] += registers[src];
}