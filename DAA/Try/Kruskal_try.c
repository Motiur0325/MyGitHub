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
		printf("\nRep : %d , Wt : %d , Next : %d",top->wt,top->rep->wt,top->next->wt);
		top=top->next;
	}
	printf("\nRep : %d , Wt : %d",top->wt,top->rep->wt);
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
int Find_Set(struct Graph*g,int *u,int *v,int *min,int *min_i,struct node *ini,struct node * fin){
	int i,R,M;
	int m[g->V];
	*min=999;
	struct node*initial=head1,*final=head1;
	for(i=1;i<=g->E;i++){
		if(g->edge[i].w<*min){
			*min=g->edge[i].w;
			*u=g->edge[i].u;
			*v=g->edge[i].v;
			*min_i=i;
		}
	}
	printf("\nMin : %d",min);
	while(initial->wt!=*u){
		initial=initial->next;
	}
	ini=initial;
	while(final->wt!=*v){
		final=final->next;
	}
	fin=final;
}
int Union_Set(int *u,int *v,int *min,int *min_i,struct Graph*g,struct node*initial,struct node *final){
	if(initial->rep!=final->rep){
		printf("\nFinal :  %d , Initial :  %d",final->rep->wt,initial->rep->wt);
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
						printf("\tk : %d\t",k);
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
						printf("\tk : %d\t",k);
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
		printf("\nFinal :  %d , Initial :  %d",final->rep->wt,initial->rep->wt);
		g->edge[*min_i].w=INF;
		//printf("\nU : %d , V : %d",*u,*v);
		return *min;
	}
	else{
		g->edge[*min_i].w=INF;
		//printf("\nU : %d , V : %d , Edge :  %d",*u,*v,g->edge[min_i].w);
		Find_Set(g,u,v,min,min_i,initial,final);	
	}
}
void Kruskal(struct Graph *g){
	int min,min_i,i=1,u,v,q,Path_Length=0;
	struct node*ini;
	struct node*fin;
	Make_Set(g->V);
	while(i<g->V){
		Find_Set(g,&u,&v,&min,&min_i,ini,fin);
		Path_Length+=Union_Set(&u,&v,&min,&min_i,g,ini,fin);
		printf("\nPath Length :  %d\n",Path_Length);
		i++;
	}
}
void main(){
	int i;
	int U[15]={0,1,1,2,2,3,3,3,4,4,5,6,7,7,8};
	int V[15]={0,2,8,3,8,4,9,6,5,6,6,7,9,8,9};
	int W[15]={0,4,8,8,11,7,2,4,9,14,10,2,6,1,7};
	struct Graph*g=(struct Graph*)malloc(sizeof(struct Graph));
	/*printf("Enter the no. of vertices and edges :  ");
	scanf("%d%d",&g->V,&g->E);*/
	g->V=9;
	g->E=14;
	g->edge=(struct Edge*)malloc((g->E+1)*sizeof(struct Edge));
	for(i=1;i<=g->E;i++){
		/*printf("Enter initial, final vertices and edge weight :  ");
		scanf("%d%d%d",&g->edge[i].u,&g->edge[i].v,&g->edge[i].w);
		*/g->edge[i].u=U[i];
		g->edge[i].v=V[i];
		g->edge[i].w=W[i];
	}
	Kruskal(g);
	print();
}