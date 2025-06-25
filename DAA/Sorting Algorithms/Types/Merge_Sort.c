#include<stdio.h>

void print(int a[],int n){
	for(int i=0;i<n;i++)
		printf("%d ",a[i]);
}
void Merge(int a[],int l,int m,int r){
	int i,j,k;
	int n1=m-l+1;
	int n2=r-m;
	int L[n1],R[n2];
	for(i=0;i<n1;i++)
		L[i]=a[l+i];
	for(i=0;i<n2;i++)
		R[i]=a[m+i+1];
	i=0;
	j=0;
	k=l;
	while(i<n1&&j<n2){
		if(L[i]>R[j]){
			a[k]=R[j];
			j++;
		}
		else{
			a[k]=L[i];
			i++;
		}
		k++;
	}
	while(i<n1){
		a[k]=L[i];
		k++;
		i++;
	}
	while(j<n2){
		a[k]=R[j];
		k++;
		j++;
	}
}
void Merge_Sort(int a[],int l,int r,int n){
	if(l<r){
		int m=(r+l)/2;
		Merge_Sort(a,l,m,n);
		Merge_Sort(a,m+1,r,n);
		printf("\nProcessed Array :  ");
		print(a,n);
		Merge(a,l,m,r);
	}
}
void main(){
	int a[]={38, 27, 43, 3, 9, 82, 10};
	int n=sizeof(a)/sizeof(a[0]);
	printf("Given Array :  ");
	print(a,n);
	Merge_Sort(a,0,n-1,n);
	printf("\nSorted Array :  ");
	print(a,n);
}