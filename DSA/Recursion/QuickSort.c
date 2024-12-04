#include<stdio.h>

void printArray(int arr[],int start,int end){
	printf("Array :  ");
	for(int i=start;i<end;i++){
		printf("%d ",arr[i]);
	}
	printf("\n");
}
void swap(int *a,int *b){
	int temp=*a;
	*a=*b;
	*b=temp;
}
int partition(int arr[],int start,int end){
	int*pivot=arr+end;
	int i=start,j=end;
	while(i<j){
		if(&arr[j]==pivot){
			if(arr[i]>*pivot){
				swap(&arr[i],pivot);
				pivot=arr+i;
			}
			else{
				i++;
			}
		}
		if(&arr[i]==pivot){
			if(arr[j]<*pivot){
				swap(&arr[j],pivot);
				pivot=arr+j;
			}
			else{
				j--;
			}
		}
	}
	printArray(arr,start,i);
	printArray(arr,i+1,end+1);
	return i;
}
void QuickSort(int arr[],int start,int end){
	if(start>=end)return;
	int pivot=partition(arr,start,end);
	printf("\nPivot is :  %d\n",arr[pivot]);
	QuickSort(arr,start,pivot-1);
	QuickSort(arr,pivot+1,end);
}
void main(){
	int arr[]={2,6,4,1,8,0,5};
	int size=sizeof(arr)/sizeof(int);
	printArray(arr,0,size);
	QuickSort(arr,0,size-1);
	printArray(arr,0,size);
}