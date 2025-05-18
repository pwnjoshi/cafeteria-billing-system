#include <stdio.h>
#include <stdlib.h>
#include "auth.h"          
#include "manageMenu.h"      
#include "processNewOrder.h"  
#include "viewOrderHistory.h" 
#include "addItem.h"
#include "deleteItem.h"
#include "updateItem.h"
#include "viewItems.h"
#include "utils.h"

int main()
{
    int choice;       
    int loggedIn = 0; 

    while (1)
    { 
        if (!loggedIn)
        { 
            clearScreen(); 
            printf("\n===== Cafeteria Billing System =====\n\n");
            printf("1. Sign Up\n");
            printf("2. Login\n");
            printf("3. Exit\n");
            printf("Enter your choice: ");
            scanf("%d", &choice);

            switch (choice)
            {
            case 1:
             clearScreen(); 
                signup();
                break;
            case 2:
             clearScreen();
                loggedIn = login(loggedIn); 
                break;
            case 3:
                exit(0);
            default:
             clearScreen();
                printf("Invalid choice!\n"); 
                printf("Please enter a valid choice.\n");
               pauseExecution();
            }
        }

        else
        { 
            clearScreen();
            printf("\n===== Cafeteria Billing System =====\n");
            printf("\n--- MAIN MENU ---\n");
            printf("1. Manage Menu\n");
            printf("2. Process New Order\n");
            printf("3. View Order History\n");
            printf("4. Logout\n");
            printf("5. Exit\n");
            printf("====================================\n");
            printf("Enter your choice: ");
            scanf("%d", &choice);

            switch (choice)
            {
            case 1:
            clearScreen();
                printf("Managing Menu...\n");
                manageMenu(); 
                break;
            case 2:
            clearScreen();
                printf("Processing New Order...\n");
                processNewOrder(); 
                break;
            case 3:
            clearScreen();
                printf("Viewing Order History...\n");
                viewOrderHistory(); 
                break;
            case 4:
            clearScreen();
                printf("Logging out...\n");
                loggedIn = 0;
                break;
            case 5:
                exit(0); 
            default:
            clearScreen();
                printf("Invalid choice!\n"); 
                printf("Please enter a valid choice.\n");
                pauseExecution(); 
            }
        }
    }

    return 0; 
}
