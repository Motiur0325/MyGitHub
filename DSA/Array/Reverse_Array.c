#include<stdio.h>
#include<stdlib.h>
#define MAX 10

void main(){
	int a[MAX];
	int i,j=MAX-1,temp;
	for(i=0;i<MAX;i++)
		a[i]=rand()%10+1;
	printf("Given Array :  ");
	for(i=0;i<MAX;i++)
		printf("%d ",a[i]);
	i=0;
	while(i<=j){
		temp=a[i];
		a[i]=a[j];
		a[j]=temp;
		i++;
		j--;
	}
	printf("\n\nReversed Array :  ");
	for(i=0;i<MAX;i++)
		printf("%d ",a[i]);
}