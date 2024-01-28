#include<stdio.h>

//void write(int n){
//	if(n>0){
//		int i;
//		printf("Enter n :  %d\n",n);
//		for(i=n;i>0;i--){
//		//	printf("N :  %d\n",n);
//			printf("Enter i :  %d\n",i);
//			printf("Before\n");
//			write(n-1);
//			//printf("n :  %d\n",n);
//			printf("After i :  %d\n",i);
//		}
//	}
//}
void write(int n){
	int i;
	for(i=n;i>0;i--){
		write(n-1);
		printf("%d ",n);
		write(n-1);
		printf("%d ",n);
		write(n-1);
	}
}
void main(){
	printf("n :  ");
	write(3);
}