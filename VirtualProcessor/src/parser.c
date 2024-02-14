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

int is_character(char* word) {
    return strlen(word) == 1;
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
    } else if (is_character(word)) {
        return 5;
    } else {
        // unknown type
        return 0;
    }
}

int main() {
    FILE *file;

    // Open the file in read mode
    file = fopen("code.txt", "r");
    if (file == NULL) { // verify if the file exists
    	printf("\x1b[31mCould not open file.\x1b[0m\n\n");
	} else {
		printf("\x1b[32mFile opened successfully.\x1b[0m\n\n");

        // Read and parse each word until end of file
        char line[256];
        while (fgets(line, sizeof(line), file)) {
            char* word = strtok(line, " ,");
            while (word != NULL) {
                printf("%d\n", recognize_and_print_type(word));
                word = strtok(NULL, " ,");
            }
        }
    }

    fclose(file); // Close the file

    return 0;
}
