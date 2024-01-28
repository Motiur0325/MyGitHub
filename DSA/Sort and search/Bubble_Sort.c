#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<time.h>
#define MAX 20

void Bi_Search(int a[]){
	int n,low=0,count=0,high=MAX,mid=(MAX/2);
	double total_t;
	printf("Enter the data item to be searched : ");
	scanf("%d",&n);
	while(a[mid]!=n&&count<sqrt(MAX)){
		if(n>a[mid])
			low=mid;
		if(n<a[mid])
			high=mid;
		mid=(low+high)/2;
		count++;
	}
	if(a[mid]==n){
		printf("\n\n%d found at %d after %d loops.",n,mid+1,count);
	}
	else{
		printf("\n\nNumber not found.");
	}
}
void Li_Search(int a[]){
	int key,i;
	printf("\nEnter the number to be searched :  ");
	scanf("%d",&key);
	while(a[i]!=key&&i<MAX)
		i++;
	if(i==MAX)
		printf("\nElement not found.\n");
	else
		printf("\nElement %d found at %d after %d loops.\n",key,i+1,i);
}
int main(){
	int ch,n;
	int a[MAX],i,j,temp;
	for(i=0;i<MAX;i++){
		a[i]=rand()%100+1;
	}
	printf("\nGiven Array :  ");
	for(i=0;i<MAX;i++){
		printf("%d ",a[i]);
	}
	printf("\n");
	for(i=0;i<MAX;i++){
		for(j=0;j<MAX-i-1;j++){
			if(a[j]>a[j+1]){
				temp=a[j];
				a[j]=a[j+1];
				a[j+1]=temp;
				printf("\nProcessed Array :  ");
				for(int k=0;k<MAX;k++){
					printf("%d ",a[k]);
				}
			}
		}
	}
	printf("\n\nSorted Array :  ");
	for(i=0;i<MAX;i++){
		printf("%d ",a[i]);
	}
	printf("\n");
	while(1){
		printf("\n1.Binary Search\n2.Linear search\n3.Exit\t\t\tEnter Choice :  ");
		scanf("%d",&ch);
		switch(ch){
			case 1 : Bi_Search(a);
					 break;
			case 2 : Li_Search(a);
					 break;
			case 3 : exit(0);
			default: printf("Wrong input.");
		}
	}
}