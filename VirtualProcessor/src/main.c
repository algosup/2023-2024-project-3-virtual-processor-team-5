#include "../include/processor.h"

int main() {
    Memory memory = {{0}};  // Initialise la mémoire avec des valeurs par défaut
    ProcessorState cpu = {0};  // Initialise le processeur avec des valeurs par défaut
    char input[100];
    printf("Simple Terminal\n");
    while (1) {
        printf("> ");
        fgets(input, sizeof(input), stdin);
        // Supprime le caractère de nouvelle ligne du buffer
        size_t len = strlen(input);
        if (len > 0 && input[len - 1] == '\n') {
            input[len - 1] = '\0';
        }
        // Analyse l'instruction (ici, nous simplifions en supposant ADD avec deux opérandes)
        if (strcmp(input, "exit") == 0) {
            printf("Exiting...\n");
            break;
        } else if (strcmp(input, "STR") == 0){
            
        } else if (strcmp(input, "ADD") == 0) {
            int operand1, operand2;
            printf("Enter operand 1: ");
            scanf("%d", &operand1);
            printf("Enter operand 2: ");
            scanf("%d", &operand2);
            // Consomme le caractère de nouvelle ligne restant dans le buffer
            while (getchar() != '\n');
            // Exécute l'instruction ADD
            executeADD(&cpu, operand1, operand2, &cpu.R0);
            // Affiche le résultat
            printf("Result in R0: %d\n", cpu.R0.value);
        } else if (strcmp(input, "MUL") == 0) {
            int operand1, operand2;
            printf("Enter operand 1: ");
            scanf("%d", &operand1);
            printf("Enter operand 2: ");
            scanf("%d", &operand2);
            // Consomme le caractère de nouvelle ligne restant dans le buffer
            while (getchar() != '\n');
            // Exécute l'instruction MUL
            executeMUL(&cpu, operand1, operand2, &cpu.R0);
            // Affiche le résultat
            printf("Result in R0: %d\n", cpu.R0.value);
        } else if (strcmp(input, "DIV") == 0){
            int operand1, operand2;
            printf("Enter operand 1: ");
            scanf("%d", &operand1);
            printf("Enter operand 2: ");
            scanf("%d", &operand2);
            while (getchar() != '\n');
            // Exécute l'instruction ADD
            executeDIV(&cpu, operand1, operand2, &cpu.R0);
            // Affiche le résultat
            printf("Result in R0: %d\n", cpu.R0.value);
        } else if (strcmp(input, "SUB") == 0){
            int operand1, operand2;
            printf("Enter operand 1: ");
            scanf("%d", &operand1);
            printf("Enter operand 2: ");
            scanf("%d", &operand2);
            while (getchar() != '\n');
            // Exécute l'instruction ADD
            executeSUB(&cpu, operand1, operand2, &cpu.R0);
            // Affiche le résultat
            printf("Result in R0: %d\n", cpu.R0.value);
        } else if (strcmp(input, "ST") == 0){
            int memoryAddress;
            printf("Enter memory address: ");
            scanf("%d", &memoryAddress);
            while (getchar() != '\n');
            // Exécute l'instruction ADD
            executeST(&cpu, cpu.R0.value, memoryAddress, &memory);
        } else if (strcmp(input, "LD")==0){
            int memoryAddress;
            printf("Enter memory address: ");
            scanf("%d", &memoryAddress);
            while (getchar() != '\n');
            // Exécute l'instruction ADD
            executeLD(&cpu, cpu.R0.value, memoryAddress, &memory);
        }
        else {
            printf("Unknown instruction. Try ADD, SUB, MUL or DIV.\n");
        }
    }
    return 0;
}