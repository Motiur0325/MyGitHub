#include<stdio.h>

void Sentinel_Search(int a[],int n,int key){
	int temp=a[n-1];
	int i=0;
	a[n-1]=key;
	while(a[i]!=key)
		i++;
	a[n-1]=temp;
	if(i<n-1||a[n-1]==key){
		printf("\nElement found at index :  %d",i);
	}
	else{
		printf("\nElement not found.");
	}
}
void main(){
	int a[]={1,2,3,4,5,6,7,8,9,10};
	int i,key;
	int n=sizeof(a)/sizeof(a[0]);
	printf("Given Array :  ");
	for(i=0;i<n;i++)
		printf("%d ",a[i]);
	printf("\n\nEnter the element to be searched :  ");
	scanf("%d",&key);
	Sentinel_Search(a,n,key);
}