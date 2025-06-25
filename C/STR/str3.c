#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define item 5
void pr_seq(){
	char a[15]="Enlightenment";
	int c,d;
	printf("\n---------------------\n");
	for(c=0;c<=12;c++){
		d=c+1;
		printf("|%.*s|\n",d,a);
	}
	printf("---------------------\n");
	for(c=12;c>=0;c--){
		d=c+1;
		printf("|%.*s|\n",d,a);
	}
	printf("\n---------------------\n");
	printf("\n\n\n");
}
void atoz(){
	char a;
	for(a=65;a<123;a++)
	{
		if(a>90&&a<97)
			continue;
		printf("%4d-%c  ",a,a);
	}
	printf("\n\n\n\n");
}
void atoifn(){
	char num[10]="1987";
	int year=atoi(num);
	printf("\n\n%s------%d ",num,year);
}
void str_add(){
	int i,j;
	char x[20],y[20],z[40];
	printf("\n\n\nEnter two strings :  ");
	gets(x);
	gets(y);
	for(i=0;x[i]!='\0';i++)
		z[i]=x[i];
	z[i]=' ';
	for(j=0;y[j]!='\0';j++)
		z[i+j+1]=y[j];
	z[i+j+1]='\0';	
	printf("\n\n%s",z);
}
void str_eq(){
	char x[20]={"HELL Y"},y[20]={"HELL Y"},z[20]={"HEAVEN"},Z[40];
	printf("\n\n%d",strcmp(x,y));
	int i=0;
	while(x[i]==y[i]&&(x[i]!='\0'||y[i]!='\0'))
		i++;
	if(x[i]==y[i])
		printf("\n\nEqual");
	else
		printf("\n\nNot Equal");
	strcpy(Z,strcat(strcat(x,y),z));
	printf("\n\n%s",Z);
	printf("\n\n%d",strlen(Z));
}                                  
void strn(){
	char a[30]={"Deoxyribonucleic"},b[30]={"nucleic"};
	printf("\n\n%d\n\n",strncmp(a,b,3));
	if(strstr(a,b)==NULL)
		printf("Substring not found");
	else
		printf("Substring found");
	printf("\n\n%s",strncat(b,a,4));
	printf("\n\n%s",strncpy(b,a,3));
}
void str_sort(){
	char a[item][20],b[20];
	int i=0,j=0;
	printf("\n\nEnter the strings :\n");
	while(i<item)
		scanf("%s",a[i++]);
	for(i=1;i<item;i++){
		for(j=1;j<=item-1;j++){
			if(strcmp(a[j-1],a[j])>0){
				strcpy(b,a[j-1]);
				strcpy(a[j-1],a[j]);
				strcpy(a[j],b);
			}
		}
	}
	printf("\n\nList in order :\n");
	for(i=0;i<item;i++)
		printf("%s\n",a[i]);
}
void main(){
	pr_seq();
	atoz();
	atoifn();
	str_eq();
	strn();
	str_sort();
}