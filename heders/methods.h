#ifndef METHODS_H
#define METHODS_H

double rectangle(double integral_from, double integral_to, double (*p_function)(double));
double trapeze(double integral_from, double integral_to, double (*p_function)(double));
#endif //METHODS_H
