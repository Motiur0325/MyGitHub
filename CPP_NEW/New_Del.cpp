#include<iostream>
using namespace std;

int main(){
	int *arr;
	int size;
	cout<<"Enter the size of array :  ";cin>>size;
	arr=new int[size];
	cout<<"Memory Allocated :  "<<sizeof(*arr/arr[0]);
	delete []arr;
	cout<<"\nMemory Allocated :  "<<sizeof(*arr/arr[0]);
	return 0;
}