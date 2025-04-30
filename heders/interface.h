#ifndef INTERFACE_H
#define INTERFACE_H

typedef enum
{
    OPERATION_RECTANGLE,
    OPERATION_TRAPEZE,
    OPERATION_MONTE_CARLO,
    OPERATION_CHANGE_ACTIVE_FUNCTION,
    OPERATION_EXIT
} OPERATIONS;

typedef enum {
    FUNCTION_1,
    FUNCTION_2,
    FUNCTION_3,
    FUNCTION_4
} FUNCTIONS;

OPERATIONS get_operation();
void print_menu();

void with_rectangle();
void with_trapeze();
void with_monte_carlo();

void change_active_function();
#endif //INTERFACE_H
