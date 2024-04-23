#include <stdio.h>
#ifndef ASCII_ART_C
#define ASCII_ART_C 

void print_ascii_art(FILE* file, int length)
{
    char buffer[length];
 
    while( fgets(buffer, sizeof(buffer), file) != NULL)
    {
        printf("%s", buffer);
    }
}
#endif
