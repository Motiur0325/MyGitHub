#include<stdio.h>

void swap(int*a,int*b){
	int temp=*a;
	*a=*b;
	*b=temp;
}
void print(int a[],int n){
	for(int i=0;i<n;i++)
		printf("%d ",a[i]);
}
int part(int a[],int p,int r){
	int piv=a[p];
	int i=p;
	int j=r;
	while(i<=j){
		printf("\nI :  %d,J :  %d",i,j);
		while(a[j]>=piv&&i!=j)
			j--;
		if(i>=j){
			if(a[p]>a[j]){
				a[p]=a[j];
				a[j]=piv;
			}
			printf("P :  %d,J :  %d",p,j);
			return j;
		}
		else{
			i++;
			swap(&a[i],&a[j]);
			printf("\nProcessed Array :  ");
			print(a,r+1);
		}
	}
	/*
	end:
		
	return j;*/
}
void Quick_Sort(int a[],int l,int r){
	if(l<r){
		int q=part(a,l,r);
		printf("\nLoop Array :  ");
		print(a,r+1);
		Quick_Sort(a,l,q-1);
		Quick_Sort(a,q+1,r);
	}
}
void main(){
	int a[]={5,3,2,6,4,1,3,7};
	int n=sizeof(a)/sizeof(a[0]);
	printf("Given Array :  ");
	print(a,n);
	Quick_Sort(a,0,n-1);
	printf("\nSorted Array :  ");
	print(a,n);
}