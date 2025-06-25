#include<stdlib.h>
#include<stdio.h>

struct node{
	int data;
	struct node* next;
}*head=NULL,*tail=NULL;

//void create(int n){
//	struct node temp;
//	temp.data=n;
//	temp.next=NULL;
//	if(head==NULL){
//		head=&temp;
//		tail=&temp;
//	}
//	else{
//		tail->next=&temp;
//		tail=&temp;
//	}
//}
//void display(){
//	struct node*top=head;
//	printf("\nList :  ");
//	while(top->next!=NULL){
//		printf("%d ",top->data);
//		top=top->next;
//	}
//}
//void main(){
//	int n,ch;
//	while(1){
//		printf("\n1.Push\n2.Display\t\tEnter Choice :  ");
//		scanf("%d",&ch);
//		switch(ch){
//			case 1: printf("Enter Data :  ");
//					scanf("%d",&n);
//					create(n);
//					break;
//			case 2: display();
//					break;
//		}
//	}
//}
void main(){
////	int head;
////	int * tail=&head;
////	int *top;
//	struct node head;
//	struct node * tail=NULL;
//	struct node *top=(struct node*)malloc(sizeof(struct node));
////	top=tail;
////	*top=5;
////	printf("%d\t%d\t%d",*top,top,*tail);
//	printf("Head Size :  %d\nTail Size :  %d\nTop :  %d",sizeof(head),sizeof(tail),sizeof(top));
//	int *x=(int*)malloc(sizeof(int));
//	*x=5;
//	printf("%d\t%d\t%d\t",*x,x,&x);
	struct node temp1,temp2;
	temp1.data=5;
	temp2.data=10;
	temp1.next=&temp2;
	temp2.next=NULL;
	head=&temp1;
	printf("%d\t%d\t",head->data,head->next->data);
	printf("%d\t%d\t%d\t%d",temp1.data,temp2.data,temp1.next,temp1.next->data);
}