#include <stdio.h>
#include <string.h>
#include <stdint.h>
#include <stdlib.h>

#include "processor.h"
#include "instructions.h"

int registerIndex;
uint16_t result;
char file_directory[500];
int fileLine;
ProcessorState cpu = {0};

// read file with command line
void read_file(char *filename, char *file_directory) {
	FILE *file = fopen(file_directory, "r");
	if (file == NULL) {
    printf("x1b[31mCould not open file.\x1b[0m\n");
    return;}
	
	// if (file == NULL){
	// 	printf("File does not exist.\n");
	// } else {
	// 	char ch;
	// 	char output[1000];
	// 	int line = 1;
	// 	while ((ch = fgetc(file)) != EOF){
	// 		if (ch != '\n'){
	// 			strncat(output, &ch, 1);
	// 		} else if (ch == '\n' && line != fileLine){
	// 			output[0] = '\0';
	// 			line++;
	// 		} else if (ch == '\n' && line == fileLine){
	// 			printf("%s\n", output);
	// 			line++;
	// 			break;
	// 		}
	// 		printf("%c", ch);
	// 	}
	// 	fclose(file);

	char line[256];
	while (fgets(line, sizeof(line), file)) {
    	int operand1, operand2;
    	char operation[4]; // For "ADD" or "SUB"
		// replace "," with " "
		if (strchr(line, ',') != NULL){
			char *p = strchr(line, ',');
			*p = ' ';
		} 
		if (sscanf(line, "%3s %d %d", operation, &operand1, &operand2) == 3) {
        	if (strcmp(operation, "ADD") == 0) {
				result = executeADD(operand1, operand2);
			} else if (strcmp(operation, "MUL") == 0) {
				result = executeMUL(operand1, operand2);
			} else if (strcmp(operation, "DIV") == 0) {
				result = executeDIV(operand1, operand2);
        	} else if (strcmp(operation, "SUB") == 0) {
            	result = executeSUB(operand1, operand2);
        	} else {
            	printf("\x1b[31mError: Unknown operation '%s'.\x1b[0m\n", operation);
        	}
    	} else if (sscanf(line, "%2s %i %hi", operation, &registerIndex, &result) == 2) {
			if (strcmp(operation, "ST") == 0) {
				executeST(&cpu, registerIndex, result);
			} else if (strcmp(operation, "LD") == 0) {
				executeLD(&cpu, &cpu.R[registerIndex], registerIndex);
			} else {
				printf("\x1b[31mError: Unknown operation '%s'.\x1b[0m\n", operation);
			}
		} else {
        	printf("\x1b[31mError: Your lines aren't well written.\x1b[0m\n");
    	}
	}
	fclose(file);
	printf("\x1b[32mFile read successfully.\x1b[0m\n");
}

//****************************** ST RESULT FUNCTION ******************************//
