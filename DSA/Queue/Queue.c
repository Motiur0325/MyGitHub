#include<stdio.h>
int MAX=5;

void insert(int x,int *F,int *R,int Q[]){
	if(*R==-1&&*F==-1){
		*F=*F+1;
		*R=*R+1;
		Q[*R]=x;	
	}
	else{
		*R=*R+1;
		Q[*R]=x;
	}
}
void del(int *F,int *R){
	if(*F==-1&&*R==-1)
		printf("Queue Underflow.\n");
	else if(*F==*R&&*F!=-1){
		*F=-1;
		*R=-1;
	}
	else{
		*F=*F+1;
		if(*R==MAX-1)
			MAX=6;
	}
}
void display(int *F,int *R,int Q[]){
	int i;
	if(*F==*R&&*F==-1)
		printf("Queue underflow");
	else{
		printf("\nQueue :  ");
		for(i=*F;i<*R+1;i++){
			printf("%d ",Q[i]);
		}
		printf("\n");
	}
}
void main(){
	int FRONT=-1,REAR=-1,queue[MAX],ch,n;
	while(1){
		printf("\n1.Insert\n2.Display\n3.Delete\t\tEnter Choice :  ");
		scanf("%d",&ch);
		printf("\t\t\t");
		switch(ch){
			case 1 : if(REAR==MAX-1){
					 	printf("\nOverflow.\n");
						break;
					 }
					 printf("Enter data :  ");
					 scanf("%d",&n);
					 insert(n,&FRONT,&REAR,queue);
					 break;
			case 2 : display(&FRONT,&REAR,queue);
					 break;
			case 3 : del(&FRONT,&REAR);
					 break;
		}
	}
}