#include<stdio.h>

void main(){
	int x=10,y=20,z;
	int *p,*ptr,*p1,**p3;
	p=&x;
	ptr=&y;
	p1=&z;
	p3=&p;
	printf("Value of x is %d\n\n",x);
	printf("%d is stored in addr %u\n",x,&x);
	printf("%d is stored in addr %u\n",*&x,&x);
	printf("%d is stored in addr %u\n",*p,p);
	printf("%d is stored in addr %u\n",p,&p);
	printf("%d is stored in addr %u\n",y,&y);
	*p=*p * *ptr;
	printf("\n\n%d ",x);
	printf("\n\n%d",**p3);
}