#include "heders/methods.h"

#include <stdio.h>

#define number_of_steps 1000000;


double rectangle_left(double integral_from, double integral_to, double (*p_function)(double)) {
    double step, sum = 0;
    double dx = integral_from;
    double width = integral_to - integral_from;
    step = width / number_of_steps;

    for(int i = 0; i < number_of_steps ++i) {
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

    for (int i = 0; i < number_of_steps i++) {
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

    for (int i = 0; i < number_of_steps ++i) {
        //printf("f(x): %f, x: %f, step: %f \n",p_function(dx), dx, step);
        dx += step;
        sum += p_function(dx);
    }
    return sum * step;
}

double rectangle(double integral_from, double integral_to, double (*p_function)(double)) {
    double sum = 0;

    sum = rectangle_left(integral_from, integral_to, p_function);
    printf("(rectangle_left) Integral from: %f, to: %f is : %f\n", integral_from, integral_to, sum);

    sum = rectangle_right(integral_from, integral_to, p_function);
    printf("(rectangle_right) Integral from: %f, to: %f is : %f\n", integral_from, integral_to, sum);

    sum = rectangle_mean(integral_from, integral_to, p_function);
    printf("(rectangle_mean) Integral from: %f, to: %f is : %f\n", integral_from, integral_to, sum);

    return 0;
}

double trapeze(double integral_from, double integral_to, double (*p_function)(double)) {
    double step, sum = 0;
    double dx = integral_from;
    double width = integral_to - integral_from;
    step = width / number_of_steps;

    sum += p_function(dx)/2;


    for (int i = 1; i < -1 + number_of_steps i++) {
        //printf("f(x): %f, x: %f, step: %f \n",p_function(dx), dx, step);
        dx += step;
        sum += p_function(dx);
    }

    dx += step;
    sum += p_function(dx)/2;

    return sum * step;
}

double monte_carlo(double integral_from, double integral_to, double (*p_function)(double)) {
    return -1;
}