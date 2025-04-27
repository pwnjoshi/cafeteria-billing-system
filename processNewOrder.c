#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char name[50];
    float price;
} MenuItem;

void processNewOrder() {
    MenuItem menu[100];
    int menuCount = 0;
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

    int choice, quantity;
    printf("Enter the number of the item you want to order: ");
    scanf("%d", &choice);

    if (choice < 1 || choice > menuCount) {
        printf("Invalid choice.\n");
        return;
    }

    printf("Enter quantity: ");
    scanf("%d", &quantity);

    float totalPrice = menu[choice - 1].price * quantity;
    printf("Total price for %d %s(s): $%.2f\n", quantity, menu[choice - 1].name, totalPrice);

    // Save the order to an order history file
    FILE *orderFile = fopen("order_history.txt", "a"); // Open the file in append mode
    if (!orderFile) {
        printf("Unable to open order history file.\n");
        return;
    }
    fprintf(orderFile, "Item: %s, Quantity: %d, Total Price: $%.2f\n", menu[choice - 1].name, quantity, totalPrice);
    fclose(orderFile);

    printf("Order saved to order history.\n");
}