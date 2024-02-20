

#include "processor.h"
#include "instructions2.h"
#include "parser.h"

void read_file(char *filename, char *file_directory) {
    FILE *file;
    char *line = NULL;
    size_t len = 0;
    ssize_t read;

    // create the file path
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
    parser(file);

    fclose(file);

    // free the memory
    if (line) {
        free(line);
    }
}