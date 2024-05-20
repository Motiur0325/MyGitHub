#include<stdio.h>

void MaxMinDAndC(int a[],int i,int j,int *max,int *min){
	if(i==j){
		*max=a[i];
		*min=a[i];
	}
	else if(i==j-1){
		if(a[i]>a[j]){
			*max=a[i];
			*min=a[j];
		}
		else{
			*max=a[j];
			*min=a[i];
		}
	}
	else{
		int max2=*max,min2=*min;
		int mid=(i+j)/2;
		MaxMinDAndC(a,i,mid,max,min);
		MaxMinDAndC(a,mid+1,j,&max2,&min2);
//		printf("Max :  %d\tMin :  %d\n",*max,*min);
//		printf("Max2 :  %d\tMin2 :  %d\n",max2,min2);
		if(max2>*max)
			*max=max2;
		if(min2<*min)
			*min=min2;
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
	int max=a[0],min=a[0];
	MaxMinDAndC(a,0,n-1,&max,&min);
	printf("\n\nMax :  %d\tMin :  %d",max,min);
}