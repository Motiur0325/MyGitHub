#include<stdio.h>
void main(){
	char str[10]={"STRING"},cop[10];
	for(int i=0;i<9;i++){
		for(int j=0;j<i-1;j++){
			printf("%d",str[i]);
		}
	}
}