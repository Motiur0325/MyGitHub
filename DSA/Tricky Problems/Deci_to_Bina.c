#include<stdio.h>
#include<stdlib.h>
#include<math.h>

void Deci_to_Bina(){
	int d,i=0,b[10];
	printf("\nEnter the decimal number :  ");
	scanf("%d",&d);
	while(d!=0){
		b[i]=d%2;
		d=d/2;
		i++;
	}
	printf("\nBinary :  ");
	for(int k=i-1;k>=0;k--){
		printf("%d",b[k]);
	}
	printf("\n");
}
void Bina_to_Deci(){
	/*int d,i=10,temp=0,x=0;
	printf("\nEnter the binary number :  ");
	scanf("%d",&d);
	while(temp!=1){
		i--;
		temp=d/pow(10,i);
		if(i==-1){
			printf("\nDecimal Equivalent :  0");
			goto end;
		}
	}
	while(i!=-1){
		if(d/(int)pow(10,i)>1){
			printf("\nGiven number not binary.");
			goto end;
		}
		x=x+(d/(int)pow(10,i))*(pow(2,i));
		d=d%(int)pow(10,i);
		i--;
	}
	printf("\nDecimal Equivalent :  %d",x);
	end :
		printf("\n");*/
	int n,i=10,x=0,temp;
	printf("\nEnter the Binary number :  ");
	scanf("%d",&n);
	while(i!=-1){
		temp=n/(int)pow(10,i);
		if(temp!=0||x!=0){
			temp=n/(int)pow(10,i);
			if(temp>1){
				printf("\nInvalid Binary Number.");
				goto end;
			}
			else{
				x+=temp*(int)pow(2,i);
				n=n%(int)pow(10,i);
			}
		}
		i--;
	}
	if(temp==0&&x==0){
		printf("\nDecimal Equivalent :  0");
	}
	else{
		printf("\nDecimal Equvalent :  %d",x);
		end :
			printf("\n");
	}
}
void Deci_to_Hexa(){
	int d,rem=0,i=0,b[10],j;
	char hex[12]={10,'A',11,'B',12,'C',13,'D',14,'E',15,'F'};
	printf("\nEnter the decimal number :  ");
	scanf("%d",&d);
	while(d!=0){
		rem=d%16;
		b[i]=rem;
		d=d/16;
		i++;
	}
	printf("\nHexadecimal Equivalent :  ");
	for(int k=i-1;k>=0;k--){
		if(b[k]>9){
			j=0;
			while(hex[j]!='\0'){
				if(b[k]==hex[j]){
					printf("%c",hex[j+1]);
				}
				j++;
			}
		}
		else{
			printf("%d",b[k]);
		}
	}
	printf("\n");
}
void Hexa_to_Deci(){
	int i,x=0,j=0,p=0;
	char deci[12]={10,'A',11,'B',12,'C',13,'D',14,'E',15,'F'},temp[10];
	printf("\nEnter the HexDecimal number :  ");
	scanf("%s",&temp);
	while(temp[j+1]!='\0'){
		j++;
	}
	while(j!=-1){
		i=0;
		if((int)temp[j]>57){
			while(deci[i]!='\0'){
				if(temp[j]==deci[i]){
					x+=(int)deci[i-1]*pow(16,p);
				}
				i++;
			}	
		}
		else{
			x+=(int)(temp[j]-48)*pow(16,p);
		}
		j--;
		p++;
	}
	if(x==0){
		printf("\nDecimal Equivalent :  0\n");
	}
	else{
		printf("\nDecimal Equvalent :  %d\n",x);
	}
}
void Deci_to_Octa(){
	int n,o[10],i=0;
	printf("\nEnter the decimal number :  ");
	scanf("%d",&n);
	while(n!=0){
		o[i]=n%8;
		n=n/8;
		i++;
	}
	printf("\nOctal Equivalent :  ");
	for(int k=i-1;k>=0;k--){
		printf("%d",o[k]);
	}
	printf("\n");
}
void Octa_to_Deci(){
	int n,i=10,d[10],x=0,temp;
	printf("\nEnter the Octal number :  ");
	scanf("%d",&n);
	while(i!=-1){
		temp=n/(int)pow(10,i);
		if(temp!=0){
			if(temp>7){
				printf("\nInvalid Octal Number.");
				goto end;
			}
			x+=n/(int)pow(10,i)*pow(8,i);
			n=n%(int)pow(10,i);
		}
		i--;
	}
	if(x==0){
		printf("\nDecimal Equivalent :  0");
		goto end;
	}
	printf("\nDecimal Equvalent :  %d",x);
	end :
		printf("\n");
}
int main(){
	int ch;
	while(1){
		printf("\n1.Deci_to_Bina\n2.Bina_to_Deci\n3.Deci_to_Hexa\n4.Hexa_to_Deci\n5.Deci_to_Octa\n6.Octa_to_Deci\n7.Exit\t\t\tEnter Choice :  ");
		scanf("%d",&ch);
		switch(ch){
			case 1 : Deci_to_Bina();
					   break;
			case 2 : Bina_to_Deci();
					   break;
			case 3 : Deci_to_Hexa();
					   break;
			case 4 : Hexa_to_Deci();
					   break;
			case 5 : Deci_to_Octa();
					   break;
			case 6 : Octa_to_Deci();
					   break;
			case 7 : exit(0);
					   break;
		}
		printf("\n\n\n----------------------------------------------------------\n\n\n");
	}
}