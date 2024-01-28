#include<stdio.h>

void print(int n,int a[n][n]){
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			printf("%2d ",a[i][j]);
		}
		printf("\n");
	}
}
void create_initial_matrix(int n,int a[n][n]){
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			a[i][j]=0;
		}
	}
}
void create_magic_square(int n,int a[n][n]){
	int count=1;
	int i=0;
	int j=n/2;
	while(count<=n*n){
		if(i<0)
			i=n-1;
		if(j<0)
			j=n-1;
		if(a[i][j]!='\0'){
			i=(i+2)%n;
			j=(j+1)%n;
		}
		a[i][j]=count;
		i--;
		j--;
		count++;
	}
}
void rec_magic_square(int count,int i,int j,int n,int a[n][n]){
	if(count==n*n){
		a[i][j]=count;
		return;
	}
	if(a[i][j]!='\0'){
		rec_magic_square(count,(i+2)%n,(j+1)%n,n,a);
	}
	else{
		a[i][j]=count;
		rec_magic_square(count+1,(i+n-1)%n,(j+n-1)%n,n,a);
	}
}
void main(){
	int n;
	loop:
	printf("Enter the size of magic square :  ");
	scanf("%d",&n);
	int a[n][n];
	if(n%2==1){
		create_initial_matrix(n,a);
		printf("Initial Array :  \n");
		print(n,a);
		rec_magic_square(1,0,n/2,n,a);
		create_magic_square(n,a);
		printf("Magic Square :  \n");
		print(n,a);
		
	}
	else{
		printf("Enter an odd number as size!!!\n");
		goto loop;
	}
}