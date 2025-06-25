#include<stdio.h>
#include<stdlib.h>
#define MAX 20
int INFO[MAX] = {8,0,22,19,0,33,0,87,50,55,0,2,0,29,99,0,5,0,79};
int LINK[MAX] = {3,0,13,2,0,8,0,14,9,18,0,16,0,5,-1,0,0,0,7};
int PTR,START=11;

void insert();
void print();
void del_info(int);

int main(){
	int ch,del;
	print();
	printf("\n\n1.Insert\n2.Display\n3.Delete\n");
	while(1){
		printf("Enter choice :  ");
		scanf("%d",&ch);
		switch(ch){
			case 1 : insert();
			break;
			case 2 : print();
			break;
			case 3 : printf("Enter the data to be deleted :  ");
					 scanf("%d",&del);
					 del_info(del);
					 break;
			default : exit(0);
		}
	}
}
void insert(){
	int ITEM,i,PTR1=0,count=0;
	for(i=0;i<MAX;i++){
		if(INFO[i]=='\0')
			count++;
	}
	if(count!=0){
		PTR=START;
		printf("Enter the data to be inserted :  ");
		scanf("%d",&ITEM);
		if(ITEM<=2)
			printf("Invalid Input.\n");
		else{
			while(INFO[PTR]<ITEM){
				PTR1=PTR;
				PTR=LINK[PTR];
			}
			for(i=0;i<MAX;i++){
				if(INFO[i]==0&&i!=16){
					INFO[i]=ITEM;
					LINK[PTR1]=i;
					LINK[i]=PTR;
					break;
				}
			}
		}
	}
	else
		printf("Data Overflow.\n");
}
void print(){
	PTR=START;
	printf("List :  ");
	while(PTR!=-1){
		printf("%4d ",INFO[PTR]);
		PTR=LINK[PTR];
	}
	PTR=START;
	printf("\nLink :  ");
	while(PTR!=-1){
		printf("%4d ",PTR);
		PTR=LINK[PTR];
	}
	printf("\n");
}
void del_info(int x){
	int i,PTR1,d=0;
	PTR=START;
	while(PTR!=-1){
		if(INFO[PTR]==x){
			LINK[PTR1]=LINK[PTR];
			INFO[PTR]='\0';
			LINK[PTR]='\0';
			d--;
			break;
		}
		else
			PTR1=PTR;
			PTR=LINK[PTR];
	}
	if(d==0)
		printf("Data Not found.\n");
}