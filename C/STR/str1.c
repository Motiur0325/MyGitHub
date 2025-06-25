#include<stdio.h>
#include<string.h>

char *substr(char *x){
	char *a=x;
	return a;
}
int main(void)
{
	char b[20]="Hello World",c[20];
	int k,i,j,m=0;
	printf("\nEnter Initial and Final Range\n");
	scanf("%d%d",&i,&j);
	for(k=i-1;k<j;k++){
		c[m]=b[k];
		m++;
	}
	c[m]='\0';
	printf("\t\t%s\t\t",substr(c));
}