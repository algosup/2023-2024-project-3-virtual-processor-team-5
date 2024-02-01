#include <stdio.h>
#include <string.h>
#include <stdint.h>
#include <stdlib.h>
#include <stdbool.h>

#include "processor.h"
#include "instructions.h"

#define MAX_LABELS 100

Label labels[MAX_LABELS]; // An array of labels
int numLabel = 0; // The number of labels
int numInstructions = 0;  // Add this line to define numInstructions
char labelName[10]; // The name of a label
int numLine;
int currentLine = 0;

int registerIndex;
uint16_t result;
bool resultCMP = true;
char file_directory[500];
int fileLine;
ProcessorState cpu = {0};

// read file with command line
void read_file(char *filename, char *file_directory) {
	FILE *file = fopen(file_directory, "r");
	if (file == NULL) {
    	printf("\x1b[31mCould not open file.\x1b[0m\n");
    	return;
	} else {
		printf("\x1b[32mFile opened successfully.\x1b[0m\n");
		char line[256];
		while (fgets(line, sizeof(line), file)) {
			currentLine++;
	    	int operand1, operand2;
	    	char operation[5];

			// replace "," with " "
			if (strchr(line, ',') != NULL){
				char *p = strchr(line, ',');
				*p = ' ';
			}
			if (strchr(line, ':') != NULL) {
				char *p = strchr(line, ':');
				*p = ' ';
				sscanf(line, "%s", labelName);
				strcpy(labels[numLabel].name, labelName);
				labels[numLabel].filePosition = ftell(file);
				numLabel++;
				continue;
			}
			if (sscanf(line, "%2s %d %d", operation, &operand1, &operand2) == 3){
				if (strcmp(operation, "LD") == 0) {
					ExecuteLD(&cpu, &cpu.R[operand1], operand2);
				} else if (strcmp(operation, "OR") == 0) {
					ExecuteOR(&cpu, operand1, operand2);
				} else {
	            	printf("\x1b[31mError: Unknown operation '%s'.\x1b[0m\n", operation);
	        	}
	    	} else if (sscanf(line, "%2s %i %hi", operation, &registerIndex, &result) == 2) {
				if (strcmp(operation, "ST") == 0) {
					ExecuteST(&cpu, registerIndex, result);
				} else {
					printf("\x1b[31mError: Unknown operation '%s'.\x1b[0m\n", operation);
				}
			} else if (sscanf(line, "%3s %d %d", operation, &operand1, &operand2) == 3) {
	        	if (strcmp(operation, "ADD") == 0) {
					result = ExecuteADD(operand1, operand2);
	        	} else if (strcmp(operation, "SUB") == 0) {
	            	result = ExecuteSUB(operand1, operand2);
				} else if (strcmp(operation, "MUL") == 0) {
					result = ExecuteMUL(operand1, operand2);
				} else if (strcmp(operation, "DIV") == 0) {
					result = ExecuteDIV(operand1, operand2);
	        	} else if (strcmp(operation, "CMP") == 0) {
	            	resultCMP = ExecuteCMP(&cpu, operand1, operand2);
	        	} else if (strcmp(operation, "AND") == 0) {
					ExecuteAND(&cpu, operand1, operand2);
				} else if (strcmp(operation, "XOR") == 0) {
					ExecuteXOR(&cpu, operand1, operand2);
				} else {
	            	printf("\x1b[31mError: Unknown operation '%s'.\x1b[0m\n", operation);
	        	}
			} else if (sscanf(line, "%3s %d", operation, &operand1) == 2) {
                if (strcmp(operation, "NOT") == 0) {
                    ExecuteNOT(&cpu, operand1);
				} else if (strcmp(operation, "REM") == 0) {
					ExecuteREM(&cpu, operand1);
                } else {
                    printf("\x1b[31mError: Unknown operation '%s'.\x1b[0m\n", operation);
                }
			} else if (sscanf(line, "%4s %d %d", operation, &operand1, &operand2) == 3) {
				if (strcmp(operation, "COPY") == 0) {
					ExecuteCOPY(&cpu, operand1, operand2);
				} else {
					printf("\x1b[31mError: Your lines aren't well written.\x1b[0m\n");
				}
			} else if (sscanf(line, "%3s %9s", operation, labelName) == 2) {
				if (strcmp(operation, "JMP") == 0) {
					// Store the label and its position
					if (resultCMP) {
						for (int i = 0; i < numLabel; i++) {
                			if (strcmp(labels[i].name, labelName) == 0) {
								fseek(file, labels[i].filePosition, SEEK_SET);
                			}
            			}
					}
				} else {
					printf("\x1b[31mError: Unknown operation '%s'.\x1b[0m\n", operation);
				}
			} else if (sscanf(line, "%3s", operation) == 1) {
				if (strcmp(operation, "HLT") == 0) {
					break;
				} else {
					printf("\x1b[31mError: Unknown operation '%s'.\x1b[0m\n", operation);
				}
			}
		}
	}
	fclose(file);
}
