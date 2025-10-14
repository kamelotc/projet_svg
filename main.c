#include <ctype.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "structures.h"
#include "fonctions.h"

/**
 * @param svg Le fichier SVG à modifier.
 * @param shape Le caractère représentant la forme, habituellement sa première lettre.
 * @param width La largeur de la forme.
 * @param height La hauteur de la forme.
 * @param color La couleur de la forme.
 * @deprecated Fonction anciennement utilisée pour générer toutes les formes. Remplacée par des fonctions spécialisées dans "fonctions.c" pour pouvoir ajouter des paramètres uniques à certaines formes.
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
        fputs("ERREUR : Caractere invalide. Il doit etre l'un des caracteres affiches dans la liste.\n", stderr);
        return EXIT_FAILURE;
    }

    //On ouvre (crée s'il n'existe pas) un fichier "resultat.svg" en mode écriture.
    //Puis, on écrit les infos SVG dedans.
    FILE *svg = fopen("resultat.svg", "w");
    switch (shape) {
        case 'R': case 'E': exit = create_classic_shape(svg, shape, NULL); break;
        case 'C': exit = create_circle(svg, NULL); break;
        case 'L': exit = create_line(svg, NULL); break;
        case 'S': case 'P': exit = create_polyshape(svg, shape, NULL); break;
        default: fputs("ERREUR : Forme invalide.\n", stderr); exit = EXIT_FAILURE; break;
    }
    return exit;
}