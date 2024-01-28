#include<stdio.h>

int A[7]={90,77,60,99,55,88,66};
int N=7,r=0;

int right(int loc1,int E,int B){
	int right=E,temp;
	printf("Dark :  %d\t",E);
	while(A[right]>=A[loc1]&&loc1!=right)
		right=right-1;
	printf("Light :  %d\t\t",right);
	if(loc1==right){
		printf("\n\nNothing could be done right...........\t%d",loc1);
		return(right);
	}
	if(A[loc1]>A[right]){
		A[right]=temp;
		A[right]=A[loc1];
		A[loc1]=temp;
		printf("\t\t%d Here1",loc1);
		loc1=right;
		printf("\t\t%d Here2",loc1);
		left(loc1,B,E);
	}
}
int left(int loc1,int B,int E){
	int left=B,temp;
	while(A[left]<=A[loc1]&&loc1!=left){
		left=left+1;
		printf("\t\t%d Now",left);
	}
	if(left==loc1){
		return(left);
	}
	if(A[left]>A[loc1]){
		A[left]=temp;
		A[left]=A[loc1];
		A[loc1]=temp;
		printf("\t\t%d There1",loc1);
		loc1=left;
		right(loc1,E,B);
		printf("\t\t%d Ther2",loc1);
	}
}

void main(){
	int loc,up[7],low[7],top,beg,end,count=0,i;
	printf("Unsorted List :  ");
	for(i=0;i<N;i++)
		printf("%d ",A[i]);
	top=-1;
	if(N>1){
		top++;
		low[top]=0;
		up[top]=N-1;
	}
	while(top!=-1){
		beg=low[top];
		end=up[top];
		printf("\t\tEND :  %d\t",end);
		top--;
		loc=right(loc,end,beg);
		printf("\n\nNothing could be done both...........\t%d",loc);
		if(beg<loc-1){
			top++;
			low[top]=beg;
			up[top]=loc-1;
		}
		else{
			if(end>loc+1){
				top++;
				printf("\t%d\t",top);
				low[top]=loc+1;
				up[top]=end;
			}
		}
		count++;
	}
	printf("\n\nSorted List :  %d\t\t",count);
	for(i=0;i<N;i++)
		printf("%d ",A[i]);
}