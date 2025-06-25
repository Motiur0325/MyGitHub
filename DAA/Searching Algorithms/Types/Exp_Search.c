#include<stdio.h>

int loc=0;

void Binary_Search(int a[],int low,int high,int key,int count1);

void Exp_Search(int a[],int n,int key){
	int i=1,count1=0;
	if(a[0]==key){
		printf("\nElement found at 0 index.");
		return;
	}
	if(a[n-1]==key){
		printf("Element found at %d index.",n-1);
		return;
	}
	while(i<n){
		if(a[i]>=key){
			Binary_Search(a,i/2,i,key,count1);
			if(loc==1)
				return;
		}
		i=i*2;
		count1++;
	}
	Binary_Search(a,i/2,n-1,key,count1);
	if(loc==0)
		printf("\nElement not found.");
}
void main(){
	int a[]={1,3,4,8,12,19,21};
	int i,key;
	if(loc==1)
		goto end;
	int n=sizeof(a)/sizeof(a[0]);
	printf("Given Array :  ");
	for(i=0;i<n;i++)
		printf("%d ",a[i]);
	while(1){
		printf("\n\nEnter the element to be searched :  ");
		scanf("%d",&key);
		Exp_Search(a,n,key);
	}
	end:
		printf("End of Search.");
}
void Binary_Search(int a[],int low,int high,int key,int count1){
	int count=0;
	int mid;
	while(low<=high&&key>=a[low]&&key<=a[high]){
		mid=(high+low)/2;
		if(a[mid]==key){
			printf("\nElement found at %d after %d loops.",mid,count+count1);
			loc=1;
			return;
		}
		if(a[mid]>key)
			high=mid-1;
		if(a[mid]<key)
			low=mid+1;
		count++;
	}		
}