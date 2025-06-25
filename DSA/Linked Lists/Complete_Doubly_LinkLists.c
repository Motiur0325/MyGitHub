#include<stdio.h>
#include<stdlib.h>
struct node{
	int data;
	struct node *next;
	struct node *prev;
}*head=NULL,*temp,*head1=NULL,*top=NULL;
int count=0;
void ins_ending(int x){
	temp=(struct node*)malloc(sizeof(struct node));
	temp->data=x;
	temp->next=NULL;
	temp->prev=NULL;
	if(head==NULL){
		temp->prev=head;
		head=temp;
		top=temp;
	}
	else{
		head->next=temp;
		temp->prev=head;
		head=temp;
	}
	count++;
}
void ins_beg(int x ){
	temp=(struct node*)malloc(sizeof(struct node));
	temp->data=x;
	temp->prev=NULL;
	if(head==NULL){
		temp->next=head;
		head=temp;
		top=temp;
	}
	else{
		temp->next=top;
		top->prev=temp;
		top=temp;
	}
	count++;
}
void display_front(){
	head1=top;
	printf("\nList :  ");
	while(head1!=NULL){
		printf("%d ",head1->data);
		head1=head1->next;
	}
	printf("\n");
}
void display_reverse(){
	head1=head;
	printf("\nList :  ");
	while(head1!=NULL){
		printf("%d ",head1->data);
		head1=head1->prev;
	}
	printf("\n");
}
void search(int x){
	int count1=1,count2=1;
	head1=top;
	while(head1->data!=x&&count1!=count){
		head1=head1->next;
		count1++;
	}
	head1=head;
	while(head1->data!=x&&count2!=count){
		head1=head1->prev;
		count2++;
	}
	if(count1==count2&&count1==count&&head==NULL){
		printf("\nData item not found.\n");
	}
	else{
		printf("\nData %d is present at position %d from front and %d from rear.\n",x,count1,count2);
	}
}
void del(int x){
	int i=0;
	if(head==NULL){
		printf("\nList is empty.\n");
	}
	else{
		head1=top;
		while(i!=x){
			if(head==top){
				top=NULL;
				free(top);
				goto end;
			}
			else{
				if(i>=1)
					head1=head1->next;
			}
			i++;
		}
		if(head1->prev==NULL){
			top=head1->next;
			head1->next->prev=NULL;
			free(head1);
		}
		else if(head1->next==NULL){
			head=head1->prev;
			head->next=NULL;
			free(head1);
		}
		else{
			head1->prev->next=head1->next;
			head1->next->prev=head1->prev;
			free(head1);
		}
		end:
			count--;
			printf("\n");
	}
}
void list_count(){
	printf("\n\t\tData items in list :  %d\n",count);
}

void main(){
	int ch,c,n;
	while(1){
		printf("1.Insert\n2.Display\n3.Search\n4.Delete\n5.Count\t\tEnter Choice :  ");
		scanf("%d",&ch);
		switch(ch){
			case 1 : printf("\n1.Beginning\n2.Ending\tEnter Choice :  ");
					 scanf("%d",&c);
					 printf("\t\tEnter data :  ");
					 scanf("%d",&n);
					 switch(c){
					 	case 1 : ins_beg(n);
					 			 break;
					 	case 2 : ins_ending(n);
						 		 break; 
						default : break;
					 }
					 break;
			case 2 : if(count==0){
						 printf("\nNothing here.\n\n");
						 break;
					 }
					 printf("\n1.Front\n2.Reverse\tEnter Choice :  ");
					 scanf("%d",&c);
					 switch(c){
					 	case 1 : display_front();
					 			 break;
					 	case 2 : display_reverse();
					 			 break;
					 	default : break;
					 }
					 printf("\n");
					 break;
			case 3 : if(count>0){
						 printf("Enter the element to be searched :  ");
						 scanf("%d",&n);
						 search(n);
					 }
					 else
					 	printf("\nList is empty.\n");
					 break;
			case 4 : if(count<=1){
						 del(1);
					 }
					 else{
					 	printf("Enter the position of element to be deleted :  ");
					 	scanf("%d",&n);
					 	if(n<=count){
					 		del(n);
						 }
					 }
					 break;
			case 5 : list_count();
					 break;
			default : exit(0);
		}
	}
}