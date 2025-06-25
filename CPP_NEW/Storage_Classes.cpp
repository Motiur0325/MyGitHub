#include<iostream>
using namespace std;

void storage_auto(){
	auto count=0;
	cout<<"Count[auto] :  "<<count<<"\n";
	count++;
}
extern void storage_static(){
	static int count=0;
	cout<<"Count[static] :  "<<count<<"\n";
	count++;
}
void storage_register(){
	register int count=0;
	cout<<"Count[register] :  "<<count<<"\n";
	count++;
}
int main(){
	int x=10;
	int *p,*q;
	*p=x;
	q=&x;
	cout<<"\nP ::  "<<*p<<" "<<p<<" "<<&p<<"\n";
	cout<<"\nQ ::  "<<*q<<" "<<q<<" "<<&q<<"\n";
	cout<<"\nX ::  "<<x<<" "<<&x<<"\n";
	storage_auto();
	storage_auto();
	storage_static();
	storage_static();
	storage_register();
	storage_register();
	return 0;
}