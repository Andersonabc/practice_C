#include <stdio.h>
#include <string.h>
#include<stdlib.h>
typedef struct University{
	char name[10];
	int BC;
	int NC;
	int CT;
	int NS;
	int NM;
	int HL;
	int NL;
	int already;
}Uni; 

int cut (char data[100] ,char *p[10]){
	int i=0;
	p[i]=strtok(data," ");
	while(p[i]!=NULL){
		p[++i]=strtok(NULL," ");
	}
	return i;
}
int cut2 (char data[100] ,char *p[10]){
	int i=0;
	p[i]=strtok(data,"+");
	while(p[i]!=NULL){
		p[++i]=strtok(NULL,"+");
	}
	return i;
}
int check(char tt[2] , int i ,Uni Uni[10]){
	//printf("%s\n",tt);
	if(strcmp(tt,"BC") == 0) {
		if(Uni[i].BC ==1) return 1;
		else return 0;
	}
	if(strcmp(tt,"NC") == 0){
		if(Uni[i].NC ==1)return 1;
		else return 0;
	}
	if(strcmp(tt,"CT") == 0){
		if(Uni[i].CT ==1)return 1;
		else return 0;
	} 
	if(strcmp(tt,"NS") == 0){
		if(Uni[i].NS ==1)return 1;
		else return 0;
	} 
	if(strcmp(tt,"NM") == 0){
		if(Uni[i].NM ==1)return 1;
		else return 0;
	} 
	if(strcmp(tt,"HL") == 0){
		if(Uni[i].HL ==1)return 1;
		else return 0;
	}
	if(strcmp(tt,"NL") == 0){
		if(Uni[i].NL ==1)return 1;
		else return 0;
	}
}
void main(){
	Uni Uni[10];
	struct University tmp;
	int amount;
	int i,j,k;
	char temp[100];
	char *p[10];
	gets(temp);
	amount = atoi(temp);
	for(i=0 ; i<amount ; i++){
		gets(temp);
		j=cut(temp,p);
		strcpy(Uni[i].name,p[0]);
		for(k=1 ; k<j ; k++){
			if(strcmp(p[k],"BC") == 0) Uni[i].BC =1;
			if(strcmp(p[k],"NC") == 0) Uni[i].NC =1;
			if(strcmp(p[k],"CT") == 0) Uni[i].CT =1;
			if(strcmp(p[k],"NS") == 0) Uni[i].NS =1;
			if(strcmp(p[k],"NM") == 0) Uni[i].NM =1;
			if(strcmp(p[k],"HL") == 0) Uni[i].HL =1;
			if(strcmp(p[k],"NL") == 0) Uni[i].NL =1;
		}
		if(Uni[i].BC != 1) Uni[i].BC = 0;
		if(Uni[i].NC != 1) Uni[i].NC = 0;
		if(Uni[i].CT != 1) Uni[i].CT = 0;
		if(Uni[i].NS != 1) Uni[i].NS = 0;
		if(Uni[i].NM != 1) Uni[i].NM = 0;
		if(Uni[i].HL != 1) Uni[i].HL = 0;
		if(Uni[i].NL != 1) Uni[i].NL = 0;
		Uni[i].already = 0;
	}
	
	for(i=0 ; i<amount-1 ; i++){
		for(j=i+1; j<amount ; j++){
			if(strcmp(Uni[i].name,Uni[j].name)>0){
				tmp = Uni[i];
				Uni[i] = Uni[j];
				Uni[j] = tmp;
			}
		}
	}
	
	int z;
	int search;
	int inform;
	int inform2;
	int correct=0;
	int yn=0;
	gets(temp);
	int a;
	char serh[100][3];
	search = atoi(temp);
	for(i=0 ; i<search ; i++){
		yn=0;
		gets(temp);
		inform=cut2(temp,p);
		for(j=0 ; j<amount ; j++){
			Uni[j].already=0;
		}
		for(z=0 ; z<amount ; z++){
			for(j=0 ; j<inform ; j++){
				if(Uni[z].already == 1) continue;
				a=0;
				correct=0;
				inform2=0;
				k=0;
				while(k<strlen(p[j])){
					if(p[j][k] != ' ' && p[j][k] != '+') {
						serh[inform2][0]=p[j][k];
						serh[inform2][1]=p[j][k+1];
						serh[inform2][2]='\0';
						inform2++;
						k+=2;
					}
					else	k++; 								
				}
				for(k=0 ; k<inform2 ; k++){
					if(check(serh[k] , z, Uni) == 1) correct++;
				}
				if(correct == inform2 ) {
					printf("%s ",Uni[z].name);
					Uni[z].already = 1;
					yn=1;
				}					
			}					
		}
		if(yn==1 && i != search-1) printf("\n");
		
	}
	
}
/*
6
NSYSU BC
NTU CT NM
NCCU NC CT NM
Providence NC CT NM
NTHU NC CT NM
XXXX BC NC CT NS NM HL NL
2
BCCT+NS+BC
NM 

*/
