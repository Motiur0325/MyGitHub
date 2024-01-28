#include<stdio.h>
#include<stdlib.h>
#define n 5
#define N 10

void sort(int a[]){
	int i,j,temp;
	for(i=0;i<N;i++){
		for(j=0;j<N-i-1;j++){
			if(a[j]>a[j+1]){
				temp=a[j];
				a[j]=a[j+1];
				a[j+1]=temp;
			}
		}
	}
}
void Find_Floor_Ceil_Linear(int a[],int key){
	printf("\nLinear : \n\n");
	if(key<=a[0]){
		printf("Floor value doesn't exist.\nCeil :  %d",a[0]);
		return;
	}
	if(key>=a[N-1]){
		printf("Floor :  %d\nCeiling value doesn't exist.",a[N-1]);
		return;
	}
	int i=0;
	while(a[i]<=key){
		if(a[i]==key){
			printf("Floor :  %d\nCeil :  %d",a[i-1],a[i+1]);
			return;
		}
		i++;
	}
	printf("Floor :  %d\nCeil :  %d",a[i-1],a[i]);
}
void Find_Floor_Ceil_Binary(int a[],int key){
	printf("\n\nBinary :\n\n");
	int low=0,high=N-1;
	if(key<=a[0]){
		printf("Floor value doesn't exist.\nCeil :  %d",a[0]);
		return;
	}
	if(key>=a[N-1]){
		printf("Floor :  %d\nCeiling value doesn't exist.",a[N-1]);
		return;
	}
	while(high>=low){
		int mid=(high+low)/2;
		if(a[mid+1]>key&&a[mid-1]<key){
			printf("Floor :  %d\nCeil :  %d",a[mid-1],a[mid+1]);
			return;
		}
		if(a[mid]>key)
			high=mid-1;
		if(a[mid]<key)
			low=mid+1;
	}
}
void main(){
	int a[n]={1,2,3,4,5};
	int b[n]={1,2,4,5,6};
	int c[n]={1,3,5,7,9};
	int i,j,k,key;
	printf("Common Elements :  ");
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			for(k=0;k<n;k++){
				if((a[i]==b[j])&&(a[i]==c[k]))
					printf("%d ",a[i]);
			}
		}
	}
	int arr[N];
	for(i=0;i<N;i++)
		arr[i]=rand()%100+2;
	printf("\n\nGiven Array :  ");
	for(i=0;i<N;i++)
		printf("%d ",arr[i]);
	sort(arr);
	printf("\n\nSorted Array :  ");
	for(i=0;i<N;i++)
		printf("%d ",arr[i]);
	printf("\n\nEnter the element whose floor and ceil is to be found :  ");
	scanf("%d",&key);
	Find_Floor_Ceil_Linear(arr,key);
	Find_Floor_Ceil_Binary(arr,key);
}