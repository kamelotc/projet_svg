#include <stdio.h>
#include <stdlib.h>
#include "circle.h"

void menu_circle(void)
{
    int x;
    int y;
    int r;
    int choose_in_menu;
    int Angle;
    int linecolor;
    int backcolor;



    printf("\nYou choose Circle\n");
    printf("Choose your size:\n");
    printf("x:");
    scanf(" %d", &x);
    printf("y:");
    scanf(" %d", &y);
    printf("r:");
    scanf(" %d", &r);
    printf("\n----- MENU CIRCLE -----\n\n");
    printf("01-Line color\n"
           "02-Background color\n"
           "03-Move elements along the X and Y axis \n"
           "04-Rotate elements by an angle (integer) \n"
           "05-Flip elements along the X or Y axis \n");
    printf("\nEnter a number: ");
    scanf(" %d", &choose_in_menu);
    
    switch (choose_in_menu)
    {
        case 1:
            printf("\nYour line color: ");
            scanf(" %d", &linecolor);
            break;
        
        case 2:
            printf("\nYour background color: ");
            scanf(" %d", &backcolor);
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


        default:
            break;
    }

    
}

