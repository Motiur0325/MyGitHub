#include<stdio.h>
void main(){
	char name[20];
	int i=0,c=0;
	printf("Enter your name :  ");
	scanf("%s",&name);
		while(name[i]!='\0'){
			printf("%d",name[i]);
			i++;
	}
}