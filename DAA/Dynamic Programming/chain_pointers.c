#include<stdio.h>

void main(){
	int x=10;
	int *p=&x;
	int **q=&p;
	printf("%d is at %d\n",x,&x);
	printf("%d is at %d\n",*p,p);
	printf("%d is at %d\n",**q,*q);
	printf("pointer 'p' is at %d\n",&p);
	printf("pointer 'p' is at %d\n",&*q);
	printf("pointer 'q' is at %d\n",&q);
}