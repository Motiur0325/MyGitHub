#include<stdio.h>

void main(){
	float x;
	printf("Enter the amount :  ");
	scanf("%f",&x);
	printf("The amount in Rupees : Rs.%.2f\n",x);
	printf("The amount in Paise  : %.0f paise",x*100);
}