#include <stdio.h>
#include <stdlib.h>
#include "circle.h"

void menu_circle(void)
{
    int circle;

    do {
        printf("Circle Menu:");
        printf("Change Color");
        printf("")
        scanf(" %d", &circle);
    
        switch (circle)
        {
        case 1:
            printf("You choose Circle\n");
            break;
        case 2:
            printf("good");
            break;
        default:
            break;
        }
    } while(circle !=0);

    
}