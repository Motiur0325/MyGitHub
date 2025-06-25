#include<stdio.h>
void main(){
	char str[20]={"Enlightenment"};
	int m,n;
	printf("Enter first and last range : \n");
	scanf("%d%d",&m,&n);
	printf("String : %s\n",str);
	printf("Substring : ");
	for(int i=m-1;i<n;i++)
		printf("%c",str[i]);
}