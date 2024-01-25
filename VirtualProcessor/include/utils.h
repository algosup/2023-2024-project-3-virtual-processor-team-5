#include <stdio.h>
#include <string.h>
#include <stdint.h>
#include <stdlib.h>

char file_directory[500];
int fileLine;

// read file with command line
void read_file(char *filename, char *file_directory) {
    FILE *fp;
	fp = fopen(file_directory, "r");
	
	if (fp == NULL){
		printf("File does not exist.\n");
	} else {
		char ch;
		char output[1000];
		int line = 1;
		while ((ch = fgetc(fp)) != EOF){
			if (ch != '\n'){
				strncat(output, &ch, 1);
			} else if (ch == '\n' && line != fileLine){
				output[0] = '\0';
				line++;
			} else if (ch == '\n' && line == fileLine){
				printf("%s\n", output);
				line++;
				break;
			}
			printf("%c", ch);
		}
		fclose(fp);

		int count = 0;	
		char buffer[1000];
		char *ptr = strstr(buffer, "ADD");
		while (ptr != NULL) {
    		count++; // Increment count for each occurrence
    		ptr = strstr(ptr + 1, "ADD");
		}

		printf("\nFile read successfully.\n");
	}
}
