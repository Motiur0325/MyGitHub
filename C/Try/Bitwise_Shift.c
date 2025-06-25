#include<stdio.h>

void step(int *a){
	*a=20;
}
void main(){
	int a=10;
	printf("%d",a);
	step(&a);
	printf("%d",a);
}