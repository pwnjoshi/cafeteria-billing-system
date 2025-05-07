#ifndef DELETE_ITEM_H
#define DELETE_ITEM_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utils.h" 

char currentItem[50];
float currentPrice;

void deleteItem()
{
    int index = 0, choice, found = 0;

    FILE *file = fopen("menu.txt", "r");
    if (!file)
    {
        printf("Unable to open file.\n");
        return;
    }

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

    printf("Enter the index of the item to delete: ");
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
        if (index != choice)
        {
            fprintf(tempFile, "%s %.2f\n", currentItem, currentPrice); 
        }
        else
        {
            found = 1;
        }
    }

    fclose(file);
    fclose(tempFile);

    remove("menu.txt");                  
    rename("temp_menu.txt", "menu.txt");

    if (found)
    {
        printf("Item deleted successfully!\n");
        printf("Updated Menu:\n");
        // Display the updated menu
        file = fopen("menu.txt", "r");
        if (!file)
        {
            printf("Unable to open file.\n");
            return;
        }
        index = 0;
        while (fscanf(file, "%s %f", currentItem, &currentPrice) != EOF)
        {
            printf("%d. %s - %.2f\n", ++index, currentItem, currentPrice);
        }
        fclose(file);

        printf("=====================\n\n");
        pauseExecution();
    }
    else
    {
        printf("Item not found in the menu.\n");
        remove("temp_menu.txt"); // Clean up temporary file if item not found

        printf("=====================\n\n");
        pauseExecution();
    }
}

#endif // DELETE_ITEM_H
