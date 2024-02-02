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

// function read file with command line
void read_file(char *filename, char *file_directory) {
	FILE *file = fopen(file_directory, "r");
	if (file == NULL) { // verify if the file exists
    	printf("\x1b[31mCould not open file.\x1b[0m\n");
    	return;
	} else {
		printf("\x1b[32mFile opened successfully.\x1b[0m\n");
		char line[256];
		while (fgets(line, sizeof(line), file)) {
			currentLine++;
	    	int operand1, operand2;
	    	char operation[5];
			// if the line has a comma, replace it by space
			if (strchr(line, ',') != NULL) {
				char *p = strchr(line, ',');
				*p = ' ';
			}
			// if the line has a label, replace colon by space, store the label, its position and pass to next line
			if (strchr(line, ':') != NULL) {
				char *p = strchr(line, ':');
				*p = ' ';
				sscanf(line, "%s", labelName);
				strcpy(labels[numLabel].name, labelName);
				labels[numLabel].filePosition = ftell(file);
				numLabel++;
				continue;
			}
			if (sscanf(line, "%2s %d %d", operation, &operand1, &operand2) == 3){ // if the line has 3 arguments, and the operation has 2 characters
				if (strcmp(operation, "LD") == 0) { // the operation LD is load
					ExecuteLD(&cpu, &cpu.R[operand1], operand2);
				} else if (strcmp(operation, "CP") == 0) { // the operation CP is copy
					ExecuteCOPY(&cpu, operand1, operand2);
				} else {
	            	printf("\x1b[31mError: Unknown operation '%s'.\x1b[0m\n", operation);
	        	}
	    	} else if (sscanf(line, "%i %3s %hi", &registerIndex, operation, &result) == 2) { // if the line has 2 arguments, and the operation has 3 characters
				if (strcmp(operation, "<<<") == 0) { // the operation <<< is store
					ExecuteST(&cpu, registerIndex, result);
				} else {
					printf("\x1b[31mError: Unknown operation '%s'.\x1b[0m\n", operation);
				}
			} else if (sscanf(line, "%d %s %d", &operand1, operation, &operand2) == 3) { // if the line has 3 arguments, and the operation has 1 character
	        	if (strcmp(operation, "+") == 0) { // the operation + is add
					result = ExecuteADD(operand1, operand2);
	        	} else if (strcmp(operation, "-") == 0) { // the operation - is subtract
	            	result = ExecuteSUB(operand1, operand2);
				} else if (strcmp(operation, "*") == 0) { // the operation * is multiply
					result = ExecuteMUL(operand1, operand2);
				} else if (strcmp(operation, "/") == 0) { // the operation / is divide
					result = ExecuteDIV(operand1, operand2);
	        	} else if (strcmp(operation, "=") == 0) { // the operation = is compare
	            	resultCMP = ExecuteCMP(&cpu, operand1, operand2);
	        	} else if (strcmp(operation, "&") == 0) { // the operation & is and
					ExecuteAND(&cpu, operand1, operand2);
				} else if (strcmp(operation, "X") == 0) { // the operation X is xor
					ExecuteXOR(&cpu, operand1, operand2);
				} else if (strcmp(operation, "|") == 0) { // the operation | is or
					ExecuteOR(&cpu, operand1, operand2);
				} else {
	            	printf("\x1b[31mError: Unknown operation '%s'.\x1b[0m\n", operation);
	        	}
			} else if (sscanf(line, "%2s %d", operation, &operand1) == 2) { // if the line has 2 arguments, and the operation has 2 characters
                if (strcmp(operation, "!!") == 0) { // the operation !! is not
                    ExecuteNOT(&cpu, operand1);
                } else {
                    printf("\x1b[31mError: Unknown operation '%s'.\x1b[0m\n", operation);
                }
			} else if (sscanf(line, "%3s %d", operation, &operand1) == 2) { // if the line has 2 arguments, and the operation has 2 characters
				if (strcmp(operation, ">>>") == 0) { // the operation >>> is remove
					ExecuteREM(&cpu, operand1);
				} else {
					printf("\x1b[31mError: Unknown operation '%s'.\x1b[0m\n", operation);
				}
			} else if (sscanf(line, "%2s %9s", operation, labelName) == 2) { // if the line has 2 arguments, and the operation has 2 characters
				if (strcmp(operation, "=>") == 0) { // the operation => is jump if, need to use with compare
					if (resultCMP) {
						for (int i = 0; i < numLabel; i++) {
							if (strcmp(labels[i].name, labelName) == 0) {
								fseek(file, labels[i].filePosition, SEEK_SET);
							}
						}
					}
				} else if (strcmp(operation, "->") == 0) { // the operation -> is jump
					for (int i = 0; i < numLabel; i++) {
						if (strcmp(labels[i].name, labelName) == 0) {
							fseek(file, labels[i].filePosition, SEEK_SET);
						}
					}
				} else {
					printf("\x1b[31mError: Unknown operation '%s'.\x1b[0m\n", operation);
				}
			} else if (sscanf(line, "%3s", operation) == 1) { // if the line has 1 argument, and the operation has 3 characters
				if (strcmp(operation, "HLT") == 0) { // the operation HLT is halt, to break the code
					break;
				} else {
					printf("\x1b[31mError: Unknown operation '%s'.\x1b[0m\n", operation);
				}
			}
		}
	}
	fclose(file);
}
