#ifndef METHODS_H
#define METHODS_H

double rectangle(double integral_from, double integral_to, double (*p_function)(double));
double rectangle_right(double integral_from, double integral_to, double (*p_function)(double));
double rectangle_mean(double integral_from, double integral_to, double (*p_function)(double));
#endif //METHODS_H
