#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void mode_1 (int line){
	int i,j = 0;
	for (i=1 ; i<=(line/2)+1 ; i++){
		for (j=0 ; j<i ; j++){
			printf("*");
		}
		printf("\n");
	}
	for(i=1 ; i<=(line/2) ; i++){
		for(j=1 ; j<=(line/2)+1-i ; j++){
			printf("*");
		}
		printf("\n");
	}
	
}
void mode_2(int line){
	int i,j=0;
	for (i=1 ; i<=(line/2)+1 ; i++){
		for (j=1 ; j<=(line/2)+1-i ; j++){
			printf(".");
		}
		for (j=0 ; j<i ; j++){
			printf("*");
		}
		printf("\n");
	}
	for(i=1 ; i<=(line/2) ; i++){
		for (j=1 ; j<=i ; j++){
			printf(".");
		}
		for(j=1 ; j<=(line/2)+1-i ; j++){
			printf("*");
		}
		printf("\n");
	}		
	}
void mode_3(int line){
	int i,j=0;
	for (i=(line/2) ; i>=0 ; i--){
		for (j=1 ; j<=i ; j++){
			printf(".");
		}
		for(j=1 ; j<=(line-(2*i)) ; j++){
			printf("*");
		}
		printf("\n");
	}
	for (i=1 ; i<=(line/2) ; i++){
		for (j=1 ; j<=i ; j++){
			printf(".");
		}
		for (j=1 ; j<=(line-(2*i)) ; j++){
			printf("*");
		}
		printf("\n");
	}
}	
int main(){
	int mode,line=0;
	scanf("%d",&mode);
	scanf("%d",&line);
	if (mode == 1){
		mode_1(line);
	}else if(mode == 2){
		mode_2(line);
	}else if (mode == 3){
		mode_3(line);
	}else{
		printf("ERROR");
	}
	return 0;
}
