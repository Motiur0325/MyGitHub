#include<stdio.h>

void Binary_Search(int a[],int n,int key){
	int low=0,count=0;
	int mid,high=n-1;
	while(low<=high){
		mid=(low+high)/2;
		if(a[mid]==key)
			goto end;
		if(a[mid]>key)
			high=mid-1;
		if(a[mid]<key)
			low=mid+1;
		count++;
	}
	printf("\nElement not found.");
	end :
		if(low<=high)
			printf("Element found at %d after %d loops.",mid,count);
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
	Binary_Search(a,n,key);
}