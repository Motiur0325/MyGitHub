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
	int a[3][3]={1,2,3,3,4,2,3,2,1};
	int b[3][3]={1,1,1,3,4,2,3,2,1};
	printf("First Matrix :  \n\n");
	Mat_Dis(3,3,a);
	printf("\nSecond Matrix :  \n\n");
	Mat_Dis(3,3,b);
	Mat_Mul(3,3,3,a,b);
}