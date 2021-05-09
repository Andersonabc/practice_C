#include<stdio.h>
#include<stdlib.h>

typedef struct node_s{
	int data;
	struct node_s *right;
	struct node_s *left;
}node_t;

typedef node_t *nodep_t;

typedef struct tree_s{
	nodep_t root;
}tree_t;

nodep_t makenode(int data){
	node_t *newnode;
	newnode = (node_t*)malloc(sizeof(node_t));
	newnode->data = data;
	newnode->left = NULL;
	newnode->right = NULL;
	return newnode;
}

void insert(tree_t *tree, int data){
	nodep_t newnode = makenode(data);
	nodep_t current = tree->root;
	if(current == NULL){
		tree->root = newnode;
		return;
	}
	while (current != NULL){
		if(data > current->data){
			if(current->right == NULL){
				current->right = newnode;
				break;
			}else{
				current = current->right;
			}
		}else{
			if(current->left == NULL){
				current->left = newnode;
				break;
			}else{
				current = current->left;
			}
		}
	}
	return;
}

void print(nodep_t root){
	if(root == NULL) return;
	print(root->left);
	printf("%d ",root->data);
	print(root->right);
}

int main(){
	tree_t tree;
	tree.root = NULL;
	int num;
	char mode;
	scanf("%c",&mode);
	while(mode != 'e'){
		if(mode == 'p'){
			if(tree.root == NULL) printf("null\n");
			else{
				print(tree.root);
				printf("\n");
			}
		}else if(mode == 'i'){
			scanf("%d",&num);
			insert(&tree,num);
		}
		scanf("%c",&mode);
	}

	return 0;
}
