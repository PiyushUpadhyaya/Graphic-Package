#include <graphics.h>
#include <stdio.h>
#include <stdlib.h>


int main()
{
    float xval1,xval2, yval1,yval2,delta_x,delta_y,p;
    float i,j;
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
  //  m = (yval2-yval1)/(xval2-xval1);

    xval1=xval1+600;
    yval1=350-yval1;
	xval2=xval2+600;
    yval2=350-yval2;
	
    delta_x=xval2-xval1;
    delta_y=yval2-yval1;
    p = (2*delta_y) - delta_x;
    printf("\n%f first p",p);

    for(i=0; i<=(delta_x-1); i++)
    {
        if(p<0)
            {
            xval1=xval1+1;
            putpixel(xval1,yval1,4);
			p = p + 2*delta_y;printf("\nIn if");
            }
        else
            {
            xval1=xval1+1;
            yval1=yval1+1;
            putpixel(xval1,yval1,4);
			p = p + 2*delta_y - 2*delta_x;printf("In else");
            printf("\n%f",p);
            }

    }


// cleardevice();
    delay(30000);
closegraph();
return 0;
}


