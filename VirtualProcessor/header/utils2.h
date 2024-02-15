#include <stdio.h>
#include <string.h>
#include <stdint.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>

#include "processor.h"
#include "instructions2.h"
#include "parser.h"

void read_file(char *filename, char *file_directory) {
    FILE *file;
    char *line = NULL;
    size_t len = 0;
    ssize_t read;

    char *file_path = malloc(strlen(file_directory) + strlen(filename) + 1);
    strcpy(file_path, file_directory);
    strcat(file_path, filename);

    file = fopen("code.txt", "r");
    if (file == NULL) {
        printf("\x1b[31mCould not open file.\x1b[0m\n");
        exit(1);
    } else {
		printf("\x1b[32mFile opened successfully.\x1b[0m\n");
    }

    // parse the file
    while ((read = getline(&line, &len, file)) != -1) {
        printf("%s", line);
        parser(line, file);
    }

    fclose(file);
    if (line) {
        free(line);
    }
}