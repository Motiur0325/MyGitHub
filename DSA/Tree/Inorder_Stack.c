#include<stdio.h>
#include<stdlib.h>

long int stack[100];
int top=-1;

struct node{
	char data;
	struct node*left;
	struct node*right;
}*root=NULL;

void push(long int data){
	top++;
	stack[top]=data;
}
int pop(){
	long int c=stack[top];
	top--;
	return c;  
}
struct node* create(char data){
	struct node*node=(struct node*)malloc(sizeof(struct node));
	node->data=data;
	node->left=NULL;
	node->right=NULL;
	return(node);
}
void print_inorder(struct node*node){
	long int f;
	if(node==NULL)
		return;
	struct node*current=node;
	f=&current;
	push(f);
	current=current->left;
	while(current!=NULL&&top!=-1){
		printf("Pass");
		if(current==NULL){
			&current=pop();
			printf("%c ",current->data);
			current=current->right;
		}
		else{
			f=&current;
			push(f);
			current=current->left;
		}
	}
}
void main(){
	root=create('1');
	root->left=create('2');
	root->right=create('3');
	root->left->left=create('4');
	root->left->right=create('5');
	printf("Inorder :  ");
	print_inorder(root);
}