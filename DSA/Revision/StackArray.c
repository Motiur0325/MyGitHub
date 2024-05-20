#include<stdio.h>

void main(){
	int ch,n;
	int top=-1,pop;
	int *arr;
	while(1){
//		printf("\nTop :  %d",top);
		printf("\n\n1.PUSH\n2.DISPLAY\n3.POP\t\tEnter Choice :  ");
		scanf("%d",&ch);
		switch(ch){
			case 1: printf("\nEnter data :  ");
					scanf("%d",&n);
//					top++;
					*(arr+(++top))=n;
					break;
			case 2: if(top==-1){
						printf("\nStack is Empty!!");
						break;
					}
					printf("\nStack :  ");
					for(int i=top;i>-1;i--){
						printf("%d ",*(arr+i));
					}
					break;
			case 3: if(top==-1){
						printf("\nStack is Empty!!");
						break;
					}
					pop=*(arr+(top--));
					printf("\nPopped Value :  %d",pop);
					break;
		}
	}	
}