#include<stdio.h>
#include<stdlib.h>
#define MAX 3

int count=1;
int A[0][1],B[1][2],C[2][3];

struct node{
	int data;
	struct node * next;
}*head=NULL,*temp,*head1=NULL;

void create(int x){
	temp=(struct node*)malloc(sizeof(struct node));
	temp->data=x;
	temp->next=NULL;
	head=temp;
	head1=head;
	count++;
}
void ins_end(){
	temp->next=NULL;
	head->next=temp;
	head=temp;
	count++;
}
void Mat_Create(int i,int j,int z[i][j]){
	for(int x=0;x<i;x++){
		for(int y=0;y<j;y++)
			z[x][y]=rand()%10+1;
	}
}
void Mat_Dis(int a,int b,int x[a][b]){
	int i,j;
	for(i=0;i<a;i++){
		printf(" | ");
		for(j=0;j<b;j++)
			printf("%3d ",x[i][j]);
		printf("  |\n\n");
	}
}
void Mat_Mul(int a,int b,int c,int x[a][b],int y[b][c]){
	if(count!=MAX){
		int i,j,k,m=0;
		int z[a][c];
		for(i=0;i<a;i++){
			for(j=0;j<c;j++)
				z[i][j]=0;
		}
		for(i=0;i<a;i++){
			for(j=0;j<c;j++){
				for(k=0;k<b;k++){
					z[i][j]+=x[i][k]*y[k][j];
				}
			}
		}
		printf("\nMultiplied Matrix :  \n\n");
		Mat_Dis(a,c,z);
		count++;
		Mat_Mul(a,c,c+1,z,Mat[count]);
	}
}
void main(){
	int i,j;
	for(i=0;i<3;i++){
		Mat_Create(i+1,i+2,Mat[i]);
	}
	for(i=0;i<3;i++){
		printf("\nMatrix %c :  \n",Mat[i]);
		Mat_Dis(i+1,i+2,Mat[i]);
		printf("\n");
	}
	Mat_Mul(1,2,3,Mat[0],Mat[1]);
}