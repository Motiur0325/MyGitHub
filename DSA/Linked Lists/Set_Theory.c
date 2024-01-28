#include<stdio.h>
#include<stdlib.h>

int Set_Data[100],D_ind[10],Uni_ind[10];
int l=0,count=1;
char Name[10];

int Set_Ele_Check(int);
void Create_Set(int N){
	int i;
	for(i=l;i<N+l;i++){
		printf("\nElement :  ");
		scanf("%d",&Set_Data[i]);
	}
	l=i;
	D_ind[count]=Set_Ele_Check(l);
	l=D_ind[count];
	count++;
}
void Set_Display(char x,int l){
	int i=0,j;
	while(Name[i]!=x)
		i++;
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
void Set_Sort_Check(int l,int r,int x[]){
	int i,j,temp;
	for(i=l;i<r;i++){
		for(j=l;j<r-i-1;j++){
			if(x[j]>x[j+1]){
				temp=x[j];
				x[j]=x[j+1];
				x[j+1]=temp;
			}
		}
	}
	for(i=l;i<r;i++){
		if(x[i]==x[i+1]&&x[r]!='\0'){
			j=i+2;
			x[i+1]='\0';
			while(j<=r){
				x[j-1]=x[j];
				j++;
			}
			r--;
		}
	}
	printf("\n\nUnion Set :  {");
	for(i=l;i<r;i++){
		if(i==r-1){
			printf("%d}",x[i]);
			break;
		}
		printf("%d,",x[i]);
	}
}
void Set_Null(int x[]){
	for(int i=0;i<10;i++)
		x[i]=0;
}
void Set_Union(char x[]){
	int l,r,k,j=0,i=0;
	int Uni_Data[100];
	Set_Null(Uni_ind);
	while(x[j]!='3'){
		k=0;
		while(Name[k]!=x[j])
			k++;
		Uni_ind[i]=D_ind[k];
		i++;
		Uni_ind[i]=D_ind[k+1];
		i++;
		j++;
	}
	j=0;
	k=0;
	while(j<i){
		l=Uni_ind[j];
		r=Uni_ind[j+1];
		while(l<r){
			Uni_Data[k]=Set_Data[l];
			k++;
			l++;
		}
		j=j+2;
	}
	Set_Sort_Check(0,k,Uni_Data);
	printf("\n");
}
void main(){
	int ch,n,i=0,j=0;
	char x,Set_Uni[5];
	D_ind[0]=0;
	while(1){
		printf("\n\t\tSETS\n\t--------------------\n\n1.Create\n2.Display\n3.Union\n0.Exit\t\tEnter Choice :  ");
		scanf("%d",&ch);
		printf("\nNon Empty Sets :  ");
		for(int j=0;Name[j]!='\0';j++)
			printf("%c ",Name[j]);
		printf("\n");
		switch(ch){
			case 1: printf("\nEnter the Set_Name :  ");
					scanf("%s",&x);
					Name[i]=x;
					i++;
					printf("\nEnter the no. of elements :  ");
					scanf("%d",&n);
					Create_Set(n);
					break;
			case 2: printf("\nEnter the Set to be displayed :  ");
					scanf("%s",&x);
					Set_Display(x,D_ind[count-1]);
					break;
			case 3: printf("\nEnter the sets for union :  ('Enter '3' to exit')");
					x='0';
					j=0;
					while(x!='3'){
						printf("\nSet :  ");
						scanf("%s",&x);
						Set_Uni[j]=x;
						j++;				
					}
					Set_Union(Set_Uni);
					break;
			case 0: exit(0);
		}
	}
}
int Set_Ele_Check(int r){
	int i,j,temp;
	for(i=D_ind[count-1];i<r-1;i++){
		for(j=D_ind[count-1];j<(r+D_ind[count-1])-i-1;j++){
			if(Set_Data[j]>Set_Data[j+1]){
				temp=Set_Data[j];
				Set_Data[j]=Set_Data[j+1];
				Set_Data[j+1]=temp;
			}
		}
	}
	printf("\n\nSorted Set :  ");
	for(i=D_ind[count-1];i<r;i++)
		printf("%d ",Set_Data[i]);
	printf("\n");
	for(i=D_ind[count-1];i<r;i++){
		if(Set_Data[i]==Set_Data[i+1]){
			j=i+2;
			Set_Data[i+1]='\0';
			while(j<=r){
				Set_Data[j-1]=Set_Data[j];
				j++;
			}
			r--;
		}
	}
	return r;
}