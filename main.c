#include <stdio.h>
#include <stdlib.h>
#include "auth.h"          
#include "manageMenu.h"      
#include "processNewOrder.h"  
#include "viewOrderHistory.h" 
#include "utils.h"
int main()
{
    int choice;       
    int loggedIn = 0; 

    while (1)
    { 
        if (!loggedIn)
        { // If the user is not logged in
            // Display initial login/signup menu
            clearScreen(); // Clear the screen for better visibility
            printf("\n===== Cafeteria Billing System =====\n");
            printf("\n--- MENU ---\n");
            printf("1. Sign Up\n");
            printf("2. Login\n");
            printf("3. Exit\n");
            printf("Enter your choice: ");
            scanf("%d", &choice);

            switch (choice)
            {
            case 1:
             clearScreen(); 
                signup(); // Call the signup function to register a new user
                break;
            case 2:
             clearScreen();
                loggedIn = login(loggedIn); // Call the login function and update login status
                break;
            case 3:
                exit(0); // Exit the program
            default:
             clearScreen();
                printf("Invalid choice!\n"); // Handle invalid input
                printf("Please enter a valid choice.\n");
               pauseExecution(); // Pause execution to allow the user to read the message
            }
        }

        else
        { // If the user is logged in
            // Display mvoid clearScreen()ain menu after successful login
            void clearScreen(); // Clear the screen for better visibility
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
                manageMenu(); // Call the manageMenu function to handle menu operations
                break;
            case 2:
            clearScreen();
                printf("Processing New Order...\n");
                processNewOrder(); // Call the processNewOrder function to handle new orders
                break;
            case 3:
            clearScreen();
                printf("Viewing Order History...\n");
                viewOrderHistory(); // Call the viewOrderHistory function to display past orders
                break;
            case 4:
            clearScreen();
                printf("Logging out...\n");
                loggedIn = 0; // Reset login status to go back to the login menu
                break;
            case 5:
                exit(0); // Exit the program
            default:
            clearScreen();
                printf("Invalid choice!\n"); // Handle invalid input
                printf("Please enter a valid choice.\n");
                pauseExecution(); // Pause execution to allow the user to read the message
            }
        }
    }

    return 0; // Return 0 to indicate successful program termination
}
