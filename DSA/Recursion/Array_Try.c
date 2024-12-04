#include<stdio.h>

void fun(int arr[],int size){
	for(int i=-2;i<size;i++){
		printf("%d ",arr[i]);
	}
}
void main(){
	int arr[]={1,2,3,4,5};
	fun(arr+2,5);
}