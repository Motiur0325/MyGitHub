#include<stdio.h>
#include<stdlib.h>

int list[5]={5,7,9,1,3};
int link[5]={4,3,-1,2,1};

void main(){
	int PTR,START;
	START=0;
	PTR=START;
	printf("List	Link\n");
	for(int i=0;i<5;i++)
		printf(" %d 	 %2d \n",list[i],link[i]);
	printf("\n\nList :  ");
	while(PTR!=-1){
		printf("%d ",list[PTR]);
		PTR=link[PTR];
	}
}