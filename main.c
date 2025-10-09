#include <ctype.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

/**
 * @param svg Le fichier SVG à modifier.
 * @param shape Le caractère représentant la forme, habituellement sa première lettre.
 * @param width La largeur de la forme.
 * @param height La hauteur de la forme.
 * @param color La couleur de la forme.
 */
void generateShape(FILE *svg, const char shape, const int width, const int height, char color[6]) {
    //On donne une couleur par défaut (rouge.)
    if (color == NULL)
        color = "ff0000";
    //On entre les tags et données nécessaires dépendant de la forme voulue.
    switch (shape) {
        case 'C': fprintf(svg, "<circle cx=\"%d\" cy=\"%d\" r=\"%d\" fill=\"#%s\"/>", width/2, height/2, width/2, color); break;
        case 'E': fprintf(svg, "<ellipse cx=\"%d\" cy=\"%d\" rx=\"%d\" ry=\"%d\" fill=\"#%s\"/>", width/2, height/2, width/2, height/2, color); break;
        case 'R': fprintf(svg, "<rect width=\"%d\" height=\"%d\" x=\"0\" fill=\"#%s\"/>", width, height, color); break;
        default: fputs("ERROR: This shape could not be recognized despite passing the first check? Has it not been implemented correctly?", stderr); break;
    }
}

int main(void) {
    char shape;
    int width = 0;
    int height = 0;

    //On demande la forme. On l'identifie à l'aide d'un seul caractère.
    //(Habituellement la première lettre.)
    printf("R = Rectangle");
    printf("\nC = Cercle");
    printf("\nE = Ellipse");
    printf("\nChoisissez la forme : ");
    if (scanf("%c",&shape) != 1) {
        fputs("ERROR: Invalid input.\n", stderr);
        return EXIT_FAILURE;
    }

    //On met le caractère en majuscule pour ne pas avoir de problèmes avec les caractères minuscules.
    //Puis on vérifie si c'est l'un des caractères autorisés, sinon on renvoie une erreur.
    shape = toupper(shape);
    if (strpbrk(&shape, "CRE") == 0) {
        fputs("ERROR: Invalid input. Must be one of the characters in the given list.\n", stderr);
        return EXIT_FAILURE;
    }

    //On demande la largeur de la forme qui doit être supérieure à 0.
    printf("Choisissez la largeur : ");
    if (scanf("%d",&width) != 1 && width <= 0) {
        fputs("ERROR: Invalid input.\n", stderr);
        return EXIT_FAILURE;
    }

    //On demande la hauteur de la forme qui doit être supérieure à 0.
    printf("\nChoisissez la hauteur : ");
    if (scanf("%d",&height) != 1 && height <= 0) {
        fputs("ERROR: Invalid input.\n", stderr);
        return EXIT_FAILURE;
    }

    //On ouvre (crée s'il n'existe pas) un fichier "resultat.svg" en mode écriture.
    //Puis on écrit les infos SVG dedans.
    const FILE *svg = fopen("resultat.svg", "w");
    fprintf(svg, "<svg xmlns=\"http://www.w3.org/2000/svg\" width=\"%d\" height=\"%d\" viewBox=\"0 0 %d %d\">\n    ", width, height, width, height);
    generateShape(svg, shape, width, height, NULL);
    fprintf(svg, "\n</svg>");

    return EXIT_SUCCESS;
}