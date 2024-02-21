// create parser for parsing the input file .txt
#define MAX_WORD_LENGTH 100
#define MAX_LINE_LENGTH 1024
#define R 8

ProcessorState cpu = {0};  // Initializes processor with default values

char word[MAX_WORD_LENGTH];

typedef struct {
    char* word;
    int type;
} Word;

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

char wordInLigne[MAX_LINE_LENGTH]; // variable to store the line read from the file
int wordSize = 0; // variable to store the size of the word

// parse the input file into words and print the type of each word separately
int parser(FILE *file) {
    char line[MAX_LINE_LENGTH];
    // Read and parse each word until end of file
    while (fgets(line, sizeof(line), file) != NULL) {
        instruction_t instruction;
        char* word = strtok(line, " ,\n");
        while (word != NULL) {
            // when the line if finished, you need to execute the instruction
            if (strcmp(word, "\n") == 0) {
                execute_instruction(instruction, &cpu);
                printf("End of line\n");
            /*if (strcmp(line, "\n") == 0) {
                printf("Line too long\n");
                if (*wordInLigne != 0) {
                    printf("coucou");
                    printf("%s\n", wordInLigne);
                    instruction.opcode = wordInLigne[0];
                    execute_instruction(instruction, &cpu);
                    // reinitialise the wordInLigne
                    wordInLigne[0] = 0;
                }*/
            } else if (recognize_and_print_type(word) == 1) {
                if (strcmp(word, "ADD") == 0) {
                    instruction.opcode = ADD_OPCODE;
                    wordInLigne[wordSize] = instruction.opcode; // add the opcode in the wordInLigne array
                    wordSize++;
                    printf("ADD\n");
                } else if (strcmp(word, "SUB") == 0) {
                    instruction.opcode = SUB_OPCODE;
                    wordInLigne[wordSize] = instruction.opcode;
                    wordSize++;
                    printf("SUB\n");
                } else if (strcmp(word, "MUL") == 0) {
                    instruction.opcode = MUL_OPCODE;
                    wordInLigne[wordSize] = instruction.opcode;
                    wordSize++;
                    printf("MUL\n");
                } else if (strcmp(word, "DIV") == 0) {
                    instruction.opcode = DIV_OPCODE;
                    wordInLigne[wordSize] = instruction.opcode;
                    wordSize++;
                    printf("DIV\n");
                } else if (strcmp(word, "CMP") == 0) {
                    instruction.opcode = CMP_OPCODE;
                    wordInLigne[wordSize] = instruction.opcode;
                    wordSize++;
                    printf("CMP\n");
                } else if (strcmp(word, "AND") == 0) {
                    instruction.opcode = AND_OPCODE;
                    wordInLigne[wordSize] = instruction.opcode;
                    wordSize++;
                    printf("AND\n");
                } else if (strcmp(word, "XOR") == 0) {
                    instruction.opcode = XOR_OPCODE;
                    wordInLigne[wordSize] = instruction.opcode;
                    wordSize++;
                    printf("XOR\n");
                } else if (strcmp(word, "NOT") == 0) {
                    instruction.opcode = NOT_OPCODE;
                    wordInLigne[wordSize] = instruction.opcode;
                    wordSize++;
                    printf("NOT\n");
                } else if (strcmp(word, "OR") == 0) {
                    instruction.opcode = OR_OPCODE;
                    wordInLigne[wordSize] = instruction.opcode;
                    wordSize++;
                    printf("OR\n");
                } else if (strcmp(word, "MOV") == 0) {
                    instruction.opcode = MOV_OPCODE;
                    wordInLigne[wordSize] = instruction.opcode;
                    wordSize++;
                    printf("MOV\n");
                } else if (strcmp(word, "RMV") == 0) {
                    instruction.opcode = RMV_OPCODE;
                    wordInLigne[wordSize] = instruction.opcode;
                    wordSize++;
                    printf("RMV\n");
                } else if (strcmp(word, "HLT") == 0) {
                    instruction.opcode = HLT_OPCODE;
                    wordInLigne[wordSize] = instruction.opcode;
                    wordSize++;
                    printf("HLT\n");
                /*} else if (strcmp(word, "SHL") == 0) {
                    instruction.opcode = SHL_OPCODE;
                    wordInLigne[wordSize] = instruction.opcode;
                    wordSize++;
                    printf("SHL\n");
                } else if (strcmp(word, "SHR") == 0) {
                    instruction.opcode = SHR_OPCODE;
                    wordInLigne[wordSize] = instruction.opcode;
                    wordSize++;
                    printf("SHR\n");*/
                } else if (strcmp(word, "STR") == 0) {
                    instruction.opcode = STR_OPCODE;
                    wordInLigne[wordSize] = instruction.opcode;
                    wordSize++;
                    printf("STR\n");
                } else if (strcmp(word, "LDR") == 0) {
                    instruction.opcode = LDR_OPCODE;
                    wordInLigne[wordSize] = instruction.opcode;
                    wordSize++;
                    printf("LDR\n");
                /*} else if (strcmp(word, "LEA") == 0) {
                    instruction.opcode = LEA_OPCODE;
                    wordInLigne[wordSize] = instruction.opcode;
                    wordSize++;
                    printf("LEA\n");
                } else if (strcmp(word, "LOA") == 0) {
                    instruction.opcode = LOA_OPCODE;
                    wordInLigne[wordSize] = instruction.opcode;
                    wordSize++;
                    printf("LOA\n");
                } else if (strcmp(word, "IN") == 0) {
                    instruction.opcode = IN_OPCODE;
                    wordInLigne[wordSize] = instruction.opcode;
                    wordSize++;
                    printf("IN\n");
                } else if (strcmp(word, "OUT") == 0) {
                    instruction.opcode = OUT_OPCODE;
                    wordInLigne[wordSize] = instruction.opcode;
                    wordSize++;
                    printf("OUT\n");
                } else if (strcmp(word, "NOP") == 0) {
                    instruction.opcode = NOP_OPCODE;
                    wordInLigne[wordSize] = instruction.opcode;
                    wordSize++;
                    printf("NOP\n");*/
                } else if (strcmp(word, "COPY") == 0) {
                    instruction.opcode = COPY_OPCODE;
                    wordInLigne[wordSize] = instruction.opcode;
                    wordSize++;
                    printf("COPY\n");
                /*} else if (strcmp(word, "PUSH") == 0) {
                    instruction.opcode = PUSH_OPCODE;
                    wordInLigne[wordSize] = instruction.opcode;
                    wordSize++;
                    printf("PUSH\n");
                } else if (strcmp(word, "POP") == 0) {
                    instruction.opcode = POP_OPCODE;
                    wordInLigne[wordSize] = instruction.opcode;
                    wordSize++;
                    printf("POP\n");
                } else if (strcmp(word, "CALL") == 0) {
                    instruction.opcode = CALL_OPCODE;
                    wordInLigne[wordSize] = instruction.opcode;
                    wordSize++;
                    printf("CALL\n");
                } else if (strcmp(word, "RET") == 0) {
                    instruction.opcode = RET_OPCODE;
                    wordInLigne[wordSize] = instruction.opcode;
                    wordSize++;
                    printf("RET\n");
                } else if (strcmp(word, "SYSCALL") == 0) {
                    instruction.opcode = SYSCALL_OPCODE;
                    wordInLigne[wordSize] = instruction.opcode;
                    wordSize++;
                    printf("SYSCALL\n");*/
                } else if (strcmp(word, "JMP") == 0) {
                    instruction.opcode = JMP_OPCODE;
                    wordInLigne[wordSize] = instruction.opcode;
                    wordSize++;
                    printf("JMP\n");
                /*} else if (strcmp(word, "JZ") == 0) {
                    instruction.opcode = JZ_OPCODE;
                    wordInLigne[wordSize] = instruction.opcode;
                    wordSize++;
                    printf("JZ\n");
                } else if (strcmp(word, "JNZ") == 0) {
                    instruction.opcode = JNZ_OPCODE;
                    wordInLigne[wordSize] = instruction.opcode;
                    wordSize++;
                    printf("JNZ\n");
                } else if (strcmp(word, "JE") == 0) {
                    instruction.opcode = JE_OPCODE;
                    wordInLigne[wordSize] = instruction.opcode;
                    wordSize++;
                    printf("JE\n");
                } else if (strcmp(word, "JNE") == 0) {
                    instruction.opcode = JNE_OPCODE;
                    wordInLigne[wordSize] = instruction.opcode;
                    wordSize++;
                    printf("JNE\n");*/
                } else {
                    printf("Unknown operation\n");
                }
            } else if (recognize_and_print_type(word) == 2) {
                if (strcmp(word, "R0") == 0) {
                    instruction.opcode = R[(int *)(word + 1)];
                    wordInLigne[wordSize] = instruction.opcode;
                    wordSize++;
                    printf("R0\n");
                } else if (strcmp(word, "R1") == 0) {
                    instruction.opcode = R[(int *)(word + 1)];
                    wordInLigne[wordSize] = instruction.opcode;
                    wordSize++;
                    printf("R1\n");
                } else if (strcmp(word, "R2") == 0) {
                    instruction.opcode = R[(int *)(word + 1)];
                    wordInLigne[wordSize] = instruction.opcode;
                    wordSize++;
                    printf("R2\n");
                } else if (strcmp(word, "R3") == 0) {
                    instruction.opcode = R[(int *)(word + 1)];
                    wordInLigne[wordSize] = instruction.opcode;
                    wordSize++;
                    printf("R3\n");
                } else if (strcmp(word, "R4") == 0) {
                    instruction.opcode = R[(int *)(word + 1)];
                    wordInLigne[wordSize] = instruction.opcode;
                    wordSize++;
                    printf("R4\n");
                } else if (strcmp(word, "R5") == 0) {
                    instruction.opcode = R[(int *)(word + 1)];
                    wordInLigne[wordSize] = instruction.opcode;
                    wordSize++;
                    printf("R5\n");
                } else if (strcmp(word, "R6") == 0) {
                    instruction.opcode = R[(int *)(word + 1)];
                    wordInLigne[wordSize] = instruction.opcode;
                    wordSize++;
                    printf("R6\n");
                } else if (strcmp(word, "R7") == 0) {
                    instruction.opcode = R[(int *)(word + 1)];
                    wordInLigne[wordSize] = instruction.opcode;
                    wordSize++;
                    printf("R7\n");
                } else {
                    printf("Unknown register\n");
                }
            } else if (recognize_and_print_type(word) == 3) {
                instruction.opcode = word[0] - '0';
                wordInLigne[wordSize] = instruction.opcode;
                wordSize++;
                printf("%s\n", word + 1); // print the number without the first character
            } else if (recognize_and_print_type(word) == 4) {
                instruction.opcode = word[0] - '0';
                wordInLigne[wordSize] = instruction.opcode;
                wordSize++;
                printf("%s\n", word);
            } else {
                printf("Unknown type\n");
            }
            word = strtok(NULL, " ,\n");
        }
    }
    return 0;
}
