#include<stdio.h>
#include<stdlib.h>

struct node{
	int data;
	int prt;
	struct node *next;
}*head=NULL,*temp,*head1=NULL;

void insert(){
	struct node *top1=NULL,*top=NULL;
	int m,n;
	printf("\t\t\tEnter data :  ");
	scanf("%d",&n);
	printf("\t\t\tEnter priority :  ");
	scanf("%d",&m);
	temp=(struct node*)malloc(sizeof(struct node));
	temp->data=n;
	temp->prt=m;
	temp->next=NULL;
	if(head==NULL){
		head=temp;
		head1=temp;
	}
	else{
		top=head1;
		while(temp->prt<=top->prt&&top!=head){
			top1=top;
			top=top->next;
		}
		if(temp->prt<=head->prt){
			head->next=temp;
			head=temp;
		}
		else if(top1==NULL){
			temp->next=head1;
			head1=temp;
		}
		else{
			top1->next=temp;
			temp->next=top;
		}
	}
}
void del(){
	struct node *ptr=head1;
	if(head1==head){
		free(head);
		head=NULL;
		head1=NULL;
		return;
	}
	head1=head1->next;
	free(ptr);
}
void display(){
	struct node *ptr=NULL;
	ptr=head1;
	printf("\nPriority Queue :  ");
	while(ptr!=NULL){
		printf("%d[%d] ",ptr->data,ptr->prt);
		ptr=ptr->next;
	}
	printf("\n");
}
void main(){
	int ch;
	while(1){
		printf("\n1.Insert\n2.Display\n3.Delete\t\tEnter Choice :  ");
		scanf("%d",&ch);
		switch(ch){
			case 1 : insert();
					 break;
			case 2 : display();
					 break;
			case 3 : del();
					 break;
			default : exit(0);
		}
	}
}