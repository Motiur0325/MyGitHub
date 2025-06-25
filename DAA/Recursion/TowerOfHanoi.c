#include<stdio.h>

void TOH(int disks,char start,char end,char other){
	if(disks==1){
		printf("Move disk %d from %c to %c.\n",disks,start,end);
	}
	else{
		TOH(disks-1,start,other,end);
		printf("Move disk %d from %c to %c.\n",disks,start,end);
		TOH(disks-1,other,end,start);
	}
}
void main(){
	TOH(3,'A','C','B');
}