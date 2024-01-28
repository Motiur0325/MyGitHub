#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int lvl=0,count=1;

void create(int n, int x[n][n]){
	int data;
	printf("\nEnter the data to be inserted : ");
	scanf("%d",&data);
	x[lvl][count]=data;
	if(count==pow(2,lvl)){
		count=1;
		lvl++;
	}
	else{
		count++;
	}
	printf("\nLevel :  %d\nCount :  %d",lvl,count);
}
void display(int n,int x[n][n]){
	int l=0,c=0;
	printf("Entert lvl and count :  ");
	scanf("%d%d",&l,&c);
	printf("\nData :  %d",x[l][c]);
	/*printf("\nTree :\n");
	printf("L,lvl :  %d,%d  C,count :  %d,%d\n",l,lvl,c,count);
	while(c!=count&&l!=lvl){
		printf("%d ",x[l][c]);
		if(c==pow(2,l)){
			printf("\n");
			c=1;
			l++;
		}
		else{
			c++;
		}
	}*/
}
void main(){
	int T[5][16],ch;
	int n=sizeof(T)/sizeof(T[0][0]);
	while(1){
		printf("\n1.Create\n2.Display\t\t\tEnter Choice :  ");
		scanf("%d",&ch);
		switch(ch){
			case 1 : create(n,T);
					 break;
			case 2 : display(n,T);
					 break;
		}
	}
}