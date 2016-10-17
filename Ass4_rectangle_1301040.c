

#include <graphics.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>


int main()
{
    float x1,y1,x2,y2,x3,y3,x4,y4;
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
    printf("\nEnter the Coordinate1:\n");
    scanf("%f%f",&x1,&y1);

    printf("\nEnter the Coordinate3:\n");
    scanf("%f%f",&x3,&y3);
     i=0;
    x1=x1+600;
    y1=350-y1;

    x3=x3+600;
    y3=350-y3;

    for(i=x1;i<x3;i++)
    {
        putpixel(i,y1,15);

    }
    for(i=y1;i>y3;i--)
    {
        putpixel(x3,i,15);

    }
    for(i=x1;i<x3;i++)
    {
        putpixel(i,y3,15);


    }
    for(i=y3;i<y1;i++)
    {
        putpixel(x1,i,15);

    }

    for(j=y3+1;j<y1;j++)
    {
    for(i=x1+1;i<x3;i++)
    {
        putpixel(i,j,4);

    }
    }

    delay(30000);
    closegraph();
}

