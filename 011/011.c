#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

int cut(char *s , char *p[]){
	int i=0;
	p[0]=strtok(s," ");
	while (p[i]!= NULL){
		i++;
		p[i]=strtok(NULL," ");
	//	printf("%s\n",p[i]);
	}
	return i;
}
void main(){
	int num1=0;
	char data[200],data1[50][200];
	int data2[200];
	char *p[100];
	//char ans[200],ans1[200],ans2[200]
	char w1[20];
	char w2[20];
	gets(data);
	num1=cut(data,p);
	scanf("%s",w1);
	scanf("%s",w2);
	int len1=0,len2=0,len=0;
	len1=strlen(w1);
	len2=strlen(w2);
	len=strlen(data);
	int i=0,j=0,k=0,match=0,yn=0,diff=0;
	int count=0;
	
	// part1
	for(i=0 ; i<num1 ;i++){		
		if(strcmp(p[i],w1)==0){
			printf("%s",w2);
		}else{
			printf("%s",p[i]);
		}
		printf(" ");
	}
	printf("\n");
	//part 2
 	for(i=0 ; i<num1 ;i++){		
		if(strcmp(p[i],w1)==0){
			printf("%s",w2);
			printf(" ");
			printf("%s",p[i]);
		}else{
			printf("%s",p[i]);
		}
		printf(" ");
	}
	printf("\n");
	//part 3
	for(i=0 ; i<num1 ;i++){		
		if(strcmp(p[i],w1)!=0){
			printf("%s",p[i]);
			printf(" ");
		}
		
	}
	printf("\n");
	//part4
	yn=0;
	strcpy(data1[0],p[0]);
	data2[0]=1;
	count=1;
	for(i=1 ; i<num1 ;i++){
		for(j=0 ; j<count ; j++){
			if(strcmp(p[i],data1[j])==0){
				data2[j]++;
				yn=1;
			}
				
		}
		if(yn==0){
			data2[j]=1;
			strcpy(data1[j],p[i]);
			count++;
		}	
		yn=0;
			
	}
	int temp=0;
	char ttp[100];
	for(i=0 ; i<count-1 ; i++){
		for(j=i+1 ; j<count ; j++){
			if(data2[i]<data2[j]){
				temp=data2[i];
				data2[i]=data2[j];
				data2[j]=temp;
				strcpy(ttp,data1[i]);
				strcpy(data1[i],data1[j]);
				strcpy(data1[j],ttp);
			}
		}
	}
	for(i=0 ; i<count-1 ; i++){
		for(j=i+1 ; j<count ; j++){
			if(data2[i]==data2[j] && strcmp(data1[i],data1[j])>0){
				temp=data2[i];
				data2[i]=data2[j];
				data2[j]=temp;
				strcpy(ttp,data1[i]);
				strcpy(data1[i],data1[j]);
				strcpy(data1[j],ttp);
			}
		}
	}	
	for(i=0 ; i<count ; i++){
		printf("%s %d\n",data1[i],data2[i]);
	}	
		
	}
	
