#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
void Reverse(char t[100])//字串反轉 
{
     int str_length,i,j;
     char temp;
     for(i=0;;i++)   //找尋字串長度
        if (t[i]=='\0') break;
     str_length=i;
     for(i=0;i<str_length/2;i++)  //反轉字串    
     {
         temp=t[i];
         t[i]=t[str_length-i-1];
         t[str_length-i-1]=temp;
     }    
}
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

void main (){
	int i=0,j=0,z=0,no=0,a=0,num1=0,num2=0,ans1=0,x=0;
	int len=0;
	char ordata1[1000]; 
	char *p[100];
	char data2[1000];
	int times[5]; //字母出現幾次
	for(i=0 ; i<5 ; i++){
		times[i]=0;
	} 
	char pdata[1000];
	
	char password1[10][10]; 
	char password2[1000]; //第二部分密碼 
	gets(ordata1);
	gets(data2);
	strcpy(pdata,data2);
	num1=cut(ordata1,p);
	a=0;
//	printf("-----");
	//part  1
	for(i=0;i<num1;i++){
		for(j=0 ; j<strlen(p[i]) ; j++){
			if(p[i][j]>='0' && p[i][j]<='9'){
				password1[a][j]=p[i][j];
				no=1;			
			}
		}
		password1[a][j]='\0';
		if(no==1){
			a++;
			no=0;
		}
	}
	
	for (i=0 ; i<a ; i++){
		Reverse(password1[i]);
		ans1+=(atoi(password1[i]));		
	}
	if(ans1/1000 == 0){
		printf("0");
		if(ans1/100 == 0){
			printf("0");
			if(ans1/10 == 0){
				printf("0");
				if(ans1/1 == 0){
				printf("0");
	}
	}
	}
	}
	if(ans1/10000 >= 1){
		ans1%=10000;
	} 	
	printf("%d",ans1);		
	//patr 2

	ans1=0;
	password2[0]=data2[0];
	times[0]=1;

	x=strlen(data2);

	for (i=1 ; i<x ; i++){
		for(j=0 ; j<=ans1 ; j++){
			if(data2[i]==password2[j]){
				times[j]++;
				no=1;
			}
		}
		if (no==0 &&((data2[i]>='a'&&data2[i]<='z')||(data2[i]>='A'&&data2[i]<='Z'))&&data2[i]!=' ' ){		
			password2[j]=data2[i];
			times[j]=1;
			ans1++;
		}
		no=0;
	}	
	for(i=0 ; i<strlen(pdata) ; i++){
		for(j=0 ; j<strlen(password2) ; j++){
			if(pdata[i]==password2[j] && times[j]<10 && times[j]>0){				
				printf("%d",times[j]);
				password2[j]='@';
				break;
			}else if (pdata[i]>='0' && pdata[i]<='9'){
				printf("%c",pdata[i]);
				break;				

			}
		}
		
	}



}
