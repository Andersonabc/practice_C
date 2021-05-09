#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void main(){
	int r1=0,r2=9,c1=0,c2=0,i=0,j=0,k=0,sum=0;
	scanf("%d %d",&r1,&c1);
	int matrix1[r1][c1];
	for (i=0;i<r1;i++){
		for(j=0;j<c1;j++){
			scanf("%d",&matrix1[i][j]);
		}
	}
	scanf("%d %d",&r2,&c2);
	int matrix2[r2][c2];
	for (i=0;i<r2;i++){
		for(j=0;j<c2;j++){
			scanf("%d",&matrix2[i][j]);
		}
	}
	if((r1!=r2) || (c1!=c2)){
		printf("ERROR");
		printf("\n");
		printf("ERROR");
	}else{
		for(i=0;i<r1;i++){
			for(j=0;j<c1;j++){
				printf("%d ",(matrix2[i][j]+matrix1[i][j]));
			}
			printf("\n");
		}
		printf("\n");
		for(i=0;i<r1;i++){
			for(j=0;j<c1;j++){
				printf("%d ",(matrix1[i][j]-matrix2[i][j]));
			}
			printf("\n");
		}		
	}
	printf("\n");
	if(c1==r2){
		for(i=0;i<r1;i++){
			for(j=0;j<c2;j++){
				sum=0;
				for(k=0;k<c1;k++){
					sum+=matrix1[i][k]*matrix2[k][j];
				}
				printf("%d ",sum);
			}
			printf("\n");
		}
	}else{
		printf("ERROR");
	}
	
}
