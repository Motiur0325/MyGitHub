#include<stdio.h>
#include<stdlib.h>
#define n 10

void Find_largest(int a[],int k){
	int L[k],max;
	int i,l=0;
	while(l<k){
		max=0;
		for(i=0;i<n;i++){
			if((a[i]>max&&l==0)||(a[i]>max&&a[i]<L[l-1]))
				max=a[i];
		}
		L[l]=max;
		l++;
	}
	printf("\nThree Largest Numbers :  ");
	for(i=0;i<k;i++)
		printf("%d ",L[i]);
}
void Find_Smallest(int a[],int k){
	int L[k],min;
	int i,l=0;
	while(l<k){
		min=999;
		for(i=0;i<n;i++){
			if((a[i]<min&&l==0)||(a[i]<min&&a[i]>L[l-1]))
				min=a[i];
		}
		L[l]=min;
		l++;
	}
	printf("\n\nThree Smallest Numbers :  ");
	for(i=0;i<k;i++)
		printf("%d ",L[i]);
}
void main(){
	int a[n];
	int i,k;
	for(i=0;i<n;i++)
		a[i]=rand()%100+2;
	printf("Given Array :  ");
	for(i=0;i<n;i++)
		printf("%d ",a[i]);
	printf("\n\nEnter the number of elements :  ");
	scanf("%d",&k);
	Find_largest(a,k);
	Find_Smallest(a,k);
}