#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void compute(int x1, int y1, int x2, int y2, int *perimeter, int *area){
	int newarea,newperimeter=0;
	newarea=(abs(x1-x2))*(abs(y1-y2));
	newperimeter=2*((abs(x1-x2))+(abs(y1-y2)));
//	printf("%d\n",*area);
//	printf("%d\n",newarea);
	if (*perimeter < newperimeter){
		*perimeter=newperimeter;
	//	printf("*perimeter < newperimeter\n");
	//	printf("%d\n",*perimeter);
	}
	if(*area < newarea){
		*area=newarea;
	//	printf("*area < newarea\n");
	//	printf("%d\n",*area);
	}
		
}
int check(int x1, int y1, int x2, int y2){
	if (x1==x2 || y1==y2){
		return 1;
	}else{
	return 0;
}}

void main(){
	int x1,x2,y1,y2,err=0;
	int area=0;
	int perimeter=0;
	scanf("%d",&x1);
	while (x1!=-1 && err!=1){
		scanf("%d %d %d", &y1, &x2, &y2);
		err=check(x1,y1,x2,y2);
		if (err==1) break;
		compute(x1,y1,x2,y2,&perimeter,&area);
		//printf("%d\n",area);
		scanf("%d",&x1);
	}

	if (err==1){
		printf("Error");
	}else{
	//	printf("printanswer\n");
		printf("%d\n",area);
		printf("%d",perimeter);
	}



}
