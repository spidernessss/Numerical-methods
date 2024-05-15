#ifndef CALCULATION_FUNCTIONS_H
#define CALCULATION_FUNCTIONS_H
// in my task: root - chord method
double root(double(*f)(double), double(*g)(double), double left_border, double right_border, double eps1, int* iterations);
// in my task integral - rectangular method
double integral(double(*f)(double), double left_border, double right_border, double eps2);
#endif
