#include<stdio.h>
#include<math.h>

void Jump_Search(int a[],int n,int key){
	int count=0;
	int m=sqrt(n);
	int i=m;
	while(i-m<n&&key<=a[n-1]&&key>=a[0]){
		if(a[i]>=key){
			for(int j=i-m;j<=i;j++){
				if(a[j]==key){
					printf("\nElement found at %d after %d[%d] loops.",j,count,i);
					return;
				}
				count++;
			}
			printf("\nElement not found.");
			return;
		}
		i=i+m;
		if(i>n-1)
			i=n-1;
		count++;
	}
	printf("\nElement not found.");
}
void main(){
	int a[]={1,3,5,7,9,11,13};
	int i,key;
	int n=sizeof(a)/sizeof(a[0]);
	printf("Given Array :  ");
	for(i=0;i<n;i++)
		printf("%d ",a[i]);
	while(1){
		printf("\n\nEnter the element to be searched :  ");
		scanf("%d",&key);
		Jump_Search(a,n,key);
	}
}