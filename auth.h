#ifndef AUTH_H
#define AUTH_H

// Define the User struct
struct User {
    char username[50];
    char password[50];
};

// Function declarations
void signup();
int login(int loggedIn);

#endif // AUTH_H