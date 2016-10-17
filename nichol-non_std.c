
#include <graphics.h>
#include <stdio.h>
#include <conio.h>
#include <math.h>
int region(int,int,int,int);
void region1(int,int,int,int);
void region2(int,int,int,int,int);
void region3(int,int,int,int,int);
void draw(int,int,int,int,int);
void window_orientation(int,int,int,int,int,int,int,int);
void draw_line(int,int,int,int,int);
int xwi,ywi,xwf,ywf,xr,yr;
float th;
int main()
{

    int x1, y1,color;
    initwindow(800,800);
    color=4;
    int i;
    int side;
    //making coordinate axes
    for(i=0;i<800;i++){
       putpixel(i,400,10);
       putpixel(400,i,10);
    }
    //asking for polygon specifications
    printf("Enter no of vertices \n");
    scanf("%d",&side);
    int edge[side+1][2];
    int temp1;
    for(i=0;i<side;i++){
       printf("Enter the vertex\n");
       scanf("%d%d", &x1, &y1);
       edge[i][0]=x1;
       edge[i][1]=y1;
    }
    edge[i][0]=edge[0][0];
    edge[i][1]=edge[0][1];
    //drawing polygon based on given input
    for(i=0;i<(side);i++){
      draw(edge[i][0],edge[i][1],edge[i+1][0],edge[i+1][1],color);
    }
     color++;
     int x11,y11,x21,y21,x31,y31,x41,y41;
     printf("Enter window vertices\n");
     scanf("%d%d",&x11,&y11);
     printf("Enter window vertices\n");
     scanf("%d%d",&x21,&y21);
     printf("Enter window vertices\n");
     scanf("%d%d",&x31,&y31);
     printf("Enter window vertices\n");
     scanf("%d%d",&x41,&y41);

     window_orientation(x11,y11,x21,y21,x31,y31,x41,y41);

     if((xwi>xwf)&&(ywi>ywf)){
        temp1=xwi;
        xwi=xwf;
        xwf=temp1;
        temp1=ywi;
        ywi=ywf;
        ywf=temp1;
     }
     else if((xwi>xwf)&&(ywi<ywf)){
        temp1=xwi;
        xwi=xwf;
        xwf=temp1;
     }
     else if((xwi<xwf)&&(ywi>ywf)){
        temp1=ywi;
        ywi=ywf;
        ywf=temp1;
     }
     int region_code=0;
      //got clipping window
      //rubbing the earlier polygon
      int xi,yi,xf,yf,reflected=0,tempx,tempy;
      float reflect,ut;

     for(i=0;i<side;i++){
            xi=edge[i][0];
            yi=edge[i][1];
            xf=edge[i+1][0];
            yf=edge[i+1][1];
            reflected=0;
            tempx=xi;
            tempy=yi;
            xi=xr+floor(((tempx-xr)*cos(-th))-((tempy-yr)*sin(-th))+0.5);
            yi=yr+floor(((tempx-xr)*sin(-th))+((tempy-yr)*cos(-th))+0.5);

            tempx=xf;
            tempy=yf;
            xf=xr+floor(((tempx-xr)*cos(-th))-((tempy-yr)*sin(-th))+0.5);
            yf=yr+floor(((tempx-xr)*sin(-th))+((tempy-yr)*cos(-th))+0.5);

            if((side==2)&&(i==1)){
                break;
            }
            region_code=region(xi,yi,xf,yf);
            if(region_code==11){
                region1(xi,yi,xf,yf);
            }
            else if(region_code==12){
                region1(xf,yf,xi,yi);
            }
            else if(region_code==21){
                region2(xi,yi,xf,yf,reflected);
            }
            else if(region_code==22){
                region2(xf,yf,xi,yi,reflected);
            }
            else if(region_code==31){
                region3(xi,yi,xf,yf,reflected);
            }
            else if(region_code==32){
                region3(xf,yf,xi,yi,reflected);
            }
            else if(region_code==41){
                reflect=(float)(ywi+ywf)/2;
                yi=floor((reflect*2)-yi+0.5);
                yf=floor((reflect*2)-yf+0.5);
                reflected=1;
                region3(xi,yi,xf,yf,reflected);
            }
            else if(region_code==42){
                reflect=(float)(ywi+ywf)/2;
                yi=floor((reflect*2)-yi+0.5);
                yf=floor((reflect*2)-yf+0.5);
                reflected=1;
                region3(xf,yf,xi,yi,reflected);
            }
            else if(region_code==51){
                reflect=(float)(xwi+xwf)/2;
                xi=floor((reflect*2)-xi+0.5);
                xf=floor((reflect*2)-xf+0.5);
                reflected=1;
                region2(xi,yi,xf,yf,reflected);
            }
            else if(region_code==52){
                reflect=(float)(xwi+xwf)/2;
                xi=floor((reflect*2)-xi+0.5);
                xf=floor((reflect*2)-xf+0.5);
                reflected=1;
                region2(xf,yf,xi,yi,reflected);
            }
            else if(region_code==61){
                reflect=(float)(xwi+xwf)/2;
                xi=floor((reflect*2)-xi+0.5);
                xf=floor((reflect*2)-xf+0.5);
                reflected=2;
                region3(xi,yi,xf,yf,reflected);
            }
            else if(region_code==62){
                reflect=(float)(xwi+xwf)/2;
                xi=floor((reflect*2)-xi+0.5);
                xf=floor((reflect*2)-xf+0.5);
                reflected=2;
                region3(xf,yf,xi,yi,reflected);
            }
            else if(region_code==71){
                reflect=(float)(xwi+xwf)/2;
                xi=floor((reflect*2)-xi+0.5);
                xf=floor((reflect*2)-xf+0.5);
                reflect=(float)(ywi+ywf)/2;
                yi=floor((reflect*2)-yi+0.5);
                yf=floor((reflect*2)-yf+0.5);
                reflected=3;
                region3(xi,yi,xf,yf,reflected);
            }
            else if(region_code==72){
                reflect=(float)(xwi+xwf)/2;
                xi=floor((reflect*2)-xi+0.5);
                xf=floor((reflect*2)-xf+0.5);
                reflect=(float)(ywi+ywf)/2;
                yi=floor((reflect*2)-yi+0.5);
                yf=floor((reflect*2)-yf+0.5);
                reflected=3;
                region3(xf,yf,xi,yi,reflected);
            }
            else if(region_code==81){
                ut=(float)(ywf-yi)/(yf-yi);
                if((ut>=0.0)&&(ut<=1.0)){
                   xi=xi + floor(ut*(xf-xi)+0.5);
                   yi=ywf;
                   region1(xi,yi,xf,yf);
                }
            }
            else if(region_code==82){
                ut=(float)(ywf-yi)/(yf-yi);
                if((ut>=0.0)&&(ut<=1.0)){
                   xf=xi + floor(ut*(xf-xi)+0.5);
                   yf=ywf;
                   region1(xf,yf,xi,yi);
                }
            }


     }
     draw_line(xwi,ywi,xwf,ywi,12);
     draw_line(xwf,ywi,xwf,ywf,12);
     draw_line(xwf,ywf,xwi,ywf,12);
     draw_line(xwi,ywf,xwi,ywi,12);
    delay(100000);
    return 0;
}
//draw line
void draw_line(int x1,int y1,int x2,int y2,int c){

            int tempx=x1;
            int tempy=y1;
            x1=xr+floor(((tempx-xr)*cos(th))-((tempy-yr)*sin(th))+0.5);
            y1=yr+floor(((tempx-xr)*sin(th))+((tempy-yr)*cos(th))+0.5);

            tempx=x2;
            tempy=y2;
            x2=xr+floor(((tempx-xr)*cos(th))-((tempy-yr)*sin(th))+0.5);
            y2=yr+floor(((tempx-xr)*sin(th))+((tempy-yr)*cos(th))+0.5);

            draw(x1,y1,x2,y2,c);

}



//orientation

void window_orientation(int x1,int y1,int x2,int y2,int x3,int y3,int x4,int y4){
    int i;
    int edge[5][2];
     edge[0][0]=x1;
     edge[0][1]=y1;
     edge[1][0]=x2;
     edge[1][1]=y2;
     edge[2][0]=x3;
     edge[2][1]=y3;
     edge[3][0]=x4;
     edge[3][1]=y4;
     edge[4][0]=x1;
     edge[4][1]=y1;


     int tempx,tempy,index=0,min;
     float m;
    min=edge[0][1];
       for(i=1;i<4;i++){
          if(edge[i][1]<min){
             min=edge[i][1];
             index=i;
          }
       }
                    xr=edge[index][0];
                    yr=edge[index][1];
                    m=(float)(edge[index][1]-edge[index+1][1])/(edge[index][0]-edge[index+1][0]);
                    th=atan(m);
                    for(i=0;i<5;i++){
					 tempx=edge[i][0];
					 tempy=edge[i][1];
                     edge[i][0]=xr+floor(((tempx-xr)*cos(-th))-((tempy-yr)*sin(-th))+0.5);
                     edge[i][1]=yr+floor(((tempx-xr)*sin(-th))+((tempy-yr)*cos(-th))+0.5);
                    }
                    //drawing polygon with transformed vertices
                     xwi=edge[0][0];
                     ywi=edge[0][1];
                     xwf=edge[2][0];
                     ywf=edge[2][1];
}



///////////

//region 1
void region1(int x1,int y1,int x2,int y2){
    float m1,m2,m3,m4,m5,ul,ur,ut,ub;

    m1=(float)(y1-ywi)/(x1-xwf);
    m2=(float)(y1-ywf)/(x1-xwf);
    m3=(float)(y1-ywf)/(x1-xwi);
    m4=(float)(y1-ywi)/(x1-xwi);
    m5=(float)(y1-y2)/(x1-x2);

    if((x2>=xwi)&&(x2<=xwf)&&(y2>=ywi)&&(y2<=ywf)){
         draw_line(x1,y1,x2,y2,14);
    }
    //right
    if(x2>xwf){
        if((m5>=m1)||(m5<=m2)){
            ur=(float)(xwf-x1)/(x2-x1);
            x2=xwf;
            y2=floor(y1+(ur*(y2-y1))+0.5);
            draw_line(x1,y1,x2,y2,14);
        }
    }
    //top
    if(y2>ywf){
        if((m5<m3)||(m5>m2)){
            ut=(float)(ywf-y1)/(y2-y1);
            x2=x1 + floor(ut*(x2-x1)+0.5);
            y2=ywf;
            draw_line(x1,y1,x2,y2,14);
        }
    }
    //left
    if(x2<xwi){
        if((m5>=m3)||(m5<=m4)){
            ul=(float)(xwi-x1)/(x2-x1);
            x2=xwi;
            y2=floor(y1+(ul*(y2-y1))+0.5);
            draw_line(x1,y1,x2,y2,14);
        }
    }

    //bottom
    if(y2<ywi){
        if((m5>m4)||(m5<m1)){
            ub=(float)(ywi-y1)/(y2-y1);
            x2=x1 + floor(ub*(x2-x1)+0.5);
            y2=ywi;
            draw_line(x1,y1,x2,y2,14);
        }
    }

}
//region 2
void region2(int x1,int y1,int x2,int y2,int reflected){
    float m1,m2,m3,m4,m5,ul,ur,ut,ub;

    m1=(float)(y1-ywi)/(x1-xwf);
    m2=(float)(y1-ywf)/(x1-xwf);
    m3=(float)(y1-ywf)/(x1-xwi);
    m4=(float)(y1-ywi)/(x1-xwi);
    m5=(float)(y1-y2)/(x1-x2);

    float reflect=(float)(xwi+xwf)/2;
    //left right
    if(x2>xwf){
        if((m5>=m1)&&(m5<=m2)){
            ul=(float)(xwi-x1)/(x2-x1);
            x1=xwi;
            y1=floor(y1+(ul*(y2-y1))+0.5);

            ur=(float)(xwf-x1)/(x2-x1);
            x2=xwf;
            y2=floor(y1+(ur*(y2-y1))+0.5);
            if(reflected==0){
                draw_line(x1,y1,x2,y2,14);
                }
                else{
                   x1=((reflect*2)-x1+0.5);
                   x2=((reflect*2)-x2+0.5);
                   draw_line(x1,y1,x2,y2,14);
                }
        }
    }
    //left top
    if((y2>ywf)&&(x2>xwi)){
        if((m5<m3)&&(m5>m2)){
            ul=(float)(xwi-x1)/(x2-x1);
            x1=xwi;
            y1=floor(y1+(ul*(y2-y1))+0.5);

            ut=(float)(ywf-y1)/(y2-y1);
            x2=x1 + floor(ut*(x2-x1)+0.5);
            y2=ywf;
            if(reflected==0){
                draw_line(x1,y1,x2,y2,14);
                }
            else{
                   x1=((reflect*2)-x1+0.5);
                   x2=((reflect*2)-x2+0.5);
                   draw_line(x1,y1,x2,y2,14);
            }
           }
    }

    //left bottom
    if((y2<ywi)&&(x2>xwi)){
        if((m5>m4)&&(m5<m1)){
            ul=(float)(xwi-x1)/(x2-x1);
            x1=xwi;
            y1=floor(y1+(ul*(y2-y1))+0.5);

            ub=(float)(ywi-y1)/(y2-y1);
            x2=x1 + floor(ub*(x2-x1)+0.5);
            y2=ywi;
            if(reflected==0){
                draw_line(x1,y1,x2,y2,14);
                }
                else{
                   x1=((reflect*2)-x1+0.5);
                   x2=((reflect*2)-x2+0.5);
                   draw_line(x1,y1,x2,y2,14);
                }
        }
    }
}
//region 3
void region3(int x1,int y1,int x2,int y2,int reflected){
    float m1,m2,m3,m4,m5,ul,ur,ut,ub;
    float reflect=(float)(ywi+ywf)/2;
    m1=(float)(y1-ywi)/(x1-xwf);
    m2=(float)(y1-ywf)/(x1-xwf);
    m3=(float)(y1-ywf)/(x1-xwi);
    m4=(float)(y1-ywi)/(x1-xwi);
    m5=(float)(y1-y2)/(x1-x2);

    if(m3<-1){
    //top right
        if((x2>xwf)&&(y2<ywf)){
            if((m5>=m1)&&(m5<=m2)){
                ut=(float)(ywf-y1)/(y2-y1);
                x1=x1 + floor(ut*(x2-x1)+0.5);
                y1=ywf;

                ur=(float)(xwf-x1)/(x2-x1);
                x2=xwf;
                y2=floor(y1+(ur*(y2-y1))+0.5);
                if(reflected==0){
                draw_line(x1,y1,x2,y2,14);
                }
                else if(reflected==2){
                  reflect=(float)(xwi+xwf)/2;
                  x1=floor((reflect*2)-x1+0.5);
                  x2=floor((reflect*2)-x2+0.5);
                  draw_line(x1,y1,x2,y2,14);
                }
                else if(reflected==3){
                    reflect=(float)(xwi+xwf)/2;
                    x1=floor((reflect*2)-x1+0.5);
                    x2=floor((reflect*2)-x2+0.5);
                    reflect=(float)(ywi+ywf)/2;
                    y1=floor((reflect*2)-y1+0.5);
                    y2=floor((reflect*2)-y2+0.5);
                    draw_line(x1,y1,x2,y2,14);
                }
                else{
                   y1=((reflect*2)-y1+0.5);
                   y2=((reflect*2)-y2+0.5);
                   draw_line(x1,y1,x2,y2,14);
                }
            }
        }
    //top bottom
        if((y2<ywi)&&(x2>xwi)){
            if((m5>m3)&&(m5<m1)){
                ut=(float)(ywf-y1)/(y2-y1);
                x1=x1 + floor(ut*(x2-x1)+0.5);
                y1=ywf;

                ub=(float)(ywi-y1)/(y2-y1);
                x2=x1 + floor(ub*(x2-x1)+0.5);
                y2=ywi;
                if(reflected==0){
                draw_line(x1,y1,x2,y2,14);
                }
                else if(reflected==2){
                  reflect=(float)(xwi+xwf)/2;
                  x1=floor((reflect*2)-x1+0.5);
                  x2=floor((reflect*2)-x2+0.5);
                  draw_line(x1,y1,x2,y2,14);
                }
                else if(reflected==3){
                    reflect=(float)(xwi+xwf)/2;
                    x1=floor((reflect*2)-x1+0.5);
                    x2=floor((reflect*2)-x2+0.5);
                    reflect=(float)(ywi+ywf)/2;
                    y1=floor((reflect*2)-y1+0.5);
                    y2=floor((reflect*2)-y2+0.5);
                    draw_line(x1,y1,x2,y2,14);
                }
                else{
                   y1=((reflect*2)-y1+0.5);
                   y2=((reflect*2)-y2+0.5);
                   draw_line(x1,y1,x2,y2,14);
                }
            }
        }

    //left bottom
        if((y2<ywi)&&(x2>xwi)){
            if((m5>=m4)&&(m3>=m5)){
                ul=(float)(xwi-x1)/(x2-x1);
                x1=xwi;
                y1=floor(y1+(ul*(y2-y1))+0.5);

                ub=(float)(ywi-y1)/(y2-y1);
                x2=x1 + floor(ub*(x2-x1)+0.5);
                y2=ywi;
                if(reflected==0){
                draw_line(x1,y1,x2,y2,14);
                }
                else if(reflected==2){
                  reflect=(float)(xwi+xwf)/2;
                  x1=floor((reflect*2)-x1+0.5);
                  x2=floor((reflect*2)-x2+0.5);
                  draw_line(x1,y1,x2,y2,14);
                }
                else if(reflected==3){
                    reflect=(float)(xwi+xwf)/2;
                    x1=floor((reflect*2)-x1+0.5);
                    x2=floor((reflect*2)-x2+0.5);
                    reflect=(float)(ywi+ywf)/2;
                    y1=floor((reflect*2)-y1+0.5);
                    y2=floor((reflect*2)-y2+0.5);
                    draw_line(x1,y1,x2,y2,14);
                }
                else{
                   y1=((reflect*2)-y1+0.5);
                   y2=((reflect*2)-y2+0.5);
                   draw_line(x1,y1,x2,y2,14);
                }
            }
        }
    }
    else if(m3>=-1){
        //top right
        if((x2>xwf)&&(y2<ywf)){
            if((m5>=m3)&&(m5<=m2)){
                ut=(float)(ywf-y1)/(y2-y1);
                x1=x1 + floor(ut*(x2-x1)+0.5);
                y1=ywf;

                ur=(float)(xwf-x1)/(x2-x1);
                x2=xwf;
                y2=floor(y1+(ur*(y2-y1))+0.5);
                if(reflected==0){
                draw_line(x1,y1,x2,y2,14);
                }
                else if(reflected==2){
                  reflect=(float)(xwi+xwf)/2;
                  x1=floor((reflect*2)-x1+0.5);
                  x2=floor((reflect*2)-x2+0.5);
                  draw_line(x1,y1,x2,y2,14);
                }
                else if(reflected==3){
                    reflect=(float)(xwi+xwf)/2;
                    x1=floor((reflect*2)-x1+0.5);
                    x2=floor((reflect*2)-x2+0.5);
                    reflect=(float)(ywi+ywf)/2;
                    y1=floor((reflect*2)-y1+0.5);
                    y2=floor((reflect*2)-y2+0.5);
                    draw_line(x1,y1,x2,y2,14);
                }
                else{
                   y1=((reflect*2)-y1+0.5);
                   y2=((reflect*2)-y2+0.5);
                   draw_line(x1,y1,x2,y2,14);
                }
            }
        }
    //left right
        if((y2<ywf)&&(x2>xwf)){
            if((m5<m3)&&(m5>m1)){
                ul=(float)(xwi-x1)/(x2-x1);
                x1=xwi;
                y1=floor(y1+(ul*(y2-y1))+0.5);

                ur=(float)(xwf-x1)/(x2-x1);
                x2=xwf;
                y2=floor(y1+(ur*(y2-y1))+0.5);
                if(reflected==0){
                draw_line(x1,y1,x2,y2,14);
                }
                else if(reflected==2){
                  reflect=(float)(xwi+xwf)/2;
                  x1=floor((reflect*2)-x1+0.5);
                  x2=floor((reflect*2)-x2+0.5);
                  draw_line(x1,y1,x2,y2,14);
                }
                else if(reflected==3){
                    reflect=(float)(xwi+xwf)/2;
                    x1=floor((reflect*2)-x1+0.5);
                    x2=floor((reflect*2)-x2+0.5);
                    reflect=(float)(ywi+ywf)/2;
                    y1=floor((reflect*2)-y1+0.5);
                    y2=floor((reflect*2)-y2+0.5);
                    draw_line(x1,y1,x2,y2,14);
                }
                else{
                   y1=((reflect*2)-y1+0.5);
                   y2=((reflect*2)-y2+0.5);
                   draw_line(x1,y1,x2,y2,14);
                }
            }
        }

    //left bottom
        if((y2<ywi)&&(x2>xwi)){
            if((m5>=m4)&&(m1>=m5)){
                ul=(float)(xwi-x1)/(x2-x1);
                x1=xwi;
                y1=floor(y1+(ul*(y2-y1))+0.5);

                ub=(float)(ywi-y1)/(y2-y1);
                x2=x1 + floor(ub*(x2-x1)+0.5);
                y2=ywi;
                if(reflected==0){
                draw_line(x1,y1,x2,y2,14);
                }
                else if(reflected==2){
                  reflect=(float)(xwi+xwf)/2;
                  x1=floor((reflect*2)-x1+0.5);
                  x2=floor((reflect*2)-x2+0.5);
                  draw_line(x1,y1,x2,y2,14);
                }
                else if(reflected==3){
                    reflect=(float)(xwi+xwf)/2;
                    x1=floor((reflect*2)-x1+0.5);
                    x2=floor((reflect*2)-x2+0.5);
                    reflect=(float)(ywi+ywf)/2;
                    y1=floor((reflect*2)-y1+0.5);
                    y2=floor((reflect*2)-y2+0.5);
                    draw_line(x1,y1,x2,y2,14);
                }
                else{
                   y1=((reflect*2)-y1+0.5);
                   y2=((reflect*2)-y2+0.5);
                   draw_line(x1,y1,x2,y2,14);
                }
            }
        }

    }

}
//get region

int region(int x1,int y1,int x2,int y2){
     if((x1>=xwi)&&(x1<=xwf)&&(y1>=ywi)&&(y1<=ywf)){
         return 11;
     }
     else if((x2>=xwi)&&(x2<=xwf)&&(y2>=ywi)&&(y2<=ywf)){
         return 12;
     }
     else if((x1<=xwi)&&(y1>=ywi)&&(y1<=ywf)){
         return 21;
     }
     else if((x2<=xwi)&&(y2>=ywi)&&(y2<=ywf)){
         return 22;
     }
     else if((x1<=xwi)&&(y1>=ywf)){
         return 31;
     }
     else if((x2<=xwi)&&(y2>=ywf)){
         return 32;
     }

     //extra
     else if((x1<=xwi)&&(y1<=ywi)){
         return 41;
     }
     else if((x2<=xwi)&&(y2<=ywi)){
         return 42;
     }

    else if((x1>=xwf)&&(y1<=ywf)&&(y1>=ywi)){
         return 51;
     }
     else if((x2>=xwf)&&(y2<=ywf)&&(y2>=ywi)){
         return 52;
     }
     else if((x1>=xwf)&&(y1>=ywf)){
         return 61;
     }
     else if((x2>=xwf)&&(y2>=ywf)){
         return 62;
     }

     else if((x1>=xwf)&&(y1<=ywi)){
         return 71;
     }
     else if((x2>=xwf)&&(y2<=ywi)){
         return 72;
     }
     else if((x1<=xwf)&&(x1>=xwi)&&(y1>=ywf)){
         return 81;
     }
     else if((x2<=xwf)&&(x2>=xwi)&&(y2>=ywf)){
         return 82;
     }

}
// draw line between two vertices passed as parameter
void draw(int x1,int y1,int x2,int y2,int colour){
    float xi,yi,x,y;
    int s,dx,dy,m;
    x1=x1+400;
       y1=400-y1;
       x2=x2+400;
       y2=400-y2;
    dx = x2 - x1;
    dy = y2 - y1;

    if (abs(dx) > abs(dy))
	s = abs(dx);
    else
	s = abs(dy);

    xi = dx / (float) s;
    yi = dy / (float) s;

    x = x1;
    y = y1;

    putpixel(x1, y1, colour);

    for (m = 0; m < s; m++) {
	x += xi;
	y += yi;
	putpixel(x, y, colour);
    }
}





