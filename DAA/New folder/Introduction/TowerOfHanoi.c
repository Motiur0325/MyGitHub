#include<stdio.h>

void TowerOfHanoi(int n,char start,char end,char aux){
	if(n>0){
		TowerOfHanoi(n-1,start,aux,end);
		printf("Move Disk %d from %c to %c\n",n,start,end);
		TowerOfHanoi(n-1,aux,end,start);
	}
}
void TowerOfHanoi_0(int n,char start,char end){
	if(n==1){
		printf("Move Disk %d from %c to %c\n",n,start,end);
	}
	else{
		char other=(char)(198-(int)(start+end));
		TowerOfHanoi_0(n-1,start,other);
		printf("Move Disk %d from %c to %c\n",n,start,end);
		TowerOfHanoi_0(n-1,other,end);
	}
}
void main(){
	int n;
	printf("Enter the no. of disks :  ");
	scanf("%d",&n);
	printf("\n");
	TowerOfHanoi(n,'A','B','C');
	printf("\nAlternate Algorithm :\n\n");
	TowerOfHanoi_0(n,'A','B');
}