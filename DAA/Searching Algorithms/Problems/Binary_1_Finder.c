#include<stdio.h>
#include<math.h>

int Digit_Find(int n){
	int i=0;
	while(1){
		int k=pow(10,i);
		if(n/k==0){
			return i;
		}
		i++;
	}
}
int Find_One(int n,int M){
	int i=M,count=0;
	while(i!=-1){
		int k=pow(10,i);
		if(n/k==1)
			count++;
		if(n/k>1){
			printf("Given number is not binary!!\n");
		}
		n=n%k;
		i--;
	}
	return count;
}
void main(){
	int n,M;
	printf("Enter the binary number :  ");
	scanf("%d",&n);
	M=Digit_Find(n);
	printf("Number of One's :  %d",Find_One(n,M));
}