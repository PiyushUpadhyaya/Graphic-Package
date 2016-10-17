#include <graphics.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>


int main()
{
     float centre1,centre2, radius,x_coordinate, y_coordinate,p,X,Y;
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
    X=x_coordinate;
    Y=2*y_coordinate;
        putpixel(floor(centre1+1/2)+x_coordinate,floor(centre2+1/2)+y_coordinate,15);
        putpixel(floor(centre1+1/2)+x_coordinate,floor(centre2+1/2)-y_coordinate,15);
        putpixel(floor(centre1+1/2)-x_coordinate,floor(centre2+1/2)+y_coordinate,15);
        putpixel(floor(centre1+1/2)-x_coordinate,floor(centre2+1/2)-y_coordinate,15);


    p = floor(5/4 - radius + 1/2);

    for(x_coordinate=0; x_coordinate<y_coordinate;)
    {
        x_coordinate++;
        X=X+2;

        if(p<0)
            p=p+X+1;
        else
        {
            Y=Y-2;
            p=p+X+1-Y;
            y_coordinate--;
        }
        putpixel(floor(centre1+1/2)+x_coordinate,floor(centre2+1/2)+y_coordinate,15);
        putpixel(floor(centre1+1/2)+x_coordinate,floor(centre2+1/2)-y_coordinate,15);
        putpixel(floor(centre1+1/2)-x_coordinate,floor(centre2+1/2)+y_coordinate,15);
        putpixel(floor(centre1+1/2)-x_coordinate,floor(centre2+1/2)-y_coordinate,15);

        putpixel(floor(centre1+1/2)+y_coordinate,floor(centre2+1/2)+x_coordinate,15);
        putpixel(floor(centre1+1/2)+y_coordinate,floor(centre2+1/2)-x_coordinate,15);
        putpixel(floor(centre1+1/2)-y_coordinate,floor(centre2+1/2)+x_coordinate,15);
        putpixel(floor(centre1+1/2)-y_coordinate,floor(centre2+1/2)-x_coordinate,15);


    }


// cleardevice();
    delay(30000);
closegraph();
return 0;
}


