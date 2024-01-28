#include<stdio.h>

int fact(int x){
	int f;
	if(x==0){
		f=1;
		return(f);
	}
	else{
		f=x*fact(x-1);
		return(f);
	}
}
void main(){
	int n,f=1;
	printf("Enter the no. whose factorial is to be calculated :  ");
	scanf("%d",&n);
	/*for(int i=n;i>0;i--){
		f=f*i;
	}
	printf("\nFactorial :  %d",f);*/
	printf("\nFactorial :  %d",fact(n));
}