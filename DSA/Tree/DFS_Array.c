#include<stdio.h>
#include<stdbool.h>

int top=-1;

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

void BFS_traversal(int e,int dfs_stack[e],int n,int tree[n][n],int vertex_status[n],int start){
	push(e,start,dfs_stack,vertex_status);
	while(not_empty(dfs_stack)){
		int vertex=pop(e,dfs_stack,vertex_status);
		for(int i=n-1;i>=0;i--){
			if(tree[vertex][i]!=0){
				if(check_status(i,vertex_status)==0){
					push(e,i,dfs_stack,vertex_status);
				}
			}
		}
		printf("%d ",vertex);
	}
}

void main(){
	int n,e,st_vertex;
	printf("Enter the no. of vertices and edges :  ");
	scanf("%d%d",&n,&e);
	int tree[n][n];
	int dfs_stack[e];
	int vertex_status[n];
	initialize_tree(n,tree);
	initialize_vertex_status(n,vertex_status);
	for(int i=0;i<e;i++){
		int u,v;
		printf("Enter start and final vertex respectively :  ");
		scanf("%d%d",&u,&v);
		tree[u][v]=1;
	}
	display_adj_matrix(n,tree);
	printf("\n\nEnter the starting vertex :  ");
	scanf("%d",&st_vertex);
	printf("\n\nBFS Traversal :  ");
	BFS_traversal(e,dfs_stack,n,tree,vertex_status,st_vertex);
	
}