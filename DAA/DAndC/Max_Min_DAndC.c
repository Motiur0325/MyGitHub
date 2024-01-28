#include<stdio.h>
#include<stdlib.h>

int max=0,min=999;

void print(int x[],int n){
	for(int i=0;i<n;i++){
		printf("%d ",x[i]);
	}
}
void max_min(int a[],int l,int m,int r){
	int i,j;
	int n1=m-l+1;
	int n2=r-m;
	int L[n1],R[n2];
	for(i=0;i<n1;i++)
		L[i]=a[i+l];
	for(j=0;j<n2;j++)
		R[j]=a[j+m+1];
	i=0;
	j=0;
	/*printf("\nL :  ");
	print(L,n1);
	printf("\nR :  ");
	print(R,n2);*/
	while(i<n1&&j<n2){
		if(L[i]<R[j]){
			if(L[i]<min)
				min=L[i];
			if(L[i]>max)
				max=R[j];
			i++;
		}
		else{
			if(R[j]>max)
				max=L[i];
			if(R[j]<min)
				min=R[j];          
			j++;
		}
	}
}
void DAndC(int a[],int l,int r){
	if(l<r){
		int m=(r+l)/2;
		DAndC(a,l,m);
		DAndC(a,m+1,r);
		max_min(a,l,m,r);
	}
}
void main(){
	int a[20];
	int arr_size=sizeof(a)/sizeof(a[0]);
	for(int i=0;i<arr_size;i++){
		a[i]=rand()%100+1;
	}
	printf("Given Array :  ");
	print(a,arr_size);
	DAndC(a,0,arr_size-1);
	printf("\n\nMax :  %d\tMin :  %d",max,min);
}