#include<stdio.h>

void digitToString(int n,char arr[10][10]){
	if(n==0){
		return;
	}
	else{
		int digit=n%10;
		n=n/10;
		digitToString(n,arr);
		printf("%s ",arr[digit]);
	}
}
void main(){
	char arr[10][10]={"Zero","One","Two","Three","Four","Five","Six","Seven","Eight","Nine"};
	int n;
	scanf("%d",&n);
	digitToString(n,arr);
}