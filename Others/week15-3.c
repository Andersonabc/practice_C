#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void f1(int x1, int y1, int x2, int y2, double m, double b){
	//printf("f1\n");
	if(y1==y2){
		printf("y=%d",y1);	
	}else if(x1==x2) {
		printf("x=%d",x1);		
	}else if(m==(int)m && b>0){
		if(b==(int)b && m==1){
			printf("y=x+%d",(int)b);
		}else if (b==(int)b && m==-1){
			printf("y=-x+%d",(int)b);
		}else if(b==(int)b){
			printf("y=%dx+%d",(int)m,(int)b);
		}	
		else if (b!=(int)b && m==1){
			printf("y=x+%.2f",b);
		}else if (b!=(int)b && m==-1){
			printf("y=-x+%.2f",b);
		}else{
			printf("y=%dx+%.2f",(int)m,b);
		}		
	}else if(m==(int)m && b<0){
		if(b==(int)b && m==1){
			printf("y=x%d",(int)b);
		}else if (b==(int)b && m==-1){
			printf("y=-x%d",(int)b);
		}else if(b==(int)b){
			printf("y=%dx%d",(int)m,(int)b);
		}	
		else if (b!=(int)b && m==1){
			printf("y=x%.2f",b);
		}else if (b!=(int)b && m==-1){
			printf("y=-x%.2f",b);
		}else{
			printf("y=%dx%.2f",(int)m,b);
		}		
	}else if(m==(int)m && b==0){
		if(m==1){
			printf("y=x");
		}else if (m==-1){
			printf("y=-x");
		}else if(b==(int)b){
			printf("y=%dx%d",(int)m,(int)b);
		}			
	}else{
		if(b==(int)b && b>0){
			printf("y=%.2fx+%d",m,(int)b);
		}else if(b==(int)b && b<0){
			printf("y=%.2fx%d",m,(int)b);
		}else if(b==(int)b && b==0){
			printf("y=%.2fx",m);
		}
		else if (b!=(int)b && b<0) {
			printf("y=%.2fx%.2f",m,b);
		}else if (b!=(int)b && b==0) {
			printf("y=%.2fx",m);
		}
		else if(b!=(int)b && b>0){
			printf("y=%.2fx+%.2f",m,b);
		}
	}
	printf("\n");
}

void f2(int x1, int y1, int x2, int y2, int m1, int m2, int b1, int b2){
	
	//printf("f2\n");	
	if(y1==y2){
		printf("y=%d",y1);	
	}else if (x1==x2){
		printf("x=%d",x1);	
	}else if (m1%m2==0){
		if (b1%b2==0 && (b1*b2)>0){
			if(m1==m2){
				printf("y=x+%d",(b1/b2));
			}else if (m1==(-1*m2)){
				printf("y=-x+%d",(b1/b2));
			}else{
				printf("y=%dx+%d",(m1/m2),(b1/b2));
			}					
		}else if (b1%b2==0 && (b1*b2)<0){
			if(m1==m2){
				printf("y=x%d",(b1/b2));
			}else if (m1==(-1*m2)){
				printf("y=-x%d",(b1/b2));
			}else{
				printf("y=%dx%d",(m1/m2),(b1/b2));
			}					
		}else if (b1%b2==0 && (b1*b2)==0){
			if(m1==m2){
				printf("y=x");
			}else if (m1==(-1*m2)){
				printf("y=-x");
			}else{
				printf("y=%dx",(m1/m2));
			}					
		}else if (b1%b2!=0 && (b1*b2)>0){
			if(m1==m2){
				printf("y=x+%d/%d",abs(b1),abs(b2));
			}else if(m1==(-1*m2)){
				printf("y=-x+%d/%d",abs(b1),abs(b2));
			}else{
				printf("y=%dx+%d/%d",(m1/m2),abs(b1),abs(b2));
			}					
		}else if (b1%b2!=0 && (b1*b2)<0){
			if(m1==m2){
				printf("y=x-%d/%d",abs(b1),abs(b2));
			}else if(m1==(-1*m2)){
				printf("y=-x-%d/%d",abs(b1),abs(b2));
			}else{
				printf("y=%dx-%d/%d",(m1/m2),abs(b1),abs(b2));
			}	
		}else if (b1%b2!=0 && (b1*b2)==0){
			if(m1==m2){
				printf("y=x");
			}else if(m1==(-1*m2)){
				printf("y=-x");
			}else{
				printf("y=%dx",(m1/m2));
			}			
		}
	}else if (m1%m2!=0){
		if (b1%b2==0 && (b1*b2)>0){
			if((m1*m2)<0){
				printf("y=-%d/%dx+%d",abs(m1),abs(m2),(b1/b2));
			}else {
				printf("y=%d/%dx+%d",abs(m1),abs(m2),(b1/b2));
			}
		}else if (b1%b2==0 && (b1*b2)<0){
			if((m1*m2)<0){
				printf("y=-%d/%dx%d",abs(m1),abs(m2),(b1/b2));
			}else {
				printf("y=%d/%dx%d",abs(m1),abs(m2),(b1/b2));
			}			
		}else if (b1%b2==0 && b1==0){
			if((m1*m2)<0){
				printf("y=-%d/%dx",abs(m1),abs(m2));
			}else {
				printf("y=%d/%dx",abs(m1),abs(m2));
			}					
		}else if (b1%b2!=0 && (b1*b2)>0){
			if((m1*m2)<0){
				printf("y=-%d/%dx+%d/%d",abs(m1),abs(m2),abs(b1),abs(b2));
			}else {
				printf("y=%d/%dx+%d/%d",abs(m1),abs(m2),abs(b1),abs(b2));
			}						
		}else if (b1%b2!=0 && (b1*b2)<0){
			if((m1*m2)<0){
				printf("y=-%d/%dx-%d/%d",abs(m1),abs(m2),abs(b1),abs(b2));
			}else {
				printf("y=%d/%dx-%d/%d",abs(m1),abs(m2),abs(b1),abs(b2));
			}
		}else if (b1%b2!=0 && b1==0){
			if((m1*m2)<0){
				printf("y=-%d/%dx",abs(m1),abs(m2));
			}else {
				printf("y=%d/%dx",abs(m1),abs(m2));
			}				
		}
	}
}

void main(){
	double x1,y1,x2,y2,m,b=0;
	int m1,m2,b1,b2=0;
	scanf("%lf %lf %lf %lf",&x1,&y1,&x2,&y2);
	//printf("%f\n",x1);
	//printf("%d\n",(int)x1);
	if (x1 != (int)x1 || y1 != (int)y1 || x2 != (int)x2 || y2 != (int)y2 ||((x1==x2)&&(x2==y1)&&(y1==y2)) ){
		printf("Error!");
	}else{
		m1=((int)y1-(int)y2);
		m2=((int)x1-(int)x2);
		b1=((int)x2*(int)y1-(int)x1*(int)y2);
		b2=((int)x2-(int)x1);
		m=(y1-y2)/(x1-x2);
		b=(x2*y1-x1*y2)/(x2-x1);
		f1(x1,y1,x2,y2,m,b);
		f2(x1,y1,x2,y2,m1,m2,b1,b2);
	}
}
