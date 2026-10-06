#include <stdio.h> 

#include "reports.h" 
#include "employees.h" 
#include "budget.h" 
#include "suppliers.h" 
#include "assets.h" 

 

void reportEmployees(void) 
{
    int i; 
    float gross; 
    float total = 0; 
    float highest = 0; 
    float lowest = 0; 

    printf("\n========== EMPLOYEE REPORT ==========\n");
    if (employeeCount == 0) { 
        printf("No employees have been added yet.\n"); 
        return; 
    } 

    for (i = 0; i < employeeCount; i++) { 
        gross = basicSalary[i] + housingAllowance[i] 
              + transportAllowance[i] + otherAllowance[i]; 

        total += gross; 
        if (i == 0 || gross > highest) { 
            highest = gross; 
        }
        if (i == 0 || gross < lowest) { 
            lowest = gross; 
        } 
    } 
    printf("TotalEmployees : %d\n", employeeCount); 
    printf("Average Salary  : N$ %.2f\n", total / employeeCount); 
    printf("Highest Salary  : N$ %.2f\n", highest); 
    printf("Lowest Salary   : N$ %.2f\n", lowest); 

} 


void reportBudget(void) 

{

    float totalBudget = getTotalBudget(); 
    float totalSpent = getTotalExpenditure(); 

    printf("\n========== BUDGET REPORT ==========\n"); 
    printf("Total Allocated Budget : N$ %.2f\n", totalBudget); 
    printf("Total Expenditure      : N$ %.2f\n", totalSpent); 
    printf("Remaining Budget       : N$ %.2f\n", totalBudget - totalSpent); 
    printf("\nDepartments exceeding budget:\n"); 

    displayExceeded(); 
} 

void reportSuppliers(void) 
{ 
    printf("\n========== SUPPLIER REPORT ==========\n"); 
    displaySupplier(); 
} 
void reportAssets(void) 

{ 
    printf("\n========== ASSET REPORT ==========\n"); 
    displayAssets(); 
} 

void reportsMenu(void) 
{

    char line[20]; 
    int choice; 
    do { 

        printf("\n===== REPORTS =====\n"); 
        printf("1. Employee Report\n"); 
        printf("2. Budget Report\n"); 
        printf("3. Supplier Report\n"); 
        printf("4. Asset Report\n"); 
        printf("5. Back to Main Menu\n"); 
        printf("Enter choice: "); 

        if (fgets(line, sizeof(line), stdin) == NULL || 
            sscanf(line, "%d", &choice) != 1) { 
            choice = 0; 

        } 

        switch (choice) { 
            case 1: reportEmployees(); break; 
            case 2: reportBudget();    break; 
            case 3: reportSuppliers(); break; 
            case 4: reportAssets();    break; 
            case 5: break; 
            default: printf("Invalid choice. Enter 1 to 5.\n"); 
        } 
    } while (choice != 5); 
} 