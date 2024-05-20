#include<stdio.h>

void MergeArray(int a[],int low,int mid,int high){
	int i,l=mid-low+1,h=high-mid;
	int L[l],R[h];
	for(i=0;i<l;i++){
		L[i]=a[low+i];
	}
	for(i=0;i<h;i++){
		R[i]=a[mid+i+1];
	}
	printf("\n\nLow : %d\tMid : %d\tHigh : %d\n",low,mid,high);
	printf("Left :  ");
	for(i=0;i<l;i++){
		printf("%d ",L[i]);
	}
	printf("\tRight :  ");
	for(i=0;i<h;i++){
		printf("%d ",R[i]);
	}
	i=0;
	int j=0,k=low;
	while(i<l&&j<h){
		if(L[i]<=R[j]){
			a[k]=L[i];
			i++;
		}
		else{
			a[k]=R[j];
			j++;
		}
		k++;
	}
	while(i<l){
		a[k]=L[i];
		k++;
		i++;
	}
	while(j<h){
		a[k]=R[j];
		k++;
		j++;
	}
}
void MergeSort(int a[],int low,int high){
	if(low<high){
		int mid=(low+high)/2;
		MergeSort(a,low,mid);
		MergeSort(a,mid+1,high);
		MergeArray(a,low,mid,high);
	}
}
void main(){
	int i,n;
	printf("Enter the number of elements :  ");
	scanf("%d",&n);
	int a[n];
	printf("Enter the numbers :  ");
	for(i=0;i<n;i++){
		scanf("%d",&a[i]);
	}
	printf("Given Array :  ");
	for(i=0;i<n;i++){
		printf("%d ",a[i]);
	}
	MergeSort(a,0,n-1);
	printf("\n\nSorted Array :  ");
	for(i=0;i<n;i++){
		printf("%d ",a[i]);
	}
}