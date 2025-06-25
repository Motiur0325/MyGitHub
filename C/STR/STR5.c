#include<stdio.h>
#include<string.h>
char *substr(char*x){
	char *a="Hello World";
	strcpy(x,a);
}
void main(){
	char b[20];
	printf("\t\t%s\t\t",substr(b));
}