#include<stdio.h>
#include<math.h>
#define MAX 10

void main(){
	int n;
	printf("Enter the number :  ");
	scanf("%d",&n);
	int count=MAX;
	while(n/(int)(pow(10,count-1))==0){
		count--;
	}
//	printf("Count :  %d",count);
	for(int i=count;i>0;i--){
		printf("%d\n",n%(int)(pow(10,i)));	
	}
}