#include<stdio.h>

void merge(int a[],int l,int m,int r){
	int i,j,k;
	int n1,n2;
	n1=m-l+1;n2=r-m;
	int L[n1],R[n2];
	for(i=0;i<n1;i++){
		L[i]=a[l+i];
	}
	for(i=0;i<n2;i++){
		R[i]=a[m+i+1];
	}
	i=0;k=l;j=0;
	while(i<n1&&j<n2){
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
	while(i<n1){
		a[k]=L[i];
		i++;
		k++;
	}
	while(j<n2){
		a[k]=R[j];
		j++;
		k++;
	}
}
void merge_sort(int a[],int low,int high){
	if(low<high){
		int mid=low+(high-low)/2;
		merge_sort(a,low,mid);
		merge_sort(a,mid+1,high);
		merge(a,low,mid,high);
	}
}
void printArray(int A[], int size)
{
    int i;
    for (i = 0; i < size; i++)
        printf("%d ", A[i]);
    printf("\n");
}
  
/* Driver code */
int main()
{
    int arr[] = { 12, 11, 13, 5, 6, 7 };
    int arr_size = sizeof(arr) / sizeof(arr[0]);
  
    printf("Given array is \n");
    printArray(arr, arr_size);
  
    merge_sort(arr, 0, arr_size - 1);
  
    printf("\nSorted array is \n");
    printArray(arr, arr_size);
    return 0;
}