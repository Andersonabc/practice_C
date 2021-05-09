#include<stdio.h>
#include<string.h> 
#include<stdlib.h>
typedef struct Company{ 
	char name[100];//廠商名字 
	char site[100];//展區位置(代號，如:P0001) 
	char topic[100];//主題(如: AI、Blockchain...) 
	char country[100];//國家 
	int award;//得獎數量 
	struct Company *next; 
}Company_t;
typedef struct HD{ 
	Company_t *head;	
}root;
// 1:降序，2:升序
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
	int i,j,k;
	root root;
	root.head=NULL;
	char input[500];
	char *p[100];
	int count=0;
	while(1){
		int num=0;
		gets(input);
		if(strcmp(input,"-1") == 0) break;
		else{
			num = cut(input,p);
			Company_t *newnode;
			newnode = (Company_t*)malloc(sizeof(Company_t));			
			strcpy(newnode->name,p[0]);
			strcpy(newnode->site,p[1]);
			strcpy(newnode->topic,p[2]);
			strcpy(newnode->country,p[3]);
			newnode->award=atoi(p[4]);
			newnode->next = NULL;
			if(root.head == NULL) root.head=newnode;
			else{
				Company_t *current = root.head;
				while(current->next != NULL) current = current->next;
				//printf("%s %s %s %s %d\n",current->name,current->site,current->topic,current->country,current->award);
				current->next = newnode;
			}
			count++;
		}
	}
	while(1){
		Company_t *curr=root.head;
		Company_t *tmp=root.head;
		Company_t *prev=root.head;
		int num=0;
		int mode=0;
		int channel=0;
		char inform[200];
		gets(input);
		if(strcmp(input,"exit") == 0) break;
		else{
			num=cut(input,p);
			strcpy(inform,p[0]);
			mode=atoi(p[1]);
		//	printf("%s %d\n",inform,mode);
			if(strcmp(inform,"name")==0){	
				if(mode == 2){
					for(i=count;i>0;i--) {
						prev = root.head;
					    curr = root.head;
					    for(j=0;j<i-1 && curr->next!=NULL ;j++) {
					    // Compares two elements, and swaps if current is bigger than next
					        if(strcmp(curr->name,curr->next->name) > 0 ) {
					            tmp = curr->next;
					            curr->next = tmp->next;
					            tmp->next = curr;
					            // In linked list, swap has two case. In head or not.
						        if(curr == root.head) {
						        	root.head = tmp;	
						        	prev = tmp;
								}else{
									prev->next = tmp;
									prev = prev->next;
								}				        
					        }else if (strcmp(curr->name,curr->next->name) == 0 ){
					        	if(strcmp(curr->site,curr->next->site) > 0 ) {
					            tmp = curr->next;
					            curr->next = tmp->next;
					            tmp->next = curr;
					            // In linked list, swap has two case. In head or not.
							        if(curr == root.head) {
							        	root.head = tmp;	
							        	prev = tmp;
									}else{
										prev->next = tmp;
										prev = prev->next;
									}				        
						        }else {
					        	curr = curr->next;
					        	if(j!=0) prev = prev->next;
					   		}
							}else {
					        	curr = curr->next;
					        	if(j!=0) prev = prev->next;
					   		}
						}
					}					
				}else if(mode == 1){
					for(i=count;i>0;i--) {
						prev = root.head;
					    curr = root.head;
					    for(j=0;j<i-1 && curr->next!=NULL ;j++) {
					    // Compares two elements, and swaps if current is bigger than next
					        if(strcmp(curr->name,curr->next->name) < 0 ) {
					            tmp = curr->next;
					            curr->next = tmp->next;
					            tmp->next = curr;
					            // In linked list, swap has two case. In head or not.
						        if(curr == root.head) {
						        	root.head = tmp;	
						        	prev = tmp;
								}else{
									prev->next = tmp;
									prev = prev->next;
								}				        
					        }else if (strcmp(curr->name,curr->next->name) == 0 ){
						       	if(strcmp(curr->site,curr->next->site) < 0 ) {
						        tmp = curr->next;
						        curr->next = tmp->next;
						        tmp->next = curr;
						        // In linked list, swap has two case. In head or not.
							    	if(curr == root.head) {
								       	root.head = tmp;	
							        	prev = tmp;
									}else{
										prev->next = tmp;
										prev = prev->next;
									}				        
							    }else {
					        	curr = curr->next;
					        	if(j!=0) prev = prev->next;
					   		}
							}else {
					        	curr = curr->next;
					        	if(j!=0) prev = prev->next;
					   		}
						}
					}					
				}			
			}else if(strcmp(inform,"site")==0){
				if(mode == 2){
					for(i=count;i>0;i--) {
						prev = root.head;
					    curr = root.head;
					    for(j=0;j<i-1 && curr->next!=NULL ;j++) {
					    // Compares two elements, and swaps if current is bigger than next
					        if(strcmp(curr->site,curr->next->site) > 0 ) {
					            tmp = curr->next;
					            curr->next = tmp->next;
					            tmp->next = curr;
					            // In linked list, swap has two case. In head or not.
						        if(curr == root.head) {
						        	root.head = tmp;	
						        	prev = tmp;
								}else{
									prev->next = tmp;
									prev = prev->next;
								}				        
					        }else {
					        	curr = curr->next;
					        	if(j!=0) prev = prev->next;
					   		}
						}
					}	
				}else if(mode == 1){
					for(i=count;i>0;i--) {
						prev = root.head;
					    curr = root.head;
					    for(j=0;j<i-1 && curr->next!=NULL ;j++) {
					    // Compares two elements, and swaps if current is bigger than next
					        if(strcmp(curr->site,curr->next->site) < 0 ) {
					            tmp = curr->next;
					            curr->next = tmp->next;
					            tmp->next = curr;
					            // In linked list, swap has two case. In head or not.
						        if(curr == root.head) {
						        	root.head = tmp;	
						        	prev = tmp;
								}else{
									prev->next = tmp;
									prev = prev->next;
								}				        
					        }else {
					        	curr = curr->next;
					        	if(j!=0) prev = prev->next;
					   		}
						}
					}					
				}				
			}else if(strcmp(inform,"topic")==0){
				if(mode == 2){
					for(i=count;i>0;i--) {
						prev = root.head;
					    curr = root.head;
					    for(j=0;j<i-1 && curr->next!=NULL ;j++) {
					    // Compares two elements, and swaps if current is bigger than next
					        if(strcmp(curr->topic,curr->next->topic) > 0 ) {
					            tmp = curr->next;
					            curr->next = tmp->next;
					            tmp->next = curr;
					            // In linked list, swap has two case. In head or not.
						        if(curr == root.head) {
						        	root.head = tmp;	
						        	prev = tmp;
								}else{
									prev->next = tmp;
									prev = prev->next;
								}				        
					        }else if (strcmp(curr->topic,curr->next->topic) == 0 ){
						       	if(strcmp(curr->site,curr->next->site) > 0 ) {
						        tmp = curr->next;
						        curr->next = tmp->next;
						        tmp->next = curr;
						        // In linked list, swap has two case. In head or not.
							    	if(curr == root.head) {
								       	root.head = tmp;	
							        	prev = tmp;
									}else{
										prev->next = tmp;
										prev = prev->next;
									}				        
							    }else {
					        	curr = curr->next;
					        	if(j!=0) prev = prev->next;
					   		}
							}else {
					        	curr = curr->next;
					        	if(j!=0) prev = prev->next;
					   		}
						}
					}					
				}else if(mode == 1){
					for(i=count;i>0;i--) {
						prev = root.head;
					    curr = root.head;
					    for(j=0;j<i-1 && curr->next!=NULL ;j++) {
					    // Compares two elements, and swaps if current is bigger than next
					        if(strcmp(curr->topic,curr->next->topic) < 0 ) {
					            tmp = curr->next;
					            curr->next = tmp->next;
					            tmp->next = curr;
					            // In linked list, swap has two case. In head or not.
						        if(curr == root.head) {
						        	root.head = tmp;	
						        	prev = tmp;
								}else{
									prev->next = tmp;
									prev = prev->next;
								}				        
					        }else if (strcmp(curr->topic,curr->next->topic)  == 0 ){
						       	if(strcmp(curr->site,curr->next->site) < 0 ) {
						        tmp = curr->next;
						        curr->next = tmp->next;
						        tmp->next = curr;
						        // In linked list, swap has two case. In head or not.
							    	if(curr == root.head) {
								       	root.head = tmp;	
							        	prev = tmp;
									}else{
										prev->next = tmp;
										prev = prev->next;
									}				        
							    }else {
					        	curr = curr->next;
					        	if(j!=0) prev = prev->next;
					   		}
							}else {
					        	curr = curr->next;
					        	if(j!=0) prev = prev->next;
					   		}
						}
					}					
				}				
			}else if(strcmp(inform,"country")==0){
				if(mode == 2){
					for(i=count;i>0;i--) {
						prev = root.head;
					    curr = root.head;
					    for(j=0;j<i-1 && curr->next!=NULL ;j++) {
					    // Compares two elements, and swaps if current is bigger than next
					        if(strcmp(curr->country,curr->next->country) > 0 ) {
					            tmp = curr->next;
					            curr->next = tmp->next;
					            tmp->next = curr;
					            // In linked list, swap has two case. In head or not.
						        if(curr == root.head) {
						        	root.head = tmp;	
						        	prev = tmp;
								}else{
									prev->next = tmp;
									prev = prev->next;
								}				        
					        }else if (strcmp(curr->country,curr->next->country) == 0 ){
								if(strcmp(curr->site,curr->next->site) > 0 ) {
						            tmp = curr->next;
						            curr->next = tmp->next;
						            tmp->next = curr;
						            // In linked list, swap has two case. In head or not.
							        if(curr == root.head) {
							        	root.head = tmp;	
							        	prev = tmp;
									}else{
										prev->next = tmp;
										prev = prev->next;
									}				        
						        }else {
					        	curr = curr->next;
					        	if(j!=0) prev = prev->next;
					   		}
							}else {
					        	curr = curr->next;
					        	if(j!=0) prev = prev->next;
					   		}
						}
					}					
				}else if(mode == 1){
					for(i=count;i>0;i--) {
						prev = root.head;
					    curr = root.head;
					    for(j=0;j<i-1 && curr->next!=NULL ;j++) {
					    // Compares two elements, and swaps if current is bigger than next
					        if(strcmp(curr->country,curr->next->country) < 0 ) {
					            tmp = curr->next;
					            curr->next = tmp->next;
					            tmp->next = curr;
					            // In linked list, swap has two case. In head or not.
						        if(curr == root.head) {
						        	root.head = tmp;	
						        	prev = tmp;
								}else{
									prev->next = tmp;
									prev = prev->next;
								}				        
					        }else if (strcmp(curr->country,curr->next->country) == 0 ){
						       	if(strcmp(curr->site,curr->next->site) < 0 ) {
						        tmp = curr->next;
						        curr->next = tmp->next;
						        tmp->next = curr;
						        // In linked list, swap has two case. In head or not.
							    	if(curr == root.head) {
								       	root.head = tmp;	
							        	prev = tmp;
									}else{
										prev->next = tmp;
										prev = prev->next;
									}				        
							    }else {
					        	curr = curr->next;
					        	if(j!=0) prev = prev->next;
					   		}
							}else {
					        	curr = curr->next;
					        	if(j!=0) prev = prev->next;
					   		}
						}
					}					
				}				
			}else if(strcmp(inform,"award")==0){
				if(mode == 2){
					for(i=count;i>0;i--) {
						prev = root.head;
					    curr = root.head;
					    for(j=0;j<i-1 && curr->next!=NULL ;j++) {
					    // Compares two elements, and swaps if current is bigger than next
					        if(curr->award > curr->next->award) {
					            tmp = curr->next;
					            curr->next = tmp->next;
					            tmp->next = curr;
					            // In linked list, swap has two case. In head or not.
						        if(curr == root.head) {
						        	root.head = tmp;	
						        	prev = tmp;
								}else{
									prev->next = tmp;
									prev = prev->next;
								}				        
					        }else if (curr->award== curr->next->award ){
					        	if(strcmp(curr->site,curr->next->site) > 0 ) {
					            tmp = curr->next;
					            curr->next = tmp->next;
					            tmp->next = curr;
					            // In linked list, swap has two case. In head or not.
							        if(curr == root.head) {
							        	root.head = tmp;	
							        	prev = tmp;
									}else{
										prev->next = tmp;
										prev = prev->next;
									}				        
						        }else {
					        	curr = curr->next;
					        	if(j!=0) prev = prev->next;
					   		}
							}else {
					        	curr = curr->next;
					        	if(j!=0) prev = prev->next;
					   		}
						}
					}					
				}else if(mode == 1){
					for(i=count;i>0;i--) {
						prev = root.head;
					    curr = root.head;
					    for(j=0;j<i-1 && curr->next!=NULL ;j++) {
					    // Compares two elements, and swaps if current is bigger than next
					        if(curr->award < curr->next->award) {
					            tmp = curr->next;
					            curr->next = tmp->next;
					            tmp->next = curr;
					            // In linked list, swap has two case. In head or not.
						        if(curr == root.head) {
						        	root.head = tmp;	
						        	prev = tmp;
								}else{
									prev->next = tmp;
									prev = prev->next;
								}				        
					        }else if (curr->award == curr->next->award ){
						       	if(strcmp(curr->site,curr->next->site) < 0 ) {
						        tmp = curr->next;
						        curr->next = tmp->next;
						        tmp->next = curr;
						        // In linked list, swap has two case. In head or not.
							    	if(curr == root.head) {
								       	root.head = tmp;	
							        	prev = tmp;
									}else{
										prev->next = tmp;
										prev = prev->next;
									}				        
							    }else {
					        	curr = curr->next;
					        	if(j!=0) prev = prev->next;
					   		}
							}else {
					        	curr = curr->next;
					        	if(j!=0) prev = prev->next;
					   		}
						}
					}					
				}				
			}
		curr=root.head;
		while(curr->next != NULL){
			printf("%s %s\n",curr->name,curr->site);
			curr=curr->next;
		}
		printf("%s %s\n\n",curr->name,curr->site);	
		}

	}
	
}

/*
Asus P0001 chatBot Taiwan 10
Acer P0002 computer Taiwan 7
CyberLink P0012 AI Taiwan 1
MICRO-STAR A1234 gaming Taiwan 4
GIGABYTE G1564 laptop Taiwan 1
-1
name 2
award 1
country 2
site 2
exit

*/
