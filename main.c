#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

#include "print_functions.h"
#include "input_functions.h"
#include "calculation_functions.h"
#include "test_functions.h"
#include "ascii_art_func.h"
int main(int argc, char* argv[])
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
    printf("\n");
    fclose(file);

    // main arguments interpretation
    char* command_flags[] = {"-help", "-roots", "-square", "-ri", "-iters", "-test-root", "-test-integral"};
    int command_number = 1;
    int flag_index = 0;
    if (argc == 1)
    {
        print_integral_value();
    }
    while (command_number < argc)
    {
        int was_there_input_error = 1;
        for (int i = 0; i <= 6; i++)
        {
            if (strcmp(argv[command_number], command_flags[i]) == 0 )
            {
                flag_index = i;
                was_there_input_error = 0;
            }
        }
        if (was_there_input_error)
        {
            print_face_border();
            fprintf(stderr, "You've typed wrong command flag (%s). The program is terminated.\n", argv[command_number]);
        }
        switch(flag_index)
        {
            case 0:
                print_instructions_info();
                break;
            case 1:
                print_x_coordinates();
                break;
            case 2:
                print_integral_value();
                break;
            case 3:
                print_coordinates_and_integral();
                break;
            case 4:
                print_iters_roots();
                break;
            case 5:
                int index_func1 = 0; 
                sscanf(argv[command_number + 1], "%d", &index_func1);
                int index_func2 = 0;
                sscanf(argv[command_number + 2], "%d", &index_func2);
                double a = 0.0;
                sscanf(argv[command_number + 3], "%lf", &a);
                double b = 0.0;
                sscanf(argv[command_number + 4], "%lf", &b);
                print_test_roots(index_func1, index_func2, a, b);
                command_number += 4;
                break;
            case 6:
                sscanf(argv[command_number + 1], "%d", &index_func1);
                sscanf(argv[command_number + 2], "%lf", &a);
                sscanf(argv[command_number + 3], "%lf", &b);
                print_test_integral(index_func1, a, b);
                command_number += 3;
                break;
        }
        command_number++;
        print_face_border();
        printf("\n");
    }

    return 0;
}
