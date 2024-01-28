#include<stdio.h>
#include<stdlib.h>

int Set_Data[100],D_ind[10],U_ind[10];
int count=1;
char Name[5]={'A','B','C','D','E'};
int D_Union[100];
void Create_Set(int N){
	int i;
	int l=D_ind[count-1];
	for(i=l;i<N+l;i++){
		printf("\nElement :  ");
		scanf("%d",&Set_Data[i]);
	}
	D_ind[count]=i;
	count++;
}
int Set_Display(char x,int l){
	int i=0,j;
	while(Name[i]!=x)
		i++;
	if(D_ind[i+1]=='\0'){
		printf("\nSet Empty.");
		return 0;
	}
	else{
		printf("\n%c = {",Name[i]);
		for(j=D_ind[i];j<D_ind[i+1];j++){
			if(j==D_ind[i+1]-1){
				printf("%d",Set_Data[j]);
			}
			else{
				printf("%d,",Set_Data[j]);
			}
		}
		printf("}\n");
	}
	return 0;
}
void Set_Union(char x[]){
	int i=0,k=0;
	while(x[k]!='\0'){
		if(k==0){
			U_ind[k]=0;
		}
		else{
			U_ind[k]=D_ind[k+1];
		}
		k++;
	}
	printf("\n%d",U_ind[k-1]);
	for(i=0;i<U_ind[k-1];i++){
			D_Union[i]=Set_Data[i];
	}
	printf("\nUnion :  ");
	for(i=0;i<U_ind[k-1];i++){
		printf("%d,",D_Union[i]);
	}
}
void main(){
	int ch,n;
	char x;
	char Union[5];
	D_ind[0]=0;
	while(1){
		printf("\n\n\t\tSETS\n\t-------------------\n\t-------------------\n\n1.Create\n2.Display\t\tEnter Choice :  ");
		scanf("%d",&ch);
		switch(ch){
			case 1: printf("\nEnter the no. of elements :  ");
					scanf("%d",&n);
					Create_Set(n);
					break;
			case 2: if(count==1){
						printf("\nNo Set to display.");
						break;
					}
					else{
						printf("\nEnter the Set to be displayed :  ");
						scanf("%s",&x);
						Set_Display(x,D_ind[count-1]);
					}
					break;
			case 3: printf("Enter the sets for union :  ");
					for(int i=0;i<2;i++){
						scanf("%s",&Union[i]);
					}
					Set_Union(Union);
		}
	}
}