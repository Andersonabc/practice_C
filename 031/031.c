#include<stdio.h>
#include<stdlib.h> 
#include<string.h>

int findIndex(char root,char *inOrder){
	int i;
	for(i=0;i<strlen(inOrder);i++){
		if(root==inOrder[i]) return i;
	}
	return -1;
}


void PostIn(char *pre,char *in,char ans[10][10],int count){
	char leftTree[30];
	char rightTree[30];
	char rightpreOrder[30]="";
	char leftpreOrder[30]="";
	int index=findIndex(pre[strlen(pre)-1],in);

	if(index==-1) return ;
	strcpy(rightTree,in+index+1);
	
	strncpy(leftTree,in,index);
	
	strncpy(rightpreOrder,pre+index,strlen(pre)-1-index);
	
	strncpy(leftpreOrder,pre,index);

	int k=0;
	while(ans[count][k] != '\0') k++;
	ans[count][k] = pre[strlen(pre)-1];	

	PostIn(leftpreOrder,leftTree,ans,count+1);
	PostIn(rightpreOrder,rightTree,ans,count+1);
}

/*void swap(char *a[100],char *b[100]){
	char *temp;
	temp = *a;
	*a=*b;
	*b=temp;
}*/
void PreIn(char *pre,char *in,char ans[10][10],int count){
	char leftTree[30];
	char rightTree[30];
	int index=findIndex(pre[0],in);
	if(index==-1) return ;

	strcpy(rightTree,in+index+1);

	strncpy(leftTree,in,index);
	int k=0;
	while(ans[count][k] != '\0') k++;
	ans[count][k] = pre[0];

	PreIn(pre+1,leftTree,ans,count+1);
	PreIn(pre+index+1,rightTree,ans,count+1);
}

void main(){
	char mode1[10];
	char data1[100];
	char mode2[10];
	char data2[100];	
	gets(mode1);
	gets(data1);
	gets(mode2);
	gets(data2);
	char ans[10][10];
	int i,j;
	int count=0;
	for(i=0 ; i<10 ; i++){
		for(j=0 ; j<10 ; j++){
			ans[i][j]='\0';
		}	
	}
//	printf("%s %s\n",mode1,data1);
	if(strcmp(mode2,"I")==0) {
		char temp[100];
		strcpy(temp,data1);
		strcpy(data1,data2);
		strcpy(data2,temp);
		strcpy(temp,mode1);
		strcpy(mode1,mode2);
		strcpy(mode2,temp);
	}
//	printf("%s %s\n",mode1,data1);
	if(strcmp(mode2,"P")==0)	PreIn(data2,data1,ans,count);
	else	PostIn(data2,data1,ans,count);	
	for(i=0 ; i<10 ; i++){
		printf("%s",ans[i]);
	}
}

/*
P
ABCDEFGHI
I
BCAEDGHFI
*/
