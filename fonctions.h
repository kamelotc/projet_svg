#ifndef fonctions
#define fonctions
#include <stdio.h>

int ask_number(char message[], int *number);
int create_classic_shape(FILE *svg, char shape, int color[3]);
int create_circle(FILE *svg, int color[3]);
int create_line(FILE *svg, int color[3]);
int create_polyshape(FILE *svg, char shape, int color[3]);

#endif