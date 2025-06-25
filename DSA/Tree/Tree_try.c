#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int tree[20],level[10];
int count=0,lvl,root=0,l=0,j=0;

void print_array(int x[],int n){
	for(int i=0;i<n;i++)
		printf("%d ",x[i]);
	printf("\n");
}
void create(int x){
	int i;
	level[0]=1;
	if(tree[0]=='\0'){
		tree[0]=x;
		count++;
	}
	else{
		if(tree[2*l+1]=='\0'){
			tree[2*l+1]=x;
			count++;
		}
		else{
			tree[2*l+2]=x;
			count++;
			l++;
		}
	}
	for(i=1;i<10;i++){
		for(int j=0;j<i;j++)
			level[i]=pow(2,i)+level[j];
	}
	if(count>level[j]){
		if(j==0){
			lvl=1;
			j++;
		}
		else{
			lvl=level[j+1]-level[j];
			j++;
		}
	}
}
void display(int n){
	int i,j=0,k,m,l=0,z;
	while(pow(2,j)!=n)
		j++;
	j=j+1;
	printf("\tj : %d \t",j);
	printf("\n\n");
	for(i=0;i<=j;i++){
		k=j-i;
		m=0;
		while(m!=k){
			printf("    ");
			m++;
		}
		if(i==0){
			printf(" %d ",tree[l]);
			l++;
		}
		else{
			z=0;
			while(z<level[i]-level[i-1]&&tree[l]!='\0'){
				printf(" %d ",tree[l]);
				m=0;
				while(m!=k-1){
					printf("  ");
					m++;
				}
				l++;
				z++;
			}
		}
		m=0;
		while(m!=k){
			printf("   ");
			m++;
		}
		printf("\n\n");
	}
}
void main(){
	int ch,n;
	while(1){
		printf("\n1.Create\n2.Display\t\tEnter Choice :  ");
		scanf("%d",&ch);
		switch(ch){
			case 1: printf("\t\t\tEnter Data :  ");
					scanf("%d",&n);
					create(n);
					break;
			case 2: printf("\tlvl :  %d\tcount :  %d\t",lvl,count);
					print_array(tree,count);
					display(lvl);
					break;
			case 3: exit(0);
		}
	}
}