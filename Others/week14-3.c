#include <stdio.h>
#include <stdlib.h>

void main(){
	long num1,base1,err,i=0;
	char num[50],base[50];
	char st_digit[] = "0123456789ABCDEF";
	//char str[] = {"0", "1", "2", "3","4","5","6","7","8","9","A","B","C","D","E"}; 
	long distance=0;
	char ans[50]={0};
	scanf("%s %s",&base,&num);
   	while(num[i]!='\0'){
		if(isdigit(num[i])==0){
			err=1;
			break;
		}
		i++;
	}
	i=0;
	while(base[i]!='\0'){
		if(isdigit(base[i])==0){
			err=1;
			break;
		}
		i++;
	}
	num1=atol(num);
	base1=atol(base);		
	//printf("%d\n", num1);
	//printf("%d", base1);
	if (base1 <2 || base1 >16 || num1 <0 || num1 >1000000000 ){
		err=1;
	}
	if (err==1){
		printf("E");
	}else{
		while (num1!=0){
			ans[distance]=st_digit[(num1%base1)];
			//printf("%c\n",ans[distance]);
			num1=num1/base1;
			distance++;
		}
		for	(i=distance-1 ; i>=0 ; i--){
			printf("%c", ans[i]);
		}
	}
	
}
