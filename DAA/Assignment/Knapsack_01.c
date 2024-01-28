#include<stdio.h>

void Knapsack_01(int n,int m,int w[],int p[],int cost[n][m]){
	int i,j,q;
	for(i=0;i<n;i++){
		for(j=0;j<m;j++)
			cost[i][j]=0;
	}
	for(i=1;i<n;i++){
		for(j=1;j<m;j++){
			if(j-w[i]<0){
				cost[i][j]=cost[i-1][j];
			}
			else{
				cost[i][j]=cost[i-1][j];
				q=p[i]+cost[i-1][j-w[i]];
				if(q>cost[i-1][j]){
					cost[i][j]=q;
				}
			}
		}
	}
}
void main(){
	int i,j,n,m;
	printf("Enter the number of items and knapsack weight :  ");
	scanf("%d%d",&n,&m);
	int w[n+1],p[n+1];
	for(i=1;i<=n;i++){
		printf("Enter the weight and profit for item [%d] :  ",i);
		scanf("%d%d",&w[i],&p[i]);
	}
	int cost[n+1][m+1];
	Knapsack_01(n+1,m+1,w,p,cost);
	printf("\nProfit Matrix :\n\n");
	for(int i=0;i<n+1;i++){
		for(int j=0;j<m+1;j++)
			printf("%3d ",cost[i][j]);
		printf("\n");
	}
	printf("\nMaximum Profit :  %d",cost[n][m]);
}