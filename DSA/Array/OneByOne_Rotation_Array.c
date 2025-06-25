#include<stdio.h>

void print(int arr[],int n){
	for(int i=0;i<n;i++){
		printf("%d ",arr[i]);
	}
	printf("\n");
}
void arr_left_rotation(int arr[],int d,int n){
	int j=0,i;
	while(j<d){
		int x=arr[0];
		for(int i=1;i<n;i++){
			arr[i-1]=arr[i];
		}
		arr[n-1]=x;
		printf("Rotating :  ");
		print(arr,n);
		j++;
	}
}
void arr_right_rotation(int arr[],int d,int n){
	int j=n;
	while(j>d){
		int x=arr[n-1];
		for(int i=n-2;i>=0;i--){
			arr[i+1]=arr[i];
		}
		arr[0]=x;
		printf("Rotating :  ");
		print(arr,n);
		j--;
	}
}
void main(){
	int n,d;
	printf("Enter the no. of elements in array :  ");
	scanf("%d",&n);
	int arr[n],a[n];
	for(int i=0;i<n;i++){
		arr[i]=i+1;
		a[i]=i+1;
	}
	printf("Given Array :  ");
	print(arr,n);
	printf("Enter array rotating position :  ");
	scanf("%d",&d);
	arr_left_rotation(arr,d,n);
	printf("Array after left rotation :  ");
	print(arr,n);
	printf("Given Array :  ");
	print(a,n);
	arr_right_rotation(a,n-d,n);
	printf("Array after right rotation :  ");
	print(a,n);
}