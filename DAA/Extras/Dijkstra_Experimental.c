#include<stdio.h>
#define INF 999

int d[10],p[10],s[10];
int count=1,u,v,w;

void matrix_initialize(int n,int x[n][n]){
	printf("\nPass M\n");
	int i,j;
	for(i=1;i<n;i++){
		for(j=1;j<n;j++)
			x[i][j]=INF;
		x[i][i]=0;
	}
}
int find(int u,int n,int Min[n],int Suc[n]){
	printf("\nPass F\n");
	int i;
	for(i=1;i<n;i++){
		if(Min[i]==u){
			return Suc[i];
		}
	}
}
int Extract_min(int S[],int n){
	int i,j,k,N=n,min=999;
	int Min[N],Suc[N];
	for(i=1;i<N;i++){
		Min[i]=d[i];
		Suc[i]=s[i];
	}
	printf("\nMin :  ");
	for(i=1;i<N;i++)
		printf("%d ",Min[i]);
	for(i=1;i<count;i++){
		for(j=1;j<N;j++){
			if(S[i]==Min[j]){
				k=j;
				while(k<N){
					Min[k]=Min[k+1];
					Suc[k]=Suc[k+1];
					k++;
				}
				N--;
			}
		}
	}
	printf("\nMin :  ");
	for(i=1;i<N;i++)
		printf("%d ",Min[i]);
	printf("\nSuccessor :  ");
	for(i=1;i<N;i++)
		printf("%d ",Suc[i]);
	printf("\nPass E\n");
	if(count==1){
		S[count]=0;
		return 1;
	}
	for(i=1;i<N;i++){
		if(Min[i]<min){
			min=Min[i];
			printf("\tMin :  %d\t",min);
		}
	}
	S[count]=min;
	return find(min,N,Min,Suc);
}
void Initialize(int n,int d[n],int p[n]){
	printf("\nPass I\n");
	int src=1;
	for(int i=1;i<n;i++){
		d[i]=INF;
		p[i]=INF;
		s[i]=INF;
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
void print(int n){
	int i;
	printf("\n\nDistance :  ");
	for(i=1;i<n;i++)
		printf("%d ",d[i]);
	printf("\nPredecessor :  ");
	for(i=1;i<n;i++)
		printf("%d ",p[i]);
	printf("\nSuccessor :  ");
	for(i=1;i<n;i++)
		printf("%d ",s[i]);
}
void Dijkstra(int n,int Adj[n][n]){
	int i;
	Initialize(n,d,p);
	int S[n];
	for(i=1;i<n;i++)
		S[n]=INF;
	while(count!=n-1){
		u=Extract_min(S,n);
		printf("\tU :  %d\t",u);
		printf("\nS :  ");
		for(i=1;i<=count;i++)
			printf("%d ",S[i]);		
		for(i=1;i<n;i++){
			if(Adj[u][i]!=INF&&Adj[u][i]!=0)
				Relax(u,i,Adj[u][i]);
		}
		print(n);
		count++;
	}
}
void main(){
	int i,n,e,w;
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