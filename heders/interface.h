#ifndef INTERFACE_H
#define INTERFACE_H

typedef enum
{
    OPERATION_RECTANGLE,
    OPERATION_TRAPEZE,
    OPERATION_MONTE_CARLO,
    OPERATION_EXIT
} OPERATIONS;

OPERATIONS get_operation();
void print_menu();

void with_rectangle();
void with_trapeze();
#endif //INTERFACE_H
