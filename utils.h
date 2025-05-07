#ifndef UTILS_H
#define UTILS_H

#include <stdio.h>
#include <stdlib.h>


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

#endif // UTILS_H
