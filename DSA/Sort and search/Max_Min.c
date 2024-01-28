#include<stdio.h>
#include<stdlib.h>
int Max_Arr(int a[],int i,int temp){
	if(a[i]!='\0'){
		if(a[i]>temp){
			return Max_Arr(a,++i,a[i]);
		}
		else{
			return Max_Arr(a,++i,temp);
		}
	}
	else{
		return temp;
	}
}
int Min_Arr(int a[],int i,int temp){
	if(a[i]!='\0'){
		if(a[i]<temp){
			return Min_Arr(a,++i,a[i]);
		}
		else{
			return Min_Arr(a,++i,temp);
		}
	}
	else{
		return temp;
	}
}
void main(){
	int a[10]={11,22,43,42,15,6,7,28,9,10};
	int i,MAX,MIN;
/*	for(i=0;i<10;i++)
		a[i]=rand()%100+1;*/
	printf("Given Array :  ");
	for(i=0;i<10;i++)
		printf("%d ",a[i]);
	MAX=Max_Arr(a,0,a[0]);
	printf("\nMaximum :  %d",MAX);
	MIN=Min_Arr(a,0,a[0]);
	printf("\nMinimum :  %d",MIN);
}