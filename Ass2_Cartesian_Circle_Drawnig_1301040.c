#include <graphics.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>


int main()
{
    float centre1,centre2, radius,x_coordinate, y_coordinate;
    int gd=DETECT,gm;
    int i,j;
//    initgraph(&gd,&gm,NULL);
    initwindow(1200,700);
    for( j=0;j<=1200;j++)
    {
        putpixel(600,j,15);
    }
    for( i=0;i<=1200;i++)
    {
        putpixel(i,350,15);
    }

    printf("\nEnter the Radius:");
    scanf("%f",&radius);
    printf("\nEnter the Centre coordinates:x and y");
    scanf("%f%f",&centre1,&centre2);
    centre1=centre1+600;
    centre2=350-centre2;
    putpixel(floor(centre1-radius+1/2),floor(centre2+1/2),15);
    putpixel(floor(centre1+radius+1/2),floor(centre2+1/2),15);
    for(x_coordinate=(floor(centre1-radius+1/2)+1);x_coordinate<=(floor(centre1+radius+1/2)-1);)
    {
        y_coordinate = centre2 + sqrt((radius*radius)-((centre1-x_coordinate)*(centre1-x_coordinate)));
        putpixel(x_coordinate,floor(y_coordinate+1/2),15);
        y_coordinate =  centre2 - sqrt((radius*radius)-((centre1-x_coordinate)*(centre1-x_coordinate)));
        putpixel(x_coordinate,floor(y_coordinate+1/2),15);
        x_coordinate=x_coordinate+1;
    }


// cleardevice();
    delay(30000);
closegraph();
return 0;
}
