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
void Selection_Sort(int a[],int n){
	int i,j,min,min_i;
	for(i=0;i<n;i++){
		min=999;
		for(j=i;j<n;j++){
			if(a[j]<min){
				min=a[j];
				min_i=j;
			}
		}
		swap(&a[min_i],&a[i]);
		printf("\nProcessed Array :  ");
		print(a,n);
	}
}
void main(){
	int a[]={64,25,12,22,11};
	int n=sizeof(a)/sizeof(a[0]);
	printf("Given Array :  ");
	print(a,n);
	Selection_Sort(a,n);
	printf("\nSorted Array :  ");
	print(a,n);
}