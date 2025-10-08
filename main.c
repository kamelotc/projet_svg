#include <stdlib.h>
#include <stdio.h>

int main(void) {
    const FILE *svg = fopen("mon_dessin.svg", "w");

    int largeur = 0;
    int hauteur = 0;

    printf("Choisissez la largeur : ");
    if (scanf("%d",&largeur) != 1 && largeur <= 0) {
        fputs ("ERROR: Invalid input.\n", stderr);
        return 1;
    }

    printf("\nChoisissez la hauteur : ");
    if (scanf("%d",&hauteur) != 1 && hauteur <= 0) {
        fputs ("ERROR: Invalid input.\n", stderr);
        return 1;
    }
    fprintf(svg, "<svg xmlns=\"http://www.w3.org/2000/svg\" width=\"%d\" height=\"%d\" viewBox=\"0 0 %d %d\">", largeur, hauteur, largeur, hauteur);
    fprintf(svg, "<rect width=\"%d\" height=\"%d\" x=\"0\" fill=\"#ff0000\"/>", largeur, hauteur);
    fprintf(svg, "</svg>");

    return EXIT_SUCCESS;
}