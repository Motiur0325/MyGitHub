#include<stdio.h>

int myFact(int n){
	int i,f=1;
	for(i=1;i<=n;i++){
		f*=i;
	}
	return f;
}
void printFact(){
	int fact;
	fact=myFact(6);
	printf("Factorial :  %d",fact);
}
void main(){
	printFact();
}