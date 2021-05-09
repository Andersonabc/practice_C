#include <stdio.h>
#include <stdlib.h>
#include <string.h>
# define PI 4
typedef struct circle{
	int radius;
}cir;
typedef struct rectangle{
	int wei;
	int hi;
}rect;
typedef struct square{
	int lon;
}squa;
typedef struct triangle{
	int lon1;
	int lon2;
	int lon3;
}tri;
void main(){
	int n=0,i=0,j=0,sum=0;
	char data[30],*p[10];
	char temp;
	scanf("%d ",&n);
	//fflush(stdin);
	cir x;
	rect y;
	squa z;
	tri k;
	for(i=0 ; i<n ; i++){
		j=0;
		gets(data);
		p[j]=strtok(data," ");
		while (p[j] != NULL){
			p[++j]=strtok(NULL," ");
		}
		temp=p[0][0];
		//fflush(stdin);
	//	printf("%c\n",temp);
		if(temp == 'C'){
			x.radius=atoi(p[1]);
			//printf("%d",x.radius);
			printf("%d",(2*PI*x.radius));
			sum+=(2*PI*x.radius);
		}else if(temp == 'R'){
			y.hi=atoi(p[1]);
			y.wei=atoi(p[2]);
			printf("%d",(2*(y.hi+y.wei)));
			sum+=2*(y.hi+y.wei);
		}else if(temp == 'S'){
			z.lon=atoi(p[1]);
			printf("%d",(4*z.lon));
			sum+= (4*z.lon);
		}else if(temp == 'T'){
			k.lon1=atoi(p[1]);
			k.lon2=atoi(p[2]);
			k.lon3=atoi(p[3]);
			printf("%d",(k.lon1+k.lon2+k.lon3));
			sum+=(k.lon1+k.lon2+k.lon3);		
		}
		//fflush(stdin);
		printf("\n");
	}
	printf("%d",sum);
}
