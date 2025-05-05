#include <stdio.h>
#include <stdlib.h>
#include "utils.h"

void clearScreen() {
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif
}

void pauseExecution() {
    printf("\nPress Enter to continue...");
    getchar();
    getchar();
}