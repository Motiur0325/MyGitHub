#include<stdio.h>

int upper[30],lower[30],loc=0,beg=0;

void quick_sort(int x[],int MAX){
	int R=MAX-1,L=0,temp,end=MAX-1;
	loop :
		while(R!=loc){
			if(x[loc]>x[R]){
				temp=x[R];
				x[R]=x[loc];
				x[loc]=temp;
				loc=R;
				printf("\t%d\t",x[loc]);
			}
			else
				R--;
		}
		while(L!=loc){
			if(x[loc]<x[L]){
				temp=x[L];
				x[L]=x[loc];
				x[loc]=temp;
				loc=L;
			}
			else
				L++;
			}
	if(check(loc,MAX,x)==5)
		return;
	else
		goto loop;
}
int check(int loc,int MAX,int x[]){
	int end=MAX-1;
	while(beg!=loc){
		if(x[beg]<x[loc])
			beg++;
		else
			return;
	}
	while(end!=loc){
		if(x[end]>x[loc])
			end--;
		else
			return;
	}
	if(beg==loc&&end==loc){
		return(5);
	}
	else
		return(0);
}
void display(int x[],int MAX){
	printf("\n\nSorted list :  ");
	for(int i=0;i<MAX;i++){
		printf("%d ",x[i]);
	}
}
void main(){
	int N=7,i,A[30]={90,77,60,99,55,88,66};
	/*printf("Enter the no. of elements :  ");
	scanf("%d",&N);
	printf("\nEnter the elements\n=====================\n");
	for(i=0;i<N;i++){
		printf("A[%d] :  ",i);
		scanf("%d",&A[i]);
	}*/
	quick_sort(A,N);
	display(A,N);
	N=loc;
	loc=beg;
	printf("\n%d\n",beg);
	quick_sort(A,N-1);
	display(A,N);
}