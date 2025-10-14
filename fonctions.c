#include "fonctions.h"
#include <stdlib.h>

/**
 * Demande un nombre à l'utilisateur puis place la valeur dans un pointeur. Le programme s'arrêtera en attendant une réponse.
 * @param message Le message à afficher à l'utilisateur lorsqu'on demande un nombre.
 * @param number Le pointeur qui contiendra la valeur entrée par l'utilisateur.
 */
void ask_number(char message[], int *number) {
    printf(message);
    if (scanf("%d",number) != 1)
        fputs("ERREUR : Caractere invalide.\n", stderr);
}

/**
* Génère une forme "classique", c'est-à-dire une forme ne prenant qu'une largeur et une hauteur pour la créer. Comprend les rectangles et les ellipses.
 * @param svg Le fichier SVG à modifier.
 * @param shape Le caractère représentant la forme pour l'identifier, habituellement sa première lettre.
 * @param color La couleur de la forme.
 * @return 1 si une erreur s'est produite, 0 sinon.
 */
int create_classic_shape(FILE *svg, char shape, char color[6]) {
    if (color == NULL)
        color = "ff0000";
    int width = 0;
    int height = 0;
    //On demande la largeur et la hauteur de la forme qui doivent être supérieures à 0.
    ask_number("Choisissez la largeur (au-dessus de 0) :", &width);
    ask_number("\nChoisissez la hauteur (au-dessus de 0) :", &height);

    if (width <= 0 || height <= 0) {
        fputs("ERREUR : Largeur et/ou hauteur invalide(s).\n", stderr);
        return EXIT_FAILURE;
    }

    fprintf(svg, "<svg xmlns=\"http://www.w3.org/2000/svg\" width=\"%d\" height=\"%d\" viewBox=\"0 0 %d %d\">\n    ", width, height, width, height);
    switch (shape) {
        case 'E': fprintf(svg, "<ellipse cx=\"%d\" cy=\"%d\" rx=\"%d\" ry=\"%d\" fill=\"#%s\"/>", width/2, height/2, width/2, height/2, color); break;
        case 'R': fprintf(svg, "<rect width=\"%d\" height=\"%d\" x=\"0\" fill=\"#%s\"/>", width, height, color); break;
        default: fputs("ERREUR : Tentative de faire une forme classique mais n'a pas pu etre reconnue ?", stderr); return EXIT_FAILURE;
    }
    fprintf(svg, "\n</svg>");
    return EXIT_SUCCESS;
}

/**
 * Génère un cercle ne prenant qu'un rayon comme paramètre.
 * @param svg Le fichier SVG à modifier.
 * @param color La couleur du cercle.
 * @return 1 si une erreur s'est produite, 0 sinon.
 */
int create_circle(FILE *svg, char color[6]) {
    if (color == NULL)
        color = "ff0000";
    int radius = 0;
    //On demande le rayon du cercle qui doit être supérieur à 0.
    ask_number("Choisissez le rayon (au-dessus de 0) :", &radius);
    if (radius <= 0) {
        fputs("ERREUR : Rayon invalide.", stderr);
        return EXIT_FAILURE;
    }

    fprintf(svg, "<svg xmlns=\"http://www.w3.org/2000/svg\" width=\"%d\" height=\"%d\" viewBox=\"0 0 %d %d\">\n    ", radius*2, radius*2, radius*2, radius*2);
    fprintf(svg, "<circle cx=\"%d\" cy=\"%d\" r=\"%d\" fill=\"#%s\"/>", radius, radius, radius, color);
    fprintf(svg, "\n</svg>");
    return EXIT_SUCCESS;
}

/**
 * Génère une ligne droite prenant des coordonnées comme paramètres pour placer les points.
 * @param svg Le fichier SVG à modifier.
 * @param color La couleur de la ligne.
 * @return 1 si une erreur s'est produite, 0 sinon.
 */
int create_line(FILE *svg, char color[6]) {
    if (color == NULL)
        color = "ff0000";
    int x1 = 0, y1 = 0, x2 = 0, y2 = 0, viewWidth = 0, viewHeight = 0;
    ask_number("Choisissez la largeur de la vue (au-dessus de 0) :", &viewWidth);
    ask_number("Choisissez la hauteur de la vue (au-dessus de 0) :", &viewHeight);
    if (viewWidth <= 0 || viewHeight <= 0) {
        fputs("ERREUR : Largeur et/ou hauteur invalide(s) .\n", stderr);
        return EXIT_FAILURE;
    }
    ask_number("Choisissez les coordonnees X du premier point :", &x1);
    ask_number("Choisissez les coordonnees Y du premier point :", &y1);
    ask_number("Choisissez les coordonnees X du second point :", &x2);
    ask_number("Choisissez les coordonnees Y du second point :", &y2);

    fprintf(svg, "<svg xmlns=\"http://www.w3.org/2000/svg\" width=\"%d\" height=\"%d\" viewBox=\"0 0 %d %d\">\n    ", viewWidth, viewHeight, viewWidth, viewHeight);
    fprintf(svg, "<line x1=\"%d\" y1=\"%d\" x2=\"%d\" y2=\"%d\" stroke=\"#%s\"/>", x1, y1, x2, y2, color);
    fprintf(svg, "\n</svg>");
    return EXIT_SUCCESS;
}

/** Génère des formes prenant des coordonnées comme paramètres pour placer la quantité de points demandée.
* @param svg Le fichier SVG à modifier.
* @param shape La forme à créer, représentée par un seul caractère.
* @param color La couleur de la ligne.
* @return 1 si une erreur s'est produite, 0 sinon.
*/
int create_polyshape(FILE *svg, const char shape, char color[6]) {
    if (color == NULL)
        color = "ff0000";
    int x1 = 0, y1 = 0, viewWidth = 0, viewHeight = 0, lines = 1;
    ask_number("Choisissez la largeur de la vue (au-dessus de 0) :", &viewWidth);
    ask_number("Choisissez la hauteur de la vue (au-dessus de 0) :", &viewHeight);
    ask_number("Choisissez le nombre de lignes :(au-dessus de 0) :", &lines);
    if (viewWidth <= 0 || viewHeight <= 0 || lines <= 0) {
        fputs("ERREUR : Largeur et/ou hauteur et/ou nombre de lignes invalide(s).\n", stderr);
        return EXIT_FAILURE;
    }
    int xPoints[lines+1] = {};
    int yPoints[lines+1] = {};
    ask_number("Choisissez les coordonnees X du premier point :", &x1);
    ask_number("Choisissez les coordonnees Y du premier point :", &y1);
    for (int i = 0; i < lines; i++) {
        int x2 = 0, y2 = 0;
        printf("%d/%d\n", i, lines);
        ask_number("Choisissez les coordonnees X du prochain point :", &x2);
        ask_number("Choisissez les coordonnees Y du prochain point :", &y2);
        xPoints[i] = x2;
        yPoints[i] = y2;
    }

    fprintf(svg, "<svg xmlns=\"http://www.w3.org/2000/svg\" width=\"%d\" height=\"%d\" viewBox=\"0 0 %d %d\">\n    ", viewWidth, viewHeight, viewWidth, viewHeight);
    switch (shape) {
        case 'S': fprintf(svg, "<polyline fill=\"none\" stroke=\"#%s\" points=\"", color); break;
        case 'P': fprintf(svg, "<polygon fill=\"none\" stroke=\"#%s\" points=\"", color); break;
        default: fputs("ERREUR : Tentative de faire une polyshape mais n'a pas pu etre reconnue ?", stderr); return EXIT_FAILURE;
    }
    fprintf(svg, "%d,%d ", x1, y1);
    for (int i = 0; i < lines; i++) {
        fprintf(svg, "%d,%d ", xPoints[i], yPoints[i]);
    }
    fprintf(svg, "\"/>\n</svg>");
    return EXIT_SUCCESS;
}