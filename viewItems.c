#include <stdio.h>
#include <stdlib.h>

void viewItems() {
    char itemName[50];
    float itemPrice;
    int index = 0;
    FILE *file = fopen("menu.txt", "r");

    if (!file) {
        printf("Unable to open file.\n");
        return;
    }

    printf("\n===== Current Menu =====\n");
    while (fscanf(file, "%s %f", itemName, &itemPrice) != EOF) {
        printf("%d. %s - $%.2f\n", ++index, itemName, itemPrice);
    }
    
    if (index == 0) {
        printf("Menu is empty.\n");
    }
    
    printf("=====================\n");
    
    fclose(file);
    printf("Press any key to continue...\n");
    getchar(); // Wait for user input
    getchar(); // Clear the newline character from the input buffer
    printf("\n"); // Print a newline for better readability
    printf("=====================\n");
}