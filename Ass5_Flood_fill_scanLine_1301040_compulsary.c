
#include <graphics.h>
#include <stdio.h>
#include <stdlib.h>
void testPixel(int ,int );
void polylines(int,int,int,int,int,int);
int z,x0,y0;
int boundary_color=4;
int fill_color=15;

int main()
{

    float first_x,first_y;
    //int fill_color,boundary_color;
  //  int gd=DETECT,gm;
    //initgraph(&gd,&gm,NULL);


    DWORD dwWidth = GetSystemMetrics(SM_CXSCREEN);
    DWORD dwHeight = GetSystemMetrics(SM_CYSCREEN);
    initwindow(dwWidth,dwHeight);
    int x0=dwWidth/2;
    int y0=dwHeight/2;
    int i,j,x[50],y[50];

    for(i=0; i<dwHeight; i++)
        putpixel(x0,i,4);

    for(j=0; j<dwWidth; j++)
        putpixel(j,y0,4);

    int n;
    printf("Enter the number of coordinates or vertices\n");
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        printf("Enter the %dth coordinate\n",(i+1));
        scanf("%d",&x[i]);
        scanf("%d",&y[i]);
    }
    for(i=0;i<n;i++)
        printf("%d\t%d\n",x[i],y[i]);
    while(z!=(n-1))
    {
        polylines(x[z],y[z],x[z+1],y[z+1],x0,y0);
        z++;
    }
    printf("\nfill color white and boundary color red:");
  //  scanf("%d%d",&fill_color,&boundary_color);
    printf("\nEnter the coordinates x,y:");
    scanf("%f%f",&first_x,&first_y);

    first_x=first_x+x0;
    first_y=y0-first_y;
    testPixel(first_x,first_y);

// cleardevice();
    delay(300000);
closegraph();
return 0;
}

void testPixel(int first_x,int first_y)
{
    // first_x,first_y,fill_color,boundary_color,
    int color;


    color=getpixel(first_x,first_y);
    printf("\n%d %d %d",color,boundary_color,fill_color);
        if((color!=boundary_color ) && (color!=fill_color))
        {
        putpixel(first_x,first_y,fill_color);
        //testPixel(first_x,first_y+1);
        testPixel(first_x,first_y-1);
        testPixel(first_x+1,first_y+1);
        //testPixel(first_x-1,first_y-1);
        }

}

void polylines(int x1,int y1,int x2,int y2,int x0,int y0){
    int y3,k;
    if(x1>=x2){
            int temp1,temp2;
            temp1=x1;
            x1=x2;
            x2=temp1;
            temp2=y1;
            y1=y2;
            y2=temp2;
        }
    float xdel=x2-x1;
    float ydel=y2-y1;
    x1=x0+x1;
    x2=x0+x2;
    y1=y0-y1;
    y2=y0-y2;

    int p[500],x[500],y[500];
    x[0]=x1;
    y[0]=y1;

    float m=(ydel/xdel);
    putpixel(x1,y1,4);

    if( m <=1 && m>0)
    {
        p[0]=(-0.5*xdel-ydel);
        for(k=0; k<xdel; k++)
        {
            if(p[k]<0)
            {
                y3=y[k]+1-y[0];
                putpixel(x[k]+1,y[k]+1-2*y3,4);
                x[k+1]=x[k]+1;
                y[k+1]=y[k]+1;
                p[k+1]=p[k]+xdel-ydel;
            }
            else
            {
                y3=y[k]-y[0];
                putpixel(x[k]+1,y[k]-2*y3,4);
                x[k+1]=x[k]+1;
                y[k+1]=y[k];
                p[k+1]=p[k]-ydel;
            }

        }
    }
   /* else if (m==1)
    {
        for(k=0;k<xdel;k++)
    }*/

    else if(m>=-1 && m<=0)
    {
        p[0]=(-0.5*xdel-ydel);
        for(k=0; k<xdel; k++)
        {
            if(p[k]<0)
            {
                y3=y[k]-y[0];
                putpixel(x[k]+1,y[k]-2*y3,4);
                x[k+1]=x[k]+1;
                y[k+1]=y[k];
                p[k+1]=p[k]-ydel;
            }
            else
            {
                y3=y[k]-1-y[0];
                putpixel(x[k]+1,y[k]-1-2*y3,4);
                x[k+1]=x[k]+1;
                y[k+1]=y[k]-1;
                p[k+1]=p[k]-xdel-ydel;
            }

        }
    }
    else if(m>1)
    {
        p[0]=(xdel-(ydel*0.5));

        for(k=0; k<ydel; k++)
        {
            if(p[k]<0)
            {
                y3=y[k]+1-y[0];
                putpixel(x[k],y[k]+1-2*y3,4);
                x[k+1]=x[k];
                y[k+1]=y[k]+1;
                p[k+1]=p[k]+xdel;
            }
            else
            {
                y3=y[k]+1-y[0];
                putpixel(x[k]+1,y[k]+1-2*y3,4);
                x[k+1]=x[k]+1;
                y[k+1]=y[k]+1;
                p[k+1]=p[k]+xdel-ydel;
            }

        }
    }
    else if(m<-1)
    {
        p[0]=(-xdel-(ydel*0.5));

        for(k=0; k<(-1)*ydel; k++)
        {
            if(p[k]<0)
            {
                y3=y[k]-1-y[0];
                putpixel(x[k]+1,y[k]-1-2*y3,4);
                x[k+1]=x[k]+1;
                y[k+1]=y[k]-1;
                p[k+1]=p[k]-xdel-ydel;
            }
            else
            {
                y3=y[k]-1-y[0];
                putpixel(x[k],y[k]-1-2*y3,4);
                x[k+1]=x[k];
                y[k+1]=y[k]-1;
                p[k+1]=p[k]-xdel;
            }

        }
    }
    //return z;

}
