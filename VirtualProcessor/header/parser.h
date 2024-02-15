// create parser for parsing the input file .txt
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORD_LENGTH 100

char word[MAX_WORD_LENGTH];

int is_instruction(char* word) {
    for (int i = 0; word[i]; i++) {
        if (!isupper(word[i])) {
            return 0;
        }
    }
    return 1;
}

int is_register(char* word) {
    if (word[0] != 'R') {
        return 0;
    }
    for (int i = 1; word[i]; i++) {
        if (!isdigit(word[i])) {
            return 0;
        }
    }
    return 1;
}

int is_number(char* word) {
    if (word[0] != '#') {
        return 0;
    }
    for (int i = 1; word[i]; i++) {
        if (!isdigit(word[i])) {
            return 0;
        }
    }
    return 1;
}

int is_label(char* word) {
    int len = strlen(word);
    return len > 0 && word[len - 1] == ':';
}

char* trim_whitespace(char* str) {
    while(isspace((unsigned char)*str)) str++;

    if(*str == 0)  
        return str;

    char* end_str;
    end_str = str + strlen(str) - 1;
    while(end_str > str && isspace((unsigned char)*end_str)) end_str--;

    end_str[1] = '\0';

    return str;
}

int recognize_and_print_type(char* word) {
    word = trim_whitespace(word);
    if (is_instruction(word)) {
        return 1;
    } else if (is_register(word)) {
        return 2;
    } else if (is_number(word)) {
        return 3;
    } else if (is_label(word)) {
        return 4;
    } else {
        // unknown type
        return 0;
    }
}

int parser(char *line, FILE *file) {
        // Read and parse each word until end of file
        while (fgets(line, sizeof(line), file)) {
            char* word = strtok(line, " ,");
            while (word != NULL) {
                if (recognize_and_print_type(word) == 1) {
                    if (strcmp(word, "ADD") == 0) {
                        printf("ADD\n");
                    } else if (strcmp(word, "SUB") == 0) {
                        printf("SUB\n");
                    } else if (strcmp(word, "MUL") == 0) {
                        printf("MUL\n");
                    } else if (strcmp(word, "DIV") == 0) {
                        printf("DIV\n");
                    } else if (strcmp(word, "CMP") == 0) {
                        printf("CMP\n");
                    } else if (strcmp(word, "AND") == 0) {
                        printf("AND\n");
                    } else if (strcmp(word, "XOR") == 0) {
                        printf("XOR\n");
                    } else if (strcmp(word, "CP") == 0) {
                        printf("CP\n");
                    } else if (strcmp(word, "OR") == 0) {
                        printf("OR\n");
                    } else if (strcmp(word, "MOV") == 0) {
                        printf("MOV\n");
                    } else {
                        printf("Unknown operation\n");
                    }
                } else if (recognize_and_print_type(word) == 2) {
                    if (strcmp(word, "R0")) {
                        printf("R0\n");
                    } else if (strcmp(word, "R1")) {
                        printf("R1\n");
                    } else if (strcmp(word, "R2")) {
                        printf("R2\n");
                    } else if (strcmp(word, "R3")) {
                        printf("R3\n");
                    } else if (strcmp(word, "R4")) {
                        printf("R4\n");
                    } else if (strcmp(word, "R5")) {
                        printf("R5\n");
                    } else if (strcmp(word, "R6")) {
                        printf("R6\n");
                    } else if (strcmp(word, "R7")) {
                        printf("R7\n");
                    } else {
                        printf("Unknown register\n");
                    }
                } else if (recognize_and_print_type(word) == 3) {
                    // print the number without the first character
                    printf("%s\n", word + 1);
                } else if (recognize_and_print_type(word) == 4) {
                    printf("%s\n", word);
                } else {
                    printf("Unknown type\n");
                }
                word = strtok(NULL, " ,");

            }
        }

    return 0;
}
