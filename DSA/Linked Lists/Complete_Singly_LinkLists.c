#include<stdio.h>
#include<stdlib.h>
struct node{
	int data;
	struct node *next;
}*head=NULL,*temp,*head1=NULL,*top=NULL,*del=NULL,*head2=NULL;

int count=0;

void create(int x){
	temp=(struct node*)malloc(sizeof(struct node));
	temp->data=x;
	temp->next=NULL;
	head=temp;
	head1=head;
	count++;
}
void display(){
	top=head1;
	printf("\nLinked list :  ");
	while(top!=NULL){
		printf("%d ",top->data);
		top=top->next;
	}
	printf("\n\n");
}
void ins_beg(){
	temp->next=head1;
	head1=temp;
	count++;
}
void ins_pos(int y){
	int i=1;
	top=head1;
	while(i!=y-1){
		top=top->next;
		i++;
	}
	temp->next=top->next;
	top->next=temp;
	count++;
}
void ins_end(){
	temp->next=NULL;
	head->next=temp;
	head=temp;
	count++;
}
void del_beg(){
	if(head1==head){
		head=NULL;
	}
	else{
		top=head1;
		head1=head1->next;
		free(top);
	}
	count--;
}
void del_pos(int x){
	int i=1;
	if(head1==head){
		head=NULL;
	}
	else{
		if(i==x){
			head1=head1->next;
			free(top);
		}
		else{
			top=head1;
			while(i!=x-1){
				top=top->next;
				i++;
			}
			del=top->next->next;
			free(top->next);
			top->next=del;
		}
	}
	count--;
}
void del_end(){
	if(head==head1){
		head=NULL;
	}
	else{
		top=head1;
		while(top->next!=head){
			top=top->next;
		}
		head=top;
		free(head->next);
		head->next=NULL;
	}
	count--;
}
void list_count(){
	printf("Total No. of data items :  %d\n",count);
}
void rev_list(){
	head2=head;
	loop:
		top=head1;
		while(top->next!=head){
			top=top->next;
		}
		head->next=top;
		head=top;
		if(head==head1){
			head->next=NULL;
			head1=head2;
			printf("\n");
			return;
		}
		else
			goto loop;
}
void main(){
	int ch,n,c,loc;
	while(1){
		printf("1.Create\n2.Insert\n3.Display\n4.Delete\n5.Count\n6.Reverse\t\tEnter choice :  ");
		scanf("%d",&ch);
		printf("\t\t\t");
		switch(ch){
			case 1 : if(head!=NULL){
					 	printf("List already created.\n\t\t\tUse insert option to edit list.\n\n");
						break;
					}
					 printf("Enter Data :  ");
					 scanf("%d",&n);
					 create(n);
					 break;
			case 2 : if(head==NULL){
					 	printf("Create a list first.\n\n");
					 	break;
					 }
		  			 printf("\n1.Beginning\n2.Any Position\n3.Ending\n\nEnter Choice :  ");
					 scanf("%d",&c);
					 temp=(struct node*)malloc(sizeof(struct node));
					 printf("Enter Data :  ");
					 scanf("%d",&n);
					 temp->data=n;
					 switch(c){
					 	case 1 : 
					 			 ins_beg();
					 			 break;
					 	case 2 : printf("Enter the position :  ");
					 			 scanf("%d",&loc);
					 			 if(loc==1||loc==count+1)
					 			 	printf("Invalid position.\n");
					 			 else{
						 			 ins_pos(loc);
						 		 }
					 			 break;
					 	case 3 : ins_end();
					 			 break;
					 	default : exit(0);
					 }
					 break;
			case 3 : display();
					 break;
			case 4 : if(count>0){
						 printf("\n1.Beginning\n2.Any Position\n3.Ending\n\nEnter Choice :  ");
						 scanf("%d",&c);
						 switch(c){
						 	case 1 : del_beg();
						 			 break;
						 	case 2 : printf("Enter position :  ");
						 			 scanf("%d",&loc);
						 			 if(loc>count)
						 			 	printf("Nothing here.\n");
						 			 else
						 			 	del_pos(loc);
						 			 break;
						 	case 3 : del_end();
						 			 break;
						 	default : exit(0);
						 }
					 }
					 else
					 	printf("Data Underflow.\n");
					 break;
			case 5 : list_count();
					 break;
			case 6 : rev_list();
					 break;
			default : exit(0);
		}
	}
}