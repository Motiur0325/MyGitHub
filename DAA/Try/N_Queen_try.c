#include<stdio.h>

int myBool=0;

void print(int q,int Q[q][q]){
	int i,j;
	printf("\n------------------------\n\n");
	for(i=1;i<q;i++){
		for(j=1;j<q;j++){
			if(Q[i][j]==q-1){
				printf("Q   ");
			}
			else{
				printf("-   ");
			}
		}
		printf("\n\n");
	}
	//printf("------------------------\n");
}
void initialize(int q,int Q[q][q]){
	int i,j;
	for(i=1;i<q;i++){
		for(j=1;j<q;j++)
			Q[i][j]=0;
	}
}
void Q_Cross(int i,int j,int q,int Q[q][q]){
	int m=1,n;
	while(m<q){
		if(Q[i][m]==0||Q[i][m]==1)
			Q[i][m]=1;
		m++;
	}
	m=1;
	while(m<q){
		if(Q[m][j]==0||Q[m][j]==1)
			Q[m][j]=1;
		m++;
	}
	m=i+1;
	n=j+1;
	while(m<q&&n<q){
		if(Q[m][n]==0||Q[m][n]==1)
			Q[m][n]=1;
		m++;
		n++;
	}
	while(m>0&&n>0){
		if(Q[m][n]==0||Q[m][n]==1)
			Q[m][n]=1;
		m--;
		n--;
	}
	m=i+1;
	n=j-1;
	while(m<q&&n>0){
		if(Q[m][n]==0||Q[m][n]==1)
			Q[m][n]=1;
		m++;
		n--;
	}
	while(m>0&&n<q){
		if(Q[m][n]==0||Q[m][n]==1)
			Q[m][n]=1;
		m--;
		n++;
	}
}
void Back_Track(int start,int q,int Q[q][q]){
	int i=1,j=start;
	Q[i][j]=q-1;
	Q_Cross(i,j,q,Q);
	for(i=2;i<q;i++){
		for(j=1;j<q;j++){
			if(Q[i][j]==0){
				Q[i][j]=q-1;
				Q_Cross(i,j,q,Q);
				print(q,Q);
				if(i==q-1){
					myBool=1;
					return;
				}
				break;
			}
		}
		if(j==q){
			return;
		}
	}
}
void N_Queen(int i,int q,int Q[q][q]){
	if(i==q){
		return;
	}
	initialize(q,Q);
	printf("\nI :  %d\n",i);
	Back_Track(i,q,Q);
	if(myBool==1){
		printf("\nSolution :  \n");
		print(q,Q);
		myBool=0;
	}
	i++;
	N_Queen(i,q,Q);
}
void main(){
	int q;
	printf("Enter the number of Queens :  ");
	scanf("%d",&q);
	int Q[q+1][q+1];
	N_Queen(1,q+1,Q);
}