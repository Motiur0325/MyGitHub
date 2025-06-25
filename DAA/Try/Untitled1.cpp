1 2 4
1 8 8
2 3 8
2 8 11
3 4 7
3 9 2
3 6 4
4 5 9
4 6 14
5 6 10
6 7 2
7 9 6
7 8 1
8 9 7
int U[15]={0,1,1,2,2,3,3,3,4,4,5,6,7,7,8};
int V[15]={0,2,8,3,8,4,9,6,5,6,6,7,9,8,9};
int W[15]={0,4,8,8,11,7,2,4,9,14,10,2,6,1,7};
int Find_Set(struct Graph*g,int *u,int *v){
	int i,min=999,min_i;
	struct node*initial=head1,*final=head1;
	for(i=1;i<=g->E;i++){
		if(g->edge[i].w<min){
			min=g->edge[i].w;
			*u=g->edge[i].u;
			*v=g->edge[i].v;
			min_i=i;
		}
	}
	while(initial->data!=*u){
		prev1=initial;
		initial=initial->next;
		forw1=initial->next;
	}
	while(final->data!=*v){
		prev2=final;
		final=final->next;
		forw2=final->next;
	}
	if(initial->rep!=final->rep){
		prev1->next=forw1;
		prev2->next=forw2;
		initial->next=
	}
	g->edge[min_i].w=INF;
	return min;
}