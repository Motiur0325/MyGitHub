#include<stdio.h>

void step(int *ac,int *qr){
	int a=*ac%10;
	int q=*qr%10;
	*a=*a>>1;
	
}
void main(){
	int ac=0000;
	int br=0111;
	int qr=0011;
	int Br=1001;
	int sc=4;
	while(sc!=0){
		int qn=qr%10;
		int Qn=0;
		if((qn==0&&Qn==0)||(qn==1&&Qn==1)){
			step(&ac,&qr);
		}
	}
}