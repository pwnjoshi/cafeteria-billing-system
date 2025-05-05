#ifndef PROCESS_NEW_ORDER_H
#define PROCESS_NEW_ORDER_H

void processNewOrder();

typedef struct {
    char name[50];
    float price;
} MenuItem;

typedef struct {
    int menuIndex;
    int quantity;
} OrderItem;

#endif // MANAGE_MENU_H