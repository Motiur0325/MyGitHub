#include<stdio.h>
#include<stdlib.h>
#define MAX 5

int front=-1,rear=-1,queue[MAX];

void insert(){
	int n;
	if((rear+1)%MAX==front){
		printf("\nQueue Overflow.\n\n");
		return;
	}
	printf("\t\t\tEnter data :  ");
	scanf("%d",&n);
	if(front==-1&&rear==-1){
		front++;
		rear++;
		queue[rear]=n;
	}
	else{
		rear=(rear+1)%MAX;
		queue[rear]=n;
		printf("\t\t%d\t%d\t\n",front,rear);
	}
}
void del(){
	if(front==-1&&rear==-1)
		printf("\nQueue Underflow.\n\n");
	else{
		if(front==rear&&front!=-1){
			front=-1;
			queue[rear]='\0';
			rear=-1;
		}
		else{
			queue[front]='\0';
			front=(front+1)%MAX;
			printf("\t\t%d\t%d\t\n",front,rear);
		}
	}
}
void display(){
	int front1=front;
	printf("\nQueue :  ");
	while(front1!=rear){
		printf("%d-> ",queue[front1]);
		front1=(front1+1)%MAX;
	}
	printf("%d ",queue[front1]);
	printf("\n\n");
}
void search(){
	int front1=front,x,loc=1,f=0;
	printf("\nEnter the element to be searched :  ");
	scanf("%d",&x);
	while(front1!=rear){
		if(queue[front1]==x){
			goto end;
		}
		else{
			front1=(front1+1)%MAX;
			loc++;
		}
		printf("\t\t%d\t%d\t\n",front,rear);
	}
	if(queue[front1]==x)
		goto end;
	printf("\nElement not found.\n\n");
	return;
	end:
		printf("\n%d is present at %d\n\n",x,loc);
}
void main(){
	int ch;
	while(1){
		printf("1.Insert\n2.Display\n3.Delete\n4.Search\t\tEnter Choice :  ");
		scanf("%d",&ch);
		switch(ch){
			case 1 : insert();
					 break;
			case 2 : display();
					 break;
			case 3 : del();
					 break;
			case 4 : search();
					 break;
			default : exit(0);
		}
	}
}