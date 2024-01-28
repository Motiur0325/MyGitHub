#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#define MAX 5
struct node{
	int data;
	struct node *next;
}*head=NULL,*tail=NULL,*top=NULL,*temp;
int count=0;

void push(){
	int n;
	if(count==MAX)
		goto end;
	printf("\t\t\tEnter data :  ");
	scanf("%d",&n);
	temp=(struct node*)malloc(sizeof(struct node));
	temp->data=n;
	temp->next=NULL;
	if(head==NULL){
		head=temp;
		tail=temp;
	}
	else{
		head->next=temp;
		head=temp;
	}
	count++;
	end:
		if(count==MAX)
			printf("Stack Overflow.\n");
		
}
int pop(){
	top=tail;
	if(head==tail){
		head=NULL;
		tail=NULL;
		return(top->data);
	}
	while(top->next!=head){
		top=top->next;
	}
	head=top;
	top=top->next;
	head->next=NULL;
	count--;
	return(top->data);
}
void display(){
	top=tail;
	printf("\nStack :  ");
	while(top!=NULL){
		printf("%d ",top->data);
		top=top->next;
	}
	printf("\n");
}
void main(){
	int ch,x;
	while(1){
		printf("\tStack\n--------------------\n1.Push\n2.Pop\n3.Display\t\tEnter choice :  ");
		scanf("%d",&ch);
		switch(ch){
			case 1 : push();
					 break;
			case 2 : if(head==NULL){
					 printf("Stack Underflow.\n");
					 break;
					 }
					 system("cls");
					 x=pop();
					 printf("\nPopped Value :  %d\n",x);
					 free(top);
					 break;
			case 3 : display();
					 break;
			default : exit(0);
		}
	}
}