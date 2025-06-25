#include<stdio.h>

void Knapsack_01(int n,int m,int w[],int p[],int cost[n][m]){
	int i,j,q;
	for(i=0;i<n;i++){
		for(j=0;j<m;j++)
			cost[i][j]=0;
	}
	for(i=1;i<n;i++){
		for(j=1;j<m;j++){
			cost[i][j]=cost[i-1][j];
			if(j-w[i]>=0){
				q=p[i]+cost[i-1][j-w[i]];
				if(q>cost[i-1][j])
					cost[i][j]=q;	
			}
		}
	}
}
void main(){
	int w[5]={0,2,3,4,5};
	int p[5]={0,3,4,5,6};
	int n=4,m=5;
	int cost[n+1][m+1];
	Knapsack_01(n+1,m+1,w,p,cost);
	printf("\nProfit Matrix :\n\n");
	for(int i=0;i<n+1;i++){
		for(int j=0;j<m+1;j++)
			printf("%2d ",cost[i][j]);
		printf("\n");
	}
	printf("\nMaximum Profit :  %d",cost[n][m]);
}