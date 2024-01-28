#include<stdio.h>
#include<time.h>
clock_t start_t,end_t;
void main(){
	int i=0;
	double total_t;
	start_t=clock();
	while(i<=1000000)
		i++;
	end_t=clock();
	total_t=(double)((end_t-start_t))/CLOCKS_PER_SEC;
	printf("Ex time : %.10f",total_t);
}