#include<stdio.h>
#define MAX 7
void main(){
	int a[MAX]={10,20,15,2,23,90,67};
	printf("Peak Elements :  ");
	for(int i=1;i<MAX-1;i++){
		if(a[i]>a[i+1]&&a[i]>a[i-1])
			printf("%d ",a[i]);
	}
}