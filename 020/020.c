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
	}
	return i;
}

void main(){
	char temp[2];
	int howbig=0,howbig2=0;
	int a=0,b=0,c=0;
	int count=0;
	int i,j,k;
	char *h[2000];
	gets(temp);
	a=cut(temp,h);
	//printf("%d",a);
	howbig=atoi(h[0]);
//	printf("%d",howbig);
	howbig2=temp[0]-'0';
	char data1[1000000];
	char data2[1000000] ;
	char *p1[100];
	char *p2[100];
	char ans11[200000];
	char *ans[10000];	
	gets(data1);
	a=cut(data1,p1);	
	gets(data2);
	b=cut(data2,p2);
	gets(ans11);	
	c=cut(ans11,ans);
	int player1=0,player2=0;
	int temp1=0,temp2=0;
	//printf("%d %d",howbig2,howbig);
	for(i=0 ; i<howbig*howbig-1 ; i+=howbig){
		for(j=i ; j<i+howbig; j++){
		//	printf("i=%d j=%d",i,j);
			for(k=0 ; k<c ; k++){
				if(strcmp(p1[j] , ans[k]) == 0) temp1++;
				if(strcmp(p2[j] , ans[k]) == 0) temp2++;
			}	
		}
		if(temp1 == howbig) player1++;
		if(temp2 == howbig) player2++;
		temp1=0;
		temp2=0;
	}
	for(i=0; i<howbig ; i++){
		for(j=i ; j<howbig*howbig ; j+=howbig){
			for(k=0 ; k<c ; k++){
				if(strcmp(p1[j] , ans[k]) == 0) temp1++;
				if(strcmp(p2[j] , ans[k]) == 0) temp2++;
			}
			//printf("i=%d j=%d",i,j);			
		}
		if(temp1 == howbig) player1++;
		if(temp2 == howbig) player2++;
		temp1=0;
		temp2=0;		
	}
	for(i=0 ; i<howbig*howbig ; i+=howbig+1){
		//printf("i=%d",i);
		//printf("%d\n",i);
		for(k=0 ; k<c ; k++){
			if(strcmp(p1[i] , ans[k]) == 0) temp1++;
			if(strcmp(p2[i] , ans[k]) == 0) temp2++;			
		}
	}
	if(temp1 == howbig) player1++;
	if(temp2 == howbig) player2++;
	temp1=0;
	temp2=0;	
	for(i=howbig-1 ; i<howbig*(howbig-1)+1 ; i+=(howbig-1)){
		//printf("i=%d",i);
		for(k=0 ; k<c ; k++){
			if(strcmp(p1[i] , ans[k]) == 0) temp1++;
			if(strcmp(p2[i] , ans[k]) == 0) temp2++;			
		}		
	}
	if(temp1 == howbig) player1++;
	if(temp2 == howbig) player2++;
	temp1=0;
	temp2=0;
	if(player1>player2){
		printf("Player1 wins %d, Player2 loses %d",player1,player2);
	}else if(player2>player1){
		printf("Player2 wins %d, Player1 loses %d",player2,player1);
	}else{
		printf("Draw %d",player1);
	}
	//printf("%d\n",player1);
	//printf("%d",player2);
	
}
