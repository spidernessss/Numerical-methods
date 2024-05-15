#include <stdlib.h>
#include <stdio.h>
#include <math.h>
//!!!!!!!!!!!!!!!!!!!!!!!!!
//need stdlib.h for abs
// in my task: root - chord method
double root(double(*f)(double), double(*g)(double), double a, double b, double eps1, int* iterations)
{
    // will be seeking root for a function F = f - g
    // this root will be the coordinate of functions f and g collision
    int is_delta_positive = ((f(b) - g(b)) - (f(a) - g(a))) > 0 ? 1 : -1;
    // Need to look at Jensen's inequality
    // if Der_1 * Der_2 > 0 then go from left to right  (a to b)
    // if Der_1 * Der_2 < 0 then go from right to left   (b to a)
    double value_at_mid = f((a + b) / 2) - g((a + b) / 2);
    double mid_value = ( (f(a) - g(a)) + (f(b) - g(b)) ) / 2;
    int convexity = mid_value > value_at_mid ? 1 : -1;
    
    int function_type = convexity * is_delta_positive;
    
    double x0;
    double x_mov;
    double root;
    switch (function_type)
    {
        case -1:
            x0 = a;
            // getting closer from right to left (a is fixed)
            x_mov = b;
            do
            {
                x_mov = x_mov - ((f(x_mov) - g(x_mov)) * (x0 - x_mov) ) / ( (f(x0) - g(x0)) - (f(x_mov) - g(x_mov)));
                (*iterations)++;
            } while((f(x_mov) - g(x_mov)) * (f(x_mov - eps1) - g(x_mov - eps1)) >= eps1);
            root = x_mov;
            break;
        case 1:
            x0 = b;
            // getting closer from left to right (b is fixed)
            x_mov = a;   // moving coordinate
            do
            {
                x_mov = x0 - ( (f(x0) - g(x0)) * (x_mov - x0) / ((f(x_mov) - g(x_mov)) - (f(x0) - g(x0))) );
                (*iterations)++;
            } while((f(x_mov) - g(x_mov)) * (f(x_mov + eps1) - g(x_mov + eps1)) >= eps1);
            root = x_mov;
            break;
        default:
            fprintf(stderr, "Error in calculation. The values of convexity: %d\n", convexity);
    }
    return root;   
}
// Rectangular method
// having fixed number of rectangles where step is width and average is length
double integral(double(*f)(double), double a, double b, double eps2)
{
    // 24.0 is a constant in estimation
    // 5 is the max value of all function in current interval
    double step = cbrt(eps2) / (24.0 * 5);
    double rectangles = (b - a) / step;
    double area = 0;
    double f_prev = f(a);
    for (int i = 0; i < rectangles - 1; i++)
    {
        double f_next = f(a + (i+1)*step);
        area += ((f_prev + f_next) / 2) * step;
        f_prev = f_next;
    }
    return area;
}


