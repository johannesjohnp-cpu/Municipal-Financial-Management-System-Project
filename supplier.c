#include <stdio.h>
#include <string.h>
#include "suppliers.h"


char supplierName[10][100];
char supplierEmail[10][100];
char supplierPhone[10][30];
char supplierTown[10][100];
char supplierID[10][100];
int supplierCount=0;

void SupplierText(char prompt[], char text[], int size)
{
    printf("%s", prompt);
    fgets(text, size, stdin);
    text[strcspn(text, "\n")] = '\0'; 
    
}
  void SupplierRequired(char prompt[], char text[], int size){
   SupplierText(prompt,text,size);
  while(strlen(text) == 0) {
        printf("Input cannot be empty.\n");
        SupplierText(prompt, text, size);
    
}
  }
  int SupplierEmail(char email[]){
    int length = strlen(email);
    int at = -1;
    int dot = -1;
    for (int i = 0; i < length; i++) {
        if (email[i] == '@') {
            at = i;
        } else if (email[i] == '.' && at != -1) {
            dot = i;
        }
    }
    return (at != -1 && dot != -1); 

  }
  int SupplierPhone(char number[]){
    int length = strlen(number);
    for (int i = 0; i < length; i++) {
        if (number[i] < '0' || number[i] > '9') {
            return 0; 
        }
    }
    return (length >= 7);
  }
  int findSupplier(char name[])
  {
      for (int i = 0; i < supplierCount; i++)
      {
          if (strcmp(supplierName[i], name) == 0)
          {
              return i; 
          }
      }
      return -1;  
  }
   void printSupplier(int i){
   char discription[400];
   strcpy(discription, supplierName[i]);
    strcat(discription, "Works in ");
    strcat(discription, supplierTown[i]);
    
    
    printf("Name : %s\n", supplierName[i]);
    printf("Email: %s\n", supplierEmail[i]);
    printf("Phone: %s\n", supplierPhone[i]);
    printf("Town : %s\n", supplierTown[i]);
    printf("%s\n", discription);
}
void addSupplier() {
    char name[100];
    char email[100];
    char phone[30];
    char town[50];

     if (supplierCount == 10) {
        printf("Supplier list is full.\n");
    } else {
        SupplierRequired("Enter supplier name: ", name, sizeof(name));

        if (findSupplier(name) != -1) {
            printf("This supplier already exists.\n");
        } else {
            SupplierText("Enter email: ", email, sizeof(email));
            while (SupplierEmail(email) == 0) {
                printf("Invalid email");
                SupplierText("Enter email: ", email, sizeof(email));
            }

            SupplierText("Enter phone: ", phone, sizeof(phone));
            while (SupplierPhone(phone) == 0) {
                printf("Invalid phone (digits only, at least 7).\n");
                SupplierText("Enter phone: ", phone, sizeof(phone));
            }
            SupplierRequired("Enter town: ", town, sizeof(town));
 strcpy(supplierName[supplierCount], name);
            strcpy(supplierEmail[supplierCount], email);
            strcpy(supplierPhone[supplierCount], phone);
            strcpy(supplierTown[supplierCount], town);
            supplierCount++;
            printf("Supplier added.\n");
        }
    }
}
void displaySupplier() {
    if (supplierCount == 0) {
        printf("No suppliers added yet.\n");
    } else {
        for (int i = 0; i < supplierCount; i++) {
            printf("\nSupplier %d\n", i + 1);
            printSupplier(i);
        }
        printf("\nTotal suppliers: %d\n", supplierCount);
    }
}

void searchSupplier() {
    char searchName[100];
    int position;

    SupplierRequired("Enter supplier name to search: ", searchName, sizeof(searchName));
    position = findSupplier(searchName);

    if (position != -1) {
        printf("Supplier found.\n");
        printSupplier(position);
        printf("Name length: %zu\n", strlen(supplierName[position]));
    } else {
        printf("Supplier not found.\n");
    }
}
int getSupplierCount() {
    return supplierCount;
}

void supplierMenu() {
    char line[10];
    char choice;

    do {
        printf("\n========================================\n");
        printf("          SUPPLIER MANAGEMENT\n");
        printf("========================================\n");
        printf("1. Add Supplier\n");
        printf("2. Display Supplier\n");
        printf("3. Search Supplier\n");
        printf("4. Back to Main Menu\n");
        readSupplierText("\nEnter choice: ", line, sizeof(line));

        choice = 'x';                  
        if (strlen(line) == 1) {
            choice = line[0];
        }

        switch (choice) {
            case '1':
                addSupplier();
                break;
            case '2':
                displaySupplier();
                break;
            case '3':
                searchSupplier();
                break;
            case '4':
                printf("Returning to main menu...\n");
                break;
            default:
                printf("Invalid choice. Enter 1 to 4.\n");
        }
    } while (choice != '4');
} 
 
