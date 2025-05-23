#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utils.h"

struct User {
    char username[50];
    char password[50];
};

void signup();
int login(int loggedIn);

void signup() {
    printf("Enter Password to add new user: ");
    char password[50];
    scanf("%s", password);
    if (strcmp(password, "admin") != 0) {
        printf("Incorrect password. Access denied.\n");
        pauseExecution();
        return;
    }

    struct User newUser;
    FILE *file = fopen("users.txt", "a");

    if (!file) {
        printf("Unable to open file.\n");
        return;
    }
    
    printf("===== Sign Up =====\n");
    printf("Enter new username: ");
    scanf("%s", newUser.username);

    printf("Enter new password: ");
    scanf("%s", newUser.password);

    fprintf(file, "%s %s\n", newUser.username, newUser.password);
    fclose(file);

    printf("Sign up successful!\n");
    printf("You can now log in with your new credentials.\n");
    pauseExecution(); 
}

int login(int loggedIn) {
    struct User inputUser, fileUser;
    

    FILE *file = fopen("users.txt", "r");
    if (!file) {
        printf("Unable to open file.\n");
        return 0;
    }
    clearScreen();
    printf("===== Login =====\n");
    printf("Enter username: ");
    scanf("%s", inputUser.username);

    printf("Enter password: ");
    scanf("%s", inputUser.password);

    while (fscanf(file, "%s %s", fileUser.username, fileUser.password) != EOF) {
        if (strcmp(inputUser.username, fileUser.username) == 0 &&
            strcmp(inputUser.password, fileUser.password) == 0) {
            loggedIn = 1;
            break;
        }
    }

    fclose(file);

    if (loggedIn) {
        printf("Login successful!\n");
        printf("Welcome, %s!\n", inputUser.username);
        pauseExecution(); 
    } else {
        printf("Invalid username or password.\n");
        printf("Please try again.\n");
        pauseExecution();
    }
    return loggedIn;
}
