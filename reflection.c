

#include<stdio.h>
#include<graphics.h>
#include<math.h>
void reflection_x(int,int,int,int,int,int);
void reflection_y(int,int,int,int,int,int);
void reflection_diag_m1(int,int,int,int,int,int);
void reflection_diag_m_less(int,int,int,int,int,int);
int polylines(int,int,int,int,int,int);
int z;
int main()
{
    int gd=DETECT,gm;

    DWORD dwWidth = GetSystemMetrics(SM_CXSCREEN);
    DWORD dwHeight = GetSystemMetrics(SM_CYSCREEN);
    initwindow(dwWidth,dwHeight);
    int x0=dwWidth/2;
    int y0=dwHeight/2;
    int i,j,x[50],y[50];

    for(i=0; i<dwHeight; i++)
        putpixel(x0,i,RED);

    for(j=0; j<dwWidth; j++)
        putpixel(j,y0,RED);

    int n;
    printf("Enter the number of coordinates or vertices\n");
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        printf("Enter the %dth coordinate\n",i+1);
        scanf("%d",&x[i]);
        scanf("%d",&y[i]);
    }
    for(i=0;i<n;i++)
        printf("%d\t%d\n",x[i],y[i]);
    int choice;
    printf("\nThe reflection along:1. x-axis\n 2. y-axis\n 3.y=x \n 4. y=-x");
    scanf("%d",&choice);
    if(choice==1)
        {//For x-axis reflection
        while(z!=(n-1))
            {
                polylines(x[z],y[z],x[z+1],y[z+1],x0,y0);
                reflection_x(x[z],y[z],x[z+1],y[z+1],x0,y0);//For x-axis reflection
                z++;
            }
        }
    else if(choice==2)
        {//For y-axis reflection
        while(z!=(n-1))
            {
                polylines(x[z],y[z],x[z+1],y[z+1],x0,y0);
                reflection_y(x[z],y[z],x[z+1],y[z+1],x0,y0);//For y-axis reflection
                z++;
            }
        }
    else if(choice==3)
        {//For y=x-axis reflection with slope +1
        while(z!=(n-1))
            {
                polylines(x[z],y[z],x[z+1],y[z+1],x0,y0);
                reflection_diag_m1(x[z],y[z],x[z+1],y[z+1],x0,y0);//For y=x-axis reflection with slope +1
                z++;
            }
        }
    else if(choice==4)
        {//For y=x-axis reflection with slope -1
        while(z!=(n-1))
            {
                polylines(x[z],y[z],x[z+1],y[z+1],x0,y0);
                reflection_diag_m_less(x[z],y[z],x[z+1],y[z+1],x0,y0);//For y=x-axis reflection with slope -
                z++;
            }
        }
    delay(40000);


    cleardevice();
    closegraph();

}
//Polyline function that creates polygon
int polylines(int x1,int y1,int x2,int y2,int x0,int y0){
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
    putpixel(x1,y1,WHITE);

    if( m <=1 && m>0)
    {
        p[0]=(-0.5*xdel-ydel);
        for(k=0; k<xdel; k++)
        {
            if(p[k]<0)
            {
                y3=y[k]+1-y[0];
                putpixel(x[k]+1,y[k]+1-2*y3,WHITE);
                x[k+1]=x[k]+1;
                y[k+1]=y[k]+1;
                p[k+1]=p[k]+xdel-ydel;
            }
            else
            {
                y3=y[k]-y[0];
                putpixel(x[k]+1,y[k]-2*y3,WHITE);
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
                putpixel(x[k]+1,y[k]-2*y3,WHITE);
                x[k+1]=x[k]+1;
                y[k+1]=y[k];
                p[k+1]=p[k]-ydel;
            }
            else
            {
                y3=y[k]-1-y[0];
                putpixel(x[k]+1,y[k]-1-2*y3,WHITE);
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
                putpixel(x[k],y[k]+1-2*y3,WHITE);
                x[k+1]=x[k];
                y[k+1]=y[k]+1;
                p[k+1]=p[k]+xdel;
            }
            else
            {
                y3=y[k]+1-y[0];
                putpixel(x[k]+1,y[k]+1-2*y3,WHITE);
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
                putpixel(x[k]+1,y[k]-1-2*y3,WHITE);
                x[k+1]=x[k]+1;
                y[k+1]=y[k]-1;
                p[k+1]=p[k]-xdel-ydel;
            }
            else
            {
                y3=y[k]-1-y[0];
                putpixel(x[k],y[k]-1-2*y3,WHITE);
                x[k+1]=x[k];
                y[k+1]=y[k]-1;
                p[k+1]=p[k]-xdel;
            }

        }
    }
    //return z;

}
//For the reflection along x-axis
void reflection_x(int x1,int y1,int x2,int y2,int x0,int y0)
{
   
    x1=x1;y1=-y1;x2=x2;y2=-y2;
    polylines(x1,y1,x2,y2,x0,y0);
}
//For the reflection along y-axis
void reflection_y(int x1,int y1,int x2,int y2,int x0,int y0)
{
    //int x1,int y1,int x2,int y2,int x0,int y0
    x1=-x1;y1=y1;x2=-x2;y2=y2;
    polylines(x1,y1,x2,y2,x0,y0);
}
//For the reflection along y=x-axis with positive slope
void reflection_diag_m1(int x1,int y1,int x2,int y2,int x0,int y0)
{
    //int x1,int y1,int x2,int y2,int x0,int y0
    int c;
    c=x1;
    x1=y1;y1=c;c=x2;x2=y2;y2=c;
    polylines(x1,y1,x2,y2,x0,y0);
}
//For the reflection along y=-x-axis with negative slope
void reflection_diag_m_less(int x1,int y1,int x2,int y2,int x0,int y0)
{

    //int x1,int y1,int x2,int y2,int x0,int y0
    int c;
    c=x1;
    x1=-y1;y1=-c;c=x2;x2=-y2;y2=-c;
    polylines(x1,y1,x2,y2,x0,y0);
}
