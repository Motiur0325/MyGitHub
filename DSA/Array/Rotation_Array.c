#include<stdio.h>

void arr_rotation(int arr[],int d,int n){
	int temp[n];
	int j=0;
	for(int i=d;i<n;i++){
		temp[j]=arr[i];
		j++;
	}
	for(int i=0;i<d;i++){
		temp[j]=arr[i];
		j++;
	}
	for(int i=0;i<n;i++){
		arr[i]=temp[i];
	}
}
void print(int arr[],int n){
	for(int i=0;i<n;i++){
		printf("%d ",arr[i]);
	}
	printf("\n");
}
void main(){
	int n,d;
	printf("Enter the no. of elements in array :  ");
	scanf("%d",&n);
	int arr[n];
	for(int i=0;i<n;i++){
		arr[i]=i+1;
	}
	printf("Given Array :  ");
	print(arr,n);
	printf("Enter array rotating position :  ");
	scanf("%d",&d);
	arr_rotation(arr,d,n);
	printf("Array after rotation :  ");
	print(arr,n);
}