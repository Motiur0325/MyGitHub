#include<stdio.h>
#include<stdlib.h>

void Mat_User(int i,int j,char Mat[],int m,int z[i][j]){
	for(int x=0;x<i;x++){
		for(int y=0;y<j;y++){
			printf("%c[%d][%d] = ",Mat[m],x,y);
			scanf("%d",&z[x][y]);
		}
	}
}
void Mat_Create(int i,int j,int z[i][j]){
	for(int x=0;x<i;x++){
		for(int y=0;y<j;y++)
			z[x][y]=rand()%20+2;
	}
}
void Mat_Dis(int a,int b,int x[a][b]){
	int i,j;
	for(i=0;i<a;i++){
		printf(" | ");
		for(j=0;j<b;j++)
			printf("%3d ",x[i][j]);
		printf("  |\n\n");
	}
}
void Mat_Add(int a,int b,int x[a][b],int y[a][b]){
	int i,j,c[a][b];
	for(i=0;i<a;i++){
		for(j=0;j<b;j++){
			c[i][j]=x[i][j]+y[i][j];
		}
	}
	printf("\nAdded Matrix :  \n\n");
	Mat_Dis(i,j,c);
}
void Mat_Sub(int a,int b,int x[a][b],int y[a][b]){
	int i,j,c[a][b];
	for(i=0;i<a;i++){
		for(j=0;j<b;j++){
			c[i][j]=x[i][j]-y[i][j];
		}
	}
	printf("\nSubtracted Matrix :  \n\n");
	Mat_Dis(i,j,c);
}
void Mat_Mul(int a,int b,int c,int x[a][b],int y[b][c]){
	int i,j,k,m=0;
	int z[a][c];
	for(i=0;i<a;i++){
		for(j=0;j<c;j++)
			z[i][j]=0;
	}
	for(i=0;i<a;i++){
		for(j=0;j<c;j++){
			for(k=0;k<b;k++){
				z[i][j]+=x[i][k]*y[k][j];
			}
		}
	}
	printf("\nMultiplied Matrix :  \n\n");
	Mat_Dis(a,c,z);
}
void main(){
	int i,j,k,ch,m,c;
	char Mat[2]={'A','B'};
	int a[10][10],b[10][10];
	while(1){
		m=0;
		printf("1.Add\n2.Multiply\n3.Subtract\n4.Exit\t\tEnter Choice :  ");
		scanf("%d",&ch);
		switch(ch){
			case 1: printf("\nEnter the order of both Matrices :  \n");
					printf("Rows :  ");
					scanf("%d",&i);
					printf("Columns :  ");
					scanf("%d",&j);
					printf("\n1.User Data\n2.Random Data\t\tEnter Choice :  ");
					scanf("%d",&c);
					if(c==1){
						Mat_User(i,j,Mat,m,a);
						m++;
						printf("\n");
						Mat_User(i,j,Mat,m,b);
					}
					if(c==2){
						Mat_Create(i,j,a);
						Mat_Create(i,j,b);
					}
					printf("\nFirst Matrix :  \n\n");
					Mat_Dis(i,j,a);
					printf("\nSecond Matrix :  \n\n");
					Mat_Dis(i,j,b);
					Mat_Add(i,j,a,b);
					break;
			case 2:	printf("\nEnter the order of First Matrix :  \nRows :  ");
					scanf("%d",&i);
					printf("Columns :  ");
					scanf("%d",&j);
					printf("\nEnter the Columns of Second Matrix :  \n");
					scanf("%d",&k);
					Mat_Create(i,j,a);
					printf("\nFirst Matrix :  \n\n");
					Mat_Dis(i,j,a);
					Mat_Create(j,k,b);
					printf("\nSecond Matrix :  \n\n");
					Mat_Dis(j,k,b);
					Mat_Mul(i,j,k,a,b);
					break;
			case 3: printf("\nEnter the order of both Matrices :\n");
					printf("Rows :  ");
					scanf("%d",&i);
					printf("Columns :  ");
					scanf("%d",&j);
					Mat_Create(i,j,a);
					printf("\nFirst Matrix :  \n\n");
					Mat_Dis(i,j,a);
					Mat_Create(i,j,b);
					printf("\nSecond Matrix :  \n\n");
					Mat_Dis(i,j,b);
					Mat_Sub(i,j,a,b);
					break;
			case 4: exit(0);
					break;
		}
	}
}