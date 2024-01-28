#include<stdio.h>
#include<stdlib.h>

int count=0;

struct node{
	int data;
	struct node *left,*right;
	int lvl;
}*root=NULL,*root1,*parent;
void Create(int n){
	struct node *temp=(struct node*)malloc(sizeof(struct node));
	temp->data=n;
	temp->lvl=count;
	temp->right=NULL;
	temp->left=NULL;
	if(root==NULL){
		root=temp;
		root1=temp;
		parent=root;
	}
	else{
		if(root->left==NULL){
			root->left=temp;
		}
		else{
			if(root->right==NULL){
				root->right=temp;
			}
			else{
				root=root->left;
			}
		}
	}
}