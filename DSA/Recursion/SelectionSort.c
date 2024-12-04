#include<stdio.h>

void swap(int*a,int*b){
	int temp=*a;
	*a=*b;
	*b=temp;
}
void printArray(int arr[],int start,int end){
	printf("Array :  ");
	for(int i=start;i<end;i++){
		printf("%d ",arr[i]);
	}
	printf("\n");
}
void SelectionSort(int*arr,int size){
//	printArray(arr,0,size);
	//base case
	if(size==1||size==0)return;
	//process
	for(int i=0;i<size;i++){
		if(arr[0]>arr[i]){
			swap(&arr[0],&arr[i]);
		}
	}
	//recursivecall
	SelectionSort(arr+1,size-1);
}
void main(){
	int arr[]={2,6,4,1,8,0};
	int size=sizeof(arr)/sizeof(int);
	printArray(arr,0,size);
	SelectionSort(arr,size);
	printArray(arr,0,size);
}