#include <stdio.h>
#include "heders/interface.h"
#include "heders//utils.h"
#include "heders//functions.h"
#include "heders/methods.h"

double integral_from = 0;
double integral_to = 10;

static char* menu_options[] =
{
    "1 - RECTANGLE",			//OPERATION_RECTANGLE
    "2 - TRAPEZE",              //OPERATION_TRAPEZE
    "3 - MONTE_CARLO",			//OPERATION_MONTE_CARLO
    "4 - EXIT",                 //OPERATION_EXIT
};

OPERATIONS get_operation() {
    int operation = -1;

    while (operation < 0) {
        printf("Select operation: ");
        if (scanf_s("%d", &operation) != 1) {
            clear_std();
            operation = -1;
            printf("Incorrect value, try again!\n");
        }
    }
    printf("\n");
    return --operation;
}

void print_menu() {
    for (int i = 0; i <= OPERATION_EXIT; i++) {
        printf("%s\n", menu_options[i]);
    }
    printf("\n");
}

void with_rectangle() {
    double sum = rectangle_mean(integral_from, integral_to, function_1);
    printf("Integral from: %f, to: %f is : %f\n", integral_from, integral_to, sum);
}