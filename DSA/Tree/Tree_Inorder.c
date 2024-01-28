#include<stdio.h>
#include<stdlib.h>

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
void main(){
	root=create_node('A');
	root->left=create_node('B');
	root->right=create_node('C');
	root->left->left=create_node('D');
	root->left->right=create_node('F');
	root->left->left->right=create_node('E');
	root->right->right=create_node('G');
	root->right->right->left=create_node('H');
	root->right->right->right=create_node('I');
	printf("Inorder :  ");
	print_inorder(root);
	printf("\n\nPreorder :  ");
	print_preorder(root);
	printf("\n\nPostorder :  ");
	print_postorder(root);
}