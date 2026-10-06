#include <stdio.h>
#include <string.h>

#define MAX_EMPLOYEES 50


int employeeID[MAX_EMPLOYEES];  
char employeeName[MAX_EMPLOYEES][50];
char department[MAX_EMPLOYEES][50];
float basicSalary[MAX_EMPLOYEES];
float housingAllowance[MAX_EMPLOYEES];
float transportAllowance[MAX_EMPLOYEES];
float otherAllowance[MAX_EMPLOYEES];
int employeeCount = 0;


void addEmployee();
void displayEmployees();
void searchEmployee();
void calculateSalary();



int main()
{
    int choice;

    do
    {
        printf("\n");
        printf("========================================\n");
        printf("       EMPLOYEE MANAGEMENT SYSTEM\n");
        printf("========================================\n");
        printf("1. Add Employee\n");
        printf("2. Display Employees\n");
        printf("3. Search Employee\n");
        printf("4. Calculate Employee Salary\n");
        printf("5. Exit\n");
        printf("========================================\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                addEmployee();
                break;

            case 2:
                displayEmployees();
                break;

            case 3:
                searchEmployee();
                break;

            case 4:
                calculateSalary();
                break;

            case 5:
                printf("\nExiting Employee Management System...\n");
                break;

            default:
                printf("\nInvalid choice. Please try again.\n");
        }

    } while (choice != 5);

    return 0;
}



void addEmployee()
{
    if (employeeCount >= MAX_EMPLOYEES)
    {
        printf("\nEmployee limit reached.\n");
        return;
    }

    printf("\n========== ADD EMPLOYEE ==========\n");

    
    printf("Enter Employee ID: ");
    scanf("%d", &employeeID[employeeCount]);

    
    printf("Enter Employee Name: ");
    scanf(" %[^\n]", employeeName[employeeCount]);

    
    printf("Enter Department: ");
    scanf(" %[^\n]", department[employeeCount]);


    do
    {
        printf("Enter Basic Salary: N$ ");
        scanf("%f", &basicSalary[employeeCount]);

        if (basicSalary[employeeCount] < 0)
        {
            printf("Salary cannot be negative.\n");
        }

    } while (basicSalary[employeeCount] < 0);



    do
    {
        printf("Enter Housing Allowance: N$ ");
        scanf("%f", &housingAllowance[employeeCount]);

        if (housingAllowance[employeeCount] < 0)
        {
            printf("Allowance cannot be negative.\n");
        }

    } while (housingAllowance[employeeCount] < 0);


    
    do
    {
        printf("Enter Transport Allowance: N$ ");
        scanf("%f", &transportAllowance[employeeCount]);

        if (transportAllowance[employeeCount] < 0)
        {
            printf("Allowance cannot be negative.\n");
        }

    } while (transportAllowance[employeeCount] < 0);


   
    do
    {
        printf("Enter Other Allowance: N$ ");
        scanf("%f", &otherAllowance[employeeCount]);

        if (otherAllowance[employeeCount] < 0)
        {
            printf("Allowance cannot be negative.\n");
        }

    } while (otherAllowance[employeeCount] < 0);


    employeeCount++;

    printf("\nEmployee added successfully!\n");
}



void displayEmployees()
{
    int i;

    if (employeeCount == 0)
    {
        printf("\nNo employees have been added yet.\n");
        return;
    }

    printf("\n========== EMPLOYEE LIST ==========\n");

    for (i = 0; i < employeeCount; i++)
    {
        printf("\nEmployee %d\n", i + 1);
        printf("-------------------------------\n");

        printf("Employee ID: %d\n", employeeID[i]);
        printf("Name: %s\n", employeeName[i]);
        printf("Department: %s\n", department[i]);
        printf("Basic Salary: N$ %.2f\n", basicSalary[i]);
        printf("Housing Allowance: N$ %.2f\n", housingAllowance[i]);
        printf("Transport Allowance: N$ %.2f\n", transportAllowance[i]);
        printf("Other Allowance: N$ %.2f\n", otherAllowance[i]);
    }
}



void searchEmployee()
{
    int id;
    int i;
    int found = 0;

    if (employeeCount == 0)
    {
        printf("\nNo employees have been added yet.\n");
        return;
    }

    printf("\n========== SEARCH EMPLOYEE ==========\n");

    printf("Enter Employee ID: ");
    scanf("%d", &id);

    for (i = 0; i < employeeCount; i++)
    {
        if (employeeID[i] == id)
        {
            printf("\nEmployee Found!\n");
            printf("-------------------------------\n");

            printf("Employee ID: %d\n", employeeID[i]);
            printf("Name: %s\n", employeeName[i]);
            printf("Department: %s\n", department[i]);
            printf("Basic Salary: N$ %.2f\n", basicSalary[i]);
            printf("Housing Allowance: N$ %.2f\n", housingAllowance[i]);
            printf("Transport Allowance: N$ %.2f\n",
                   transportAllowance[i]);
            printf("Other Allowance: N$ %.2f\n",
                   otherAllowance[i]);

            found = 1;
            break;
        }
    }

    if (found == 0)
    {
        printf("\nEmployee not found.\n");
    }
}



void calculateSalary()
{
    int id;
    int i;
    int found = 0;

    float grossSalary;

    if (employeeCount == 0)
    {
        printf("\nNo employees have been added yet.\n");
        return;
    }

    printf("\n========== SALARY CALCULATION ==========\n");

    printf("Enter Employee ID: ");
    scanf("%d", &id);

    for (i = 0; i < employeeCount; i++)
    {
        if (employeeID[i] == id)
        {
            grossSalary = basicSalary[i]
                        + housingAllowance[i]
                        + transportAllowance[i]
                        + otherAllowance[i];

            printf("\nEmployee: %s\n", employeeName[i]);
            printf("-------------------------------\n");

            printf("Basic Salary: N$ %.2f\n",
                   basicSalary[i]);

            printf("Housing Allowance: N$ %.2f\n",
                   housingAllowance[i]);

            printf("Transport Allowance: N$ %.2f\n",
                   transportAllowance[i]);

            printf("Other Allowance: N$ %.2f\n",
                   otherAllowance[i]);

            printf("-------------------------------\n");

            printf("Gross Salary: N$ %.2f\n",
                   grossSalary);

            found = 1;
            break;
        }
    }

    if (found == 0)
    {
        printf("\nEmployee not found.\n");
    }
}