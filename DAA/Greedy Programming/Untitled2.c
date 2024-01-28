#include<stdio.h>
#define INF 999

int d[10],p[10],s[10];
int count=1,u,v,w;

void matrix_initialize(int n,int x[n][n]){
	int i,j;
	for(i=1;i<n;i++){
		for(j=1;j<n;j++)
			x[i][j]=INF;
		x[i][i]=0;
	}
}
void Initialize(int n,int d[n],int p[n]){
	int src=1;
	for(int i=1;i<n;i++){
		d[i]=INF;
		p[i]=0;
		s[i]=0;
	}
	d[src]=0;
	p[src]=1;
	s[src]=1;
}
void Relax(int u,int v,int w){
	if(d[v]>d[u]+w){
		d[v]=d[u]+w;
		p[v]=u;
		s[v]=v;
	}
}
void Dijkstra(int n,int Adj[n][n],int e,int W[e]){
	int i;
	Initialize(n,d,p);
	for(i=1;i<n;i++)
		S[n]=INF;
	while(count!=n-1){
		u=Extract_min(S,n);	
		for(i=1;i<n;i++){
			if(Adj[u][i]!=INF&&Adj[u][i]!=0)
				Relax(u,i,Adj[u][i]);
		}
		count++;
	}
	print(n);
}
void main(){
	int i,n,e,u,v,w;
	printf("Enter no. of vertices and edges in the graph :  ");
	scanf("%d%d",&n,&e);
	int Adj[n+1][n+1];
	int W[e+1];
	matrix_initialize(n+1,Adj);
	for(i=1;i<=e;i++){
		printf("Enter initial, final vertex and edge weight :  ");
		scanf("%d%d%d",&u,&v,&w);
		Adj[u][v]=w;
		W[i]=w;
	}
	Dijkstra(n+1,Adj,e+1,W);
}