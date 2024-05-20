#include<stdio.h>
#include<stdlib.h>

struct stack{
	int data;
	struct stack *next;
}*top=NULL,*head=NULL;

void stack_push(int n){
	struct stack*temp=(struct stack*)malloc(sizeof(struct stack));
	temp->data=n;
	temp->next=NULL;
	if(top==NULL){
		head=temp;
		top=temp;
	}
	else{
		top->next=temp;
		top=temp;
	}
}
void stack_display(){
	struct stack*show=head;
	printf("\nStack :  ");
	while(show!=NULL){
		printf("%d ",show->data);
		show=show->next;
	}
}
struct stack stack_pop(){
	struct stack temp;
	temp=*top;
	if(top==head){
		head=NULL;
		free(top);
		top=NULL;
		return temp;
	}
	struct stack*show=head;
	while(show->next!=top){
		show=show->next;
	}
	show->next=NULL;
	free(top);
	top=show;
	return temp;
}
void main(){
	int ch,n;
	while(1){
//		printf("\nTop :  %d",top);
		printf("\n\n1.PUSH\n2.DISPLAY\n3.POP\t\tEnter Choice :  ");
		scanf("%d",&ch);
		switch(ch){
			case 1: printf("\nEnter data :  ");
					scanf("%d",&n);
					stack_push(n);
					break;
			case 2: if(top==NULL){
						printf("\nStack is Empty!!");
						break;
					}
					stack_display();
					break;
			case 3: if(top==NULL){
						printf("\nStack is Empty!!");
						break;
					}
					struct stack temp=stack_pop();
					printf("\nPopped value :  %d",temp.data);
					break;
		}
	}	
}