#include<stdio.h>
#include<stdlib.h>

typedef struct node{
	int data;
	struct node *next;
}NODE;

NODE*tail=NULL;

void create_node(){
	if(tail==NULL){
		int n;
		printf("\nEnter the data :  ");
		scanf("%d",&n);
		NODE * temp=(NODE*)malloc(sizeof(NODE));
		temp->data=n;
		temp->next=temp;
		tail=temp;
	}
	else{
		printf("\nNode Already Created!! Please use Insert!");
	}
}
void display(){
	if(tail==NULL){
		printf("\nLinkedList is Empty!!");
	}
	else{
		NODE*top=tail->next;
		printf("\nLinkedList :  ");
		while(top!=tail){
			printf("%d ",top->data);
			top=top->next;
		}
		printf("%d\n",top->data);
	}
}
void insert_node(){
	if(tail==NULL){
		printf("\nCreate a node First!!");
	}
	else{
		int n;
		printf("\nEnter the data :  ");
		scanf("%d",&n);
		NODE*temp=(NODE*)malloc(sizeof(NODE));
		temp->data=n;
		temp->next=tail->next;
		tail->next=temp;
		tail=temp;
	}
}
void delete_node(){
	if(tail==NULL){
		printf("\nNo data available for deletion!!");
	}
	else{
		if(tail->next==tail){
			free(tail);
			tail=NULL;
		}
		else{
			NODE*top=tail->next;
			while(top->next!=tail)
				top=top->next;
			top->next=tail->next;
			free(tail);
			tail=top;
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