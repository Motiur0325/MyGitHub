#include<stdio.h>
#include<stdlib.h>

struct node{
	int data;
	struct node *next;
}*head=NULL,*temp,*tail;

void create(){
	int n;
	printf("\nEnter data : ");
	scanf("%d",&n);
	temp=(struct node*)malloc(sizeof(struct node));
	temp->data=n;
	temp->next=NULL;
	if(head==NULL){
		tail=temp;
		head=temp;
	}
	else{
		head->next=temp;
		head=temp;
	}
}
void display(){
	struct node * top;
	top=tail;
	printf("\nList :  ");
	while(top!=NULL){
		printf("%d ",top->data);
		top=top->next;
	}
	printf("\n");
}
void main(){
	int ch;
	while(1){
		printf("1.Create\n2.Display\n3.Exit\t\t\tEnter choice :  ");
		scanf("%d",&ch);
		switch(ch){
			case 1 : create();
					 break;
			case 2 : display();
					 break;
			case 3 : exit(0);
		}
	}
}