#ifndef MATH_H
#define MATH_H
#include <math.h>
#endif

#ifndef INPUT_FUNCTIONS_C
#define INPUT_FUNCTIONS_C
double function_1(double x)
{
    return pow(2, x) + 1;
}
/*
double function_1_der(double x)
{
    return pow(2, x)*log10(2)
}
*/
double function_2(double x)
{
    return pow(x, 5);
}
/*
double function_2_der(double x)
{
    return 5 * pow(x, 4)
}
*/
double function_3(double x)
{
    return (1 - x) / 3;
}
/*
double function_3_der(double x)
{
    return -1/3;
}
*/
#endif
