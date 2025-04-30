#include <stdio.h>
#include <stdlib.h>

#include "heders/interface.h"

int main() {
    OPERATIONS operation = OPERATION_EXIT;
    while (operation >= OPERATION_RECTANGLE && operation <= OPERATION_EXIT) {
        print_menu();
        operation = get_operation();
        switch (operation) {
            case OPERATION_RECTANGLE:
                printf("OPERATION_RECTANGLE\n");
                with_rectangle();
                break;
            case OPERATION_TRAPEZE:
                printf("OPERATION_TRAPEZE\n");
                with_trapeze();
                break;
            case OPERATION_MONTE_CARLO:
                printf("OPERATION_MONTE_CARLO\n");
                with_monte_carlo();
                break;
            case OPERATION_CHANGE_ACTIVE_FUNCTION:
                printf("OPERATION_CHANGE_ACTIVE_FUNCTION\n");
                change_active_function();
                break;
            case OPERATION_EXIT:
                return EXIT_SUCCESS;
            default:
                printf("Unknown operation choice, try again.\n");
        };
        printf("\n");
    }
    return EXIT_SUCCESS;
}
