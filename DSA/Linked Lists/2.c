#include<stdio.h>
#include<stdlib.h>

int INFO[20] = {8,0,22,19,0,33,0,87,50,55,0,2,0,29,99,0,5,0,79};
int LINK[20] = {3,0,13,2,0,8,0,14,9,18,0,16,0,5,-1,0,0,0,7};
int START;
int SEARCH(int i);

int main(){
	int PTR,LOC,ITEM;
	START=11;
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
	while(1){
		printf("\n\nEnter the item to be searched :  ");
		scanf("%d",&ITEM);
		LOC=SEARCH(ITEM);
		if(LOC==-1){
			printf("\nData item not present.");
			break;
		}
		else
			printf("\nITEM %d is present at %d in LIST.",ITEM,LOC);
	}
}
int SEARCH(int i){
	int P=START;
	int L;
	while(P!=-1){
		if(i>INFO[P])
			P=LINK[P];
		else if(i==INFO[P]){
			L=P;
			return(L);
		}
		else{
			L=-1;
			return(L);
		}
	}
	L=-1;
	return(L);
}