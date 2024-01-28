
#include<stdio.h>
#include<string.h>

void main(){
	char a[80];
	int vow=0,con=0,i=0,sp=0;
	printf("Enter the string :  ");
	gets(a);
	while(a[i]!='\0'){
		if(a[i]=='a'||a[i]=='e'||a[i]=='i'||a[i]=='o'||a[i]=='u'
		||a[i]=='A'||a[i]=='E'||a[i]=='O'||a[i]=='I'||a[i]=='U')
			vow++;
		else{
			if(a[i]==' ')
				sp++;
			else
				con++;
		}
		i++;
	}
	printf("\n\nNo. of vowels :  %d\nNo. of consonants :  %d\nNo. of spaces :  %d\nString Length :  %d",vow,con,sp,strlen(a));
}