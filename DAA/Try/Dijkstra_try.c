#include<stdio.h>
#define INF 999

int d[10],p[10];
int count=1;

void matrix_initialize(int n,int x[n][n]){
	int i,j;
	for(i=1;i<n;i++){
		for(j=1;j<n;j++)
			x[i][j]=INF;
		x[i][i]=0;
	}
}
int Extract_min(int S[],int n,int Adj[n][n]){
	int i,j,u,loc,min=999;
	if(count==1){
		S[count]=0;
		return 1;
	}
	for(i=1;i<n&&d[i]!=INF;i++){
		loc=0;
		for(j=1;j<count;j++){
			if(d[i]==S[j])
			loc=1;
		}
		if(loc==0){
			if(d[i]<min){
				min=d[i];
				u=i;
			}
		}
	}
	S[count]=min;
	return u;
}
void Initialize(int n,int d[n],int p[n]){
	int src=1;
	for(int i=1;i<n;i++){
		d[i]=INF;
		p[i]=0;
	}
	d[src]=0;
}
void Relax(int u,int v,int w){
	if(d[v]>d[u]+w){
		d[v]=d[u]+w;
		p[v]=u;
	}
}
void print(int n){
	int i;
	printf("\n\nDistance    :  ");
	for(i=1;i<n;i++)
		printf("%d ",d[i]);
	printf("\nPredecessor :  ");
	for(i=1;i<n;i++)
		printf("%d ",p[i]);
}
void Dijkstra(int n,int Adj[n][n]){
	int i,u;
	Initialize(n,d,p);
	int S[n];
	for(i=1;i<n;i++)
		S[n]=INF;
	while(count!=n-1){
		u=Extract_min(S,n,Adj);	
		for(i=1;i<n;i++){
			if(Adj[u][i]!=INF&&Adj[u][i]!=0)
				Relax(u,i,Adj[u][i]);
		}
		count++;
	}
	print(n);
}
void main(){
	int i,n=5,e=10,u,v,w;
	printf("Enter no. of vertices and edges in the graph :  ");
	scanf("%d%d",&n,&e);
	int Adj[n+1][n+1];
	matrix_initialize(n+1,Adj);
	for(i=1;i<=e;i++){
		printf("Enter initial, final vertex and edge weight :  ");
		scanf("%d%d%d",&u,&v,&w);
		Adj[u][v]=w;
	}
	Dijkstra(n+1,Adj);
	}