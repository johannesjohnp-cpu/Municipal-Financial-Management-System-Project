#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "validation.h"

int getMenuChoice(int maxOption) {
    char line[50];
    int choice = -1;
    while (1) {
        printf("Enter choice (1-%d): ", maxOption);
        if (fgets(line, sizeof(line), stdin) != NULL) {
            if (sscanf(line, "%d", &choice) == 1 && choice >= 1 && choice <= maxOption) {
                return choice;
            }
        }
        printf("Invalid input. Please enter a number between 1 and %d.\n", maxOption);
    }
}

void getString(const char *prompt, char *dest, int size) {
    do {
        printf("%s", prompt);
        if (fgets(dest, size, stdin) != NULL) {
            dest[strcspn(dest, "\n")] = '\0';
        }
        if (strlen(dest) == 0) {
            printf("Input cannot be empty. Please try again.\n");
        }
    } while (strlen(dest) == 0);
}