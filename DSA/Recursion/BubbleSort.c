#include<stdio.h>

void swap(int*a,int*b){
	int temp=*a;
	*a=*b;
	*b=temp;
}
void BubbleSort(int arr[],int size){
	if(size==0||size==1)return;
	for(int i=0;i<size-1;i++){
		if(arr[i]>arr[i+1]){
			swap(&arr[i],&arr[i+1]);
		}
	}
	BubbleSort(arr,size-1);
}
void printArray(int arr[],int size){
	printf("Array :  ");
	for(int i=0;i<size;i++){
		printf("%d ",arr[i]);
	}
	printf("\n");
}
void main(){
	int arr[]={2,6,4,1,8,0};
	int size=sizeof(arr)/sizeof(int);
	printArray(arr,size);
	BubbleSort(arr,size);
	printArray(arr,size);
}