#include<stdio.h>
#include<stdlib.h>
#define INF 999

int Path[100],count=1;;

struct node{
	struct node *rep;
	int wt;
	struct node *next;
}*head=NULL,*head1,*root=NULL,*Check=NULL;

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
void print(){
	struct node*top;
	top=head1;
	while(top->next!=NULL){
		printf("\nRep : %d , Wt : %d , Next : %d",top->rep->wt,top->wt,top->next->wt);
		top=top->next;
	}
	printf("\nRep : %d , Wt : %d , Next : NULL",top->rep->wt,top->wt);
}
void Make_Set(int n){
	int i=1;
	while(i<=n){
		struct node *temp=(struct node*)malloc(sizeof(struct node));
		temp->rep=temp;
		temp->wt=i;
		temp->next=NULL;
		if(head==NULL){
			head=temp;
			head1=temp;
		}
		else{
			head->next=temp;
			head=temp;
		}
		i++;
	}
}
int Find_Set(struct Graph*g,int *u,int *v){
	int i,min=999,min_i,R,M;
	int m[g->V];
	struct node*initial=head1,*final=head1;
	for(i=1;i<=g->E;i++){
		if(g->edge[i].w<min){
			min=g->edge[i].w;
			*u=g->edge[i].u;
			*v=g->edge[i].v;
			min_i=i;
		}
	}
	while(initial->wt!=*u){
		initial=initial->next;
	}
	while(final->wt!=*v){
		final=final->next;
	}
	if(initial->rep!=final->rep){
		if(root==NULL){
			root=initial->rep;
			final->rep=initial->rep;
		}
		else{
			Check=head1;
			if(initial->rep==root){
				int k=1;
				while(Check!=NULL){
					if(Check->rep==final->rep&&Check!=final){
						Check->rep=root;
					}
					k++;
					Check=Check->next;
				}
				final->rep=root;
			}
			if(final->rep==root){
				int k=1;
				while(Check!=NULL){
					if(Check->rep==initial->rep&&Check!=initial){
						Check->rep=root;
					}
					k++;
					Check=Check->next;
				}
				initial->rep=root;
			}
			else{
				initial->rep=final->rep;
			}
		}
		g->edge[min_i].w=INF;
		return min;
	}
	else{
		g->edge[min_i].w=INF;
		Find_Set(g,u,v);	
	}
}
void Kruskal(struct Graph *g){
	int i=1,u,v,q,Path_Length=0;
	Make_Set(g->V);
	while(i<g->V){
		Path_Length+=Find_Set(g,&u,&v);
		i++;
	}
	printf("\nPath Length :  %d\n",Path_Length);
}
void main(){
	int i;
	struct Graph*g=(struct Graph*)malloc(sizeof(struct Graph));
	printf("Enter the no. of vertices and edges :  ");
	scanf("%d%d",&g->V,&g->E);
	g->edge=(struct Edge*)malloc((g->E+1)*sizeof(struct Edge));
	for(i=1;i<=g->E;i++){
		printf("Enter initial, final vertices and edge weight :  ");
		scanf("%d%d%d",&g->edge[i].u,&g->edge[i].v,&g->edge[i].w);
	}
	Kruskal(g);
	print();
}