#include "heders/methods.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define number_of_steps 10000


double rectangle_left(double integral_from, double integral_to, double (*p_function)(double)) {
    double step, sum = 0;
    double dx = integral_from;
    double width = integral_to - integral_from;
    step = width / number_of_steps;

    time_t start = clock();
    for (int i = 0; i < number_of_steps; ++i) {
        sum += p_function(dx);
        dx += step;
    }
    time_t end = clock();
    double time_taken = (double)(end - start);

    printf("Function completed in: %.4f clock ticks\n", time_taken);
    return sum * step;
}

double rectangle_right(double integral_from, double integral_to, double (*p_function)(double)) {
    double step, sum = 0;
    double dx = integral_from;
    double width = integral_to - integral_from;
    step = width / number_of_steps;

    time_t start = clock();
    for (int i = 0; i < number_of_steps; i++) {
        //printf("f(x): %f, x: %f, step: %f \n",p_function(dx), dx, step);
        dx += step;
        sum += p_function(dx);
    }

    time_t end = clock();
    double time_taken = (double)(end - start);

    printf("Function completed in: %.4f clock ticks\n", time_taken);

    return sum * step;
}

double rectangle_mean(double integral_from, double integral_to, double (*p_function)(double)) {
    double step, sum = 0;
    double dx = integral_from;
    double width = integral_to - integral_from;
    step = width / number_of_steps;
    dx += step / 2;

    time_t start = clock();
    for (int i = 0; i < number_of_steps; ++i) {
        //printf("f(x): %f, x: %f, step: %f \n",p_function(dx), dx, step);
        dx += step;
        sum += p_function(dx);
    }

    time_t end = clock();
    double time_taken = (double)(end - start);

    printf("Function completed in: %.4f clock ticks\n", time_taken);
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

    sum += p_function(dx) / 2;

    time_t start = clock();
    for (int i = 1; i < -1 + number_of_steps; i++) {
        //printf("f(x): %f, x: %f, step: %f \n",p_function(dx), dx, step);
        dx += step;
        sum += p_function(dx);
    }

    dx += step;
    sum += p_function(dx) / 2;

    time_t end = clock();
    double time_taken = (double)(end - start);

    printf("Function completed in: %.4f clock ticks\n", time_taken);

    return sum * step;
}

void find_min_max(double range_from, double range_to, double (*p_function)(double), double *p_min_value,
                  double *p_max_value) {
    *p_min_value = INFINITY;
    *p_max_value = -INFINITY;
    double step = 0;
    double dx = range_from;
    double width = range_to - range_from;
    step = width / number_of_steps;

    double function_value = 0;
    for (int i = 0; i < number_of_steps; ++i) {
        function_value = p_function(dx);
        if (function_value > *p_max_value) {
            *p_max_value = function_value;
        } else if (function_value < *p_min_value) {
            *p_min_value = function_value;
        }
        dx += step;
    }
}

double rand_from(double min, double max) {
    double range = (max - min);
    double div = RAND_MAX / range;
    return min + (rand() / div);
}


double monte_carlo(double integral_from, double integral_to, double (*p_function)(double)) {
    double min_value = 0;
    double max_value = 0;

    find_min_max(integral_from, integral_to, p_function, &min_value, &max_value);
    if(min_value == INFINITY) min_value = 0;
    if(max_value == -0) max_value = 0;

    printf("Min: %f Max: %f\n", min_value, max_value);

    int number_of_points = number_of_steps;
    int points_under_function = 0;

    time_t start = clock();
    for (int i = 0; i < number_of_points; i++) {
        double x = rand_from(integral_from, integral_to);
        double y = rand_from(min_value, max_value);

        double function_y = p_function(x);

        if (y < function_y && y > 0) {
            points_under_function++;
        } else if(y > function_y && y < 0) {
            points_under_function--;
        }
    }

    double ratio = (double)points_under_function / number_of_points;
    double rectangle_area = (integral_to - integral_from) * (max_value - min_value);

    time_t end = clock();
    double time_taken = (double)(end - start);

    printf("Function completed in: %.4f clock ticks\n", time_taken);

    return rectangle_area * ratio;
}
