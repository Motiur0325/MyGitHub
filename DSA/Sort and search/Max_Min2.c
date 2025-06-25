#include<stdio.h>
#include<stdlib.h>
int Max_Arr(int a[],int i,int temp){
	if(i>=0){
		if(a[i]>temp){
			return Max_Arr(a,--i,a[i]);
		}
		else{
			return Max_Arr(a,--i,temp);
		}
	}
	else{
		return temp;
	}
}
int Min_Arr(int a[],int i,int temp){
	if(i>=0){
		if(a[i]<temp){
			return Min_Arr(a,--i,a[i]);
		}
		else{
			return Min_Arr(a,--i,temp);
		}
	}
	else{
		return temp;
	}
}
void main(){
	int a[20];
	int i,MAX,MIN,size;
	for(i=0;i<20;i++)
		a[i]=rand()%100+7;
	printf("Given Array :  ");
	for(i=0;i<20;i++)
		printf("%d ",a[i]);
	size=sizeof(a)/sizeof(a[i]);
	MAX=Max_Arr(a,size-1,a[0]);
	printf("\nMaximum :  %d",MAX);
	MIN=Min_Arr(a,size-1,a[0]);
	printf("\nMinimum :  %d",MIN);
}