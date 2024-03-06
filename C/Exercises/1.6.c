#include<stdio.h>

mul_table(int n){
	for(int i=1;i<=10;i++){
		printf("%2d x %2d = %3d\n",n,i,n*i);
	}
}
void main(){
	int n;
	printf("Enter the number :  ");
	scanf("%d",&n);
	mul_table(n);
}