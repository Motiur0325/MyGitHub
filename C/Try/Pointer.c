#include<stdio.h>

void dis(int *a){
	for(int i=0;i<3;i++){
		printf("%d at address %d\n",*(a+i),a+i);
	}
}
void main(){
//	int x,y,z;
//	int *p;
//	p=&x;
//	*p=20;
//	p=&y;
//	*p=30;
//	p=&z;
//	*p=40;
//	printf("x : %d\ty : %d\tz : %d\t",x,y,z);
	int x=10;
	int *p=&x;
	printf("%d\t%d\t%d\t%d\n",*p,p,&x,&p);
	int a[]={1,2,3};
	dis(a);
}