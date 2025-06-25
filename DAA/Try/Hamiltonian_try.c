#include<stdio.h>

void write(int x[],int n){
	printf("\nX :  ");
	for(int i=1;i<=n;i++)
		printf("%d ",x[i]);
	printf("\n");
}
void Next_Value(int k,int x[],int n,int Adj[n][n]){
	int j;
	printf("\nK :  %d",k);
	while(1){
		x[k]=(x[k-1]+1)%(n+1);
		if(x[k]==0)
			return;
		if(Adj[x[k-1]][x[k]]!=0){
			for(j=1;j<=k-1;j++){
				if(x[j]==x[k])
					break;
			}
			if(j==k){
				if((k<n)||((k==n)&&Adj[x[n]][x[1]]!=0))
					return;
			}
		}
	}
}
void Hamiltonian(int k,int x[],int n,int Adj[n][n]){
	while(1){
		Next_Value(k,x,n,Adj);
		if(x[k]==0)
			return;
		if(k==n)
			write(x,n);
		Hamiltonian(k+1,x,n,Adj);
	}
}
void main(){
	int i,j,u,v,n=8,e=10;
	int x[n+1];
	int U[11]={0,1,1,1,2,2,3,4,5,6,7};
	int V[11]={0,2,3,7,8,3,4,5,6,7,8};
	/*printf("Enter the no of vertices and edges :  ");
	scanf("%d%d",&n,&e);*/
	int Adj[n+1][n+1];
	for(i=1;i<=n;i++){
		for(j=1;j<=n;j++)
			Adj[i][j]=0;
	}
	for(i=1;i<=e;i++){
		//printf("Enter the vertices :  ");
		//scanf("%d%d",&u,&v);
		Adj[U[i]][V[i]]=1;
		Adj[V[i]][U[i]]=1;
	}
	printf("\nAdjacency Matrix : \n");
	for(i=1;i<=n;i++){
		for(j=1;j<=n;j++)
			printf("%d ",Adj[i][j]);
		printf("\n");
	}
	x[1]=1;
	for(i=2;i<=n;i++)
		x[i]=0;
	Hamiltonian(2,x,n,Adj);
}