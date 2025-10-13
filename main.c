#include <ctype.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "structures.h"

/**
 * @param svg Le fichier SVG à modifier.
 * @param shape Le caractère représentant la forme, habituellement sa première lettre.
 * @param width La largeur de la forme.
 * @param height La hauteur de la forme.
 * @param color La couleur de la forme.
 * @deprecated Fonction anciennement utilisée pour générer toutes les formes. Remplacée par des fonctions spécialisées pour pouvoir ajouter des paramètres uniques à certaines formes.
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

/**
 * Demande un nombre à l'utilisateur puis place la valeur dans un pointeur. Le programme s'arrêtera en attendant une réponse.
 * @param message Le message à afficher à l'utilisateur lorsqu'on demande un nombre.
 * @param number Le pointeur qui contiendra la valeur entrée par l'utilisateur.
 */
void askNumber(char message[], int *number) {
    printf(message);
    if (scanf("%d",number) != 1)
        fputs("ERROR: Invalid input.\n", stderr);
}

/**
* Génère une forme "classique", c'est-à-dire une forme ne prenant qu'une largeur et une hauteur pour la créer. Comprend les rectangles et les ellipses.
 * @param svg Le fichier SVG à modifier.
 * @param shape Le caractère représentant la forme pour l'identifier, habituellement sa première lettre.
 * @param color La couleur de la forme.
 * @return 1 si une erreur s'est produite, 0 sinon.
 */
int generateClassicShape(FILE *svg, const char shape, char color[6]) {
    if (color == NULL)
        color = "ff0000";
    int width = 0;
    int height = 0;
    //On demande la largeur et la hauteur de la forme qui doivent être supérieures à 0.
    askNumber("Choisissez la largeur (au-dessus de 0) :", &width);
    askNumber("\nChoisissez la hauteur (au-dessus de 0) :", &height);

    if (width <= 0 || height <= 0) {
        fputs("ERROR: Largeur et/ou hauteur invalide(s).\n", stderr);
        return EXIT_FAILURE;
    }

    fprintf(svg, "<svg xmlns=\"http://www.w3.org/2000/svg\" width=\"%d\" height=\"%d\" viewBox=\"0 0 %d %d\">\n    ", width, height, width, height);
    switch (shape) {
        case 'E': fprintf(svg, "<ellipse cx=\"%d\" cy=\"%d\" rx=\"%d\" ry=\"%d\" fill=\"#%s\"/>", width/2, height/2, width/2, height/2, color); break;
        case 'R': fprintf(svg, "<rect width=\"%d\" height=\"%d\" x=\"0\" fill=\"#%s\"/>", width, height, color); break;
        default: fputs("ERROR: Attempted to generate classic shape but could not be identified?", stderr); return EXIT_FAILURE;
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
int generateCircle(FILE *svg, char color[6]) {
    if (color == NULL)
        color = "ff0000";
    int radius = 0;
    //On demande le rayon du cercle qui doit être supérieur à 0.
    askNumber("Choisissez le rayon (au-dessus de 0) :", &radius);
    if (radius <= 0) {
        fputs("ERROR: Rayon invalide.", stderr);
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
int generateLine(FILE *svg, char color[6]) {
    if (color == NULL)
        color = "ff0000";
    int x1 = 0, y1 = 0, x2 = 0, y2 = 0, viewWidth = 0, viewHeight = 0;
    askNumber("Choisissez la largeur de la vue :", &viewWidth);
    askNumber("Choisissez la hauteur de la vue :", &viewHeight);
    if (viewWidth <= 0 || viewHeight <= 0) {
        fputs("ERROR: Invalid input.\n", stderr);
        return EXIT_FAILURE;
    }
    askNumber("Choisissez les coordonnees X du premier point :", &x1);
    askNumber("Choisissez les coordonnees Y du premier point :", &y1);
    askNumber("Choisissez les coordonnees X du second point :", &x2);
    askNumber("Choisissez les coordonnees Y du second point :", &y2);

    fprintf(svg, "<svg xmlns=\"http://www.w3.org/2000/svg\" width=\"%d\" height=\"%d\" viewBox=\"0 0 %d %d\">\n    ", viewWidth, viewHeight, viewWidth, viewHeight);
    fprintf(svg, "<line x1=\"%d\" y1=\"%d\" x2=\"%d\" y2=\"%d\" stroke=\"#%s\"/>", x1, y1, x2, y2, color);
    fprintf(svg, "\n</svg>");
    return EXIT_SUCCESS;
}

/** Génère des formes prenant des coordonnées comme paramètres pour placer la quantité de points demandée.
* @param svg Le fichier SVG à modifier.
* @param color La couleur de la ligne.
* @return 1 si une erreur s'est produite, 0 sinon.
*/
int generatePolyShape(FILE *svg, char shape, char color[6]) {
    if (color == NULL)
        color = "ff0000";
    int x1 = 0, y1 = 0, viewWidth = 0, viewHeight = 0, lines = 1;
    askNumber("Choisissez la largeur de la vue :", &viewWidth);
    askNumber("Choisissez la hauteur de la vue :", &viewHeight);
    askNumber("Choisissez le nombre de lignes :", &lines);
    if (viewWidth <= 0 || viewHeight <= 0 || lines <= 0) {
        fputs("ERROR: Invalid input.\n", stderr);
        return EXIT_FAILURE;
    }
    int xPoints[lines+1] = {};
    int yPoints[lines+1] = {};
    askNumber("Choisissez les coordonnees X du premier point :", &x1);
    askNumber("Choisissez les coordonnees Y du premier point :", &y1);
    for (int i = 0; i < lines; i++) {
        int x2 = 0, y2 = 0;
        printf("%d/%d\n", i, lines);
        askNumber("Choisissez les coordonnees X du prochain point :", &x2);
        askNumber("Choisissez les coordonnees Y du prochain point :", &y2);
        xPoints[i] = x2;
        yPoints[i] = y2;
    }

    fprintf(svg, "<svg xmlns=\"http://www.w3.org/2000/svg\" width=\"%d\" height=\"%d\" viewBox=\"0 0 %d %d\">\n    ", viewWidth, viewHeight, viewWidth, viewHeight);
    switch (shape) {
        case 'S': fprintf(svg, "<polyline fill=\"none\" stroke=\"#%s\" points=\"", color); break;
        case 'P': fprintf(svg, "<polygon fill=\"none\" stroke=\"#%s\" points=\"", color); break;
        default: fputs("ERROR: Attempted to generate polyshape but could not be identified?", stderr); return EXIT_FAILURE;
    }
    fprintf(svg, "%d,%d ", x1, y1);
    for (int i = 0; i < lines; i++) {
        fprintf(svg, "%d,%d ", xPoints[i], yPoints[i]);
    }
    fprintf(svg, "\"/>\n</svg>");
    return EXIT_SUCCESS;
}

int main(void) {
    char shape;
    int exit = EXIT_SUCCESS;

    //On demande la forme. On l'identifie à l'aide d'un seul caractère.
    //(Habituellement la première lettre.)
    printf("R = Rectangle");
    printf("\nC = Cercle");
    printf("\nE = Ellipse");
    printf("\nL = Ligne");
    printf("\nS = Suite de Lignes");
    printf("\nP = Polygone");
    printf("\nConseil : Il est possible de faire un carre en utilisant un rectangle!");
    printf("\nChoisissez la forme : ");
    if (scanf("%c",&shape) != 1) {
        fputs("ERROR: Invalid input.\n", stderr);
        return EXIT_FAILURE;
    }

    //On met le caractère en majuscule pour ne pas avoir de problèmes avec les caractères minuscules.
    //Puis, on vérifie si c'est l'un des caractères autorisés, sinon on renvoie une erreur.
    shape = toupper(shape);
    if (strpbrk(&shape, "RCELSP") == 0) {
        fputs("ERROR: Invalid input. Must be one of the characters in the given list.\n", stderr);
        return EXIT_FAILURE;
    }

    //On ouvre (crée s'il n'existe pas) un fichier "resultat.svg" en mode écriture.
    //Puis, on écrit les infos SVG dedans.
    const FILE *svg = fopen("resultat.svg", "w");
    switch (shape) {
        case 'R': case 'E': exit = generateClassicShape(svg, shape, NULL); break;
        case 'C': exit = generateCircle(svg, NULL); break;
        case 'L': exit = generateLine(svg, NULL); break;
        case 'S': case 'P': exit = generatePolyShape(svg, shape, NULL); break;
        default: fputs("ERROR: Invalid input.\n", stderr); exit = EXIT_FAILURE; break;
    }
    return exit;
}