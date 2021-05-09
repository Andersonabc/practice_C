#include <stdio.h>
int mini=0;
int cut(char *s , char *p[]){
	int i=0;
	p[0]=strtok(s," ");
	while (p[i]!= NULL){
		i++;
		p[i]=strtok(NULL," ");
	}
	return i;
}

void main(){
	mini=999999;
	int n=0 ,m=0 ,i=0 ,j=0;
	scanf("%d",&n);
	scanf("%d",&m);
	int data[n][9];
	int path[n][9];
	for(i=0 ; i<n ; i++){
		for(j=0 ; j<m ; j++){
			scanf("%d",&data[i][j]);
			path[i][j]=0;
		}
	}
	path[0][0]=-1;
	compute(data,path,0,0,m,n,0);	
	printf("%d",mini); 

}
int compute(int data[][9],int path[][9],int i,int j,int m,int n,int sum){

	if(sum > mini) return 0;
	if(i == n-1 && j == m-1){
		if(sum < mini){
			mini = sum;	
	}
	return 0;
}
		   
		
	if(detection(path , i , j+1 , n , m)){
		path[i][j+1]=-1;
		compute(data,path,i,j+1,m,n,sum+data[i][j+1]);
		path[i][j+1]=0;
	}
	if(detection(path , i , j-1 , n , m)){
		path[i][j-1]=-1;
		compute(data,path,i,j-1,m,n,sum+data[i][j-1]);
		path[i][j-1]=0;		    
	}
	if(detection(path , i+1 , j , n , m)){
		path[i+1][j]=-1;
		compute(data,path,i+1,j,m,n,sum+data[i+1][j]);
		path[i+1][j]=0;		                      
	}
	if(detection(path , i-1 , j , n , m)){
		path[i-1][j]=-1;
		compute(data,path,i-1,j,m,n,sum+data[i-1][j]);
		path[i-1][j]=0;		                      
	}           
	return 0;
}

int detection (int path[][9] ,int i,int j,int n ,int m){

	if(i>=n || j>=m || i<0 || j<0 || path[i][j]==-1) return 0;
	else{
		return 1;
	}
}
