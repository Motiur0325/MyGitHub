#include<stdio.h>
#include<stdlib.h>
#define n 20

int Find_Max(int a[]){
	int i,max=0;
	for(i=0;i<6;i++){
		if(a[i]>max)
			max=a[i];
	}
	return max;
}
void First_Repeat(int a[]){
	int i,j=0,loc=0;
	while(loc<2){
		loc=0;
		for(i=0;i<n;i++){
			if(a[j]==a[i])
				loc++;
		}
		j++;
	}
	printf("\n\nFirst Repeated Number :  %d",a[j-1]);
}
void Repeat_No(int a[]){
	int i,j,k=0,loc,loc1;
	int Rep[n];
	printf("\n\nRepeating Numbers :  ");
	for(i=0;i<n;i++){
		loc=0;
		for(j=0;j<n;j++){
			if(a[i]==a[j])
				loc++;
		}
		if(loc>1){
			loc1=0;
			for(j=0;j<k;j++){
				if(Rep[j]==a[i])
					loc1=1;
			}
			if(loc1==0){
				Rep[k]=a[i];
				k++;
			}
		}
	}
	for(i=0;i<k;i++)
		printf("%d ",Rep[i]);
}
void main(){
	int a[n];
	int i,loc;
	for(i=0;i<n;i++)
		a[i]=rand()%10+1;
	printf("Array :  ");
	for(i=0;i<n;i++)
		printf("%d ",a[i]);
	int MAX=Find_Max(a);
	printf("\n\nMissing :  ");
	for(i=1;i<MAX;i++){
		loc=0;
		for(int j=0;j<n;j++){
			if(i==a[j])
				loc=1;
		}
		if(loc==0)
			printf("%d ",i);
	}
	First_Repeat(a);
	Repeat_No(a);
}