
#include <stdio.h>

//Employee Management Header File Inclusion

#if __has_include("employees.h")
#include "employees.h"
#elif __has_include("employee.h")
#include "employee.h"
#else
void addEmployee(void);
void displayEmployees(void);
void searchEmployee(void);
void calculateSalary(void);
#endif

//================================================================================
//Budget Management Header File Inclusion


#if __has_include("budget.h")
#include "budget.h"
#else
int budgetManagement(void);
#endif

//================================================================================
//Supplier Management Header File Inclusion


#if __has_include("suppliers.h")
#include "suppliers.h"
#elif __has_include("supplier.h")
#include "supplier.h"
#else
void supplierMenu(void);
#endif


 //================================================================================
//Asset Management Header File Inclusion

#if __has_include("assets.h")
#include "assets.h"
#elif __has_include("asset.h")
#include "asset.h"
#else
void addAssets(void);
void displayAssets(void);
void searchAssets(void);
#endif

//================================================================================
static int readChoice(void)
{
    char line[20];
    int choice;

    if (fgets(line, sizeof(line), stdin) == NULL ||
        sscanf(line, "%d", &choice) != 1) {
        return 0;
    }
    return choice;
}

static void employeeMenu(void)
{
    int choice;
    do {
        printf("\n===== EMPLOYEE MANAGEMENT =====\n");
        printf("1. Add Employee\n2. Display Employees\n");
        printf("3. Search Employee\n4. Calculate Salary\n5. Back\n");
        printf("Enter choice: ");
        choice = readChoice();

        switch (choice) {
            case 1: addEmployee();      break;
            case 2: displayEmployees(); break;
            case 3: searchEmployee();   break;
            case 4: calculateSalary();  break;
            case 5: break;
            default: printf("Invalid choice.\n");
        }
    } while (choice != 5);
}

static void assetMenu(void)
{
    int choice;
    do {
        printf("\n===== ASSET MANAGEMENT =====\n");
        printf("1. Add Asset\n2. Display Assets\n3. Search Asset\n4. Back\n");
        printf("Enter choice: ");
        choice = readChoice();

        switch (choice) {
            case 1: addAssets();     break;
            case 2: displayAssets(); break;
            case 3: searchAssets();  break;
            case 4: break;
            default: printf("Invalid choice.\n");
        }
    } while (choice != 4);
}

int main(void)
{
    int choice;

    do {
        printf("\n========================================\n");
        printf("MUNICIPAL FINANCIAL MANAGEMENT SYSTEM\n");
        printf("========================================\n");
        printf("1. Employee Management\n2. Budget Management\n");
        printf("3. Supplier Management\n4. Asset Management\n");
        printf("5. Reports\n6. Exit\n");
        printf("Enter your choice: ");

        choice = readChoice();

        switch (choice) {
            case 1: employeeMenu();     break;
            case 2: budgetManagement(); break;
            case 3: supplierMenu();     break;
            case 4: assetMenu();        break;
            case 5: printf("Reports coming soon.\n"); break;
            case 6: printf("Goodbye.\n"); break;
            default: printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 6);

    return 0;
}