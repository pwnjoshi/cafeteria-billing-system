#ifndef ADD_ITEM_H
#define ADD_ITEM_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utils.h" 

int addItem();

int addItem() {
    char itemName[50];
    float itemPrice;

    FILE *file = fopen("menu.txt", "a"); // Open the menu file in append mode

    if (!file) {
        printf("Unable to open file.\n");
        return 1; 
    }

    printf("Enter item name: ");
    scanf("%s", itemName);

    printf("Enter item price: ");
    scanf("%f", &itemPrice);

    fprintf(file, "%s %.2f\n", itemName, itemPrice); // Write the new item to the file
    fclose(file);

    printf("Item added successfully!\n\n");
    printf("=====================\n");
    printf("Item Name: %s\n", itemName);
    printf("Item Price: %.2f\n", itemPrice);
    printf("=====================\n\n");
    pauseExecution(); 
    return 0; 
}

#endif // ADD_ITEM_H
