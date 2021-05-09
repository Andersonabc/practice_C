#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
typedef struct Homework{ 
	char name[10];//學生名字 
	int isDelay;//是否遲交(遲交True，未遲交False) 
	struct Homework *next;	
}HW;
typedef struct HD{ 
	HW *head;	
}hd;

void main(){
	hd stackhd;
	stackhd.head=NULL;
	char tempname[100];
	gets(tempname);
	while(strcmp(tempname,"-1") != 0){		
		HW *newnode;
		newnode = (HW*)malloc(sizeof(HW));
		strcpy(newnode->name,tempname);
		newnode->isDelay = 0;
		newnode->next=stackhd.head;
		stackhd.head=newnode;
		gets(tempname);
	}
	int i=0,j=0;
	char ttempname[100];
	while(1){
		gets(ttempname);
		//printf("%s",ttempname);
		if(ttempname[0]=='3') {
			HW *current ;
			current = stackhd.head ;
			if(current == NULL) printf("Empty\n");
			while(current!=NULL){
				if(current->isDelay == 1) printf("%s's HW is delay\n",current->name);
				else printf("%s's HW is not delay\n",current->name);
				current = current->next;				
			}
			return ;	
		}else if(ttempname[0]=='2'){		
			if (stackhd.head == NULL) printf("Empty\n");
			else{
				HW *current ;
				current = stackhd.head;
				if(current->isDelay == 1) printf("%s's HW is delay\n",current->name);
				else printf("%s's HW is not delay\n",current->name);		
				stackhd.head =	current->next;
				//free(current);		
				}			
						
		}else if(ttempname[0]=='1'){
			HW *current;
			HW *newnode;	
			current = stackhd.head ;
			newnode = (HW*)malloc(sizeof(HW));	
			char nn[100];
			j=0;
			for (i=2 ; i<strlen(ttempname) ; i++){
				nn[j++]=ttempname[i];
			}
			nn[j]='\0';
			strcpy(newnode->name,nn);
			newnode->isDelay = 1;	
			newnode->next = stackhd.head;
			stackhd.head = newnode ;		
		}
	} 
	/*HW *current = Root;
	while(current != NULL){
		printf("%s  %d\n",current->name,current->isDelay);
		current=current->next;		
	}*/
	/*
	Jeff
	Cindy
	Medhi
	Candy
	Mike
	-1
	1 Eden
	1 Jacky
	*/
}
