#include<stdio.h>
int count=0;
void write(char a[],int start,int end){
	printf("Permutation :  ");
	for(int i=start;i<end;i++){
		printf("%c ",a[i]);
	}
	printf("\n");
}
void Perm(char a[],int k,int n){
	//printf("k : %d ",k);
	if(k==n){
		write(a,0,n);
	}
	else{
		for(int i=k;i<n;i++){
			char t=a[k];
			a[k]=a[i];
			a[i]=t;
			count++;
			printf("k : %d i : %d ",k,i);
			Perm(a,k+1,n);
			printf("k : %d i : %d ",k,i);
			count++;
			t=a[k];
			a[k]=a[i];
			a[i]=t;
		}
	}
}
void main(){
	char a[]={'a','b','c','d'};
	int n=sizeof(a)/sizeof(a[0]);
	Perm(a,0,n);
	printf("Count :  %d",count);
}