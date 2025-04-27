#include <stdio.h>
#include <stdlib.h>
#include "auth.h"
#include "manageMenu.h"
#include "processNewOrder.h"
#include "viewOrderHistory.h"

void displayMainMenu(); // Forward declaration of displayMainMenu function
int main() {
    int choice;
    int loggedIn = 0;

    while (1) {
        if (!loggedIn) {
            // Display initial login/signup menu
            printf("\n===== Cafeteria Billing System =====\n");
            printf("\n--- MENU ---\n");
            printf("1. Sign Up\n");
            printf("2. Login\n");
            printf("3. Exit\n");
            printf("Enter your choice: ");
            scanf("%d", &choice);

            switch (choice) {
                case 1:
                    signup();
                    break;
                case 2:
                    loggedIn = login(loggedIn); // Store the returned value
                    break;
                case 3:
                    exit(0); // Exit the program
                default:
                    printf("Invalid choice!\n");
            }
        } 

        if (loggedIn) {
            // Display main menu after successful login
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

            switch (choice) {
                case 1:
                    printf("Managing Menu...\n");
                    manageMenu(); // Call the manageMenu function from menu.c
                    break;
                case 2:
                    printf("Processing New Order...\n");
                    processNewOrder(); // Call the processNewOrder function from processNewOrder.c
                    break;
                case 3:
                    printf("Viewing Order History...\n"); 
                    viewOrderHistory(); 
                    break;
                case 4:
                    printf("Logging out...\n");
                    loggedIn = 0; // Set loggedIn flag to false to go back to login menu
                    break;
                case 5:
                    exit(0); // Exit the program
                default:
                    printf("Invalid choice!\n");
            }
        }
    }

    return 0;
}
