#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <ctype.h>

int isPrime (int n ){
	int i;
	for (i=2 ; i<n ; i++){
		if ((n%i)==0){
			return 0;
		}
	}
	return 1;
}

int f2 (int i){
	//printf("%d\n",i);
	int j=0;
	long summary=1;
	for (j=1 ; j<=i ; j++){
		summary=summary*j;
		//printf("%d\n",summary);
	}
	return summary;
}

void main (){
	int i,j,err,n = 0;
	long sum,adder=0;
	char num[50];
	scanf("%s",&num);
	while(i<strlen(num)){
		if(isdigit(num[i])==0){
			err=1;
			break;
		}
		i++;
	}
	n=atol(num); 
	if ((n <= 0)|| (n>=1000) || err==1 ){
		printf("E");
	}else{
		sum=0;
		for (i=2 ; i < n ; i++){
			if ((n%i)==0 && isPrime(i)==1){
				adder=f2(i);
				printf("%d,%d\n",i,adder);
				sum=sum+adder;				
				adder=0;
			}
		}
		printf("%d", sum);
	}
	return 0;
}
