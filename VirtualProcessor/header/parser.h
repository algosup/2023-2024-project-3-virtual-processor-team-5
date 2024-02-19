// create parser for parsing the input file .txt
#define MAX_WORD_LENGTH 100
#define MAX_LINE_LENGTH 1024

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

// parse the input file into words and print the type of each word separately
int parser(FILE *file) {
    char line[MAX_LINE_LENGTH];
    // Read and parse each word until end of file
    while (fgets(line, sizeof(line), file) != NULL) {
        char* word = strtok(line, " ,\n");
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
                } else if (strcmp(word, "NOT") == 0) {
                    printf("NOT\n");
                } else if (strcmp(word, "OR") == 0) {
                    printf("OR\n");
                } else if (strcmp(word, "MOV") == 0) {
                    printf("MOV\n");
                } else if (strcmp(word, "RMV") == 0) {
                    printf("RMV\n");
                } else if (strcmp(word, "HLT") == 0) {
                    printf("HLT\n");
                } else if (strcmp(word, "SHL") == 0) {
                    printf("SHL\n");
                } else if (strcmp(word, "SHR") == 0) {
                    printf("SHR\n");
                } else if (strcmp(word, "STR") == 0) {
                    printf("STR\n");
                } else if (strcmp(word, "LDR") == 0) {
                    printf("LDR\n");
                } else if (strcmp(word, "LEA") == 0) {
                    printf("LEA\n");
                } else if (strcmp(word, "LOA") == 0) {
                    printf("LOA\n");
                } else if (strcmp(word, "IN") == 0) {
                    printf("IN\n");
                } else if (strcmp(word, "OUT") == 0) {
                    printf("OUT\n");
                } else if (strcmp(word, "NOP") == 0) {
                    printf("NOP\n");
                } else if (strcmp(word, "COPY") == 0) {
                    printf("COPY\n");
                } else if (strcmp(word, "PUSH") == 0) {
                    printf("PUSH\n");
                } else if (strcmp(word, "POP") == 0) {
                    printf("POP\n");
                } else if (strcmp(word, "CALL") == 0) {
                    printf("CALL\n");
                } else if (strcmp(word, "RET") == 0) {
                    printf("RET\n");
                } else if (strcmp(word, "SYSCALL") == 0) {
                    printf("SYSCALL\n");
                } else if (strcmp(word, "JMP") == 0) {
                    printf("JMP\n");
                } else if (strcmp(word, "JZ") == 0) {
                    printf("JZ\n");
                } else if (strcmp(word, "JNZ") == 0) {
                    printf("JNZ\n");
                } else if (strcmp(word, "JE") == 0) {
                    printf("JE\n");
                } else if (strcmp(word, "JNE") == 0) {
                    printf("JNE\n");
                } else {
                    printf("Unknown operation\n");
                }
            } else if (recognize_and_print_type(word) == 2) {
                if (strcmp(word, "R0") == 0) {
                    printf("R0\n");
                } else if (strcmp(word, "R1") == 0) {
                    printf("R1\n");
                } else if (strcmp(word, "R2") == 0) {
                    printf("R2\n");
                } else if (strcmp(word, "R3") == 0) {
                    printf("R3\n");
                } else if (strcmp(word, "R4") == 0) {
                    printf("R4\n");
                } else if (strcmp(word, "R5") == 0) {
                    printf("R5\n");
                } else if (strcmp(word, "R6") == 0) {
                    printf("R6\n");
                } else if (strcmp(word, "R7") == 0) {
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
            word = strtok(NULL, " ,\n");
        }
    }
    return 0;
}
