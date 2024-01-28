#include<stdio.h>
#include<stdlib.h>

struct node{
	int data;
	struct node *root=NULL;
}*next,*prev,*temp,*root1=NULL,*ptr;
int lvl=0;
void create(int x){
	int j=0,i=0;
	temp=(struct node*)malloc(sizeof(struct node));
	temp->data=x;
	temp->next=NULL;
	temp->prev=NULL;
	if(root==NULL){
		root=temp;
	}
	else if(root->left==NULL)
		root->left=temp;
	else if(root->left!=NULL){
		root->right=temp;
		lvl++;
	}
	else{
		root1=root;
		ptr=root;
		while(i!=lvl-1){
			ptr=ptr->right;
			root1=root1->left;
			i++;
		}
		if(ptr->right!=NULL){
			root1->left->left=temp;
			lvl++;
		}
		else{
			if(root1->left==NULL){
				root1->left=temp;
			}
			else if(root1->right==NULL){
				root1->right=temp;
			}
			else{
				while(j!=lvl-2){
					root1=root1->left;
					j++;
				}
				if(root1!=root){
					while(root1->right!=NULL){
						root1=root1->right;
					if(root1->left==NULL)
						root1->left=temp;
					else if(root1->right==NULL)
						root1->right=temp;
					}
				}
				else{
					while(root1->right!=NULL)
						root1=root1->right;
					
				}
			}
		}
	}
}