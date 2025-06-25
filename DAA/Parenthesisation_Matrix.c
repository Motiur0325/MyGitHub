#include<stdio.h>
#include<bits.h>

int s[100][100],m[100][100];
int n;

void Matrix_Chain_Order(int P[]){
	int l,i,j,q,k;
	for(i=1;i<=n+1;i++)
		m[i][i]=0;
	for(l=2;l<=n;l++){
		for(i=1;i<=n-l+1;i++){
			j=i+l-1;
			m[i][j]=INT_MAX;
			for(k=i;k<j;k++){
				q=m[i][k]+m[k+1][j]+P[i-1]*P[k]*P[j];
				if(q<=m[i][j]){
					m[i][j]=q;
					s[i][j]=k;
				}
			}
		}
	}
}
void Print_Optimal_Parens(int s[100][100],int i,int j){
	if(i==j){
		printf("A%d",i);
	}
	else{
		printf("(");
		Print_Optimal_Parens(s,i,s[i][j]);
		Print_Optimal_Parens(s,s[i][j]+1,j);
		printf(")");
	}
}
void main(){
	int P[]={2,4,3,6,5,7};
	n=sizeof(P)/sizeof(P[0])-1;
	printf("Optimal Parenthesisation :  ");
	Matrix_Chain_Order(P);
	Print_Optimal_Parens(s,1,n);
	printf("\n\nOptimal Cost :  %d",m[1][n]);
}
