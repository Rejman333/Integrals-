#include "heders/methods.h"

#include <stdio.h>

#define number_of_steps 10000;

double rectangle(double integral_from, double integral_to, double (*p_function)(double)) {
    double step, sum = 0;
    double dx = integral_from;
    double width = integral_to - integral_from;
    step = width / number_of_steps;

    while (dx < integral_to) {
        //printf("f(x): %f, x: %f, step: %f \n",p_function(dx), dx, step);
        sum += p_function(dx);
        dx += step;

    }

    return sum * step;
}

double rectangle_right(double integral_from, double integral_to, double (*p_function)(double)) {
    double step, sum = 0;
    double dx = integral_from;
    double width = integral_to - integral_from;
    step = width / number_of_steps;
    while (dx < integral_to) {
        //printf("f(x): %f, x: %f, step: %f \n",p_function(dx), dx, step);
        dx += step;
        sum += p_function(dx);

    }

    return sum * step;
}

double rectangle_mean(double integral_from, double integral_to, double (*p_function)(double)) {
    double step, sum = 0;
    double dx = integral_from;
    double width = integral_to - integral_from;
    step = width / number_of_steps;
    dx += step/2;
    while (dx < integral_to + step/2) {
        //printf("f(x): %f, x: %f, step: %f \n",p_function(dx), dx, step);
        dx += step;
        sum += p_function(dx);

    }

    return sum * step;
}

double trapeze() {
    return -1;
}

double monte_carlo() {
    return -1;
}


#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#define lp 1000

double c_od,c_do;

double f3(double x)
{
 return -1;
}
double f4(double x) {

 return 1;
}


double prostokaty(double( *f)(double))
{
       double krok, p, suma=0;
       krok=(c_do-c_od)/lp;
       for(p=c_od; p<c_do; p+=krok)
               suma+=(*f)(p)*krok;
       return suma;
}

double trapezy(double (*f)(double))
{
return 1;
}

double mc(double(*f)(double))
{
 return 1;
}