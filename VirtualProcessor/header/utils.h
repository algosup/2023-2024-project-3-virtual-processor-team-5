

void read_file(char *filename, char *file_directory) {
    FILE *file;
    char *line = NULL;
    size_t len = 0;
    ssize_t read;

    // create the file path
    char *file_path = (char *)malloc(strlen(file_directory) + strlen(filename) + 1);
    strcpy(file_path, file_directory);
    strcat(file_path, filename);

    file = fopen("C:\\Users\\LucasMEGNAN\\Desktop\\2023-2024-project-3-virtual-processor-team-5\\code.txt", "r");
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