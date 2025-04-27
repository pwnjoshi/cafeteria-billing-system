#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int addItem() {
    char itemName[50];
    float itemPrice;
    FILE *file = fopen("menu.txt", "a"); // Open the menu file in append mode

    if (!file) {
        printf("Unable to open file.\n");
        return 1; // Return an error code
    }

    printf("Enter item name: ");
    scanf("%s", itemName);

    printf("Enter item price: ");
    scanf("%f", &itemPrice);

    fprintf(file, "%s %.2f\n", itemName, itemPrice); // Write the new item to the file
    fclose(file);

    printf("Item added successfully!\n");
    return 0; // Return success code
}