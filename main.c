#include <stdio.h>

#include "validation.h"
#include "employment_management.h"

#include "budget.h"

#include "suppliers.h"

#include "assets.h"

#include "reports.h"


#define MENU_EMPLOYEES 1

#define MENU_BUDGET    2

#define MENU_SUPPLIERS 3

#define MENU_ASSETS    4

#define MENU_REPORTS   5

#define MENU_EXIT      6


static void displayMenu(void);

static void displayWelcome(void);

static int  confirmExit(void);

static void runEmployeeMenu(void);

static void runAssetMenu(void);


int main(void)

{

    int choice;

    int running = 1;


    displayWelcome();


    while (running) {

        displayMenu();

        choice = getMenuChoice(MENU_EXIT);


        switch (choice) {

        case MENU_EMPLOYEES:

            runEmployeeMenu();

            break;

        case MENU_BUDGET:

            budgetManagement();

            break;

        case MENU_SUPPLIERS:

            supplierMenu();

            break;

        case MENU_ASSETS:

            runAssetMenu();

            break;

        case MENU_REPORTS:

            reportsMenu();

            break;

        case MENU_EXIT:

            if (confirmExit()) {

                running = 0;

            }

            break;

        default:

            printf("Invalid option. Please try again.\n");

            break;

        }

    }


    printf("\nThank you for using the MFMS. Goodbye!\n");

    return 0;

}


static void displayWelcome(void)

{

    printf("\n");

    printf("========================================\n");

    printf("   Welcome to the Municipal System\n");

    printf("========================================\n");

}


static void displayMenu(void)

{

    printf("\n========================================\n");

    printf("MUNICIPAL FINANCIAL MANAGEMENT SYSTEM\n");

    printf("========================================\n");

    printf("1. Employee Management\n");

    printf("2. Budget Management\n");

    printf("3. Supplier Management\n");

    printf("4. Asset Management\n");

    printf("5. Reports\n");

    printf("6. Exit\n");

    printf("========================================\n");

}


static int confirmExit(void)

{

    char answer[8];


    getString("Are you sure you want to exit? (y/n): ", answer, sizeof answer);

    return (answer[0] == 'y' || answer[0] == 'Y');

}


static void runEmployeeMenu(void)

{

    int choice;

    int back = 0;


    while (!back) {

        printf("\n--- EMPLOYEE MANAGEMENT ---\n");

        printf("1. Add employee\n");

        printf("2. Display employees\n");

        printf("3. Search employee\n");

        printf("4. Calculate salary\n");

        printf("5. Back to main menu\n");

        choice = getMenuChoice(5);


        switch (choice) {

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

            back = 1;

            break;

        }

    }

}


static void runAssetMenu(void)

{

    int choice;

    int back = 0;


    while (!back) {

        printf("\n--- ASSET MANAGEMENT ---\n");

        printf("1. Add asset\n");

        printf("2. Display assets\n");

        printf("3. Search asset\n");

        printf("4. Back to main menu\n");

        choice = getMenuChoice(4);


        switch (choice) {

        case 1:

            addAssets();

            break;

        case 2:

            displayAssets();

            break;

        case 3:

            searchAssets();

            break;

        case 4:

            back = 1;

            break;

        }

    }

}