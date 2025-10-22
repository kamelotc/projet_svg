#include <stdio.h>
#include <stdlib.h>
#include "line.h"

void menu_line(void)
{
    //reserve memory space for the form and then free it up
    line_t *line = malloc(sizeof(line));

    if (line == NULL)
    {
        printf("Malloc failure\n");
        return;
    }
    
    int x1;
    int y1;
    int x2;
    int y2;
    int choose_in_menu;
    int Angle;
    int linecolor;
    int backcolor;



    //x and y allows you to place the SVG shape in the space
    printf("\nYou choose Line\n");
    printf("Choose your size:\n");
    printf("x1:");
    scanf(" %d", &x1);
    printf("y1:");
    scanf(" %d", &y1);
    printf("x2:");
    scanf(" %d", &x2);
    printf("y2:");
    scanf(" %d", &y2);
    
    do {
        printf("\n----- MENU Line -----\n\n");
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
                printf("\nx: ");
                scanf(" %d", &x1);
                printf("y: ");
                scanf(" %d", &y1);
                break;
            case 4:
                printf("\nAngle: ");
                scanf(" %d", &Angle);
                break;
            case 5:
                printf("\nx: ");
                scanf(" %d", &x1);
                printf("y: ");
                scanf(" %d", &y1);
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
                    "<line x1=\"%d\" y1=\"%d\" x2=\"%d\" y2=\"%d\"/>\n"
                    "</g>\n"
                "</svg>\n",
                colors[linecolor - 1],colors[backcolor - 1],x1,y1,x2,y2);
                
                fclose(svg);

                printf("\nSVG Shape export\n");
                break;


            case 0:
                printf("\nExiting Line menu\n");
                break;

            default:
                printf("\n==========\n");
                printf("  Error\n");
                printf("==========\n");
                break;
        }
        

    } while (choose_in_menu != 0);

    free(line);
}

