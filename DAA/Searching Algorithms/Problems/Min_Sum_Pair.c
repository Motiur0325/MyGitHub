#include<stdio.h>
#define n 6

int mod(int x){
	if(x>=0)
		return x;
	else
		return -x;
}
void Min_Sum_Pair(int a[]){
	int u,v,i,j,min=999;
	for(i=0;i<n;i++){
		for(j=0;j<n&&j!=i;j++){
			int q=mod(a[i]+a[j]);
			if(q<min){
				min=q;
				u=i;
				v=j;
			}
		}
	}
	printf("\nSum of Numbers closest to 0 :  %d and %d \n",a[u],a[v]);
}
void Diff_Pair(int b[]){
	int u,v,i,j,key,loc=0;
	printf("\nEnter the difference value :  ");
	scanf("%d",&key);
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			if((b[j]-b[i])==key){
				printf("\nPair Found :  %d and %d",b[j],b[i]);
				loc=1;
			}
		}
	}
	if(loc==1)
		return;
	printf("\nPair not found.");
}
void print(int x[]){
	printf("\nGiven Array :  ");
	for(int i=0;i<n;i++)
		printf("%d ",x[i]);
	printf("\n");
}
void main(){
	int a[n]={1,60,-10,70,-80,85};
	int b[n]={5,20,3,2,50,80};
	print(a);
	Min_Sum_Pair(a);
	print(b);
	Diff_Pair(b);
}