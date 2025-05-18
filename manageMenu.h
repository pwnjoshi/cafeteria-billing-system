#ifndef MANAGE_MENU_H
#define MANAGE_MENU_H

#include <stdio.h>
#include "addItem.h" 
#include "updateItem.h" 
#include "deleteItem.h"
#include "viewItems.h" 
#include "utils.h"

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
            clearScreen(); 
            printf("\n===== Add Item =====\n");
            addItem();
            break;
        case 2:
            clearScreen();
            printf("\n===== Update Item =====\n");
            updateItem(); 
            break;
        case 3:
            clearScreen();
            printf("\n===== Delete Item =====\n");
            deleteItem(); 
            break;
        case 4:
            clearScreen();
            printf("\n===== View Items =====\n");
            viewItems(); 
            break;
        case 5:
            return; 
        default:
            printf("Invalid choice!\n");
            printf("Please enter a valid choice.\n");
            pauseExecution(); 
    }
}

#endif 
