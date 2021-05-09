#include <stdio.h>
#include <stdlib.h>
int testla(int *gogonumber);
int testla(int *gogonumber){
	int i,j,ex=0;
	/*for (i=0;i<9;i++){
		printf("%d",gogonumber[i]);
	}*/
//	printf("\n");
	for (i=1 ; i<=9 ; i++){
		for (j=0 ; j<=8 ; j++){
			if (i == gogonumber[j])
				ex+=1;
		}
		if (ex!=1)
			return 1;
		ex=0;
	}
	return 0;
}
void main(){
	int data[9][9];
	int gogonumber[9];
	int i,j,k,w,x,err=0;
	for (i=0;i<9;i++){
		scanf("%d %d %d %d %d %d %d %d %d",&data[i][0],&data[i][1],&data[i][2],&data[i][3],&data[i][4],&data[i][5],&data[i][6],&data[i][7],&data[i][8]);
	}	
	//err=test(gogonumber);
	for (i=0 ; i<=8 ; i++){
		x=0;
		for (j=0 ; j<=8 ; j++){
			gogonumber[x]=data[i][j];
			x+=1;
		}
		if(testla(gogonumber)==1){
			printf("No");
			return;			
		}
		
	}	
	
	for (i=0 ; i<=8 ; i++){
		x=0;
		for (j=0 ; j<=8 ; j++){
			gogonumber[x]=data[j][i];
			x+=1;
		}
		if(testla(gogonumber)==1){
			printf("No");
			return;			
		}		
	}
		
	for (i=0 ; i<=6 ; i+=3){
		for (j=0 ; j<=6 ; j+=3){
			x=0;
			for(k=i ; k<=i+2 ; k++){
				for(w=j ; w<=j+2 ; w++){
					gogonumber[x]=data[k][w];
					x+=1;
				}
			}
			if(testla(gogonumber)==1){
				printf("No");
				return;			
			} 		
		}
	}

	printf("Yes");	

}
