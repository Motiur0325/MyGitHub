#include<iostream>

using namespace std;

enum Shape{
	circle=0,
	line=1,
	rectangle=4,
	triangle=3
};
int main(){
	int code;
	bool flag=true;
	do{
		cout<<"\n\n1.Circle : "<<circle<<"\n2.Rectangle : "<<rectangle<<"\n3.Line : "<<line<<"\n4.Triangle : "<<triangle;
		cout<<"\nEnter Shape Code :  ";
		cin>>code;
		switch(code){
			case circle: cout<<"Circle";
						break;
			case rectangle: cout<<"Rectangle";
						break;
			case line: cout<<"Line";
						break;
			case triangle: cout<<"Triangle";
						break;
			default : flag=false;
		}
	}while(flag==true);
	cout<<"Bye";
	return 0;
}