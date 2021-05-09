#include <stdio.h>
int cut(char *s , char *p[]){
	int i=0;
	p[0]=strtok(s," ");
	while (p[i]!= NULL){
		i++;
		p[i]=strtok(NULL," ");
		//printf("%s\n",p[i]);
	}
	return i;
}
int n=0;
void main(){
	int m=0 ,i=0 ,j=0;
	scanf("%d",&m);
	n=m;
	int data[n][n];
	int path[n][n];
	for(i=0 ; i<n ; i++){
		for(j=0 ; j<n ; j++){
			scanf("%d",&data[i][j]);
			path[i][j]=data[i][j];
		}
	}
	path[1][1]=-1;
	compute(data,path,1,1);	 
	data[n-2][n-2]=8;
	for(i=0 ; i<n ; i++){ 
		for(j=0 ; j<n ; j++){
				if(data[i][j] == 1){
					printf("1 ");
				}else if(data[i][j] == 8){
					printf("# ");
				}else if(data[i][j] == 4){
					printf("* ");
				}else{
					printf("0 ");
				}
				
			}
			printf("\n");
		}
		
		
	
}

int compute(int data[][n],int path[][n],int i,int j){
	int a=0,b=0;
	int test=0;
	path[i][j]=1;
	if(i == n-2 && j == n-2){
		return 1;
	}
	if((data[i+1][j] == 0) && (path[i+1][j] == 0 ) ){
		a=compute(data,path,i+1,j);
		path[i+1][j]=0;
		if(a==1){
			data[i][j]=8;
			return 1;
		}	                     
	}else{
		test++;
	} 	
	if((data[i-1][j] == 0) && (path[i-1][j] == 0 ) ){
		a=compute(data,path,i-1,j);
		path[i-1][j]=0;
		if(a==1){
			data[i][j]=8;
			return 1;
		}	                     
	}else{
		test++;
	} 		   	
	if((data[i][j-1] == 0) && (path[i][j-1] == 0 ) ){
		a=compute(data,path,i,j-1);
		path[i][j-1]=0;
		if(a==1){
			data[i][j]=8;
			return 1;
		}	                     
	}else{ 
		test++;
	} 		
	if((data[i][j+1] == 0) && (path[i][j+1] == 0 ) ){
		a=compute(data,path,i,j+1);
		path[i][j+1]=0;
		if(a==1){
			data[i][j]=8;
			return 1;
		}	                     
	}else{
		test++;
	} 

          
	if(test >= 1){
		data[i][j]=4;
		return 0;
	}
}

