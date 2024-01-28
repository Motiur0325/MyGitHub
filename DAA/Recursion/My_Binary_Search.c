#include<stdio.h>

int count=0;

int my_ceil(float x,float y){
	if((int)(x/y)!=x/y){
		return x/y+1;
	}
	else{
		return x/y;
	}
}
int binary_search(int l,int r,int m,int key,int a[]){
	printf("\nHello");
	if(a[m]==key){
		return m;
	}
	else{
		if(key>a[m]){
			binary_search(m,r,my_ceil(r+m,2),key,a);
		}
		else{
			binary_search(l,m,my_ceil(l+m,2),key,a);
		}
	}
}
void main(){
	int a[]={1,2,3,4,5,6,7,8};
	int left=0;
	int right=sizeof(a)/sizeof(a[0])-1;
	int mid=my_ceil(left+right,2);
	int key=5;
	printf("Position of key element :  %d after %d searches..",binary_search(left,right,mid,key,a),count);
}