// #include <stdio.h>
// #include <string.h>
// #include <stdint.h>
// #include <stdlib.h>
// #include <stdbool.h>
// #include <ctype.h>

// #include "processor.h"
// #include "instructions.h"
// #include "parser.h"

// #define MAX_LABELS 100

// Label labels[MAX_LABELS]; // An array of labels
// int numLabel = 0; // The number of labels
// int numInstructions = 0;  // Add this line to define numInstructions
// char labelName[10]; // The name of a label
// int numLine;
// int currentLine = 0;

// int destination, operand1, operand2;

// int registerIndex;
// uint16_t result;
// bool resultCMP = true;
// char file_directory[500];
// int fileLine;
// ProcessorState cpu = {0};

// // function read file with command line
// void read_file(char *filename, char *file_directory) {
// 	FILE *file = fopen(file_directory, "r");
// 	if (file == NULL) { // verify if the file exists
//     	printf("\x1b[31mCould not open file.\x1b[0m\n");
//     	return;
// 	} else {
// 		printf("\x1b[32mFile opened successfully.\x1b[0m\n");
// 		char line[256];
// 		while (fgets(line, sizeof(line), file)) {
// 			currentLine++;
// 	    	int operand1, operand2;
// 			char register1[50];
// 			char register2[50];
// 	    	char operation[4];
// 			// if the line has a comma, replace it by space
// 			if (strchr(line, ',') != NULL) {
// 				char *p = strchr(line, ',');
// 				*p = ' ';
// 			}
// 			// if the line has a label, replace colon by space, store the label, its position and pass to next line
// 			if (strchr(line, ':') != NULL) {
// 				char *p = strchr(line, ':');
// 				*p = ' ';
// 				sscanf(line, "%s", labelName);
// 				strcpy(labels[numLabel].name, labelName);
// 				labels[numLabel].filePosition = ftell(file);
// 				numLabel++;
// 				continue;
// 			}
// 			if (sscanf(line, "%s %d %d", operation, &operand1, &operand2) == 3) { // if the line has 3 arguments, and the operation has 1 character
// 	        	if (strcmp(operation, "ADD") == 0) {
// 					char destination[3], operand1[3], operand2[3];
// 					if (sscanf(line, "%*s %s %s %s", destination, operand1, operand2) == 3) {
// 						int destIndex = destination[1] - '0';
// 						int op1Index = operand1[1] - '0';
// 						int op2Index = operand2[1] - '0';
// 						ExecuteADD(&cpu, destIndex, op1Index, op2Index);
// 					} else {
// 						printf("\x1b[31mError: Invalid arguments for 'ADD' operation.\x1b[0m\n");
// 					}
// 				} else if (strcmp(operation, "SUB") == 0) {
// 	            	result = ExecuteSUB(operand1, operand2);
// 				} else if (strcmp(operation, "MUL") == 0) {
// 					result = ExecuteMUL(operand1, operand2);
// 				} else if (strcmp(operation, "DIV") == 0) {
// 					result = ExecuteDIV(operand1, operand2);
// 	        	} else if (strcmp(operation, "CMP") == 0) { // the operation CMP is compare
// 	            	resultCMP = ExecuteCMP(&cpu, operand1, operand2);
// 	        	} else if (strcmp(operation, "AND") == 0) {
// 					ExecuteAND(&cpu, operand1, operand2);
// 				} else if (strcmp(operation, "XOR") == 0) {
// 					ExecuteXOR(&cpu, operand1, operand2);
// 				} else {
// 	            	printf("\x1b[31mError: Unknown operation '%s'.\x1b[0m\n", operation);
// 	        	}
// 			} else if (sscanf(line, "%2s %d %d", operation, &operand1, &operand2) == 3){ // if the line has 3 arguments, and the operation has 2 characters
// 				if (strcmp(operation, "CP") == 0) { // the operation CP is copy
// 					ExecuteCOPY(&cpu, operand1, operand2);
// 				} else if (strcmp(operation, "OR") == 0) {
// 					ExecuteOR(&cpu, operand1, operand2);
// 				} else {
// 	            	printf("\x1b[31mError: Unknown operation '%s'.\x1b[0m\n", operation);
// 	        	}
// 			} else if (sscanf(line, "%3s %s %s", operation, register1, register2) == 3){ // if the line has 3 arguments, and the operation has 3 characters
// 				if (strcmp(operation, "MOV") == 0){
// 					ProcessorState *registers = 0;
// 					int index1;
// 					int index2;
// 					if (isdigit(register1[1])) {
//         				index1 = register1[1] - '0';
//     				} else {
//         				printf("Error: Invalid register index\n");
//     				}
//     				if (isdigit(register2[1])) {
//         				index2 = register2[1] - '0';
//     				} else {
//         				printf("Error: Invalid register index\n");
//     				}
//     				if (register2[0] == '#'){
//         				int immediateValue;
//         				if (sscanf(register2, "#%d", &immediateValue) == 1) {
//             				ExecuteMOV(&cpu.R[index1].value, &immediateValue, IMMEDIATE);
//         				} else {
//             				printf("Error: Invalid immediate value\n");
//         				}
//     				} else {
//         				ExecuteMOV(&cpu.R[index1].value, &cpu.R[index2].value, REGISTER);
//     				}
// 				} else {
// 	            	printf("\x1b[31mError: Unknown operation '%s'.\x1b[0m\n", operation);
// 	        	}
// 			} else if (sscanf(line, "%3s %d %d", operation, &operand1, &operand2) == 3){ // if the line has 3 arguments, and the operation has 2 characters
// 				if (strcmp(operation, "LDR") == 0) { // the operation LDR is load
// 					ExecuteLDR(&cpu, &cpu.R[operand1], operand2);
// 				} else {
// 	            	printf("\x1b[31mError: Unknown operation '%s'.\x1b[0m\n", operation);
// 	        	}
// 			} else if (sscanf(line, "%3s %d", operation, &operand1) == 2) { // if the line has 2 arguments, and the operation has 2 characters
//                 if (strcmp(operation, "NOT") == 0) {
//                     ExecuteNOT(&cpu, operand1);
// 				} else if (strcmp(operation, "STR") == 0) { // the operation STR is store
// 					ExecuteSTR(&cpu, operand1, result);
// 				} else if (strcmp(operation, "RMV") == 0) { // the operation RMV is remove
// 					ExecuteRMV(&cpu, operand1);
//                 } else {
//                     printf("\x1b[31mError: Unknown operation '%s'.\x1b[0m\n", operation);
//                 }
// 			} else if (sscanf(line, "%3s %9s", operation, labelName) == 2) { // if the line has 2 arguments, and the operation has 2 characters
// 				if (strcmp(operation, "JMP") == 0) { // the operation JMP is jump
// 					if (resultCMP) { // conditional jump with the CMP operation
// 						for (int i = 0; i < numLabel; i++) {
// 							if (strcmp(labels[i].name, labelName) == 0) {
// 								fseek(file, labels[i].filePosition, SEEK_SET);
// 							}
// 						}
// 					} else { // unconditional jump
// 						for (int i = 0; i < numLabel; i++) {
// 							if (strcmp(labels[i].name, labelName) == 0) {
// 								fseek(file, labels[i].filePosition, SEEK_SET);
// 							}
// 						}
// 					}
// 				} else {
// 					printf("\x1b[31mError: Unknown operation '%s'.\x1b[0m\n", operation);
// 				}
// 			} else if (sscanf(line, "%3s", operation) == 1) { // if the line has 1 argument, and the operation has 3 characters
// 				if (strcmp(operation, "HLT") == 0) { // the operation HLT is halt, to break the code
// 					// printf("Program execution halted.\n");
// 					break;
// 				} else {
// 					printf("\x1b[31mError: Unknown operation '%s'.\x1b[0m\n", operation);
// 				}
// 			}
// 		}
// 	}
// 	fclose(file);
// }
