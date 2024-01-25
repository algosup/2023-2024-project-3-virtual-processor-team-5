#include <stdio.h>
#include <string.h>
#include <stdint.h>
#include <stdlib.h>

#include "processor.h"
#include "instructions.h"

int registers[8];
uint16_t result = 0;
char file_directory[500];
int fileLine;


// read file with command line
void read_file(char *filename, char *file_directory) {
	FILE *file = fopen(file_directory, "r");
	if (file == NULL) {
    printf("Could not open file.\n");
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
    	if (sscanf(line, "%3s %d %d", operation, &operand1, &operand2) == 3) 
		
		{
        	if (strcmp(operation, "ADD") == 0) {
				executeADD(operand1, operand2);
			} else if (strcmp(operation, "MUL") == 0) {
				executeMUL(operand1, operand2);
			} else if (strcmp(operation, "DIV") == 0) {
				executeDIV(operand1, operand2);
        	} else if (strcmp(operation, "SUB") == 0) {
            	executeSUB(operand1, operand2);
        	} else if (strcmp(operation, "ST") == 0) {
				executeST(registers, result);
			} else {
            	printf("Error: Unknown operation '%s'.\n", operation);
        	}
    	} else {
        	printf("Error: Each line must contain an operation and two operands.\n");
    	}
	}
	fclose(file);
	printf("File read successfully.\n");
}


//****************************** ST RESULT FUNCTION ******************************//
