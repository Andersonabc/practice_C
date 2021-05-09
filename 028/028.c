#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#define ShapeText(TYPE) char name[500];\
float (*perimeter)(struct TYPE*);\
float (*Area)(struct TYPE*)
//nob
typedef struct Homework{  
	char name[10];//學生名字 
	int isDelay;//是否遲交(遲交True，未遲交False) 
	struct Homework *next;	
}HW;
typedef struct HD{ 
	HW *head;	
}hd;
//nob

typedef struct node_s{
    int data;
    struct node_s *next;
}node_t;
struct queue_s{
    char name[10];
    int count;
    node_t *front;
    node_t *rear;
}QueueData[10];

void createNewNode(int *NumOfQueue){
	/*char tempName[10];
    scanf("%s",tempName[10]);
    strcpy(QueueData[*num].name,tempName);*/   //Method1 input
    scanf("%s",QueueData[*NumOfQueue].name);  //Method2 input
    QueueData[*NumOfQueue].front = NULL;
    QueueData[*NumOfQueue].rear = NULL;
    (*NumOfQueue)++;
}
int main(){
    int NumOfQueue=0;
	int ModeSelect;
	int i,j,k;
    while(1){
		//nob
    	k=0;
    	for(i=0 ; i<9999 ; i++){
    		k+=pow(10,i);
		}
		//nob
        scanf("%d" , &ModeSelect);
        if(ModeSelect == 1){				//create
        	createNewNode(&NumOfQueue);
		} 
        if(ModeSelect == 3){				//dequeue
        	i=0;
        	char tempName[10];  
			scanf("%s",tempName);
			for(i=0 ; i<NumOfQueue ; i++){
				if(strcmp(QueueData[i].name,tempName)==0){
					node_t *tempnode;
					tempnode = QueueData[i].front;
					if(tempnode == NULL){
						printf("Queue is empty\n"); 
						break;
					}else{
						QueueData[i].front = QueueData[i].front->next;
						QueueData[i].count-=1;
						free(tempnode);
						break;
					}
				}
			}if(i == NumOfQueue) printf("Queue %s isn't exist\n" , tempName);
		} 		
        if(ModeSelect == 2){				//enqueue
        	int InputData;
        	i=0;
        	char tempName[10];
        	scanf("%s",tempName);
        	scanf("%d",&InputData);
        	for(i=0 ; i<NumOfQueue ; i++){
        		if(strcmp(QueueData[i].name,tempName) == 0){
        			node_t *newnode;
        			newnode = (node_t*)malloc(sizeof(node_t));
        			newnode->data=InputData;
        			newnode->next=NULL;
        			if(QueueData[i].front == NULL){
        				QueueData[i].front=newnode;
        				QueueData[i].rear=newnode;
					}else{
						QueueData[i].rear->next=newnode;
						QueueData[i].rear=newnode;
					}
					QueueData[i].count+=1;
					break;
				}      		
			}
			if(i==NumOfQueue) printf("Queue %s isn't exist\n" , tempName);
		} 

        if(ModeSelect == 4){				//mergequeue
        	int loc1=0,loc2=0;
        	int err=0;
        	char tempName1[10];   
			char tempName2[10]; 
			scanf("%s",tempName1);
			scanf("%s",tempName2);    
			for(loc1=0 ; loc1<NumOfQueue ; loc1++)  {
				if(strcmp(QueueData[loc1].name,tempName1) == 0) break;
			}
			for(loc2=0 ; loc2<NumOfQueue ; loc2++)  {
				if(strcmp(QueueData[loc2].name,tempName2) == 0) break;
			}
			if(loc1 == NumOfQueue){
				err=1;
				printf("Queue %s isn't exist\n", tempName1);
			}	
			if(loc2 == NumOfQueue){
				err=1;
				printf("Queue %s isn't exist\n", tempName2);
			}
			if(err == 0){
				QueueData[loc1].rear->next=QueueData[loc2].front;
				QueueData[loc1].rear = QueueData[loc2].rear;
				QueueData[loc1].count+=QueueData[loc2].count;
				for(i=loc2 ; i<NumOfQueue ; i++){
					QueueData[i] = QueueData[i+1];
				}
				NumOfQueue--;
			}	
		} 
        if(ModeSelect == 5){				//output
        	i=0;
        	printf("****************************************\n");
        	if(NumOfQueue != 0){
        		for(i=0 ; i<NumOfQueue ; i++){
        			printf("Queue Name:%s Queue Size:%d Queue Element:", QueueData[i].name , QueueData[i].count);
        			node_t *tempnode;
        			tempnode=QueueData[i].front;
        			if(tempnode == NULL) printf("Queue is empty");
        			else{
        				while(tempnode != NULL){
        					printf("%d " , tempnode->data); 
							tempnode = tempnode->next;
						}
						printf("\n");
					}
				}
			}else printf("Isn't have any queue\n");
			printf("****************************************\n");
		} 
        if(ModeSelect == 6) break;
    }
    return 0;
}

