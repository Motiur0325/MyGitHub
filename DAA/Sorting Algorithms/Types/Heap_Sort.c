#include<stdio.h>

void swap(int*a,int*b){
	int temp=*a;
	*a=*b;
	*b=temp;
}
void print(int a[],int n){
	for(int i=0;i<n;i++)
		printf("%d ",a[i]);
}
void Heapify(int a[],int n,int i){
	int largest=i;
	int left=2*i+1;
	int right=2*i+2;
	if(a[left]>a[largest]&&left<n)
		largest=left;
	if(a[right]>a[largest]&&right<n)
		largest=right;
	if(largest!=i){
		swap(&a[i],&a[largest]);
		Heapify(a,n,largest);
	}
}
void Heap_Sort(int a[],int n){
	int i;
	for(i=n/2-1;i>=0;i--){
		Heapify(a,n,i);
	}
	printf("\n\nMax Heap :  ");
	print(a,n);
	for(i=n-1;i>=0;i--){
		swap(&a[0],&a[i]);
		Heapify(a,i,0);
		printf("\nProcessed Heap :  ");
		print(a,i);
	}
}
void main(){
	int a[]={ 12, 11, 13, 5, 6, 7 };
	int n=sizeof(a)/sizeof(a[0]);
	printf("Given Heap :  ");
	print(a,n);
	Heap_Sort(a,n);
	printf("\n\nHeapSort :  ");
	print(a,n);
}