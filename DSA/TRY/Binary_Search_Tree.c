#include<stdio.h>
#include<stdlib.h>

struct node{
	int data;
	struct node*left;
	struct node*right;
};

struct node* create(int n){
	struct node*temp=(struct node*)malloc(sizeof(struct node));
	temp->data=n;
	temp->left=NULL;
	temp->right=NULL;
	return(temp);
}
struct node* insert(int n,struct node*Node){
	if(Node==NULL){
		return(create(n));
	}
	if(n<=Node->data){
		Node->left=insert(n,Node->left);
	}
	else{
		Node->right=insert(n,Node->right);
	}
	return Node;
}
void print_inorder_ascend(struct node*root){
	if(root==NULL){
		return;
	}
	print_inorder_ascend(root->left);
	printf("%d ",root->data);
	print_inorder_ascend(root->right);
}
void print_inorder_descend(struct node*root){
	if(root==NULL){
		return;
	}
	print_inorder_descend(root->right);
	printf("%d ",root->data);
	print_inorder_descend(root->left);
}
void print_preorder(struct node*root){
	if(root==NULL){
		return;
	}
	printf("%d ",root->data);
	print_preorder(root->left);
	print_preorder(root->right);
}
void print_postorder(struct node*root){
	if(root==NULL){
		return;
	}
	print_postorder(root->left);
	print_postorder(root->right);
	printf("%d ",root->data);
}
void main(){
	int ch,n;
	struct node*root=NULL;
	while(1){
		printf("\n\n1.Create\n2.Display_Ascending\n3.Display_Descending\n4.Preorder\n5.Postorder\t\tEnter Choice :  ");
		scanf("%d",&ch);
		switch(ch){
			case 1: printf("\nEnter Data :  ");
					scanf("%d",&n);
					root=insert(n,root);
					break;
			case 2: printf("\nAscending :  ");
					print_inorder_ascend(root);
					break;
			case 3: printf("\nDescending :  ");
					print_inorder_descend(root);
					break;
			case 4: printf("\nPreorder :  ");
					print_preorder(root);
					break;
			case 5: printf("\nPostorder :  ");
					print_postorder(root);
					break;
		}
	}
}