#include "input_functions.h"
#include <stdio.h>
#include "calculation_functions.h"
void print_x_coordinates(void)
{
    printf("Root's x coordinate of functions #1 and #2 is: %f\n", root(function_1, function_2, 0, 2, 0.00001));
    printf("Root's x coordinate of functions #2 and #3 is: %f\n", root(function_2, function_3, 0.3, 0.9, 0.00001));
    printf("Root's x coordinate of functions #1 and #3 is: %f\n", root(function_1, function_3, -4, -2, 0.00001));
}
void print_integral_value(void)
{
    double root1, root2, root3;
    root1 = root(function_1, function_2, 0, 2, 0.00001);
    root2 = root(function_2, function_3, 0.3, 0.9, 0.00001);
    root3 = root(function_1, function_3, -4, -2, 0.00001);
    double area;
    // Formula: f1[root3, root1] - f2[root1, root2] - f3[root2, root1]
    area = integral(function_1, root3, root1, 0.001);
  //  printf("Area1: %f\n", area);
    area -= integral(function_2, root2, root1, 0.001);
  //  printf("Area2: %f\n", area);
    area -= integral(function_3, root3, root1, 0.001);
 //   printf("Area3: %f\n", area);
    printf("The value of area bordered by given three functions is %f.\n", area);
}
void print_coordinates_and_integral(void)
{
    print_x_coordinates();
    print_integral_value();
}
void print_face_border(void)
{
    for (int i = 0; i < 7; i++)
    {
        printf("_______(*___*)_______");
    }
    printf("\n");
}
void print_usual_border(void)
{
    for (int i = 0; i < 7; i++)
    {
        printf("*********************");
    }
    printf("\n");  
}
void print_instructions_info(void)
{
    print_usual_border();
    for (int i = 0; i < 3; i++)
    {
        printf("----------------");
    }
    printf("Set of instructions");
    for (int i = 0; i < 5; i++)
    {
        printf("----------------");
    }
    printf("\n");
    printf("-help   Prints this text\n");
    printf("-r      Calculates roots for 3 given functions and prints the results\n");
    printf("-i      Calculates the integral and prints the result\n");
    printf("-ri     Calculates integral and prints roots needed to calculate it and the integral\n");
}
