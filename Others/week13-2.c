#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int main() {
    float a =0, b = 0, c = 0 ;
    float delta = 0.0, x1 = 0.0, x2 = 0.0, x11 = 0.0, x21 = 0.0 ;
    scanf("%f", &a);
    scanf("%f", &b);
    scanf("%f", &c);
    delta = (b*b)-(4*a*c);
    //printf("%.1f\n", delta);
    if (delta >= 0.0){
       // printf("delta>0\n");
       // printf("%.2f\n" , delta);
        x1=x1*10;
        x1=(int)x1;
        x1=x1/10;
        x2=x2*10;
        x2=(int)x2;
        x2=x2/10;
        x1=((-b)+sqrt(delta))/(2*a);
        x2=((-b)-sqrt(delta))/(2*a);
        printf("%.1f\n" ,x1);
        printf("%.1f",x2);
        return 0;
    }else {
        //printf("delta<0\n");
       	//printf("%.2f\n" , delta);
        x1=((-b))/(2*a);
        //x2=((-b)))/(2*a);
        x11=sqrt(-delta)/(2*a);
        x1=x1*10;
        x1=(int)x1;
        x1=x1/10;
        x11=x11*10;
        x11=abs((int)x11);
        x11=x11/10;
        //printf("%d",x11);
        //x22=sqrt(-delta);
       	printf("%.1f+%.1fi\n" ,x1,x11);
        printf("%.1f-%.1fi" ,x1,x11);
       // if (x1==0.0) {
      //      printf("%.1fi\n" ,x11);
      //      printf("-%.1fi" ,x11);
      //      return 0;
     //   }else{

     //   return 0;
       // }
    }
}

