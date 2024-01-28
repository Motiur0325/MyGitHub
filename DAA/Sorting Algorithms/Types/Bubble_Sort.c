#include<stdio.h>

void print(int a[],int n){
	for(int i=0;i<n;i++)
		printf("%d ",a[i]);
}
void swap(int *a,int *b){
	int temp=*a;
	*a=*b;
	*b=temp;
}
void Bubble_Sort(int a[],int n){
	int i,j;
	for(i=0;i<n-1;i++){
		for(j=0;j<n-i-1;j++){
			if(a[j]>a[j+1])
				swap(&a[j],&a[j+1]);
		}
	}
}
void main(){
	int a[]={5,1,3,2,4};
	int n=sizeof(a)/sizeof(a[0]);
	printf("Given Array :  ");
	print(a,n);
	Bubble_Sort(a,n);
	printf("\nSorted Array :  ");
	print(a,n);
}