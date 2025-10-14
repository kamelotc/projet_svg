#ifndef fonctions
#define fonctions
#include <stdio.h>

void ask_number(char message[], int *number);
int create_classic_shape(FILE *svg, char shape, char color[6]);
int create_circle(FILE *svg, char color[6]);
int create_line(FILE *svg, char color[6]);
int create_polyshape(FILE *svg, char shape, char color[6]);

#endif