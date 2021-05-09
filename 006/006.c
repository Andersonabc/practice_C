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
     //str_length=42;
     for(i=0;i<str_length/2;i++)  //反轉字串    
     {
         temp=t[i];
         t[i]=t[str_length-i-1];
         t[str_length-i-1]=temp;
     }     
     
}
void minus(char a[42],char b[42],int blank){
	int minusans[42];
	int bit=0,i=0,frontlon=0,backlon=41,pp=0;
	for(i=41;i>=0;i--){		
		minusans[i]=(a[i]-'0')-(b[i]-'0')-bit;
		if(minusans[i]<0){
			bit=1;
			minusans[i]+=10;
		}else{
			bit=0;
		}
	}

	for(i=0;i<=41;i++){
		if (minusans[i]==0){
			frontlon+=1;
		}else{
			break;
		}
	}
	for(i=41;i>=0;i--){
		if (minusans[i]==0){
			backlon-=1;			
		}else{
			break;
		}
	}
	if(frontlon >= 21){
		frontlon=21;
	}	
	pp=backlon-blank+1;	
	if(pp<=22){
		pp=22;
	}
	if(backlon<=21){
		backlon=21;
	}		
	for (i=frontlon;i<=backlon;i++){
		if(i==pp){
			printf(".");
		}
		printf("%d",minusans[i]);	
	}		
}

void plus(char num1[42],char num2[42],int blank){
	int plusans[42];
	int pp=0,i=0,j=0;	
	for(i=0;i<42;i++){
		plusans[i]=(num1[i]-'0')+(num2[i]-'0');
	}
	for(i=41;i>=0;i--){
		if(plusans[i]>=10){
			plusans[i-1]+=plusans[i]/10;
			plusans[i]=plusans[i]%10;
						
		}
	}

	int frontlon=0,backlon=41;
	for(i=0;i<=41;i++){
		if (plusans[i]==0){
			frontlon+=1;
		}else{
			break;
		}
	}
	if(frontlon >= 21){
		frontlon=21;
	}
	for(i=41;i>=0;i--){
		if (plusans[i]==0){
			backlon-=1;
		}else{
			break;
		}
	}
	pp=backlon-blank+1;	
	if(pp<=22){
		pp=22;
	}	
	if(backlon<=21){
		backlon=21;
	}

	for(i=frontlon ; i<=backlon ; i++){
		if(i==pp){
			printf(".");
		}
		printf("%d",plusans[i]);
	}			
}
void main(){
	int no1=0,no2=0,i=0,j=0,point1=0,point2=0,blank1=0,blank2=0,blank=0,a=0,b=0;
	char num1[42];
	char num2[42];
	char t1[46];
	char t2[46];	
	for(i=0 ; i<46 ; i++){	
		t2[i]='0';
		t1[i]='0';
	}		
	char a1[21];
	char a2[21];
	char b1[21];
	char b2[21];
	for(i=0 ; i<21 ; i++){
		a1[i]='0';
		a2[i]='0';
		b1[i]='0';
		b2[i]='0';
	}
 	int timesans[100];
	scanf ("%s",num1);
	scanf ("%s",num2);	
	
	if(num1[0]=='-'){
		no1=1;
		for(i=0 ; i<strlen(num1) ; i++){
			num1[i]=num1[i+1];
		}
	}
	if(num2[0]=='-'){
		no2=1;
		for(i=0 ; i<strlen(num2) ; i++){
			num2[i]=num2[i+1];
		}
	}
	//字串處理 
	point1=strstr(num1,".")-num1;
	blank1=strlen(num1)-point1-1;
	point2=strstr(num2,".")-num2;
	blank2=strlen(num2)-point2-1;

	for(i=0 ; i<point1 ; i++){
		a1[22-point1+i]=num1[i]; 
		t1[46-strlen(num1)+i]=num1[i];		
	} 	
	for (i=0 ; i<point2 ; i++){
		b1[22-point2+i]=num2[i];
		t2[46-strlen(num2)+i]=num2[i];		
	}
	
	for(i=point1+1 ; i<strlen(num1) ; i++){
		t1[45-strlen(num1)+i]=num1[i];
		a2[j]=num1[i];
		j++;
	}	
	j=0;
	for(i=point2+1 ; i<strlen(num2) ; i++){
		t2[45-strlen(num2)+i]=num2[i];
		b2[j]=num2[i];
		j++;
	}
	for(i=0 ; i<strlen(t1) ; i++){  //t1 t2為乘法前後補0 並向右對齊處理後之字串 
		printf("%c",t1[i]);
	}
	printf("\n");
	for(i=0 ; i<strlen(t2) ; i++){
		printf("%c",t2[i]);
	}
	printf("\n");
	for(i=0 ; i<strlen(a1) ; i++){   //字串前後部分合起來 
		num1[i]=a1[i];
	}

	for(i=0 ; i<strlen(a2) ; i++){
		num1[strlen(a1)+i]=a2[i];
	}
	for(i=0 ; i<strlen(b1) ; i++){
		num2[i]=b1[i];
	}
	for(i=0 ; i<strlen(b2) ; i++){
		num2[strlen(b1)+i]=b2[i];
	}	
		
	if(blank1>blank2){
		blank=blank1;
	}else if(blank1<blank2){
		blank=blank2;
	}else{
		blank=blank2;
	}

	for(i=0 ; i<45 ; i++){
		if(num1[i]>num2[i]){
			a=1;b=0;
			break;
		}else if (num1[i]<num2[i]){
			a=0;b=1;
			break;
		}else if(num1[i]=num2[i]){
			a=0;b=0;
		}
	}
	if(no1==1 && no2==0){
		if(a==1 && b==0){
			printf("-");
			minus(num1,num2,blank);
			printf("\n");
			printf("-");
			plus(num1,num2,blank);
			printf("\n");
			printf("-"); 
		}else if(a==0 && b==1){
			minus(num2,num1,blank);
			printf("\n");
			printf("-");
			plus(num1,num2,blank);
			printf("\n");
			printf("-");
		}
	}else if(no1==0 && no2==1){
		if(a==1 && b==0){
			minus(num1,num2,blank);
			printf("\n");
			plus(num1,num2,blank);
			printf("\n");
			printf("-"); 
		}else if(a==0 && b==1){
			printf("-"); 
			minus(num2,num1,blank);
			printf("\n");
			plus(num1,num2,blank);
			printf("\n");
			printf("-");
		}		
	}else if(no1==0 && no2==0){
		if(a==1 && b==0){
			plus(num1,num2,blank);
			printf("\n");
			minus(num1,num2,blank);
			printf("\n"); 
		}else if(a==0 && b==1){
			plus(num2,num1,blank);
			printf("\n");
			printf("-");
			minus(num2,num1,blank);
			printf("\n");
		}		
	}else if(no1==1 && no2==1){
		if(a==1 && b==0){
			printf("-");
			plus(num1,num2,blank);
			printf("\n");
			printf("-");
			minus(num1,num2,blank);
			printf("\n"); 
		}else if(a==0 && b==1){
			printf("-");
			plus(num2,num1,blank);
			printf("\n");
			minus(num2,num1,blank);
			printf("\n");
		}		
	}
	
	//乘法
	Reverse(t1);
	Reverse(t2);
	for(i=0 ; i<strlen(t1)-1; i++){
		t1[i]=t1[i+1];
	}
	for(i=0 ; i<strlen(t2)-1; i++){
		t2[i]=t2[i+1];
	}		

	for(i=0 ; i<100 ; i++){
		timesans[i]=0;
	}
	
	for (i=0 ; i<45 ; i++){
		for(j=0 ; j<45 ; j++){
			timesans[i+j]+=(t1[i]-'0')*(t2[j]-'0');
		}
	}
	for(i=0;i<100;i++){
		if(timesans[i]>=10){
			timesans[i+1]+=timesans[i]/10;
			timesans[i]=timesans[i]%10;				
		}
	}	
	int lon=99;
	for(i=99 ; i>=0 ; i--){
		if(timesans[i]==0){
			lon--;
		}else{
			break;
		}

	}
	blank=blank1+blank2-1;

	for(i=lon ; i>=0 ; i--){
		if(i==blank){
			printf(".");
		}
		printf("%d",timesans[i]);
	}

	
} 
