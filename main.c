#include <stdio.h>
#include <stdlib.h>
#include "auth.h"              // Header file for authentication functions
#include "manageMenu.h"        // Header file for menu management functions
#include "processNewOrder.h"   // Header file for processing new orders
#include "viewOrderHistory.h"  // Header file for viewing order history

int main() {
    int choice;                // Variable to store user menu choice
    int loggedIn = 0;          // Flag to track login status (0 = not logged in, 1 = logged in)

    while (1) {                // Infinite loop to keep the program running
        if (!loggedIn) {       // If the user is not logged in
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
                    signup();  // Call the signup function to register a new user
                    break;
                case 2:
                    loggedIn = login(loggedIn); // Call the login function and update login status
                    break;
                case 3:
                    exit(0);   // Exit the program
                default:
                    printf("Invalid choice!\n"); // Handle invalid input
            }
        } 

        if (loggedIn) {        // If the user is logged in
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
                    manageMenu(); // Call the manageMenu function to handle menu operations
                    break;
                case 2:
                    printf("Processing New Order...\n");
                    processNewOrder(); // Call the processNewOrder function to handle new orders
                    break;
                case 3:
                    printf("Viewing Order History...\n"); 
                    viewOrderHistory(); // Call the viewOrderHistory function to display past orders
                    break;
                case 4:
                    printf("Logging out...\n");
                    loggedIn = 0; // Reset login status to go back to the login menu
                    break;
                case 5:
                    exit(0);   // Exit the program
                default:
                    printf("Invalid choice!\n"); // Handle invalid input
                    printf("Please enter a valid choice.\n");
            }
        }
    }

    return 0; // Return 0 to indicate successful program termination
}
