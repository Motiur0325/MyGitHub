#include<stdio.h>
#include<stdlib.h>
#define MAX 5

int front=-1,rear=-1,Q[MAX];

void ins_front(int x){
	if(front==-1&&rear==-1){
		front=0;
		rear=0;
		Q[front]=x;
	}
	else if(front==0){
		front=MAX-1;
		Q[front]=x;
	}
	else{
		front--;
		Q[front]=x;
	}
}
void ins_rear(int x){
	if((rear+1)%MAX==front){
		printf("\nQueue Overflow.\n");
		return;
	}
	if(front==-1&&rear==-1){
		front=0;
		rear=0;
		Q[rear]=x;
	}
	else{
		rear=(rear+1)%MAX;
		Q[rear]=x;
	}
}
void del_front(){
	if(front==-1&&rear==-1){
		printf("\nQueue Underflow.\n");
		return;
	}
	else if(front==rear){
		Q[front]='\0';
		front=-1;
		rear=-1;
	}
	else{
		Q[front]='\0';
		front=(front+1)%MAX;
	}
}
void del_rear(){
	if(front==-1&&rear==-1){
		printf("\nQueue Underflow.\n");
		return;
	}
	else if(front==rear){
		Q[rear]='\0';
		rear=-1;
		front=-1;
	}
	else if(rear==0){
		Q[rear]='\0';
		rear=MAX-1;
	}
	else{
		Q[rear]='\0';
		rear--;
	}
}
void display(){
	int i;
	printf("\nDequeue :  ");
	for(i=front;i!=rear;i=(i+1)%MAX)
		printf("%d ",Q[i]);
	printf("%d\n\n",Q[i]);
	
}
void get_front(){
	printf("\nFront Element :  %d\n",Q[front]);
}
void get_rear(){
	printf("\nRear Element :  %d\n",Q[rear]);
}
void isfull(){
	if((rear+1)%MAX==front)
		printf("\nFull!!!!!!.\n");
	else
		printf("\nNot Full??????.\n");
}
void isempty(){
	if(rear==-1&&front==-1)
		printf("\nEmpty!!!!.\n");
	else
		printf("\nNot Empty?????.\n");
}
void main(){
	int ch,c,n;
	while(1){
		printf("\n1.Insert\n2.Delete\n3.Display\n4.Get_Front\n5.Get_Rear\n6.Full or Empty\t\t\tEnter Choice :  ");
		scanf("%d",&ch);
		switch(ch){
			case 1 : if((rear+1)%MAX==front){
					 printf("\nQueue Overflow.\n");
					 break;
					 }
					 printf("\n1.Front\n2.Rear\t\t\t\tEnter Choice :  ");
					 scanf("%d",&c);
					 printf("\n\t\t\t\tEnter data :  ");
					 scanf("%d",&n);
					 switch(c){
					 	case 1 : ins_front(n);
					 			 break;
						case 2 : ins_rear(n);
							 	 break;
						}
					 break;
			case 3 : display();
					 break;
			case 2 : printf("\n1.Front\n2.Rear\t\tEnter Choice :  ");
					 scanf("%d",&c);
					 switch(c){
					 	case 1 : del_front();
					 			 break;
					 	case 2 : del_rear();
					 			 break;
					 }
					 break;
			case 4 : get_front();
					 break;
			case 5 : get_rear();
					 break;
			case 6 : isfull();
					 isempty();
					 break;
			default : exit(0);
		}
	}
}