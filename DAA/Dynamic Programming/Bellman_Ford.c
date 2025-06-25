#include<stdio.h>
#include<stdlib.h>
#define INF 99999

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
void Bellman_Ford(struct Graph *g,int src){
	int i,j,u,v,w;
	int tV=g->V;
	int tE=g->E;
	int d[tV];
	for(i=1;i<=tV;i++)
		d[i]=INF;
	d[src]=0;
	for(i=1;i<tV;i++){
		for(j=1;j<=tE;j++){
			u=g->edge[j].u;
			v=g->edge[j].v;
			w=g->edge[j].w;
			printf("d[%d] : %d||d[%d] : %d||w : %d\n",v,d[v],u,d[u],w);
			if(d[v]>d[u]+w){
				d[v]=d[u]+w;
				printf("d[%d] : %d\t",v,d[v]);
			}
		}
	}
	printf("\nDistance Array :  ");
	for(i=1;i<=tV;i++){
		if(d[i]!=INF){
			printf("%d ",d[i]);
		}
		else{
			printf("INF ");
		}
	}
}
void main(){
	int i;
	struct Graph *g=(struct Graph*)malloc(sizeof(struct Graph));
	printf("Enter number of vertices :  ");
	scanf("%d",&g->V);
	printf("Enter number of Edges :  ");
	scanf("%d",&g->E);
	g->edge=(struct Edge *)malloc(g->E*sizeof(struct Edge));
	for(i=1;i<=g->E;i++){
		printf("Enter initial, final vertex and edge weight respectively :  ");
		scanf("%d",&g->edge[i].u);
		scanf("%d",&g->edge[i].v);
		scanf("%d",&g->edge[i].w);
	}
	Bellman_Ford(g,1);
}