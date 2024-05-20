#include<stdio.h>

void main(){
	int a=5;
//	printf("%d\t%d\t%d\t",a++,a,++a);
//	printf("%d\t%d\t%d",a--,a,--a);
	printf("%d\t%d\t%d\t%d\t%d\t",a++,a++,++a,a,++a);
	printf("%d\t%d\t%d\t%d\t%d",a--,a,a--,--a,--a);
}