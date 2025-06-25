#include<stdio.h>

void Interpolation_Search(int a[],int n,int key){
	int low=0,count=0;
	int mid,high=n-1;
	while(low<=high&&key>=a[low]&&key<=a[high]){
		mid=low+((high-low)*(key-a[low]))/(a[high]-a[low]);
		printf("\nMid :  %d",mid);
		if(a[mid]==key){
			printf("\nElement found at %d after %d loops.",mid,count);
			return;
		}
		if(a[mid]>key)
			high=mid-1;
		if(a[mid]<key)
			low=mid+1;
		count++;
	}
	printf("\nElement not found.");		
}
void main(){
	int a[]={1,3,4,8,12,19,21};
	int i,key;
	int n=sizeof(a)/sizeof(a[0]);
	printf("Given Array :  ");
	for(i=0;i<n;i++)
		printf("%d ",a[i]);
	while(1){
		printf("\n\nEnter the element to be searched :  ");
		scanf("%d",&key);
		Interpolation_Search(a,n,key);
	}
}