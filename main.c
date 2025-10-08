#include <ctype.h>
#include <stdlib.h>
#include <stdio.h>

void generateShape(FILE *svg, const char shape, const int width, const int height, char color[6]) {
    if (color == NULL)
        color = "ff0000";
    switch (shape) {
        case 'C': fprintf(svg, "<circle cx=\"%d\" cy=\"%d\" r=\"%d\" fill=\"#%s\"/>", width/2, height/2, width/2, color); break;
        case 'R': fprintf(svg, "<rect width=\"%d\" height=\"%d\" x=\"0\" fill=\"#%s\"/>", width, height, color); break;
        default: fputs ("ERROR: This shape could not be recognized despite passing the first check?", stderr); break;
    }
}

int main(void) {
    const FILE *svg = fopen("resultat.svg", "w");

    char shape;
    int width = 0;
    int height = 0;

    printf("R = Rectangle");
    printf("\nC = Cercle");
    printf("\nChoisissez la forme : ");
    if (scanf("%c",&shape) != 1 && toupper(shape) != 'C' && toupper(shape) != 'R') {
        fputs ("ERROR: Invalid input.\n", stderr);
        return 1;
    }

    shape = toupper(shape);

    printf("Choisissez la largeur : ");
    if (scanf("%d",&width) != 1 && width <= 0) {
        fputs ("ERROR: Invalid input.\n", stderr);
        return 1;
    }

    printf("\nChoisissez la hauteur : ");
    if (scanf("%d",&height) != 1 && height <= 0) {
        fputs ("ERROR: Invalid input.\n", stderr);
        return 1;
    }

    fprintf(svg, "<svg xmlns=\"http://www.w3.org/2000/svg\" width=\"%d\" height=\"%d\" viewBox=\"0 0 %d %d\">", width, height, width, height);
    generateShape(svg, shape, width, height, NULL);
    fprintf(svg, "</svg>");

    return EXIT_SUCCESS;
}