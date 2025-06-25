#include<stdio.h>
#include<stdlib.h>

int Linear_Search(int a[],int key){
	int i,loc=0;
	for(i=0;i<10;i++){
		if(a[i]==key)
			return i;
	}
	return 0;
}
void main(){
	int a[10];
	int i,key;
	for(i=0;i<10;i++)
		a[i]=rand()%100+2;
	printf("Given Array :  ");
	for(i=0;i<10;i++)
		printf("%d ",a[i]);
	printf("\n\nEnter the element to be searched :  ");
	scanf("%d",&key);
	if(Linear_Search(a,key)!=0){
		printf("Element found at location :  %d ",Linear_Search(a,key)+1);
	}
	else{
		printf("Element not found.");
	}
}