#include<stdio.h>

int count=0;

int Ternary_Search(int a[],int n,int key){
	int l=0,r=n-1;
	while(l<=r){
		int mid1=l+(r-l)/3;
		int mid2=r-(r-l)/3;
		if(a[mid1]==key)
			return mid1;
		if(a[mid2]==key)
			return mid2;
		if(a[mid1]>key){
			r=mid1-1;
		}
		else{
			if(a[mid2]<key)
				l=mid2+1;
			else{
				l=mid1+1;
				r=mid2-1;
			}
		}
		count++;
	}
	printf("\nElement not found.");
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
	int result=Ternary_Search(a,n,key);
	if(result>=0&&result<n)
		printf("\nElement found at %d after %d loops",result,count);
}