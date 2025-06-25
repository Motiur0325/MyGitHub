#include<stdio.h>

void main(){
	char exp[100];
    char *e, x;
    printf("Enter the expression : ");
    scanf("%s",exp);
    printf("\n");
    e = exp;
    while(*e!='\0'){
    	printf("%c ",*e);
    	e++;
	}
}