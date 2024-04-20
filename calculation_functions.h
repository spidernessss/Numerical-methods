#ifndef CALCULATION_FUNCTIONS_H
#define CALCULATION_FUNCTIONS_H
// in my task: root - chord method
double root(double(*f)(double), double(*g)(double), int left_border, int right_border, double eps1);
// in my task integral - rectangular method
double intergal(double(*f)(double), int left_border, int right_border, double eps2);
#endif
