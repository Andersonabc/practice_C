#include <stdio.h>
#include <stdlib.h>

/*void horizontal(int *data);
void horizontal (int *data){
	int i ,j ,k ,front ,back=0;

	
}*/

void main(){
	int i,j,k=0;
	int data[10][10];
	int front ,back=0;
	for(i=0 ; i<=9 ; i++){
		for(j=0 ; j<=9 ; j++){
			scanf("%d",&data[i][j]);
		}
	}

/*	for(i=0 ; i<=9 ; i++){
		for(j=0 ; j<=9 ; j++){
			printf("%d",data[i][j]);
		}
		printf("\n");
	}*/
//horizontal	
	for(i=0 ; i<=9 ; i++){
		for(j=0 ; j<=9 ; j++){
			front=0;
			back=0;
			if(data[i][j] == 0){
				for(k=1 ; k<=4 ; k++){
					if(data[i][j+k]==1 && j+k<10 ){
						front++;
					}else{
						break;
					}
				}			
				for(k=1 ; k<=4 ; k++){
					if(data[i][j-k]==1 && j-k > -1){
						back++;
					}else {
						break;
					}									
				}
		}
		if((front+back)>=4){
	 		data[i][j]=2;
			}
		}
	}
// vertical	
	for(i=0 ; i<=9 ; i++){
		for(j=0 ; j<=9 ; j++){
			front=0;
			back=0;
			if(data[j][i] == 0){
				for(k=1 ; k<=4 ; k++){
					if(data[j+k][i]==1 && j+k<10 ){
						front++;
					}else{
						break;
					}
				}			
				for(k=1 ; k<=4 ; k++){
					if(data[j-k][i]==1 && j-k > -1){
						back++;
					}else {
						break;
					}									
				}
		}
		if((front+back)>=4){
	 		data[j][i]=2;
			}
		}
	}	
//slash
	for(i=0 ; i<=9 ; i++){
		for(j=0 ; j<=9 ; j++){
			front=0;
			back=0;
			if(data[i][j] == 0){
				for(k=1 ; k<=4 ; k++){
					if(j+k<10 && i+k < 10 && data[i+k][j+k]==1){
						front++;
					}else{
						break;
					}
				}			
				for(k=1 ; k<=4 ; k++){
					if(j-k > -1 && i-k > -1 && data[i-k][j-k]==1){
						back++;
					}else {
						break;
					}									
				}
		}
		if((front+back)>=4){
	 		data[i][j]=2;
			}
		}
	}	
//slash
	for(i=0 ; i<=9 ; i++){
		for(j=0 ; j<=9 ; j++){
			front=0;
			back=0;
			if(data[i][j] == 0){
				for(k=1 ; k<=4 ; k++){
					if(data[i-k][j+k]==1 && j+k<10 && i-k >-1){
						front++;
					}else{
						break;
					}
				}			
				for(k=1 ; k<=4 ; k++){
					if(data[i+k][j-k]==1 && i+k < 10 && j-k > -1){
						back++;
					}else {
						break;
					}									
				}
		}
		if((front+back)>=4){
	 		data[i][j]=2;
			}
		}
	}			
/*	
	printf("figure2\n");
	for(i=0 ; i<=9 ; i++){
		for(j=0 ; j<=9 ; j++){
			printf("%d",data[i][j]);
		}
		printf("\n");
	}*/	
	for(i=0 ; i<=9 ; i++){
		for(j=0 ; j<=9 ; j++){
			if (data[i][j]==2){
				printf("%d %d",i,j);
				printf("\n");
		 	}
		}
	}
}

