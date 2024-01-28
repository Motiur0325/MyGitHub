#include<stdio.h>
#include<stdlib.h>

struct node{
	int data;
	struct node *next;
}*temp,*last1=NULL,*temp1=NULL,*del=NULL;

struct node *last=NULL;
int count=0;

void create(){
	int n;
	printf("\t\t\tEnter data :  ");
	scanf("%d",&n);
	temp=(struct node*)malloc(sizeof(struct node));
	temp->data=n;
	last=temp;
	temp->next=last;
	count++;
}
void ins_beg(int x){
	temp=(struct node*)malloc(sizeof(struct node));
	temp->data=x;
	temp->next=last->next;
	last->next=temp;
	count++;
}
void ins_last(int x){
	temp=(struct node*)malloc(sizeof(struct node));
	temp->data=x;
	temp->next=last->next;
	last->next=temp;
	last=temp;
	count++;
}
void ins_pos(int x,int y){
	int i=1;
	temp=(struct node*)malloc(sizeof(struct node));
	if(x==count+1){
		ins_last(y);
	}
	else if(x==i){
		ins_beg(y);
	}
	else{
		temp->data=y;
		last1=last;
		while(i!=x){
			last1=last1->next;
			i++;
		}
		temp->next=last1->next;
		last1->next=temp;
		count++;
	}
}
void data_del(int x){
	int i=1,pos=0;
	if(last==NULL){
		printf("List is empty.\n");
	}
	else if(x==i){
		if(count==i){
			free(last);
			last=NULL;
		}
		else{
			last1=last->next;
			last->next=last1->next;
			free(last1);
		}
	}
	else if(x==count){
		last1=last->next;
		while(last1->next!=last){
			last1=last1->next;
		}
		last=last1;
		last1=last->next;
		last->next=last1->next;
		free(last1);
	}
	else if(x<count){
		last1=last->next;
		while(i!=x-1){
			last1=last1->next;
			i++;
		}
		del=last1->next->next;
		free(last1->next);
		last1->next=del;
	}
	else
		pos=1;
	if(pos==0)
		count--;
	else
		printf("\nDeletion not possible.\n\n");
}
void display(){
	if(last==NULL)
		printf("Underflow.\n");
	else{
		last1=last->next;
		printf("\nList :  ");
		while(last1!=last){
			printf("%d->",last1->data);
			last1=last1->next;
		}
		printf("%d\n",last1->data);
	}
}

void main(){
	int ch,loc,c,n;
	while(1){
		printf("\n1.Create\n2.Insert\n3.Display\n4.Delete\n5.Count\t\t\tEnter Choice :  ");
		scanf("%d",&ch);
		switch(ch){
			case 1 : if(last==NULL)
						create();
					 else
					 	printf("\nList already created.\n");
					 break;
			case 2 : if(last!=NULL){
						 printf("\n1.Beginning\n2.Any Position\n3.Ending\t\tEnter Choice :  ");
						 scanf("%d",&c);
						 printf("\n\t\t\tEnter data :  ");
						 scanf("%d",&n);
						 switch(c){
						 	case 1 : ins_beg(n);
						 			 break;
						 	case 2 : printf("Enter the position :  ");
						 			 scanf("%d",&loc);
						 			 if(loc>count+1)
						 			 	printf("Invalid position.\n");
						 			 else{
							 			 ins_pos(loc,n);
							 		 }
					
					 				 break;
					 		case 3 : ins_last(n);
					 			 	 break;
					 		default : exit(0);
					 	 }
					 }
					 else
					 	printf("\nCreate a list first.\n");
					 break;
			case 3 : display();
					 break;
			case 4 : if(count==0)
					 	printf("\t\t\tList is empty\n");
					 else{
					 	printf("Enter location of data to be deleted :  ");
					 	scanf("%d",&loc);
					 	data_del(loc);
					 }
					 break;
			case 5 : printf("\t\t\tData items present :  %d\n",count);
					 break;
			default : exit(0);
		}
	}
}