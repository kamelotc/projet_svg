#include <stdio.h>
#include <stdlib.h>
#include "01_Circle/circle.h"
#include "02_Ellipse/ellipse.h"
#include "03_Square/square.h"
#include "04_Rectangle/rectangle.h"
#include "05_Line/line.h"
#include "06_Sequence/sequence.h"
#include "07_Polygon/polygon.h"
#include "08_Paths/paths.h"
#include "09_Group/group.h"



int main(void)
{
    int menu;
    int choose;
    
    printf("\n----- MENU SVG -----\n\n");
    printf("01-Edit an SVG\n"
          "02-Remove an SVG\n"
          "03-Export an SVG\n"
          "04-Import an SVG\n");
    printf("Enter a number:");
    scanf("%d",&menu);

    switch (menu)
    {
        case 1:
            printf("\nWhich shape would you like to choose? \n\n");
            printf("01-Circle \n"
                   "02-Ellipse \n"
                   "03-Square \n"
                   "04-Rectangle \n"
                   "05-Line \n"
                   "06-Sequence of lines \n"
                   "07-Polygon \n"
                   "08-Paths (Trajectories) \n"
                   "09-Group \n\n");
            printf("Enter a number:");
            break;
        
        case 2:
            break;


        default:
            break;
    }

    scanf("%d",&choose);
    
    switch (choose)
    {
        case 1:
            menu_circle();
            break;

        default:
            break;
    }
    
    
    
    return 0;
}

