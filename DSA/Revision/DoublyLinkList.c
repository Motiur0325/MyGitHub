#include<stdio.h>
#include<stdlib.h>

typedef struct node{
	int data;
	struct node *next;
	struct node *prev;
}NODE;

NODE*head=NULL;

void create_node(){
	if(head==NULL){
		int n;
		printf("\nEnter the data :  ");
		scanf("%d",&n);
		NODE * temp=(NODE*)malloc(sizeof(NODE));
		temp->data=n;
		temp->prev=NULL;
		temp->next=NULL;
		head=temp;
	}
	else{
		printf("\nNode Already Created!! Please use Insert!");
	}
}
void delete_node(){
	if(head==NULL){
		printf("\nNo data available for deletion!!");
	}
	else{
		if(head->next==NULL&&head->prev==NULL){
			free(head);
			head=NULL;
		}
		else{
			head=head->prev;
			free(head->next);
			head->next=NULL;
		}
	}
}
void display(){
	if(head==NULL){
		printf("\nLinkedList is Empty!!");
	}
	else{
		NODE*top=head;
		printf("\nLinkedList :  ");
		while(top!=NULL){
			printf("%d ",top->data);
			top=top->prev;
		}
	}
}
void insert_node(){
	if(head==NULL){
		printf("\nCreate a node First!!");
	}
	else{
		int n;
		printf("\nEnter the data :  ");
		scanf("%d",&n);
		NODE*temp=(NODE*)malloc(sizeof(NODE));
		temp->data=n;
		temp->prev=head;
		temp->next=NULL;
		head->next=temp;
		head=temp;
	}
}
void main(){
	int ch;
	while(1){
		printf("\n\n1.Create\n2.Insert\n3.Display\n4.Delete\t\tEnter Choice :  ");
		scanf("%d",&ch);
		switch(ch){
			case 1:	create_node();
						break;
			case 2:	insert_node();
						break;
			case 3:	display();
						break;
			case 4:	delete_node();
						break;
		}
	}
}