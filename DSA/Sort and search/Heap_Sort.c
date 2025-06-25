#include<stdio.h>

void heapify(int a[],int n,int i){
	int largest = i; // Initialize largest as root  
    int left = 2 * i + 1; // left child  
    int right = 2 * i + 2; // right child  
    // If left child is larger than root  
    if (left < n && a[left] > a[largest])  
        largest = left;  
    // If right child is larger than root  
    if (right < n && a[right] > a[largest])  
        largest = right;  
    // If root is not largest  
    if (largest != i) {  
        // swap a[i] with a[largest]  
        int temp = a[i];  
        a[i] = a[largest];  
        a[largest] = temp;  
        heapify(a,n,largest); 
	}
}
void heap_sort(int a[],int n){
	int temp;
	for(int i=n/2-1;i>=0;i--)
		heapify(a,n,i);
	for(int i=n-1;i>=0;i--){
		temp=a[i];
		a[i]=a[0];
		a[0]=temp;
		heapify(a,i,0);
	}
}
int main(){
	int n=7;
	int a[7]={1,2,3,4,5,6,8,10};
	printf("Given Array :  ");
	for(int i=0;i<n;i++)
		printf("%d ",a[i]);
	heap_sort(a,n);
	printf("Sorted Array :  ");
	for(int i=0;i<n;i++)
		printf("%d ",a[i]);
}