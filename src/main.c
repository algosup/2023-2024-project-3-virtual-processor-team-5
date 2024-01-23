#include <stdio.h>
#include <string.h>
// Structure du registre
typedef struct {
    int value;
} Register;
// Structure de l'état du processeur
typedef struct {
    Register R0;
    Register R1;
    Register R2;
    Register R3;
    Register R4;
    int PC;  // Compteur de programme
} ProcessorState;
// Fonction d'exécution de l'instruction ADD
void executeADD(ProcessorState *state, int operand1, int operand2, Register *destination) {
    destination->value = operand1 + operand2;
}
void executeMUL(ProcessorState *state, int operand1, int operand2, Register *destination) {
    int result = 0;
    // Itération pour simuler la multiplication
    for (int i = 0; i < operand2; ++i) {
        result += operand1;
    }
    destination->value = result;
}
void executeDIV(ProcessorState *state, int operand1, int operand2, Register *destination) {
    destination->value = operand1 / operand2;
}
void executeSUB(ProcessorState *state, int operand1, int operand2, Register *destination) {
    destination->value = operand1 - operand2;
}
int main() {
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
        } else {
            printf("Unknown instruction. Try ADD.\n");
        } if (strcmp(input, "MUL") == 0) {
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
        } else {
            printf("Unknown instruction. Try MUL.\n");
        } if (strcmp(input, "DIV") == 0){
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
        } else {
            printf("Unknown instruction. Try DIV.\n");
        } if (strcmp(input, "SUB") == 0){
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
        } else {
            printf("Unknown instruction. Try SUB.\n");
        }
    }
    return 0;
}