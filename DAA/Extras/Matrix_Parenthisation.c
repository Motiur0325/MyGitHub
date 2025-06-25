#include<stdio.h>
#include<stdlib.h>
#include<bits.h>

char Name[8]={'A','B','C','D','E','F','G','H'};
int count=0;
void print_parens(int n,int*s,int i,int j);

void Chain_Order(int P[],int n){
	int m[n][n],s[n][n];
	int j,q;
	for(int i=1;i<n;i++)
		m[i][i]=0;
	for(int l=2;l<n;l++){
		for(int i=1;i<n+1-l;i++){
			j=i+l-1;
			m[i][j]=INT_MAX;
			for(int k=i;k<j;k++){
				q=m[i][k]+m[k+1][j]+P[i-1]*P[k]*P[j];
				if(q<m[i][j]){
					m[i][j]=q;
					s[i][j]=k;
				}
			}
		}
	}
	printf("\n\nTotal No. of Scalar Multiplications :  %d\n\nOptimal Parenthisation :  ",m[1][n-1]);
	print_parens(n,(int*)s,1,n-1);
}
void print_parens(int n,int*s,int i,int j){
	if(i==j){
		printf("%c",Name[count]);
		count++;
	}
	else{
		printf("(");
		print_parens(n,s,i,*((s+i*n)+j));
		print_parens(n,s,*((s+i*n)+j)+1,j);
		printf(")");
	}
}
int main(){
	int P[100]={40,20,30,10,30};
	int n=0;
	while(P[n]!='\0')
		n++;
	Chain_Order(P,n);
}