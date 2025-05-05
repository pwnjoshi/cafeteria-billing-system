#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "updateItem.h"
#include "utils.h"

void updateItem()
{
    int index = 0, choice = 0, found = 0;
    FILE *file = fopen("menu.txt", "r"); // Open the menu file in read mode
    if (!file)
    {
        printf("Unable to open file.\n");
        return;
    }

    clearScreen();
    printf("\n===== Update Item =====\n");

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

    printf("Enter the index of the item to update: ");
    scanf("%d", &choice);

    if (choice < 1 || choice > index)
    {
        printf("Invalid choice.\n");
        return;
    }

    file = fopen("menu.txt", "r"); 
    FILE *tempFile = fopen("temp_menu.txt", "w");
    if (!tempFile)
    {
        printf("Unable to create temporary file.\n");
        fclose(file);
        return;
    }

    index = 0;
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
        clearScreen();
        printf("Item updated successfully!\n\n");
        printf("Updated Menu:\n");
        printf("=====================\n");
        file = fopen("menu.txt", "r");
        while (fscanf(file, "%s %f", currentItem, &currentPrice) != EOF)
        {
            printf("%s - %.2f\n", currentItem, currentPrice); // Display updated menu
        }
        printf("\n=====================\n\n");
        fclose(file);

        printf("Do you want to update another item? (y/n): ");
        char anotherChoice;
        scanf(" %c", &anotherChoice); // Space before %c to consume newline character
        if (anotherChoice == 'y' || anotherChoice == 'Y')
        {
            updateItem(); // Call updateItem again for another update
        }
        else
        {
        pauseExecution(); 
        }
       
    }
    else
    {
        printf("Item not found in the menu.\n\n");
        remove("temp_menu.txt"); // Clean up temporary file if item not found
        pauseExecution(); 
    }
}