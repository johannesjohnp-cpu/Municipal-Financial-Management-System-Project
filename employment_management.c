#include <stdio.h>
#include <string.h>
#include "employment_management.h"
#include "validation.h"

int employeeCount = 0;
double basicSalary[MAX_EMPLOYEES];
double housingAllowance[MAX_EMPLOYEES];
double transportAllowance[MAX_EMPLOYEES];
double otherAllowance[MAX_EMPLOYEES];

void addEmployee(void) {
    if (employeeCount >= MAX_EMPLOYEES) {
        printf("Employee database is full.\n");
        return;
    }
    
    printf("\n--- Add New Employee ---\n");
    printf("Enter basic salary: ");
    if (scanf("%lf", &basicSalary[employeeCount]) != 1) {
        basicSalary[employeeCount] = 0.0;
    }
    
    printf("Enter housing allowance: ");
    if (scanf("%lf", &housingAllowance[employeeCount]) != 1) {
        housingAllowance[employeeCount] = 0.0;
    }
    
    printf("Enter transport allowance: ");
    if (scanf("%lf", &transportAllowance[employeeCount]) != 1) {
        transportAllowance[employeeCount] = 0.0;
    }
    
    printf("Enter other allowance: ");
    if (scanf("%lf", &otherAllowance[employeeCount]) != 1) {
        otherAllowance[employeeCount] = 0.0;
    }
    
    employeeCount++;
    printf("Employee added successfully!\n");
}

void displayEmployees(void) {
    if (employeeCount == 0) {
        printf("No employees recorded yet.\n");
        return;
    }
    
    printf("\n--- Employee List ---\n");
    for (int i = 0; i < employeeCount; i++) {
        printf("Employee %d: Basic=%.2f, Housing=%.2f, Transport=%.2f, Other=%.2f\n",
               i + 1, basicSalary[i], housingAllowance[i], transportAllowance[i], otherAllowance[i]);
    }
}

void searchEmployee(void) {
    printf("Search feature not fully implemented yet.\n");
}

void calculateSalary(void) {
    if (employeeCount == 0) {
        printf("No employees to calculate salaries for.\n");
        return;
    }
    
    printf("\n--- Salary Calculations ---\n");
    for (int i = 0; i < employeeCount; i++) {
        double gross = basicSalary[i] + housingAllowance[i] + transportAllowance[i] + otherAllowance[i];
        printf("Employee %d Total Gross Salary: %.2f\n", i + 1, gross);
    }
}
