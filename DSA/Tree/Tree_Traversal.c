#include<stdio.h>
#include<stdlib.h>

int flag=0;

struct node{
	char data;
	struct node*left;
	struct node*right;
}*root=NULL;

struct node* create_node(char data){
	struct node*node=(struct node*)malloc(sizeof(struct node));
	node->data=data;
	node->left=NULL;
	node->right=NULL;
	return(node);
}
void print_inorder(struct node *node){
	if(node==NULL)
		return;
	print_inorder(node->left);
	printf("%c ",node->data);
	print_inorder(node->right);
}
void print_preorder(struct node*node){
	if(node==NULL)
		return;
	printf("%c ",node->data);
	print_preorder(node->left);
	print_preorder(node->right);
}
void print_postorder(struct node * node){
	if(node==NULL)
		return;
	print_postorder(node->left);
	print_postorder(node->right);
	printf("%c ",node->data);
}
void inorder_search(struct node*node,char key){
	if(node==NULL)
		return;
	inorder_search(node->left,key);
	if(node->data==key){
		printf("\n!!Element found .");
		flag=1;
		return;
	}
	inorder_search(node->right,key);
}
void main(){
	char key;
//	root=create_node('A');
//	root->left=create_node('B');
//	root->right=create_node('C');
//	root->left->left=create_node('D');
//	root->left->right=create_node('E');
//	root->right->left=create_node('F');
//	root->right->right=create_node('G');
//	root->left->left->left=create_node('H');
//	root->left->left->right=create_node('I');
	root=create_node('3');
	root->left=create_node('2');
	root->right=create_node('2');
	root->left->left=create_node('1');
	root->left->right=create_node('1');
	root->right->left=create_node('1');
	root->right->right=create_node('1');
	root->left->left->left=create_node('0');
	root->left->left->right=create_node('0');
	printf("Inorder :  ");
	print_inorder(root);
	printf("\n\nPreorder :  ");
	print_preorder(root);
	printf("\n\nPostorder :  ");
	print_postorder(root);
	printf("\n\nEnter the key element to be searched :  ");
	scanf("%c",&key);
	inorder_search(root,key);
	if(flag==0)
		printf("\n!!Element (not) found.");
}