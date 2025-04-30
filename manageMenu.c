#include <stdio.h>
#include "manageMenu.h"
#include "addItem.h" // Include the addItem function header
#include "updateItem.h" // Added updateItem header
#include "deleteItem.h" // Added deleteItem header
#include "viewItems.h" // Added viewItems header

void manageMenu(){
    int choice;
    printf("\n===== Manage Menu =====\n");
    printf("1. Add Item\n");
    printf("2. Update Item\n");
    printf("3. Delete Item\n");
    printf("4. View Items\n");
    printf("5. Back to Main Menu\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            printf("Adding item...\n"); 
            addItem(); // Call the addItem function from addItem.c
            break;
        case 2:
            printf("Updating item...\n");
            updateItem(); // Call the updateItem function 
            break;
        case 3:
            printf("Deleting item...\n");
            deleteItem(); // Call the deleteItem function
            break;
        case 4:
            printf("Viewing items...\n");
            viewItems(); // Call the viewItems function
            break;
        case 5:
            return; // Go back to main menu
        default:
            printf("Invalid choice!\n");
    }
}