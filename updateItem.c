#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void updateItem()
{
    char currentItem[50];
    float currentPrice;
    int index = 0, choice, found = 0;

    // Open the menu file in read mode
    FILE *file = fopen("menu.txt", "r");
    if (!file)
    {
        printf("Unable to open file.\n");
        return;
    }

    // Display the menu with indices
    printf("Menu:\n");
    while (fscanf(file, "%s %f", currentItem, &currentPrice) != EOF)
    {
        printf("%d. %s - %.2f\n", ++index, currentItem, currentPrice);
    }
    fclose(file);

    if (index == 0)
    {
        printf("Menu is empty.\n");
        return;
    }

    // Ask the user to select an item by index
    printf("Enter the index of the item to update: ");
    scanf("%d", &choice);

    if (choice < 1 || choice > index)
    {
        printf("Invalid choice.\n");
        return;
    }

    // Reopen the menu file to read and create a temporary file
    file = fopen("menu.txt", "r");
    FILE *tempFile = fopen("temp_menu.txt", "w");
    if (!tempFile)
    {
        printf("Unable to create temporary file.\n");
        fclose(file);
        return;
    }

    index = 0;
    char newItemName[50];
    float newPrice;

    // Read each item from the original file and write to the temporary file
    while (fscanf(file, "%s %f", currentItem, &currentPrice) != EOF)
    {
        index++;
        if (index == choice)
        {
            found = 1; // Item found
            printf("Enter new name for %s: ", currentItem);
            scanf("%s", newItemName);
            printf("Enter new price for %s: ", newItemName);
            scanf("%f", &newPrice);
            fprintf(tempFile, "%s %.2f\n", newItemName, newPrice); // Update item
        }
        else
        {
            fprintf(tempFile, "%s %.2f\n", currentItem, currentPrice); // Write unchanged item
        }
    }

    fclose(file);
    fclose(tempFile);

    // Replace the original menu file with the updated one
    remove("menu.txt");                  // Delete the original file
    rename("temp_menu.txt", "menu.txt"); // Rename temp file to original file name

    if (found)
    {
        printf("Item updated successfully!\n");
        printf("Updated Menu:\n");
        file = fopen("menu.txt", "r");
        while (fscanf(file, "%s %f", currentItem, &currentPrice) != EOF)
        {
            printf("%s - %.2f\n", currentItem, currentPrice); // Display updated menu
        }
        fclose(file);

        printf("Enter any key to continue...\n");
        getchar(); // Clear the newline character from the input buffer
        getchar(); // Wait for user input before returning to the main menu
    }
    else
    {
        printf("Item not found in the menu.\n");
        remove("temp_menu.txt"); // Clean up temporary file if item not found

        printf("Enter any key to continue...\n");
        getchar(); // Clear the newline character from the input buffer
        getchar(); // Wait for user input before returning to the main menu

        printf("\n"); // Print a newline for better readability
        printf("=====================\n");
    }
}