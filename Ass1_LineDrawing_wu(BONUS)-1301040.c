
#include<graphics.h>
#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int main()
{
    int gd=DETECT,gm,i,j;
    initgraph(&gd,&gm,NULL);
    float x1,x2,y1,y2,c,xf,yf,xfgap;
    float tx,ty,m,xs,ys,yinter,xsgap;
	initwindow(1200,700);
    for( j=0;j<=1200;j++)
    {
        putpixel(600,j,15);
    }
    for( i=0;i<=1200;i++)
    {
        putpixel(i,350,15);
    }
    printf("Enter Starting x Coordinates\n");
    scanf("%f",&x1);
    printf("Enter Starting y Coordinates\n");
    scanf("%f",&y1);
    printf("Enter Ending x Coordinates\n");
    scanf("%f",&x2);
    printf("Enter Ending y Coordinates\n");
    scanf("%f",&y2);
    x1=x1+600;
    y1=350-y1;
	x2=x2+600;
    y2=350-y2;
    if(x1>x2){
        c=x1;
        x1=x2;
        x2=c;
    }
    if(y1>y2){
        c=y1;
        y1=y2;
        y2=c;
    }
    tx=x2-x1;
    ty=y2-y1;
    m=(ty/tx);
    xs=floor(x1+0.5);
    ys=y1+m*(xs-x1);
    yinter=ys+m;
    xsgap=xs+0.5-x1;
    putpixel(xs,floor(ys),((floor(ys)+1-ys)*xsgap));
    putpixel(xs,floor(ys)+1,((ys-floor(ys))*xsgap));
    xf=floor(x2+0.5);
    yf=(y2+m*(xf-x2));
    xfgap=(x2+0.5-xf);
    putpixel(xf,floor(yf),((floor(yf)+1-yf)*xfgap));
    putpixel(xf,floor(yf)+1,((yf-floor(yf))*xfgap));
    for(i=(xs+1);i<=(xf-1);i++){
        putpixel(i,floor(yinter),(floor(yinter)+1-yinter));
        putpixel(i,floor(yinter)+1,(yinter-floor(yinter)));
        yinter=yinter+m;
    }

    delay(30000);
    cleardevice();
    closegraph();
}


