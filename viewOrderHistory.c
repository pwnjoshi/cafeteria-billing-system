#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void viewOrderHistory() {
    FILE *file = fopen("order_history.txt", "r");
    if (file == NULL) {
        printf("No order history found.\n");
        return;
    }

    char line[256];
    printf("\n--- Order History ---\n");
    while (fgets(line, sizeof(line), file)) {
        printf("%s", line);
    }
    fclose(file);
}
    