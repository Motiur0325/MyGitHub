#include<stdio.h>

void print(int a[],int n){
	for(int i=0;i<n;i++)
		printf("%d ",a[i]);
}
void swap(int*a,int*b){
	int temp=*a;
	*a=*b;
	*b=temp;
}
void Insertion_Sort(int a[],int n){
	int i,j;
	for(i=1;i<n;i++){
		j=i;
		while(j>0&&a[j-1]>a[j]){
			swap(&a[j],&a[j-1]);
			j--;
		}
		printf("\nProcessed Array :  ");
		print(a,n);
	}
}
void main(){
	int a[]={12,11,13,5,6};
	int n=sizeof(a)/sizeof(a[0]);
	printf("Given Array :  ");
	print(a,n);
	Insertion_Sort(a,n);
	printf("\nSorted Array :  ");
	print(a,n);
}