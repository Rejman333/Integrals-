#include <stdio.h>
#include "heders/interface.h"
#include "heders//utils.h"
#include "heders//functions.h"
#include "heders/methods.h"

double integral_from = 1;
double integral_to = 10;

double (*active_function)(double, double) = function_1;

int active_function_index = 0;

static char *menu_options[] =
{
    "1 - RECTANGLE", //OPERATION_RECTANGLE
    "2 - TRAPEZE", //OPERATION_TRAPEZE
    "3 - MONTE_CARLO", //OPERATION_MONTE_CARLO
    "4 - CHANGE_ACTIVE_FUNCTION", //OPERATION_CHANGE_ACTIVE_FUNCTION
    "5 - EXIT", //OPERATION_EXIT
};

static char *function_options[] =
{
    "1 - -3.13*x^3 + 14.5*x^2 - 6*x +7",
    "2 - cos(2(x^2)) / 2 * sin(8*x^2) - 3cos(5 + x) + 1",
    "3 - (x/pi) * (sin(x)^2 + cos(x))",
    "4 - ((x^3 -3) / 4) -x^2 + x*sin(4x)",
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

FUNCTIONS get_function() {
    int function = -1;

    while (function < 0) {
        printf("Select function: ");
        if (scanf_s("%d", &function) != 1) {
            clear_std();
            function = -1;
            printf("Incorrect value, try again!\n");
        }
    }
    printf("\n");
    return --function;
}


void print_menu() {
    printf("Active Function: %s\n", function_options[active_function_index]);
    for (int i = 0; i <= OPERATION_EXIT; i++) {
        printf("%s\n", menu_options[i]);
    }
    printf("\n");
}

void print_functions() {
    for (int i = 0; i <= FUNCTION_4; i++) {
        printf("%s\n", function_options[i]);
    }
    printf("\n");
}

void change_active_function() {
    FUNCTIONS function = FUNCTION_1;
    while (1) {
        print_functions();
        function = get_function();
        switch (function) {
            case FUNCTION_1:
                active_function = function_1;
                active_function_index = 0;
                return;
            case FUNCTION_2:
                active_function = function_2;
                active_function_index = 1;
                return;
            case FUNCTION_3:
                active_function = function_3;
                active_function_index = 2;
                return;
            case FUNCTION_4:
                active_function = function_4;
                active_function_index = 3;
                return;
            default:
                printf("Unknown function choice, try again.\n");
        }
    }
}

void with_rectangle() {
    double sum = rectangle(integral_from, integral_to, *active_function);
    printf("Integral from: %f, to: %f is : %f\n", integral_from, integral_to, sum);
}

void with_trapeze() {
    double sum = trapeze(integral_from, integral_to, *active_function);
    printf("Integral from: %f, to: %f is : %f\n", integral_from, integral_to, sum);
}

void with_monte_carlo() {
    double sum = monte_carlo(integral_from, integral_to, *active_function);
    printf("Integral from: %f, to: %f is : %f\n", integral_from, integral_to, sum);
}
