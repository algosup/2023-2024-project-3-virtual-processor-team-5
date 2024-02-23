#include <stdio.h>
#include <string.h>
#include <stdint.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>

#include "processor.h"
#include "instructions.h"
#include "parser.h"

char wordInLigne[MAX_LINE_LENGTH];

void read_file(char *filename, char *file_directory) {
    FILE *file;
    char *line = NULL;
    size_t len = 0;
    ssize_t read;

    // create the file path
    char *file_path = (char *)malloc(strlen(file_directory) + strlen(filename) + 1);
    strcpy(file_path, file_directory);
    strcat(file_path, filename);

    file = fopen("code.txt", "r");
    if (file == NULL) {
        printf("\x1b[31mCould not open file.\x1b[0m\n");
        exit(1);
    } else {
		printf("\x1b[32mFile opened successfully.\x1b[0m\n\n");
    }

    // parse the file
    parser(file);

    fclose(file);

    // free the memory
    printf("\n\x1b[32mmemory = %d\x1b[0m\n", *file_path);
    free(file_path);
    printf("\x1b[32mmemory = %d\x1b[0m\n", *file_path);
}
