#include<stdio.h>

int fibo(int x){
	int fib,fiba,fibb;
	if(x==0||x==1){
		fib=x;
		return(fib);
	}
	else{
		fiba=fibo(x-2);
		fibb=fibo(x-1);
		fib=fiba+fibb;
		return(fib);
	}
}
void main(){
	int n,i;
	printf("Enter the no. of elments in series :  ");
	scanf("%d",&n);
	printf("\nFibonacci Series :  ");
	for(int i=1;i<=n;i++){
		printf("%d ",fibo(i));
	}
}