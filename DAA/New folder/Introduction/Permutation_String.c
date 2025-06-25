#include<stdio.h>

void main(){
	int n;
	printf("Enter the no. of characters in string :  ");
	scanf("%d",&n);
	char set[n];
	int arr[n];
	int i=0;

	while(i<n){
		printf("Enter Character :  ");
		scanf("%s",&set[i]);
		i++;
	}
	//for(i=0;i<n;i++){}
	printf("String Set :  ");
	for(i=0;i<n;i++){
		printf("%c",set[i]);
	}
}