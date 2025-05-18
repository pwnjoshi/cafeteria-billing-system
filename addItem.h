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

    FILE *file = fopen("menu.txt", "a"); 
    
    if (!file) {
        printf("Unable to open file.\n");
        return 1; 
    }

    printf("Enter item name: ");
    scanf("%s", itemName);

    printf("Enter item price (in Rs.): ");
    scanf("%f", &itemPrice);

    fprintf(file, "%s %.2f\n", itemName, itemPrice); 
    fclose(file);

    printf("Item added successfully!\n\n");
    printf("=====================\n");
    printf("Item Name: %s\n", itemName);
    printf("Item Price: Rs.%.2f\n", itemPrice);
    printf("=====================\n\n");

    pauseExecution(); 
    return 0; 
}

#endif 
