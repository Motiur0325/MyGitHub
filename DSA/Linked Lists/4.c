#include<stdio.h>
#define MAX 5

int top=-1,stack[MAX],count=0;

void push(int x){
	top++;
	stack[top]=x;
	count++;
}
int pop(void){
	int m=stack[top];
	stack[top]=NULL;
	top--;
	count--;
	return(m);
}
void display(){
	printf("\nStack :  ");
	for(int i=top;i!=-1;i--){
		printf("%d ",stack[i]);
	}
	printf("\n");
}
void main(){
	int ch,n;
	while(1){
		printf("\tStack\n------------------------\n1.Push\n2.Pop\n3.Display\t\tEnter choice :  ");
		scanf("%d",&ch);
		switch(ch){
			case 1 : if(top==MAX-1){
				 	 	printf("Stack Overflow.\n");
				 	 	break;
					 }
					 else{
					 	printf("\t\t\tEnter data :  ");
					 	scanf("%d",&n);
					 	push(n);
					 }
					 break;
			case 2 : if(top==-1){
					 	printf("Stack Underflow.\n");
					 }
					 else{
					 	n=pop();
					 	printf("Popped Value :  %d\n",n);
					 }
					 break;
			case 3 : if(top==-1)
						printf("Stack Empty.\n");
					 else
					 	display();
					 break;
			default : exit(0);
		}
	}
}