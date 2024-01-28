#include<stdio.h>
#define INF 999

void matrix_initialize(int n,int x[n][n]){
	int i,j;
	for(i=1;i<n;i++){
		for(j=1;j<n;j++)
			x[i][j]=INF;
		x[i][i]=0;
	}
}
void Bellman_Ford(int n,int m,int V[2*m+1],int E[n][n]){
	int i,j,u,v,w,src;
	int d[n];
	printf("\nEnter Source Vertex :  ");
	scanf("%d",&src);
	for(i=1;i<n;i++)
		d[i]=INF;
	d[src]=0;
	for(i=1;i<n-1;i++){
		for(j=1;j<=m;j++){
			u=V[2*j-1];
			v=V[2*j];
			w=E[u][v];
			if(d[v]>d[u]+w){
				d[v]=d[u]+w;
			}
		}
	}
	printf("\nDistance Array :  ");
	for(i=1;i<n;i++)
		printf("%d ",d[i]);
}
void main(){
	int i,n,e,u,v,w;
	printf("Enter no. of vertices and edges in the graph :  ");
	scanf("%d%d",&n,&e);
	int N=2*e+1;
	int V[N],E[n+1][n+1];
	matrix_initialize(n+1,E);
	for(i=1;i<=e;i++){
		printf("Enter initial, final vertex and edge weight :  ");
		scanf("%d%d%d",&u,&v,&w);
		E[u][v]=w;
		V[2*i-1]=u;
		V[2*i]=v;
	}
	Bellman_Ford(n+1,e,V,E);
}