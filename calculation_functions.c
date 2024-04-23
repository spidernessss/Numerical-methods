#include <stdlib.h>
#include <stdio.h>
//!!!!!!!!!!!!!!!!!!!!!!!!!
//need stdlib.h for abs
// in my task: root - chord method
double root(double(*f)(double), double(*g)(double), int a, int b, double eps1)
{
    // will be seeking root for a function F = f - g
    // this root will be the coordinate of functions f and g collision
    int is_delta_positive = ((f(b) - g(b)) - (f(a) - g(a))) > 0 ? 1 : 0;
    // for chord method we don't need to look at Jensen's inequality
    // if Der_1 * Der_2 > 0 then go from left to right  (a to b)
    // if Der_1 * Der_2 < 0 then go from right to left   (b to a)
    int x0;
    int F_x0;
    int x;
    int root;
    switch(is_delta_positive)
    {
        case 1:
            x0 = a;
            // formula:
            // new_x = x - F(x)(pre_x - x)/(F(pre_x) - F(x))
            F_x0 = a - (((f(a)) - g(a)) * (b - a)) / ((f(b) - g(b)) - (f(a) - g(a)));
            do
            {
                x = F_x0 - ( (f(F_x0) - g(F_x0)) * (x0 - F_x0) ) / ( (f(x0) - g(x0)) -(f(F_x0) - g(F_x0)) );
                x0 = F_x0;
                F_x0 = x;

            } while( abs( (f(x + eps1) - g(x + eps1)) - ((f(x) - g(x))) ) >= eps1);
            // there we have +
            root = x;
            break;
        case 2:
            x0 = b;
            // formula:
            // new_x = x - F(x)(pre_x - x)/(F(pre_x) - F(x))
            F_x0 = b - (((f(b)) - g(b)) * (a - b)) / ((f(a) - g(a)) - (f(b) - g(b)));
            do
            {
                x = F_x0 - ( (f(F_x0) - g(F_x0)) * (x0 - F_x0) ) / ( (f(x0) - g(x0)) -(f(F_x0) - g(F_x0)) );
                x0 = F_x0;
                F_x0 = x;

            } while( abs( (f(x - eps1) - g(x + eps1)) - ((f(x) - g(x))) ) );
            //there we have -
            root = x;
            break;
        default:
            fprintf(stderr, "Error in delta calculation. The values of is_delta_positive: %d\n", is_delta_positive);
    }
     return root;   
}
// Rectangular method
// having fixed number of rectangles where step is width and average is length
double integral(double(*f)(double), int a, int b, double eps2)
{
    int rectangles = 50000;
    double step = (f(b) - f(a)) / rectangles;
    double area = 0;
    double x0 = 0;
    double x1 = step;
    for (int i = 0; i < rectangles - 1; i++)
    {
        area += f((x1 + x0) / 2) * step;
        x0 += step;
        x1 += step; 
    }
    return area;
}
