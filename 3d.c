#include<stdlib.h>
#include<stdio.h>
#include<graphics.h>
#include<math.h>
void display(float,float,float,float,float,float);
void display(float x1,float y1,float z1,float x2,float y2,float z2)
{
    int k,l;
    for(k=0;k<=1000;k++)
    {
        putpixel(k,500,6);
        putpixel(500,k,6);
    }
    //Reflection Plane request
    printf("1.xy plane \n2. yz plane \n 3. zx plane\n4.yx plane\n5.zy plane\n6.xz plane\n");
    int i;
    scanf("%d",&i);
    switch(i)
    {
    case 1:
        //line drawning
        line(500+x1,500-y1,500+x2,500-y2);
        break;
    case 2:
        //line drawning
        line(500+y1,500-z1,500+y2,500-z2);
        break;
    case 3:
        //line drawning
        line(500+z1,500-x1,500+z2,500-x2);
        break;
    case 4://line drawning
        line(500+y1,500-x1,500+y2,500-x2);
        break;
    case 5://line drawning
        line(500+z1,500-y1,500+z2,500-y2);
        break;
    case 6://line drawning
        line(500+x1,500-z1,500+x2,500-z2);
        break;
    default:
        printf("\ntry again \n");
        break;
    }
}
int main()
{
 //   printf("how many point do you want   ");
    int n,i,j;
    //scanf("%d",&n);
    //n=8;
    //split window
    initwindow(1000,1000);
      float x1,y1,z1,x2,y2,z2,vx1,vx2,vy1,vy2,vz1,vz2;//variables
      //predefined inputs for x y z coordinates
      //start and end points
       x1=100.0;
       x2=200.0;
       y1=100.0;
       y2=300.0;
       z1=400.0;
       z2=100.0;
       //int i;
      while(1)
      {//choice for the action
          printf("1.Translation\n2.Rotation\n3.scaling\n4.shearing\n 5. display\npress   ");
          scanf("%d",&i);
          switch(i)
          {
          case 1://translation request
              float tx,ty,tz;
              printf("\n tx ty tz   ");
              scanf("%f %f %f",&tx,&ty,&tz);

            //tx ty tz varibale added to coordinates and line drawns
              x1=x1+tx;
              x2=x2+tx;
              y1=y1+ty;
              y2=y2+ty;
              z1=z1+tz;
              z2=z2+tz;
              display(x1,y1,z1,x2,y2,z2);
            break;
          case 2:
              //rotation choice
              printf("1.xaxis\n2.yaxis\n3.zaxis\npress   ");
              //int j:
                  float rx,ry,rz;
                  scanf("%d",&j);
                  switch(j)
                  {
                  case 1:
                      //along x axis rotatiuon
                      printf("\nRotation along x  ");
                      scanf("%f",&rx);
                          rx=rx*3.14/180;
                          //radian to angle

                          //components of coordinates along axes
                        y1=y1*cos(rx)-z1*sin(rx);
                        y2=y2*cos(rx)-z2*sin(rx);
                        z1=y1*sin(rx)+z1*cos(rx);
                        z2=y2*sin(rx)+z2*cos(rx);
                      display(x1,y1,z1,x2,y2,z2);
                    break;
                  case 2:
                      //along y axis rotatiuon
                      printf("\nRotation along y  ");
                      scanf("%f",&ry);
                      ry=ry*3.14/180;
                      //radian to angle

                          //components of coordinates along axes
                        x1=z1*sin(ry)+x1*cos(ry);
                        x2=z2*sin(ry)+x2*cos(ry);
                        z1=z1*cos(ry)-x1*sin(ry);
                        z2=z2*cos(ry)-x2*sin(ry);
                      display(x1,y1,z1,x2,y2,z2);
                    break;
                  case 3: //along y axis rotatiuon
                      printf("\nRotation along z ");
                      scanf("%f",&rz);
                      rz=rz*3.14/180;
                      //radian to angle

                          //components of coordinates along axes
                        x1=x1*cos(ry)-y1*sin(ry);
                        x2=x2*cos(ry)-y2*sin(ry);
                        y1=y1*cos(ry)+x1*sin(ry);
                        y2=y2*cos(ry)+x2*sin(ry);

                      display(x1,y1,z1,x2,y2,z2);
                    break;
                  default:
                    printf(" try later");
                    break;
                  }
              display(x1,y1,z1,x2,y2,z2);
            break;
          case 3: //basic  Scalong
              float sx,sy,sz;
              printf("\n Scaling values sx sy sz   ");
              scanf("%f %f %f",&sx,&sy,&sz);
              //change coordinates scale accordingly
                x1=x1*sx;
              x2=x2*sx;
              y1=y1*sy;
              y2=y2*sy;
              z1=z1*sz;
              z2=z2*sz;
              display(x1,y1,z1,x2,y2,z2);
            break;
          case 4:
              //along Scalong along different axis
              printf("1.Along xaxis\n2.Along yaxis\n3.Along zaxis\npress   ");
              //int j;
                  float shxy,shxz,shyx,shyz,shzx,shzy;
                  scanf("%d",&j);
                  switch(j)
                  {
                  case 1://along Scalong along x axis
                      printf("\nsxy sxz  ");
                      scanf("%f %f",&shxy,&shxz);
                        //scale pouints
                        y1=x1*shxy+y1;
                        y2=x2*shxy+y2;
                        z1=x1*shxz+z1;
                        z2=x2*shxz+z2;
                      display(x1,y1,z1,x2,y2,z2);
                    break;
                  case 2:
                      //along Scalong along y axis
                      printf("\nsyx syz  ");
                      scanf("%f %f",&shyx,&shyz);
                      //scale pouints
                        x1=y1*shyx+x1;
                        x2=y2*shyx+x2;
                        z1=y1*shyz+z1;
                        z2=y2*shyz+z2;
                      display(x1,y1,z1,x2,y2,z2);
                    break;
                  case 3:
                      //along Scalong along z axis
                      printf("\nszx szy  ");
                      scanf("%f %f",&shzx,&shzy);
                       //scale pouints
                        x1=z1*shzx+x1;
                        x2=z2*shzx+x2;
                        y1=z1*shzy+y1;
                        y2=z2*shzy+y2;

                      display(x1,y1,z1,x2,y2,z2);
                    break;
                  default:
                    printf(" try later");
                    break;
                  }
            break;
            case 5:
                break;
            default :
                printf("\ntry again   \n");
                break;

          }
      }
     delay(300000);
     closegraph();
}
