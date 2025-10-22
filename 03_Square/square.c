#include <stdio.h>
#include <stdlib.h>
#include "square.h"

void menu_square(void)
{
    //reserve memory space for the form and then free it up
    square_t *square = malloc(sizeof(square));

    if (square == NULL)
    {
        printf("Malloc failure\n");
        return;
    }
    
    int cx;
    int cy;
    int width;
    int height;
    int choose_in_menu;
    int Angle;
    int linecolor;
    int backcolor;



    //x and y allows you to place the SVG shape in the space
    printf("\nYou choose Square\n");
    printf("Choose your size:\n");
    printf("cx:");
    scanf(" %d", &cx);
    printf("cy:");
    scanf(" %d", &cy);
    printf("width:");
    scanf(" %d", &width);
    printf("height:");
    scanf(" %d", &height);
    
    do {
        printf("\n----- MENU SQUARE -----\n\n");
        printf("01-Line color\n"
               "02-Background color\n"
               "03-Move elements along the X and Y axis \n"
               "04-Rotate elements by an angle (integer) \n"
               "05-Flip elements along the X or Y axis \n"
               "06-Export an svg \n"
               "00-Exit menu\n");
        printf("\nEnter a number: ");
        scanf(" %d", &choose_in_menu);
    
        switch (choose_in_menu)
        {
            case 1:
                printf("\n01-Red\n02-Green\n03-Blue\nYour line color: ");
                scanf(" %d", &linecolor);
                if (linecolor >= 1 && linecolor <= 3) 
                {
                printf("======================\n");
                printf("  Defined line color\n");
                printf("======================\n");
                } 
                else 
                {
                printf("\n==========\n");
                printf("  Error\n");
                printf("==========\n");
                }
                break;
            case 2:
                printf("\n01-Red\n02-Green\n03-Blue\nYour background color: ");
                scanf(" %d", &backcolor);
                if (linecolor >= 1 && linecolor <= 3) 
                {
                printf("===========================\n");
                printf("  Defined background color\n");
                printf("===========================\n");
                } 
                else 
                {
                printf("\n==========\n");
                printf("  Error\n");
                printf("==========\n");
                }
                break;
            case 3:
                printf("\ncx: ");
                scanf(" %d", &cx);
                printf("cy: ");
                scanf(" %d", &cy);
                break;
            case 4:
                printf("\nAngle: ");
                scanf(" %d", &Angle);
                break;
            case 5:
                printf("\ncx: ");
                scanf(" %d", &cx);
                printf("cy: ");
                scanf(" %d", &cy);
                break;
            

            case 6:
                {
                if (linecolor ==0 || backcolor ==0)
                {
                    printf("\n Choose valid colors for line and back\n");
                    break;
                }
                }
                
                const char *colors[] = {"red","green","blue"};
                FILE *svg = fopen("export_shape.svg", "w");
                if (svg == NULL) {
                printf("\n==========\n");
                printf("  Error\n");
                printf("==========\n");
                break;
                }
                
                fprintf(svg,
                    "<svg viewBox=\"0 0 100 100\" xmlns=\"http://www.w3.org/2000/svg\">\n"
                    "<g stroke=\"%s\" stroke-width=\"2\" fill=\"%s\">\n"
                    "<rect width=\"%d\" height=\"%d\" />\n"
                    "</g>\n"
                "</svg>\n",
                colors[linecolor - 1],colors[backcolor - 1],cx,cy);
                
                fclose(svg);

                printf("\nSVG Shape export\n");
                break;
            
            
            case 0:
                printf("\nExiting Square menu\n");
                break;

            default:
                printf("\n==========\n");
                printf("  Error\n");
                printf("==========\n");
                break;
        }
        

    } while (choose_in_menu != 0);

    free(square);
}