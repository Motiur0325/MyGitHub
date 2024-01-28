#include<stdio.h>
#define INF 999

void print(int n,int x[n][n]){
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			if(x[i][j]!=INF){
				printf("%3d ",x[i][j]);
			}
			else printf("INF ");
		}
		printf("\n");
	}
}
void Floyd_Warshall(int n,int A[n][n]){
	int i,j,k,q;
	for(i=0;i<n;i++)
		A[i][i]=0;
	for(k=0;k<n;k++){
		for(i=0;i<n;i++){
			for(j=0;j<n;j++){
				q=A[i][k]+A[k][j];
				if(q<=A[i][j])
					A[i][j]=q;
			}
		}
		printf("\nA[%d] : \n",k+1);
		print(4,A);
	}
		
}
void main(){
	int A[4][4]={{0,3,INF,7},{8,0,2,INF},{5,INF,0,1},{2,INF,INF,0}};
	printf("\nA[0] : \n");
	print(4,A);
	Floyd_Warshall(4,A);
}