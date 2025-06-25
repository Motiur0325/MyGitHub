#include<stdio.h>
#include<stdlib.h>
#define MAX 5
struct node{
	int data;
	struct node *next;
}*front=NULL,*rear=NULL,*temp;

void insert(int *count){
	int n;
	if(*count==MAX){
		printf("\t\t\tQueue Overflow.\n");
		return;
	}
	printf("\t\t\tEnter data :  ");
	scanf("%d",&n);
	temp=(struct node*)malloc(sizeof(struct node));
	temp->data=n;
	temp->next=NULL;
	if(front==NULL&&rear==NULL){
		front=temp;
		rear=temp;
		*count=*count+1;
	}
	else{
		rear->next=temp;
		rear=temp;
		*count=*count+1;
	}
}
void del(int *count){
	struct node *front1;
	front1=front;
	if(rear==front&&front!=NULL){
		front=NULL;
		free(rear);
		rear=NULL;
		*count=*count-1;
	}
	else if(front==NULL&&rear==NULL)
		printf("\n\t\t\tQueue Underflow.\n");
	else{
		front=front->next;
		free(front1);
		*count=*count-1;
	}
	printf("\n");
}
void display(){
	struct node *front1;
	front1=front;
	printf("\nQueue :  ");
	while(front1!=NULL){
		printf("%d ",front1->data);
		front1=front1->next;
	}
	printf("\n\n");
}
void main(){
	int ch,count=0;
	while(1){
		printf("1.Insert\n2.Display\n3.Delete\t\tEnter Choice :  ");
		scanf("%d",&ch);
		switch(ch){
			case 1 : insert(&count);
					 break;
			case 2 : display();
					 break;
			case 3 : del(&count);
					 break;
			default : exit(0);
		}
	}
}