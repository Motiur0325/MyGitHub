#include<stdio.h>

int myBool=0,count=0;
int top=0;

void print(int q,int Q[q][q]){
	int i,j;
	printf("\n------------------------\n\n");
	for(i=1;i<q;i++){
		for(j=1;j<q;j++){
			if(Q[i][j]==q-1){
				printf("Q   ");
			}
			else{
				printf("-   ");
			}
		}
		printf("\n\n");
	}
	//printf("------------------------\n");
}
void initialize(int q,int Q[q][q]){
	int i,j;
	for(i=1;i<q;i++){
		for(j=1;j<q;j++)
			Q[i][j]=0;
	}
}
void sort(int arr[],int n){
	int temp,i,j;
	printf("\nTop[%d] : %d",n,arr[n]);
	for(i=1;i<=n;i++){
		for(j=1;j<=n-i;j++){
			if(arr[j]<arr[j+1]){
				temp=arr[j];
				arr[j]=arr[j+1];
				arr[j+1]=temp;
			}
		}
	}
}
void push(int n,int arr[]){
	top++;
	arr[top]=n;
}
void pop(int arr[]){
	int q=arr[top];
	arr[top]=0;
	top--;
}
void Q_Cross(int i,int j,int q,int Q[q][q]){
	int m=1,n;
	while(m<q){
		if(Q[i][m]==0||Q[i][m]==1)
			Q[i][m]=1;
		m++;
	}
	m=1;
	while(m<q){
		if(Q[m][j]==0||Q[m][j]==1)
			Q[m][j]=1;
		m++;
	}
	m=i+1;
	n=j+1;
	while(m<q&&n<q){
		if(Q[m][n]==0||Q[m][n]==1)
			Q[m][n]=1;
		m++;
		n++;
	}
	while(m>0&&n>0){
		if(Q[m][n]==0||Q[m][n]==1)
			Q[m][n]=1;
		m--;
		n--;
	}
	m=i+1;
	n=j-1;
	while(m<q&&n>0){
		if(Q[m][n]==0||Q[m][n]==1)
			Q[m][n]=1;
		m++;
		n--;
	}
	while(m>0&&n<q){
		if(Q[m][n]==0||Q[m][n]==1)
			Q[m][n]=1;
		m--;
		n++;
	}
}
void Back_Track(int start,int q,int Check[q],int Q[q][q]){
	int i=1,j=start,myCheck=0;
	Q[i][j]=q-1;
	Q_Cross(i,j,q,Q);
	for(i=2;i<q;i++){
		int p=1;
		if(Check[top]==0){
			while(p!=q){
				if(Q[i][p]==0)
					push(p,Check);
				p++;
			}
			printf("\nCheck :  ");
			for(int k=1;k<=top;k++)
				printf("%d ",Check[k]);
			sort(Check,top);
		}
		printf("\nCheck :  ");
		for(int k=1;k<=top;k++)
			printf("%d ",Check[k]);
		for(j=1;j<q;j++){	
			if(Check[top]==0)
					return;
			for(int k=top;k!=0;k--){
				if(Check[k]==j)
					myCheck=1;
			}
			if(myCheck==1){
				Q[i][j]=q-1;
				Q_Cross(i,j,q,Q);
				pop(Check);
				print(q,Q);
				if(i==q-1){
					myBool=1;
					return;
				}
			}
		}
		printf("\nCheck :  ");
		for(int k=top;k>0;k--)
			printf("%d ",Check[k]);
		if(Check[top]!=0){
			initialize(q,Q);
			printf("\nI[loop] :  %d\n",i);
			Back_Track(start,q,Check,Q);
		}      
		if(Check[top]==0&&j==q){
			return;
		}
	}	
}
void N_Queen(int i,int q,int Check[q],int Q[q][q]){
	if(i==q){
		return;
	}
	initialize(q,Q);
	printf("\nI :  %d\n",i);
	Back_Track(i,q,Check,Q);
	printf("\nTop :  %d",Check[top]);
	if(myBool==1){
		printf("\nSolution :  \n");
		print(q,Q);
		myBool=0;
	}
	i++;
	N_Queen(i,q,Check,Q);
}
void main(){
	int q;
	printf("Enter the number of Queens :  ");
	scanf("%d",&q);
	int Q[q+1][q+1],Check[q+1];
	for(int k=0;k<q;k++)
		Check[k]=0;
	N_Queen(1,q+1,Check,Q);
}