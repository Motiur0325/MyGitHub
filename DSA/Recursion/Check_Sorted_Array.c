#include<stdio.h>
#include<stdbool.h>

//bool isSorted(int *arr,int size){
//	if(size==0||size==1){
//		return true;
//	}
//	if(arr[0]>arr[1])return false;
//	isSorted(arr+1,size-1);
//}
bool isSorted(int arr[],int size){
	if(size==0||size==1)return true;
	if(arr[size-1]<arr[size-2])return false;
	isSorted(arr,size-1);
}
void main(){
	int arr[]={1,2,3,4,5};
	int size=sizeof(arr)/sizeof(arr[0]);
	bool flag=isSorted(arr,size);
	if(flag){
		printf("Array is sorted!");
	}
	else{
		printf("Array is not Sorted!");
	}
}