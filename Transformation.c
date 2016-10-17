#include<stdio.h>
#include<graphics.h>
#include<math.h>
void Translate(int,int ,int ,int ,int ,int ,int ,int);
void scale(int,int ,int ,int ,int ,int ,int ,int);
void rotate(int ,int ,int ,int ,int ,int ,int );
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
//Split screen into coordinate axes
    for(i=0; i<dwHeight; i++)
        putpixel(x0,i,RED);

    for(j=0; j<dwWidth; j++)
        putpixel(j,y0,RED);

    int n,Sx,Sy;
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
    printf("\nThe reflection along:1. Scaling\n 2. Rotation\n 3.Translation");
    scanf("%d",&choice);
    //For the Scaling purpose
    if(choice==1)
        {
            printf("\nEnter the Scaling factor Sx and Sy :\t");
            scanf("%d%d",&Sx,&Sy);
        while(z!=(n-1))
            {
                //simultaneously plots the new curve to be plotted.
                polylines(x[z],y[z],x[z+1],y[z+1],x0,y0);
                //Shows the scaled polygon
                scale(x[z],y[z],x[z+1],y[z+1],x0,y0,Sx,Sy);
                z++;
            }
        }
         //For rotation of polygon
    else if(choice==2)
        {
        int theta;//angle for rotation
        printf("\n Enter the rotation factor:theta\n\t");
        scanf("%d",&theta);
        while(z!=(n-1))
            {
                //simultaneously plots the new curve to be plotted.
                polylines(x[z],y[z],x[z+1],y[z+1],x0,y0);
                //Shows the rotated polygon
                rotate(x[z],y[z],x[z+1],y[z+1],x0,y0,theta);
                z++;
            }
        }
        //For translation of polygon
    else if(choice==3)
        {
        int tx,ty;
        printf("\n Enter the translation factor:x-axis y-axis\n\t");
        scanf("%d%d",&tx,&ty);
        while(z!=(n-1))
            {
                //simultaneously plots the new curve to be plotted.
                polylines(x[z],y[z],x[z+1],y[z+1],x0,y0);
                 //Shows the translated polygon
                Translate(x[z],y[z],x[z+1],y[z+1],x0,y0,tx,ty);
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
//For translation
void Translate(int x1,int y1,int x2,int y2,int x0, int y0, int tx ,int ty)
{
    //Translation input update in coordinates
    x1 += tx;
    y1 += ty;
    x2 += tx;
    y2 += ty;polylines(x1,y1,x2,y2,x0,y0);
}
//For Scaling
void scale(int x1,int y1,int x2,int y2,int x0, int y0, int Sx ,int Sy)
{
      //Scaling input update in coordinates
    x1=x1*Sx;
    y1=y1*Sy;
    x2=x2*Sx;
    y2=y2*Sy;
    polylines(x1,y1,x2,y2,x0,y0);

}
//For rotation
void rotate(int x1,int x2,int y1,int y2,int x0,int y0,int theta)
{
      //Rotaion input update in coordinates
    int c=x1;int b=y1;int d=x2;int e=y2;
    x1 = c*cos(theta) - b*sin(theta);
    y1 =  b*cos(theta) + c*sin(theta);

    x2 = d*cos(theta) - e*sin(theta);
    y2 =  e*cos(theta) + d*sin(theta);
    polylines(x1,y1,x2,y2,x0,y0);
}

