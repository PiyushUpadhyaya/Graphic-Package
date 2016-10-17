#include <graphics.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>


int main()
{
    float x_center,y_center, radius,x_coordinate, y_coordinate,angle_increment,angle;
    int gd=DETECT,gm;
    int i,j;
    angle=1.0;
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
    scanf("%f%f",&x_center,&y_center);
    x_center=x_center+600;
    y_center=350-y_center;
    putpixel(floor(x_center+1/2),floor(y_center+radius+1/2),15);
    putpixel(floor(x_center+1/2),floor(y_center-radius+1/2),15);
    putpixel(floor(x_center+radius+1/2),floor(y_center+1/2),15);
    putpixel(floor(x_center-radius+1/2),floor(y_center+1/2),15);



    angle_increment=1/radius;
    for(angle=1;angle<45;angle=angle+angle_increment)
    {
        if(angle<45)
        {
        x_coordinate = radius * cos((float)angle*3.14/180);
        y_coordinate = radius * sin((float)angle*3.14/180);
        putpixel(floor(x_center+x_coordinate+1/2),floor(y_center+y_coordinate+1/2),15);
        putpixel(floor(x_center+x_coordinate+1/2),floor(y_center-y_coordinate+1/2),15);
        putpixel(floor(x_center-x_coordinate+1/2),floor(y_center+y_coordinate+1/2),15);
        putpixel(floor(x_center-x_coordinate+1/2),floor(y_center-y_coordinate+1/2),15);
        putpixel(floor(x_center+y_coordinate+1/2),floor(y_center+x_coordinate+1/2),15);
        putpixel(floor(x_center+y_coordinate+1/2),floor(y_center-x_coordinate+1/2),15);
        putpixel(floor(x_center-y_coordinate+1/2),floor(y_center+x_coordinate+1/2),15);
        putpixel(floor(x_center-y_coordinate+1/2),floor(y_center-x_coordinate+1/2),15);
         }
       else if(angle=45)
       {
           putpixel(floor(x_center+x_coordinate+1/2),floor(y_center+y_coordinate+1/2),15);
           putpixel(floor(x_center+x_coordinate+1/2),floor(y_center-y_coordinate+1/2),15);
           putpixel(floor(x_center-x_coordinate+1/2),floor(y_center+y_coordinate+1/2),15);
           putpixel(floor(x_center-x_coordinate+1/2),floor(y_center-y_coordinate+1/2),15);
       }

    }


// cleardevice();
    delay(30000);
closegraph();
return 0;
}
