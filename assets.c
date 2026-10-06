#include <stdio.h>
#include <string.h>

#define MAX_ASSETS 100

char assetID[MAX_ASSETS][20];
char assetName[MAX_ASSETS][50];
char assetType[MAX_ASSETS][20];
char department[MAX_ASSETS][40];
double valueOfPurchase[MAX_ASSETS];
char condition[MAX_ASSETS];
int assetCount = 0;

void searchAssets(void);

static void  readText(const char * prompt, char *dest, int size )
{
    do{
        printf("%s", prompt);
        fgets(dest, size, stdin);
        dest[strcspn(dest, "\n")] = '\0';
        if (strlen(dest) == 0) {
            printf("Input cannot be empty. Please try again.\n");
        }
    }
    while (strlen(dest) == 0);
}

void addAssets(void) {
    char line[50];
    double value;

    if (assetCount >= MAX_ASSETS) {
        printf("Asset register is completely full. Cannot add more assets.\n");
        return;
    }

    readText("Enter Asset ID: ", assetID[assetCount], sizeof(assetID[assetCount]));
    readText("Enter Asset Name: ", assetName[assetCount], sizeof(assetName[assetCount]));
    readText("Enter Asset Type: ", assetType[assetCount], sizeof(assetType[assetCount]));
    readText("Enter Department: ", department[assetCount], sizeof(department[assetCount]));

    do {
        printf("Enter Value of Purchase: ");
        fgets(line, sizeof(line), stdin);
        if (sscanf(line, "%lf", &value) != 1 || value < 0) {
            printf("Invalid input. Please enter a valid non-negative number.\n");
            value = -1;
        }
    } while (value < 0);

    valueOfPurchase[assetCount] = value;

    do {
        printf("Enter Condition (G for Good, F for Fair, P for Poor): ");
        fgets(line, sizeof(line), stdin);
        condition[assetCount] = line[0];

        if (condition[assetCount] != 'G' && condition[assetCount] != 'F' && condition[assetCount] != 'P') {
            printf("Invalid input. Please enter G, F, or P.\n");
            condition[assetCount] = '\0';
        }
    } while (condition[assetCount] == '\0');

    assetCount++;
    printf("Asset added.\n");
}

void displayAssets(void)
{
    if (assetCount == 0) {
        printf("No assets to display.\n");
        return;
    }

    printf("Asset Register:\n");
    printf("------------------------------------------------------------\n");
    printf("| %-10s | %-20s | %-10s | %-15s | %-10s | %-10s |\n", "Asset ID", "Asset Name", "Type", "Department", "Value", "Condition");
    printf("------------------------------------------------------------\n");

    for (int i = 0; i < assetCount; i++) {
        printf("| %-10s | %-20s | %-10s | %-15s | $%-9.2f | %-10c |\n",
               assetID[i], assetName[i], assetType[i], department[i], valueOfPurchase[i], condition[i]);
    }
    printf("------------------------------------------------------------\n");
}

void searchAssets(void)
{
    searchAssets();
}
    
void searchAssets(void) {
    char term[50];
    int found = 0;
    readText("Enter Asset ID or Name to search: ", term, sizeof(term));

    printf("Search Results:\n");
    printf("------------------------------------------------------------\n");
    printf("| %-10s | %-20s | %-10s | %-15s | %-10s | %-10s |\n", "Asset ID", "Asset Name", "Type", "Department", "Value", "Condition");
    printf("------------------------------------------------------------\n");

    for (int i = 0; i < assetCount; i++) {
        if (strstr(assetID[i], term) != NULL || strstr(assetName[i], term) != NULL) {
            printf("| %-10s | %-20s | %-10s | %-15s | $%-9.2f | %-10c |\n",
                   assetID[i], assetName[i], assetType[i], department[i], valueOfPurchase[i], condition[i]);
            found = 1;
        }
    }

    if (!found) {
        printf("No assets found matching the search term.\n");
    }
    printf("------------------------------------------------------------\n");
}
