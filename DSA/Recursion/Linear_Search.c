#include<stdio.h>

int LinearSearch(int arr[],int size,int key){
	if(size==0)return -1;
	if(arr[size-1]==key)return size-1;
	LinearSearch(arr,size-1,key);
}
void main(){
	int arr[]={1,2,4,3,5,6};
	int size=sizeof(arr)/sizeof(arr[0]);
	int key=10;
	int ans=LinearSearch(arr,size,key);
	if(ans==-1){
		printf("Element not found!");
	}
	else{
		printf("%d found at %d!",key,ans);
	}
}