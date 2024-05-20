#include<stdio.h>

int checkqn(int x){
	if(x%2==0)return 0;
	else return 1;
}
void ashr(int*ac,int *qr){
	int acn;
	if(*ac%2==0)acn=0;
	else acn=1;
	*qr=*qr>>1;
	if(acn==1)*qr=*qr|8;
//	printf("\nAC(Shift) :  %d\t%d\n",*ac,*ac&8);
	acn=*ac&8;
	if(acn==0){
//		printf("\nInside 0\n");
		*ac=*ac>>1;
	}
	else{
		*ac=*ac>>1;
		*ac=*ac|8;
	}
}
int booth(int a,int b){
	int ac=0;
	int qn1=0;
	int sc=4;
	int qr=b;
	int br=15-a+1;
//	printf("AC :  %d\tQR :  %d\n",ac,qr);
	while(sc>0){
		int qn=checkqn(qr);
		if(qn==1&&qn1==0){
			ac=(ac+br)%16;
//			printf("\nInside 10 :  %d\n",ac);
		}
		if(qn==0&&qn1==1){
//			printf("\nInside 01 :  %d\n",ac);
			ac=(ac+a)%16;
//			printf("\nInside 01 :  %d\n",ac);
		}
		ashr(&ac,&qr);
		qn1=qn;
//		printf("\nQ(n) :  %d\tQ(n+1) :  %d\n",qn,qn1);
		printf("AC :  %d\tQR :  %d\n",ac,qr);
		sc--;
	}
	ac=ac<<4;
	return ac+qr;
}
void main(){
	int a,b;
	printf("Enter the two numbers :  ");
	scanf("%d%d",&a,&b);
	printf("\nThe product is :  %d",booth(a,b));
}