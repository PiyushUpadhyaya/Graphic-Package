#include <graphics.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>


int main()
{
     float centre1,centre2, radius,x_coordinate, y_coordinate,p;
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
    x_coordinate=0.0;
    y_coordinate=floor(radius+1/2);


    p = floor(3- 2*radius + 1/2);

    for(x_coordinate=0; x_coordinate<=y_coordinate;)
    {
        putpixel(floor(centre1+1/2)+x_coordinate,floor(centre2+1/2)+y_coordinate,15);
        putpixel(floor(centre1+1/2)+x_coordinate,floor(centre2+1/2)-y_coordinate,15);
        putpixel(floor(centre1+1/2)-x_coordinate,floor(centre2+1/2)+y_coordinate,15);
        putpixel(floor(centre1+1/2)-x_coordinate,floor(centre2+1/2)-y_coordinate,15);
        putpixel(floor(centre1+y_coordinate+1/2),floor(centre2+x_coordinate+1/2),15);
        putpixel(floor(centre1+y_coordinate+1/2),floor(centre2-x_coordinate+1/2),15);
        putpixel(floor(centre1-y_coordinate+1/2),floor(centre2+x_coordinate+1/2),15);
        putpixel(floor(centre1-y_coordinate+1/2),floor(centre2-x_coordinate+1/2),15);

        x_coordinate++;
        if(p<0)
            p=p+4*x_coordinate+6;
        else
        {
            y_coordinate=y_coordinate-1;
            p=p+4*(x_coordinate-y_coordinate)+10;
        }
    }


// cleardevice();
    delay(30000);
closegraph();
return 0;
}



