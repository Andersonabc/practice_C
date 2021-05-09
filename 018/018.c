#include <stdio.h>
#include <math.h>
void decimal_to_binary(int n, int length){
	//printf("decimal_to_binary\n");
	int i=0,j=0,k=0;
	k=pow(2,length-1);
	for (i=0 ; i<length ; i++){
		//printf("%d   %d\n",k,n);
		if((n/k)==1){
			printf("1");
			n=n%k;
		}else{
			printf("0");
		}
		k=pow(2,length-2-i);		
	}
	printf("\n");
}
int binary_to_decimal(const char* binary, int length){
	int i=0,j=0,k=0;
	int sum=0;
	for (i=0 ; i<length ; i++){
		if(binary[i] == '1'){
			sum+=pow(2,length-1-i);
			//printf("%d  %d\n",i,sum);
		}
	}
	//printf("%d",sum);
	return sum;
}
int loopCircuit(int n){
	if(n==0 || n==1) return 0;
	if((n%2)==0){
		n=n/2;
		return loopCircuit(n)+1;
	}
	if((n%2)==1){
		n=(n+1)/2;
		return loopCircuit(n)+1;
	}
}
void main(){
	int i=0,j=0,k=0,count=0;
	char firstdata[8];
	int check=1;
	int num=0;
	scanf("%s",firstdata);
	scanf("%d",&check);
	num=binary_to_decimal(firstdata,8);
//	printf("decimal=%d\n",num);
	for (i=0 ; i<=num ;i++){
		count+=loopCircuit(i);
	}
//	printf("coumt=%d\n",count);
	decimal_to_binary(count,11);
	
	//printf(" %d",count);
	while (check == 0){
		int num=0,count=0;
		scanf("%s",firstdata);
		scanf("%d",&check);
		num=binary_to_decimal(firstdata,8);
		for (i=0 ; i<=num ;i++){
			count+=loopCircuit(i);
		}	
		decimal_to_binary(count,11);
	}
}
