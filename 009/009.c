#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

void main (){
	int i = 0 , j = 0 , k=0 , x = 0 , y = 0 , start=0 ,max=0;
	char data1[100];
	char data2[100];
	int len1=0 , len2=0;
	scanf("%s",data1);
	scanf("%s",data2);
	len1=strlen(data1);
	len2=strlen(data2);
	char ans[100];
	for(i=0 ; i<len1 ; i++){
		for(j=0 ; j<len2 ; j++){
			while(data1[i+k] == data2[j+k] && data1[i+k]!='\0' && data2[j+k]!='\0'){
				k++;
				} 
			if(k>x){
				x=k;
				start=i;
				}
			k=0;					
		}			
	}
	max=start+x;
	for(i=start ; i<max ; i++){
		printf("%c",data1[i]);
	}
}

