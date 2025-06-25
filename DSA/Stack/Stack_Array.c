#include<stdio.h>
#define MAX 5

int push(int x,int *top,int stack[]){
	*top=*top+1;
	stack[*top]=x;
}
int pop(int stack[],int *top){
	int m=stack[*top];
	stack[*top]=NULL;
	*top=*top-1;
	return(m);
}
void display(int *top,int stack[]){
	printf("\nStack :  ");
	for(int i=*top;i!=-1;i--){
		printf("%d ",stack[i]);
	}
	printf("\n");
}
void main(){
	int top=-1,stack[MAX],ch,n;
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
					 	push(n,&top,stack);
					 }
					 break;
			case 2 : if(top==-1){
					 	printf("Stack Underflow.\n");
					 }
					 else{
					 	n=pop(stack,&top);
					 	printf("Popped Value :  %d\n",n);
					 }
					 break;
			case 3 : if(top==-1)
						printf("Stack Empty.\n");
					 else
					 	display(&top,stack);
					 break;
			default : exit(0);
		}
	}
}