/*Contents :::----

1.BellmanFord. 

/*Bellman Ford Algorithm Extras :-
void print(int n,int x[]){
	for(int i=1;i<n;i++)
		printf("%d ",x[i]);
	printf("\n");
}
void print_mat(int n,int x[n][n]){
	for(int i=1;i<n;i++){
		printf("\n|");
		for(int j=1;j<n;j++)
			printf("%3d ",x[i][j]);
		printf("|");
	}
	printf("\n");
}
	for main function :-
	printf("\nVertex Set :  ");
	print(N,V);
	printf("\nEdge Adjacency Matrix : \n");
	print_mat(n+1,E);
*/
//Dijkstra :-
/*int Extract_min(struct Graph*g,int d[],int ini_u){
	int i,min=999,min_v;
	int u=d[ini_u];
	for(i=0;i<g->E;i++){
		if(g->edge[i].u==d[ini_u]){
			if(g->edge[i].w<min){
				min=g->edge[i].w;
				min_v=g->edge[i].v;
			}
		}
	}
	return min_v;
}*/
/*while(S[i]!=INF){
			j=0;
			while(j<8){
				if(g->edge[j].u==u&&g->edge[j].v==S[i])
					w=g->edge[j].w;
				j++;
			}
			if(w<min)
				min=g->edge[i].u;
			i++;
		}
		i=0;
		while(S[i]!=INF){
			S[i]=INF;
			i++;
		}
		*/