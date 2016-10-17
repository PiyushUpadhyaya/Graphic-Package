#include <graphics.h>
#include <stdio.h>
#include <stdlib.h>


int main()
{
    float xval1,xval2, yval1,yval2;
    float m;
  
    int gd=DETECT,gm;
    initwindow(1200,700);
    for( j=0;j<=1200;j++)
    {
        putpixel(600,j,15);
    }
    for( i=0;i<=1200;i++)
    {
        putpixel(i,350,15);
    }

    printf("\nEnter the start coordinates:x and y");
    scanf("%f%f",&xval1,&yval1);
    printf("\nEnter the end coordinates:x and y");
    scanf("%f%f",&xval2,&yval2);
	xval1=xval1+600;
    yval1=350-yval1;
	xval2=xval2+600;
    yval2=350-yval2;
    m = (yval2-yval1)/(xval2-xval1);
	

    for(xval1; xval1<xval2; xval1++)
    {
        putpixel((int)xval1,(int)yval1,4);
        yval1=yval1+m;
        printf("\n %f",yval1);

    }


// cleardevice();
    delay(30000);
closegraph();
return 0;
}
