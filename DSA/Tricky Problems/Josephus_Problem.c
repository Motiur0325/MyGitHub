#include<stdio.h>
#include<stdlib.h>

struct node{
	int data;
	struct node *next;
}*temp,*last1=NULL,*last2=NULL;
struct node *last=NULL;
int N,order[1000],count=0;

void create(int);
void display();
void eliminate(int);
int del_order(int);
void order_display();

void main(){
	int M;
	printf("Enter the number of victims :  ");
	scanf("%d",&N);
	printf("\nEnter the position of victim to be killed :  ");
	scanf("%d",&M);
	create(N);
	display();
	eliminate(M);
	order_display();
}
void create(int n){
	int i=0;
	while(i!=n){
		temp=(struct node*)malloc(sizeof(struct node));
		if(last==NULL){
			i++;
			temp->data=i;
			last=temp;
			temp->next=last;
		}
		else{
			i++;
			temp->data=i;
			temp->next=last->next;
			last->next=temp;
			last=temp;
		}
		count++;
	}
}
void display(){
	last2=last->next;
	printf("\nList :  ");
	while(last2!=last){
		printf("%d ",last2->data);
		last2=last2->next;
	}
	printf("%d\n",last2->data);
}
void eliminate(int x){
	int i;
	last1=last->next;
	while(count>1){
		i=1;
		while(i!=x){
			last2=last1;
			last1=last1->next;
			i++;
		}
		if(last1==last){
			last1=last->next;
			last=last2;
		}
		else{
			last1=last1->next;
		}
		del_order(last2->next->data);
		free(last2->next);
		last2->next=last1;
		count--;
		display();
	}
	if(count==1){
		printf("\nThe victim at position %d will be spared.",last1->data);
	}
}
int del_order(int x){
	int i=N;
	i=N-count;
	order[i]=x;
}
void order_display(){
	int j;
	printf("\n\nExtermination Order :  ");
	for(j=1;j<N;j++){
		printf("%d ",order[j-1]);
	}
}