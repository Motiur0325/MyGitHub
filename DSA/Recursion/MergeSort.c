#include<stdio.h>

void printArray(int arr[],int start,int end){
	printf("Array :  ");
	for(int i=start;i<end;i++){
		printf("%d ",arr[i]);
	}
	printf("\n");
}
void MergeSortedArray(int arr[],int low,int mid,int end){
	int size1=mid-low+1;
	int size2=end-mid;
	int subArray1[size1];
	int subArray2[size2];
	for(int i=0;i<size1;i++){
		subArray1[i]=arr[low+i];
	}
	for(int i=0;i<size2;i++){
		subArray2[i]=arr[mid+i+1];
	}
//	printArray(subArray1,0,size1);
//	printArray(subArray2,0,size2);
	int i=0,j=0,k=low;
	while(i<size1&&j<size2){
		if(subArray1[i]>subArray2[j]){
			arr[k]=subArray2[j];
			j++;
		}else{
			arr[k]=subArray1[i];
			i++;
		}
		k++;
	}
	while(i<size1){
		arr[k]=subArray1[i];
		i++;
		k++;
	}
	while(j<size2){
		arr[k]=subArray2[j];
		j++;
		k++;
	}
}
void MergeSort(int arr[],int start,int end){
	if(start>=end)return;
	int mid=start+(end-start)/2;
//	MergeSortedArray(arr,start,mid,end);
	MergeSort(arr,start,mid);
	MergeSort(arr,mid+1,end);
	MergeSortedArray(arr,start,mid,end);
}
void main(){
	int arr[]={2,6,4,1,8,0};
	int size=sizeof(arr)/sizeof(int);
	printArray(arr,0,size);
	MergeSort(arr,0,size-1);
	printArray(arr,0,size);
}