#include<stdio.h>
#include<math.h>
#define PI 3.142857

void main(){
	printf("x(in degrees)\tsin(x)\t\tcos(x)\n");
	for(int i=0;i<=90;i+=15){
		printf("%d\t\t%.2f\t\t%.2f\n",i,sin(i*PI/180),cos(i*PI/180));
	}
}