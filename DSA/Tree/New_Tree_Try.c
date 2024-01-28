#include<stdio.h>
#include<math.h>
#define MAX 5

int level=0,count=0;

void initialize(int t[MAX][(int)pow(2,MAX)]){
	int i,j;
	for(i=0;i<MAX;i++){
		for(j=0;j<(int)pow(2,MAX);j++){
			t[i][j]=0;
		}
	}
}
void create_node(int t[MAX][(int)pow(2,MAX)]){
	int n;
	printf("\nEnter Data :  ");
	scanf("%d",&n);
	if(count<(int)pow(2,level)){
		t[level][count]=n;
		count++;
	}
	else{
		level++;
		count=0;
		t[level][count]=n;
		count++;
	}
}
void display_node(int t[MAX][(int)pow(2,MAX)]){
	int i,j=0;
	printf("\n  Tree\n-------\n\n");
	for(i=0;i<=level;i++){
		j=0;
		while(t[i][j]!='\0'){
			printf("%d  ",t[i][j]);
			j++;
		}
		printf("\n\n");
	}
}
void main(){
	int tree[MAX][(int)pow(2,MAX)];
	int ch;
	initialize(tree);
		while(1){
		printf("\n\n1.Create\n2.Display\t\tEnter Choice :  ");
		scanf("%d",&ch);
		switch(ch){
			case 1 : create_node(tree);
					 break;
			case 2 : display_node(tree);
					 break;
		}
	}
}