#include<stdio.h>

void P_by_W_sort(int n,float W[],float P[]){
	int w,p;
	for(int i=0;i<n;i++){
		for(int j=0;j<n-1;j++){
			if(P[i]/W[i]>P[j]/W[j]){
				w=W[i];
				p=P[i];
				P[i]=P[j];
				W[i]=W[j];
				P[j]=p;
				W[j]=w;
			}
		}
	}
}
void Knap_Sack(int m,int n,float W[],float P[]){
	float profit=0.0,x[n];
	int i,rem_w=m;
	for(i=0;i<n;i++){
		x[i]=0.0;
	}
	for(i=0;i<n;i++){
		if(rem_w-W[i]>0){
			x[i]=1.0;
			rem_w=rem_w-W[i];
		}
		else{
			x[i]=(float)rem_w/W[i];
			break;
		}
	}
	for(i=0;i<n&&x[i]>0;i++)
		profit+=P[i]*x[i];	
	printf("\nMaximum Profit :  %.2f\n",profit);
}
void main(){
	int m,n;
	printf("Enter No. of Items and Knapsack Weight Resp. :  ");
	scanf("%d",&n);
	scanf("%d",&m);
	float W[n],P[n];
	for(int i=0;i<n;i++){
		printf("Enter the Item weight and Profit earned :  ");
		scanf("%f",&W[i]);
		scanf("%f",&P[i]);
	}
	P_by_W_sort(n,W,P);
	Knap_Sack(m,n,W,P);
}