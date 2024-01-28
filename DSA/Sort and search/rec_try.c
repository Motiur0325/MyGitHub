#include<stdio.h>

int rec(int x){
	int a,b;
	if(x>0){
		a=rec(x-1);
		b=rec(x-1);
		printf("%d-%d[%d] ",a,b,x);
	}
}
int main(){
	int n=3;
	rec(n);
}