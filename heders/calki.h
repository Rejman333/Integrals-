//
// Created by jansw on 21.03.2025.
//

#pragma once
extern double c_od, c_do;

double f3(double x);
double f4(double x);
double prostokaty(double(*f)(double));
double trapezy(double (*f)(double));
double mc(double(*f)(double));

