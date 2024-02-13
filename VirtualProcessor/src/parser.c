// create parser for parsing the input file .txt
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORD_LENGTH 100

int main() {
    FILE *file;
    char word[MAX_WORD_LENGTH];

    // Open the file in read mode
    file = fopen("code.txt", "r");
    if (file == NULL) { // verify if the file exists
    	printf("\x1b[31mCould not open file.\x1b[0m\n\n");
	} else {
		printf("\x1b[32mFile opened successfully.\x1b[0m\n\n");

        // Read and parse each word until end of file
        while (fscanf(file, "%s", word) != EOF) {
            // Replace commas with spaces
            char *token = strtok(word, ",");
            while (token != NULL) {
                printf("Word: %s\n", token); // Print or process each word as desired
                token = strtok(NULL, ",");
            }
        }
    }

    fclose(file); // Close the file

    return 0;
}
