#include <math.h>
#include "heders/functions.h"

// -3.13*x^3 + 14.5*x^2 - 6*x +7
double function_1(double x) {
    return -3.13 * x * x * x + 14.5 * x * x - 6 * x + 7;
}

// cos(2(x^2) / 2*sin(8*x^2) - 3cos(5 + x) + 1)
double function_2(double x) {
    return cos(2 * x * x) / 2 * sin(8 * x * x) - 3 * cos(5 + x) + 1;
}

double function_3(double x) {
    return -1;
}

double function_4(double x) {
    return -1;
}