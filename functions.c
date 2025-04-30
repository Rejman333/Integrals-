#include <math.h>
#include "heders/functions.h"

double PI = acos(-1.0);

// -3.13*x^3 + 14.5*x^2 - 6*x +7
double function_1(double x) {
    return -3.13 * x * x * x + 14.5 * x * x - 6 * x + 7;
}

// cos(2(x^2)) / 2 * sin(8*x^2) - 3cos(5 + x) + 1
double function_2(double x) {
    return cos(2 * x * x) / 2 * sin(8 * x * x) - 3 * cos(5 + x) + 1;
}

// (x/pi) * (sin(x)^2 + cos(x))
double function_3(double x) {
    return x * (sin(x) * sin(x) + cos(x)) / PI;
}

// ((x^3 -3) / 4) -x^2 + x*sin(4x)
double function_4(double x) {
    return ((x*x*x-3) / 4) - x*x + x * sin(4*x);
}
