#include <stdlib.h>
#include <stdio.h>

int main(void) {
    const FILE *svg = fopen("mon_dessin.svg", "w");

    fprintf(svg, "<svg xmlns=\"http://www.w3.org/2000/svg\" width=\"1\" height=\"1\" viewBox=\"0 0 1 1\">");
    fprintf(svg, "<rect width=\"1\" height=\"1\" x=\"0\" fill=\"#ff0000\"/>");
    fprintf(svg, "</svg>");
}