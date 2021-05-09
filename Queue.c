#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct node{
    int data;
    struct node *next;
}node;
struct queue{
    char name[10];
    int count;
    node *front;
    node *rear;
}queue[10];

void create(int *num){
    scanf("%s" , queue[*num].name);
    queue[*num].front = NULL;
    queue[*num].rear = NULL;
    (*num)++;
}
void enqueue(int num){
    int i , value;
    char name[10];
    scanf("%s%d" , name , &value);
    for(i=0;i<num;i++){
        if(strcmp(queue[i].name , name)==0){
            node *unit;
            unit = (node*)malloc(sizeof(node));
            unit->data = value;
            unit->next = NULL;
            if(queue[i].front == NULL) queue[i].front = queue[i].rear = unit;
            else{queue[i].rear->next = unit; queue[i].rear = unit;}
            queue[i].count++; break;
        }
    }if(i==num) printf("Queue %s isn't exist\n" , name);
}
void dequeue(int num){
    int i;
    char name[10];
    scanf("%s" , name);
    for(i=0;i<num;i++){
        if(strcmp(queue[i].name , name)==0){
            node* tmp = queue[i].front;
            if(tmp == NULL){printf("Queue is empty\n"); break;}
            else{
                queue[i].front = queue[i].front->next;
                queue[i].count--;
                free(tmp); break;
            }
        }
    }if(i==num) printf("Queue %s isn't exist\n" , name);
}
void mergequeue(int *num){
    int i , j , error=0;
    char name1[10] , name2[10];
    scanf("%s%s" , name1 , name2);
    for(i=0;i<*num;i++) if(strcmp(queue[i].name , name1)==0) break;
    for(j=0;j<*num;j++) if(strcmp(queue[j].name , name2)==0) break;
    if(i==*num){error = 1; printf("Queue %s isn't exist\n", name1);}
    if(j==*num){error = 1; printf("Queue %s isn't exist\n", name2);}
    if(error==0){
        queue[i].rear->next = queue[j].front;
        queue[i].rear = queue[j].rear;
        queue[i].count += queue[j].count;
        for(i=j;i<*num;i++) queue[i] = queue[i+1];
        (*num)--;
    }
}
void output(int num){
    int i;
    printf("****************************************\n");
    if(num!=0){
        for(i=0;i<num;i++){
            printf("Queue Name:%s Queue Size:%d Queue Element:", queue[i].name , queue[i].count);
            node *tmp = queue[i].front;
            if(tmp == NULL) printf("Queue is empty");
            else while(tmp!=NULL){printf("%d " , tmp->data); tmp = tmp->next;}
            printf("\n");
        }
    }else printf("Isn't have any queue\n");
    printf("****************************************\n");
}
int main(){
    int num=0 , select;
    while(1){
        scanf("%d" , &select);
        if(select == 1) create(&num);
        if(select == 2) enqueue(num);
        if(select == 3) dequeue(num);
        if(select == 4) mergequeue(&num);
        if(select == 5) output(num);
        if(select == 6) break;
    }
    return 0;
}
