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
		temp->prev=temp;
		temp->next=temp;
		head=temp;
	}
	else{
		printf("\nNode Already Created!! Please use Insert!");
	}
}
void display(){
	if(head==NULL){
		printf("\nLinkedList is Empty!!");
	}
	else{
		NODE*top=head->next;
		printf("\nLinkedList :  ");
		while(top!=head){
			printf("%d ",top->data);
			top=top->next;
		}
		printf("%d\n",top->data);
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
		temp->next=head->next;
		head->next->prev=temp;
		head->next=temp;
		head=temp;
	}
}
void delete_node(){
	if(head==NULL){
		printf("\nNo data available for deletion!!");
	}
	else{
		if(head->next==head&&head->prev==head){
			free(head);
			head=NULL;
		}
		else{
			NODE*top=head->next;
			head=head->prev;
			top->prev=head;
			free(head->next);
			head->next=top;
//			NODE*last=head;
//			head->next->prev=head->prev;
//			head->prev->next=head->next;
//			head=head->prev;
//			free(last);
		}
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