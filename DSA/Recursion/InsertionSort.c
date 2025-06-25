#include<stdio.h>

void printArray(int arr[],int start,int end){
	printf("Array :  ");
	for(int i=start;i<end;i++){
		printf("%d ",arr[i]);
	}
	printf("\n");
}
void InsertionSort(int arr[],int change,int size){
	//base case
	if(size==0||size==1)return;
	int j=0,temp=arr[1];
	while(j>=change*-1&&temp<=arr[j]){
		arr[j+1]=arr[j];
		j-=1;	
	}
	arr[j+1]=temp;
	//recursivecall
	InsertionSort(arr+1,change+1,size-1);
}
void main(){
	int arr[]={2,6,4,1,8,0};
	int size=sizeof(arr)/sizeof(int);
	printArray(arr,0,size);
	InsertionSort(arr,0,size);
	printArray(arr,0,size);
}