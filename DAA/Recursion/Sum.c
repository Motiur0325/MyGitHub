#include<stdio.h>

int sum(int a,int b,int c){
	return a+b*c+b+a*b+c;
}
int isum(int a[],int n){
	int s=0;
	for(int i=0;i<n;i++){
		s+=a[i];
	}
	return s;
}
int rsum(int a[],int n){
	if(n==0){
		return a[0];
	}
	else{
		return rsum(a,n-1)+a[n];
	}
}
void main(){
	int a=2,b=3,c=1;
	printf("sum is :  %d\n",sum(a,b,c));
	int arr[]={a,b*c,b,a*b,c};
	int n=sizeof(arr)/sizeof(arr[0]);
	printf("isum is :  %d\n",isum(arr,n));
	printf("rsum is :  %d\n",rsum(arr,n));
}