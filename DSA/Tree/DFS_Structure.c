#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>

int top=-1;

struct Edge{
	int u;
	int v;
};
struct Tree{
	int E;
	int V;
	struct Edge*edge;
};

void initialize_tree(int n,int tree[n][n]){
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			tree[i][j]=0;
		}
	}
}

void initialize_vertex_status(int n,int vertex_status[n]){
	for(int i=0;i<n;i++){
		vertex_status[i]=0;
	}
}

void display_adj_matrix(int n,int tree[n][n]){
	printf("\nAdjacency Matrix : \n\n");
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			printf("%d ",tree[i][j]);
		}
		printf("\n");
	}
}

void set_vertex_status(int n,int vertex_status[],int status){
	vertex_status[n]=status;
}

void push(int e,int adj_vertex,int stack[e],int vertex_status[]){
	top++;
	stack[top]=adj_vertex;
	set_vertex_status(adj_vertex,vertex_status,1);
}

int pop(int e,int stack[e],int vertex_status[]){
	int ret_vertex=stack[top];
	stack[top]=0;
	set_vertex_status(ret_vertex,vertex_status,2);
	top--;
	return ret_vertex;
}

bool not_empty(int dfs_stack[]){
	if(top==-1){
		return false;
	}
	else{
		return true;
	}
}

int check_status(int n,int vertex_status[n]){
	return vertex_status[n];
}

void DFS_traversal(int e,int dfs_stack[e],struct Tree* myTree,int start,int vertex_status[]){
	push(e,start,dfs_stack,vertex_status);
	while(not_empty(dfs_stack)){
		int vertex=pop(e,dfs_stack,vertex_status);
		for(int i=0;i<e;i++){
			if(myTree->edge[i].u==vertex){
				if(check_status(myTree->edge[i].v,vertex_status)==0){
					push(e,myTree->edge[i].v,dfs_stack,vertex_status);
				}
			}
		}
		printf("%d ",vertex);
	}
}

void main(){
	int st_vertex;
	struct Tree*myTree=(struct Tree*)malloc(sizeof(struct Tree));
	printf("Enter the no. of vertices and edges :  ");
	scanf("%d%d",&myTree->V,&myTree->E);
	int dfs_stack[myTree->E];
	int vertex_status[myTree->V];
	initialize_vertex_status(myTree->V,vertex_status);
	myTree->edge=(struct Edge*)malloc(sizeof(struct Edge)*myTree->E);
	for(int i=0;i<myTree->E;i++){
		printf("Enter start and final vertex respectively :  ");
		scanf("%d%d",&myTree->edge[i].u,&myTree->edge[i].v);
	}
	printf("\n\nEnter the starting vertex :  ");
	scanf("%d",&st_vertex);
	printf("\n\nBFS Traversal :  ");
	DFS_traversal(myTree->E,dfs_stack,myTree,st_vertex,vertex_status);
}