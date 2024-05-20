#include<stdio.h>
#define SUM(x,y) x+y

void main(){
	int x,y;
	printf("Enter the two numbers :  ");
	scanf("%d%d",&x,&y);
	printf("Sum is :  %d",SUM(x,y));
} 