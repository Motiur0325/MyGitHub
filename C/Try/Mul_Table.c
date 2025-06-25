#include<stdio.h>

void main(){
	int mul[11][11];
	for(int i=0;i<11;i++){
		for(int j=0;j<11;j++){
			if(i==0){
				mul[i][j]=j;
			}
			else{
				if(i!=0&&j==0){
					mul[i][j]=i;
				}
				else{
					mul[i][j]=i*j;
				}
			}
		}
	}
	for(int i=0;i<11;i++){
		for(int j=0;j<11;j++){
			if(i==0&&j==0){
				printf("    |\t");
			}
			else{
				printf("%3d |\t",mul[i][j]);
			}
		}
		printf("\n-------------------------------------------------------------------------------------\n");
	}
}