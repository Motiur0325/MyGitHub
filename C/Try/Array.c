#include<stdio.h>

void main(){
	int a[2][5]={};
	for(int i=0;i<2;i++){
		for(int j=0;j<5;j++){
			printf("%d ",a[i][j]);
		}
		printf("\n");
	}
}