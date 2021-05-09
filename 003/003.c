#include <stdio.h>
#include <stdlib.h>
#include <math.h>
void Reverse(char t[100])//字串反轉 
{
     int str_length,i,j;
     char temp;
     str_length=60;
     for(i=0;i<str_length/2;i++)  //反轉字串    
     {
         temp=t[i];
         t[i]=t[str_length-i-1];
         t[str_length-i-1]=temp;
     }    
}

void minus(char a[60],char b[60]){
	int minusans[60];
	int bit=0,i=0,lon=0;
	for(i=59;i>=0;i--){		
		minusans[i]=(a[i]-'0')-(b[i]-'0')-bit;
		if(minusans[i]<0){
			bit=1;
			minusans[i]+=10;
		}else{
			bit=0;
		}
		//printf("running %d\n",minusans[i]);
	}
	lon=0;
	for(i=0;i<=59;i++){
		if (minusans[i]==0){
			lon+=1;
		}else{
			break;
		} 
	}
	//printf("%d\n",lon);	
	for (i=lon;i<=59;i++){
		printf("%d",minusans[i]);	
	}		
}

void putin(char x[60],char pre[60],int *len){
	int i=0,j=0,length1=0;
	for(i=0;i<=60;i++){
		if (pre[i]=='\0'){
			//pre[i]='0';
			break;
		}else{
			length1+=1;
		}
	}
	
	*len=length1;
	for(i=length1-1;i>=0;i--){
		x[59-j]=pre[i];
		j++;		
	}
}
void main(){
	int length1=0,length2=0,lon=0;
	int i=0,j=0,w=0;
	char pre1[60];
	char pre2[60];
	char num1[60]={'0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0'};
	char num2[60]={'0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0'};
	int plusans[60];	
	int minusans[60];
	int timeans[360];
	for (i=0;i<360;i++){
		timeans[i]=0;
	}
	scanf("%s",pre1);
	scanf("%s",pre2);
	//printf("test  %c\n",num1[6]);
	putin(num1,pre1, &length1);
	putin(num2,pre2, &length2);
	//printf("%s\n",num1);
	//加法 
	for(i=0;i<60;i++){
		plusans[i]=(num1[i]-'0')+(num2[i]-'0');
	}
	for(i=59;i>=0;i--){
		if(plusans[i]>=10){
			plusans[i-1]+=plusans[i]/10;
			plusans[i]=plusans[i]%10;
						
		}
	}
	for(i=0;i<=59;i++){
		if (plusans[i]==0){
			lon+=1;
		}else{
			break;
		}
	}	
	for (i=lon;i<=59;i++){
		printf("%d",plusans[i]);	
	}
	printf("\n");
	//減法 
	w=0;
	if(length1>length2){
		minus(num1,num2);
	}else if(length1<length2){
		printf("-");
		minus(num2,num1);
	}else if(length1==length2){
		for(i=60-length1;i<60;i++){
			if(num1[i]>num2[i]){
				minus(num1,num2);
				break;
			}else if(num1[i]<num2[i]){
				printf("-");
				minus(num2,num1);
				break;
			}else{
				w++;
			}
		}
		if(w==length1){
			printf("0");
		}
	} 	
	printf("\n");
	//乘法	
	Reverse(num1);
	Reverse(num2);
	for(i=0;i<60;i++){
		for(j=0;j<60;j++){
			timeans[i+j]+=(num1[i]-'0')*(num2[j]-'0');
			//printf("num1=%c  num2=%c  ans= %d\n",num1[i],num2[j],timeans[i+j]);
		}
	}
	for(i=0;i<360;i++){
		if(timeans[i]>=10){
			timeans[i+1]+=timeans[i]/10;
			timeans[i]=timeans[i]%10;				
		}
	}	
	lon=0;
	for(i=359;i>=0;i--){
		if (timeans[i]==0){
			lon+=1;
		}else{
			break;
		}
	}
	lon=360-lon;
			
	for (i=lon-1;i>=0;i--){
		printf("%d",timeans[i]);	
	}		
	
}


