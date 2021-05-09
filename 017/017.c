#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
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
void resett(char a,char data[4][50],int loc){
	int i,j;
	for(i=0;i<4;i++){
    	for(j=0;j<7;j=j+2){
	 		if(data[i][j]==a){
         	 data[i][j]='0';
       		}
		}
	}
	strcpy(data[loc],"0,0,0,0");
}
char com(char data[50]){
	int i;
    for(i=0;i<7;i=i+2){
		if(data[i]!='0'){
        	return data[i];
   		}
    }	
}
void run(char ans[4],char teacher[4][50],char student[4][50],int n){
	int temp[4]={0,0,0,0};
	char sav;
	int i=0,j=0;
	for(i=0 ; i<4 ; i++){
		if(student[i][n]=='A') temp[0]++;
		else if(student[i][n]=='B') temp[1]++;
		else if(student[i][n]=='C') temp[2]++;
		else if(student[i][n]=='D') temp[3]++;
		//else printf("ERROR"); 
	}
	for (i=0 ; i<4 ; i++){
		if(temp[i] == 1){
			for(j=0 ; j<4 ; j++){
				if(student[j][n]=='A'+i){
					ans[j]='A'+i;
					resett('A'+i,student,j);
					resett('W'+j,teacher,i);
				}
			}
		}
		
	}
	for (i=0 ; i<4 ; i++){
		if(temp[i]>=2){
			sav=com(teacher[i]);
			ans[sav-'W']='A'+i;
			resett('A'+i,student,sav-'W');
			resett('W'+sav-'W',teacher,i);
			break;
		}	
	}
	
}
void main(){
	int i=0,j=0,k=0;
	int count=0;
	char student[4][50];
	char teacher[4][50];
	char ans[4]="0000";
	for(i=0;i<4;i++){
		scanf("%s",student[i]);
	}
	for(i=0;i<4;i++){
		scanf("%s",teacher[i]);
	}
	while (ans[0]=='0' || ans[1]=='0' || ans[2]=='0' || ans[3]=='0'){
		run(ans,teacher,student,count);
		
		for(i=0 ; i<4 ; i++){
			student[i][count]='0';
		}
		count+=2;
		
	}	
	for(i=0 ; i<4 ; i++){
		printf("%c->%c\n",'W'+i,ans[i]);
	}
		
	
}
