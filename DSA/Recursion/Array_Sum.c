#include<stdio.h>

int getSum(int *arr,int size){
	if(size==1){
		return *arr;
	}
	else{
		return *arr+getSum(arr+1,size-1);
	}
}
void main(){
	int arr[]={1,2,3,4,5};
	int size=sizeof(arr)/sizeof(arr[0]);
	printf("Sum :  %d",getSum(arr,size));
}