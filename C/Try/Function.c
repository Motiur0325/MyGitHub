#include<stdio.h>

void main(){
	extern void fun(int);
	fun(5);
}
void fun(int a){
	printf("a :  %d",a);
}