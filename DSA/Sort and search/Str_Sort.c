#include<stdio.h>
#include<string.h>

void main(){
	char a[5][100],n[100],temp[100];
	int i,j,count=0,low=0,high=5,mid=(high+low)/2;
	printf("Enter 5 players name : \n");
	for(i=0;i<5;i++)
		scanf("%s",&a[i]);
	for(i=0;i<5;i++){
		for(j=0;j<4-i;j++){
			if(strcmp(a[j],a[j+1])==1){
				strcpy(temp,a[j]);
				strcpy(a[j],a[j+1]);
				strcpy(a[j+1],temp);
			}
		}
	}
	printf("\nSorted List :  ");
	for(i=0;i<5;i++)
		printf("| %s |",a[i]);
	printf("\nEnter the name to be searched :  ");
	scanf("%s",&n);
	while(count!=4){
		if(strcmp(a[mid],n)==0){
			printf("\n%s Playing.",n);
			break;
		}
		if(strcmp(n,a[mid])==-1)
			high=mid;
		if(strcmp(n,a[mid])==1)
			low=mid;
		mid=(low+high)/2;
		count++;
	}
	if(count==4){
		printf("\n%s Not Playing.",n);
	}
}