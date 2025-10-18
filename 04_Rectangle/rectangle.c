#include <stdio.h>
#include <stdlib.h>
#include "rectangle.h"

void menu_rectangle(void)
{
    //reserve memory space for the form and then free it up
    rectangle_t *rectangle = malloc(sizeof(rectangle));

    if (rectangle == NULL)
    {
        printf("Malloc failure\n");
        return;
    }
    
    int x;
    int y;
    int width;
    int height;
    int choose_in_menu;
    int Angle;
    int linecolor;
    int backcolor;



    //x and y allows you to place the SVG shape in the space
    printf("\nYou choose Rectangle\n");
    printf("Choose your size:\n");
    printf("x:");
    scanf(" %d", &x);
    printf("y:");
    scanf(" %d", &y);
    printf("width:");
    scanf(" %d", &width);
    printf("height:");
    scanf(" %d", &height);
    
    do {
        printf("\n----- MENU Rectangle -----\n\n");
        printf("01-Line color\n"
               "02-Background color\n"
               "03-Move elements along the X and Y axis \n"
               "04-Rotate elements by an angle (integer) \n"
               "05-Flip elements along the X or Y axis \n"
               "06-Exit menu\n");
        printf("\nEnter a number: ");
        scanf(" %d", &choose_in_menu);
    
        switch (choose_in_menu)
        {
            case 1:
                printf("\n01-Red\n02-Green\n03-Blue\nYour line color: ");
                scanf(" %d", &linecolor);
                if (linecolor == 1 || linecolor == 2 || linecolor == 3) 
                {
                printf("Defined line color\n");
                } 
                else 
                {
                printf("Error\n");
                }
                break;
            case 2:
                printf("\n01-Red\n02-Green\n03-Blue\nYour background color: ");
                scanf(" %d", &backcolor);
                if (backcolor == 1 || backcolor == 2 || backcolor == 3) 
                {
                printf("Defined background color\n");
                } 
                else 
                {
                printf("Error\n");
                }
                break;
            case 3:
                printf("\nx: ");
                scanf(" %d", &x);
                printf("y: ");
                scanf(" %d", &y);
                break;
            case 4:
                printf("\nAngle: ");
                scanf(" %d", &Angle);
                break;
            case 5:
                printf("\nx: ");
                scanf(" %d", &x);
                printf("y: ");
                scanf(" %d", &y);
                break;
            case 6:
                printf("\nExiting Rectangle menu\n");
                break;

            default:
                printf("\nError");
                break;
        }
        

    } while (choose_in_menu != 6);

    free(rectangle);
}

