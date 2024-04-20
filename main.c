#ifndef STDIO_H
#define STDIO_H
#include <stdio.h>
#endif

#ifndef STDLIB_H
#define STDLIB_H
#include <stdlib.h>
#endif

#ifndef MATH_H
#define MATH_H
#include <math.h>
#endif

#include "input_functions.h"
#include "calculation_functions.h"
#include "test_functions.h"
#include "ascii_art_func.h"
int main(int argc, char* argx[])
{
   // printing ascii_art
    char filename[] = "ascii_art.txt";
    FILE *file;
 
    if ((file = fopen(filename,"r")) == NULL)
    {
        fprintf(stderr,"Error with opening %s\n", filename);
        return 1;
    }
    print_ascii_art(file, 5200);
    fclose(file);
    //


    return 0;
}
