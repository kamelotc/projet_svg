#include <stdio.h>
#include <stdlib.h>
#include "ellipse.h"


void menu_ellipse(void)
{
    //reserve memory space for the form and then free it up
    ellipse_t *ellipse = malloc(sizeof(ellipse));

    if (ellipse == NULL)
    {
        printf("Malloc failure\n");
        return;
    }
    
    int cx;
    int cy;
    int rx;
    int ry;
    int choose_in_menu;
    int Angle = 0;
    int linecolor = 0;
    int backcolor =0;


    //x and y allows you to place the SVG shape in the space
    printf("\nYou choose Ellipse\n");
    printf("Choose your size:\n");
    printf("cx:");
    scanf(" %d", &cx);
    printf("cy:");
    scanf(" %d", &cy);
    printf("rx:");
    scanf(" %d", &rx);
    printf("ry:");
    scanf(" %d", &ry);
    
    do {
        printf("\n----- MENU Ellipse -----\n\n");
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
                if (backcolor >= 1 && backcolor <= 3) 
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
                    "<ellipse cx=\"%d\" cy=\"%d\" rx=\"%d\" ry=\"%d\" />\n"
                    "</g>\n"
                "</svg>\n",
                colors[linecolor - 1],colors[backcolor - 1],cx,cy,rx,ry);
                
                fclose(svg);

                printf("\nSVG Shape export\n");
                break;
            
            case 0:
                printf("\nExiting Ellipse menu\n");
                break;

            default:
                printf("\n==========\n");
                printf("  Error\n");
                printf("==========\n");
                break;
        }
        

    } while (choose_in_menu != 0);

    free(ellipse);
}