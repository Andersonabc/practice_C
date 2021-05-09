#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
void sorting(int *a, int n, int **acti){ 
    int j, k, tmp;
    for(j=1;j<n;j++)
        for(k=0;k<n-j;k++){
            if(a[k+1]==0) break;
            if(acti[a[k]-1][1]>acti[a[k+1]-1][1]){
                tmp = a[k];
                a[k] = a[k+1];
                a[k+1] = tmp;
            }
        }
}
int Sameornot(int *a, int n){ 
    int i, j;
    for(i=0;i<n-1;i++){
        for(j=i+1;j<n;j++) {
        	if(a[i]==a[j] && a[i]!=0) return 0;
		}   	
	}			
    return 1;
}

int countla(int *a, int i, int **acti){
    int Max = 1;
	int temp = a[i];
    for(i=i-1;i>=0;i--){ 
        if(acti[temp-1][1]<acti[a[i]-1][2]) Max++;
    }
    return Max;
}
int assign(int *a, int k, int i){
    int j=0;
    while(j<k){
        if(i==0) return 1;
        if(i%10==0 || i%10>k) return 0; 
        a[j++] = i%10;
        i /= 10;
    }
    return 1;
}
void Reverse(char t[100]) 
{
     int str_length,i,j;
     char temp;
     for(i=0;;i++)   
        if (t[i]=='\0') break;
     str_length=i;
     
     for(i=0;i<str_length/2;i++)      
     {
         temp=t[i];
         t[i]=t[str_length-i-1];
         t[str_length-i-1]=temp;
     }     
     
}
int getmroom(int **a, int n, int m, int length, int **acti){
	int i=0,j=0,count=0,ans=0;
	int mroom=0;
    while(i<length){
        sorting(a[i], n, acti); 

        for(j=0;j<n;j++){ 
            if(a[i][j]==0) break;
            mroom = countla(a[i], j, acti);
            if(mroom>m) break;
        }

        if(mroom>m) a[i][0] = -1; 
        else{
            for(j=0;j<n;j++) if(a[i][j]!=0) count++; 
            a[i][10] = count; 
        }

        if(a[i][0]!=-1 && ans < count) ans = count; 
        count = 0;
        i++;
    }
    return ans;	
	
}
int gen(int **a, int n){ 
    int length=0, i;
	int coun=pow(10, n);
    for(i=1;i<coun;i++)
	{
		if(assign(a[length], n, i) && Sameornot(a[length], n)) length++; 
	}	 
    return length;
}
void swa (char str[100][100] , int count ){
	char temp[100];
	int i,j;
	for(i=0; i<count ; i++){
		for ( j = i + 1 ; j < count ; j++  ) //i + 1
          { 
          	printf("%d %d \n",i,j);
              if ( strcmp ( str [ i ] , str [ j ] ) > 0 ) 
              { 
                  strcpy ( temp , str [ i ] ) ; strcpy ( str [ i ] , str [ j ] ) ; strcpy ( str [ j ] , temp ) ; } 
          } 	
	}

}
int getmtime(int **a, int n, int m, int length, int **acti){
    int i=0, j=0, ans=0, count=0;
    while(i<length){
        if(a[i][0]==-1){ 
            i++;
            continue;
        }

        for(j=0;j<n;j++){
            if(a[i][j]==0) break;
            count += (acti[a[i][j]-1][2] - acti[a[i][j]-1][1]);
        }

        a[i][11] = count; 
        if(ans<count) ans = count; 

        count = 0;
        i++;
    }
    return ans;
}
void haha(){
	int j=0, sum=0;
	for (j=0 ; j<=1000 ; j++){
		sum*=j;
	}
}
void main(){
	int i, j, n, m,length;
	int temp;
	int mroom,mtime;
	int **data,**acti;
	scanf("%d", &m);
    scanf("%d", &n);
    temp=pow(10, n);
    data = (int **)malloc(temp * sizeof(int *));
    acti = (int **)malloc(n * sizeof(int *));
    for(i=0;i<temp;i++) data[i] = (int *)calloc(12, sizeof(int));
    for(i=0;i<n;i++) acti[i] = (int *)calloc(3, sizeof(int));
	length=gen(data,n);
	for(i=0;i<n;i++) scanf("%d %d %d", &acti[i][0], &acti[i][1], &acti[i][2]);
	
	mroom=getmroom(data, n, m, length, acti);
	mtime=getmtime(data, n, m, length, acti);
	//haha();
	printf("%d\n",mtime);
	printf("%d",mroom);
	
}
