#include <stdio.h>
#include <string.h>
#include "budget.h"


#define MAX_DEPARTMENTS 20

char departments[MAX_DEPARTMENTS][50];
float budgets[MAX_DEPARTMENTS];
float expenditures[MAX_DEPARTMENTS];
int department_count = 0;

float calculateBudget(float department_budget, float expenditure) {
     return department_budget - expenditure;
}

float getTotalBudget() {
    float total = 0;
    for (int i = 0; i < department_count; i++) {
        total = total + budgets[i];
    }
    return total;
}
float getTotalExpenditure() {
    float total = 0;
    for (int i = 0; i < department_count; i++) {
        total = total + expenditures[i];
    }
    return total;
}

void displayExceeded() {
    int found = 0;
    for (int i = 0; i < department_count; i++) {
        if (expenditures[i] > budgets[i]) {
            printf("%s\n", departments[i]);
            found = 1;
        }
    }
    if (found == 0) {
        printf("No department has exceeded its budget.\n");
    }
}

void budgetManagement() {
    float department_budget;
    float expenditure;
    char department[50];
    float remaining;
    int number;   

    printf("How many departments?\n");
    scanf("%d", &number);
     while (number < 1 || number > MAX_DEPARTMENTS) {
        printf("Enter a number from 1 to %d. Try Again\n", MAX_DEPARTMENTS);
        scanf("%d", &number);
    }

    department_count = 0;

    for (int i = 0; i < number; i++) {
        printf("\nDepartment %d\n", i + 1);

        printf("Enter Department name:\n");
        scanf("%s", department);

        printf("Enter Department Budget:\n");
        scanf("%f", &department_budget);
        while (department_budget < 0) {
            printf("Budget can't be negative. Try Again\n");
            scanf("%f",&department_budget);
        }

        printf("Enter Expenditure:\n");
        scanf("%f", &expenditure);
        while (expenditure < 0) {
            printf("Expenditure can't be negative.Try Again\n");
            scanf("%f", &expenditure);
        }

        strcpy(departments[i], department);
        budgets[i] = department_budget;
        expenditures[i] = expenditure;
        department_count++;

        remaining = calculateBudget(department_budget, expenditure);

        printf("Department: %s\n", department);
        printf("Department Budget: N$%.2f\n", department_budget);
        printf("Expenditure: N$%.2f\n", expenditure);
        printf("Remaining Balance: N$%.2f\n", remaining);

        if (expenditure <= department_budget) {
           printf("Status: WITHIN BUDGET\n");
        } 
        else {
           printf("Status: EXCEEDED BUDGET\n");
        }
    }

    printf("\nDepartments over budget:\n");
    displayExceeded();
}
