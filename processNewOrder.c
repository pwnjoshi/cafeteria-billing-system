#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef struct {
    char name[50];
    float price;
} MenuItem;

typedef struct {
    int menuIndex;
    int quantity;
} OrderItem;

void processNewOrder() {
    MenuItem menu[100];
    int menuCount = 0;
    OrderItem orders[100];
    int orderCount = 0;
    float totalPrice = 0.0;
    char customerName[100];
    time_t orderTime;
    struct tm *timeinfo;
    char timeString[50];

    // Get customer name
    printf("Enter customer name: ");
    scanf("%s", customerName);
    getchar(); // Clear the newline character

    // Get current time
    time(&orderTime);
    timeinfo = localtime(&orderTime);
    strftime(timeString, sizeof(timeString), "%Y-%m-%d %H:%M:%S", timeinfo);

    FILE *file = fopen("menu.txt", "r"); // Open the menu file in read mode

    if (!file) {
        printf("Unable to open file.\n");
        return;
    }

    // Read menu items into the array
    while (fscanf(file, "%s %f", menu[menuCount].name, &menu[menuCount].price) != EOF) {
        menuCount++;
    }
    fclose(file);

    // Display the menu
    printf("Menu:\n");
    for (int i = 0; i < menuCount; i++) {
        printf("%d. %s - $%.2f\n", i + 1, menu[i].name, menu[i].price);
    }

    while (1) {
        int choice, quantity;
        printf("Enter the number of the item you want to order: ");
        scanf("%d", &choice);

        if (choice < 1 || choice > menuCount) {
            printf("Invalid choice.\n");
            continue;
        }

        printf("Enter quantity: ");
        scanf("%d", &quantity);

        if (quantity <= 0 || quantity > 100) {
            printf("Invalid quantity.\n");
            continue;
        }

        // Add the item to the order list
        orders[orderCount].menuIndex = choice - 1;
        orders[orderCount].quantity = quantity;
        orderCount++;

        // Calculate the price for this item
        totalPrice += menu[choice - 1].price * quantity;

        printf("Do you want to add more items? (1 for Yes, 0 for No): ");
        int addMore;
        scanf("%d", &addMore);
        if (addMore != 1) {
            break;
        }
    }

    // Apply discount
    printf("Apply Discount? (1 for Yes, 0 for No): ");
    int applyDiscount;
    float discountAmount = 0.0;
    float discountPercentage = 0.0;

    scanf("%d", &applyDiscount);
    if (applyDiscount == 1) {
        printf("Enter discount percentage: ");
        scanf("%f", &discountPercentage);
        if (discountPercentage < 0 || discountPercentage > 100) {
            printf("Invalid discount percentage.\n");
            return;
        }
        discountAmount = totalPrice * (discountPercentage / 100);
        printf("Discount applied: $%.2f\n\n", discountAmount);
    } else {
        printf("No discount applied.\n\n");
    }

    float originalPrice = totalPrice;
    totalPrice = totalPrice - discountAmount;

    // Save the order to an order history file
    FILE *orderFile = fopen("order_history.txt", "a");
    if (!orderFile) {
        printf("Unable to open order history file.\n");
        return;
    }

    // Write detailed order information to the history file
    fprintf(orderFile, "======================================\n");
    fprintf(orderFile, "ORDER DETAILS\n");
    fprintf(orderFile, "======================================\n");
    fprintf(orderFile, "Customer: %s\n", customerName);
    fprintf(orderFile, "Date/Time: %s\n", timeString);
    fprintf(orderFile, "--------------------------------------\n");
    fprintf(orderFile, "ITEMS ORDERED:\n");
    
    for (int i = 0; i < orderCount; i++) {
        fprintf(orderFile, "  %s x%d - $%.2f\n",
                menu[orders[i].menuIndex].name,
                orders[i].quantity,
                menu[orders[i].menuIndex].price * orders[i].quantity);
    }
    
    fprintf(orderFile, "--------------------------------------\n");
    fprintf(orderFile, "Total Items: %d\n", orderCount);
    fprintf(orderFile, "Subtotal: $%.2f\n", originalPrice);
    
    if (applyDiscount == 1) {
        fprintf(orderFile, "Discount: %.1f%% ($%.2f)\n", discountPercentage, discountAmount);
    } else {
        fprintf(orderFile, "Discount: None\n");
    }
    
    fprintf(orderFile, "TOTAL AMOUNT: $%.2f\n", totalPrice);
    fprintf(orderFile, "======================================\n\n");
    
    fclose(orderFile);

    // Display the order summary to the customer
    printf("\n======== ORDER SUMMARY ========\n");
    printf("Customer: %s\n", customerName);
    printf("Date/Time: %s\n\n", timeString);
    
    printf("Ordered Items:\n");
    for (int i = 0; i < orderCount; i++) {
        printf("%s x%d - $%.2f\n",
               menu[orders[i].menuIndex].name,
               orders[i].quantity,
               menu[orders[i].menuIndex].price * orders[i].quantity);
    }
    
    printf("\nSubtotal: $%.2f\n", originalPrice);
    if (applyDiscount == 1) {
        printf("Discount: %.1f%% ($%.2f)\n", discountPercentage, discountAmount);
    }
    printf("Total price: $%.2f\n", totalPrice);
    printf("==============================\n");
    
    printf("Thank you for your order, %s!\n", customerName);
    printf("Press any key to continue...\n");
    getchar(); // Wait for user input before returning to the main menu
    getchar(); // Clear the newline character from the input buffer
    printf("\n"); // Print a newline for better readability
}