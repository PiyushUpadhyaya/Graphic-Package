#include<stdio.h>
#include<graphics.h>
#include<math.h>
void Shear_x(int,int ,int ,int ,int ,int ,int );
void Shear_y(int,int ,int ,int ,int ,int ,int );
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
//Creates the coordinate axes in centre
    for(i=0; i<dwHeight; i++)
        putpixel(x0,i,RED);

    for(j=0; j<dwWidth; j++)
        putpixel(j,y0,RED);

    int n,Shx,Shy;
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
    printf("\nThe reflection along:1. Shear x\n 2. Shear_y\n");
    scanf("%d",&choice);
	////if along x axis shearing is required
    if(choice==1)
        {
            printf("\nEnter the Shearing factor Shx\n\t");
            scanf("%d",&Shx);
        while(z!=(n-1))
            {//plots the ployline curve
                polylines(x[z],y[z],x[z+1],y[z+1],x0,y0);
				//simultaneously plots the new curve to be plotted.
				//Sx and Sy are the shearing coefficients.
                Shear_x(x[z],y[z],x[z+1],y[z+1],x0,y0,Shx);////if along x axis shearing is required
                z++;
            }
        }
		////if along y axis shearing is required
    else if(choice==2)
        {
        printf("\n Enter the Shearing factor Shy\n\t");
        scanf("%d",&Shy);
        while(z!=(n-1))
            {//simultaneously plots the new curve to be plotted.
				//Sx and Sy are the shearing coefficients.
                polylines(x[z],y[z],x[z+1],y[z+1],x0,y0);
                Shear_y(x[z],y[z],x[z+1],y[z+1],x0,y0,Shy);//if along y axis shearing is required
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
//Function for shearing along x axis;
void Shear_x(int x1,int y1,int x2,int y2,int x0, int y0, int Shx )
{
    x1 += Shx*y1;
    x2 += Shx*y2;
    
    polylines(x1,y1,x2,y2,x0,y0);
}

//Function for shearing along y axis;
void Shear_y(int x1,int y1,int x2,int y2,int x0, int y0,int Shy)
{
    y1 += Shy*x1;
    y2 += Shy*x2;
    
    polylines(x1,y1,x2,y2,x0,y0);
}


