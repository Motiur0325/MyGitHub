#include<stdio.h>
#include<stdlib.h>
#define INF 999

int count=0;

struct Edge{
	int u;
	int v;
	int w;
};
struct Graph{
	int V;
	int E;
	struct Edge*edge;
};
void print(int d[],int p[],int n){
	printf("\n\nDistance Array :  ");
	for(int i=0;i<n;i++)
		printf("%d ",d[i]);
	printf("\nPredecessor Array :  ");
	for(int i=0;i<n;i++)
		printf("%d ",p[i]);
}
void Initialize_single_source(struct Graph*g,int src,int d[],int p[]){
	for(int i=0;i<g->V;i++){
		d[i]=INF;
		p[i]=INF;
	}
	d[src]=0;
}
int Extract_min(struct Graph*g,int P[],int Q,int S[],int d[]){
	int u,w,i=0,j,min=999,min_v;
	u=P[count-1];
	if(count==0){
		return 0;
	}
	else{
		u=P[count-1];
		for(i=0;i<g->E;i++){
			if(g->edge[i].u==u){
				if(g->edge[i].w<min){
					min=g->edge[i].w;
					min_v=g->edge[i].v;
				}
			}
		}
	}
	return min_v;
}
void Relax(int i,int S[],int u,int v,int w,int d[],int p[]){
	S[i]=v;
	if(d[v]>d[u]+w){
		d[v]=d[u]+w;
		p[v]=u;
	}
	printf("\nP :  ");
	for(int i=0;i<5;i++)
		printf("%d ",p[i]);
	printf("\n");
}
void Dijkstra(struct Graph*g,int src){
	int d[g->V],S[g->V],p[g->V];
	int ini_u=0,u,n;
	Initialize_single_source(g,src,d,p);
	for(int i=0;i<g->V;i++)
		S[i]=INF;
	S[0]=0;
	int Q=S[0];
	print(d,p,g->V);
	while(count<g->V){
		u=Extract_min(g,p,Q,S,d);
		printf("\tU : %d\t",u);
		for(int i=0;i<g->V;i++){
			if(g->edge[i].u==u){
				Relax(n,S,u,g->edge[i].v,g->edge[i].w,d,p);
				printf("U : %d , V : %d\t",g->edge[i].u,g->edge[i].v);
			}
			n++;
		}
		print(d,p,g->V);
		printf("\nS :  ");
		for(int i=0;S[i]!=INF;i++)
			printf("%d ",S[i]);
		count++;
	}
}
void main(){
	int i,j;
	struct Graph*g=(struct Graph*)malloc(sizeof(struct Graph));
	/*printf("Enter no. of vertices and edges respectively :  ");
	scanf("%d%d",&g->V,&g->E);*/
	g->V=5;
	g->E=10;
	g->edge=(struct Edge*)malloc(g->E*sizeof(struct Edge));
	for(i=0;i<g->E;i++){
		/*printf("Enter initial, final vertex and weight :  ");
		scanf("%d%d%d",&g->edge[i].u,&g->edge[i].v,&g->edge[i].w);*/
		g->edge[i].u=U[i];
		g->edge[i].v=V[i];
		g->edge[i].w=W[i];
	}
	Dijkstra(g,0);
}