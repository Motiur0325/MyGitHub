#include<stdio.h>
#include<string.h>
#include<stdlib.h>

void main(){
	char str[50];
	char temp[50]="Hello World";
//	scanf("%[^\n]",&str);
//	if(strcmp(str,temp)==0){
//		printf("True");
//	}
//	else{
//		printf("False");
//	}
//	char a='A';
//	int x=1;
//	printf("Char :  %d\tInt :  %d\n",sizeof(a),sizeof(x));
//	int A[4];
//	printf("Size :  %d\n",sizeof(A));
	if(strstr(temp,"Hell ")!=NULL){
		printf("Found!\n");
	}
	puts(temp);
	char num[10];
	gets(num);
	printf("%s\t%d\n",num,strlen(num)/sizeof(num[0]));
	int n=atoi(num);
	printf("%d\t%d",n,sizeof(n));
}