#include<stdio.h>
#include<stdlib.h>

struct node{
	int data;
	struct node *next;
}*head=NULL,*temp,*top,*ptr=NULL,*ptr1=NULL;
void ins_sort(){
	int n;
	printf("Enter data :  ");
	scanf("%d",&n);
	temp=(struct node*)malloc(sizeof(struct node));
	temp->data=n;
	temp->next=NULL;
	if(head==NULL){
		head=temp;
		top=temp;
	}
	else{
		if(n<=top->data){
			temp->next=top;
			top=temp;
		}
		else if(n>=head->data){
			head->next=temp;
			head=temp;
		}
		else{
			ptr=top;
			while(n>ptr->data){
				ptr1=ptr;
				ptr=ptr->next;
			}
			ptr1->next=temp;
			temp->next=ptr;
		}
	}
}
void display(){
	struct node *top1=top;
	printf("\nList :  ");
	while(top1!=NULL){
		printf("%d ",top1->data);
		top1=top1->next;
	}
	printf("\n");
}
void main(){
	int ch;
	while(1){
		printf("1.Insert\n2.Display\t\tEnter Choice :  ");
		scanf("%d",&ch);
		switch(ch){
			case 1 : ins_sort();
					 break;
			case 2 : display();
					 break;
			default : exit(0);
		}
	}
}