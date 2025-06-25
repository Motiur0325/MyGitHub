#include<stdio.h>

void main(){
	char i,prior[10]={'(','@','+','-','*','/','^',')'};
	for(i=0;prior[i]!='\0';i++){
		printf("%d ",prior[i]);
	}
}